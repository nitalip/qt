/****************************************************************************
**
** Copyright (C) 2010 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtDeclarative module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qdeclarativeparser_p.h"

#include "qdeclarativepropertyvaluesource.h"
#include "qdeclarativevme_p.h"
#include "qdeclarative.h"
#include "qdeclarativecomponent_p.h"
#include "qdeclarativecomponent.h"
#include "qmetaobjectbuilder_p.h"
#include "qdeclarativevmemetaobject_p.h"
#include "qdeclarativecompiler_p.h"
#include "parser/qdeclarativejsast_p.h"
#include "parser/qdeclarativejsengine_p.h"

#include <qfxperf_p_p.h>

#include <QStack>
#include <QColor>
#include <QPointF>
#include <QSizeF>
#include <QRectF>
#include <QtDebug>

QT_BEGIN_NAMESPACE

using namespace QDeclarativeJS;
using namespace QDeclarativeParser;

QDeclarativeParser::Object::Object()
: type(-1), majorVersion(-1), minorVersion(-1), idIndex(-1), metatype(0), defaultProperty(0), parserStatusCast(-1)
{
}

QDeclarativeParser::Object::~Object() 
{ 
    if (defaultProperty) defaultProperty->release();
    foreach(Property *prop, properties)
        prop->release();
    foreach(Property *prop, valueProperties)
        prop->release();
    foreach(Property *prop, signalProperties)
        prop->release();
    foreach(Property *prop, attachedProperties)
        prop->release();
    foreach(Property *prop, groupedProperties)
        prop->release();
    foreach(Property *prop, valueTypeProperties)
        prop->release();
    typedef QPair<Property *, int> PropPair;
    foreach(const PropPair &prop, scriptStringProperties)
        prop.first->release();
    foreach(const DynamicProperty &prop, dynamicProperties)
        if (prop.defaultValue) prop.defaultValue->release();
    foreach(Object *obj, scriptBlockObjects)
        obj->release();
}

void Object::setBindingBit(int b)
{
    while (bindingBitmask.size() < 4 * (1 + b / 32))
        bindingBitmask.append(char(0));

    quint32 *bits = (quint32 *)bindingBitmask.data();
    bits[b / 32] |= (1 << (b % 32));
}

const QMetaObject *Object::metaObject() const
{
    if (!metadata.isEmpty() && metatype)
        return &extObject;
    else
        return metatype;
}

QDeclarativeParser::Property *Object::getDefaultProperty()
{
    if (!defaultProperty) {
        defaultProperty = new Property;
        defaultProperty->parent = this;
    }
    return defaultProperty;
}

void QDeclarativeParser::Object::addValueProperty(Property *p)
{
    p->addref();
    valueProperties << p;
}

void QDeclarativeParser::Object::addSignalProperty(Property *p)
{
    p->addref();
    signalProperties << p;
}

void QDeclarativeParser::Object::addAttachedProperty(Property *p)
{
    p->addref();
    attachedProperties << p;
}

void QDeclarativeParser::Object::addGroupedProperty(Property *p)
{
    p->addref();
    groupedProperties << p;
}

void QDeclarativeParser::Object::addValueTypeProperty(Property *p)
{
    p->addref();
    valueTypeProperties << p;
}

void QDeclarativeParser::Object::addScriptStringProperty(Property *p, int stack)
{
    p->addref();
    scriptStringProperties << qMakePair(p, stack);
}


Property *QDeclarativeParser::Object::getProperty(const QByteArray &name, bool create)
{
    if (!properties.contains(name)) {
        if (create) {
            Property *property = new Property(name);
            property->parent = this;
            properties.insert(name, property);
        } else {
            return 0;
        }
    }
    return properties[name];
}

QDeclarativeParser::Object::DynamicProperty::DynamicProperty()
: isDefaultProperty(false), type(Variant), defaultValue(0)
{
}

QDeclarativeParser::Object::DynamicProperty::DynamicProperty(const DynamicProperty &o)
: isDefaultProperty(o.isDefaultProperty),
  type(o.type),
  customType(o.customType),
  name(o.name),
  defaultValue(o.defaultValue),
  location(o.location)
{
}

QDeclarativeParser::Object::DynamicSignal::DynamicSignal()
{
}

QDeclarativeParser::Object::DynamicSignal::DynamicSignal(const DynamicSignal &o)
: name(o.name), parameterTypes(o.parameterTypes), 
  parameterNames(o.parameterNames)
{
}

QDeclarativeParser::Object::DynamicSlot::DynamicSlot()
{
}

QDeclarativeParser::Object::DynamicSlot::DynamicSlot(const DynamicSlot &o)
: name(o.name), body(o.body), parameterNames(o.parameterNames)
{
}

QDeclarativeParser::Property::Property()
: parent(0), type(0), index(-1), value(0), isDefault(true), isDeferred(false)
{
}

QDeclarativeParser::Property::Property(const QByteArray &n)
: parent(0), type(0), index(-1), value(0), name(n), isDefault(false), 
  isDeferred(false)
{
}

QDeclarativeParser::Property::~Property() 
{ 
    foreach(Value *value, values)
        value->release();
    foreach(Value *value, onValues)
        value->release();
    if (value) value->release(); 
}

Object *QDeclarativeParser::Property::getValue(const LocationSpan &l)
{
    if (!value) { value = new Object; value->location = l; }
    return value;
}

void QDeclarativeParser::Property::addValue(Value *v)
{
    values << v;
}

void QDeclarativeParser::Property::addOnValue(Value *v)
{
    onValues << v;
}

bool QDeclarativeParser::Property::isEmpty() const
{
    return !value && values.isEmpty() && onValues.isEmpty();
}

QDeclarativeParser::Value::Value()
: type(Unknown), object(0)
{
}

QDeclarativeParser::Value::~Value() 
{ 
    if (object) object->release();
}

QDeclarativeParser::Variant::Variant()
: t(Invalid) {}

QDeclarativeParser::Variant::Variant(const Variant &o)
: t(o.t), d(o.d), s(o.s)
{
}

QDeclarativeParser::Variant::Variant(bool v)
: t(Boolean), b(v)
{
}

QDeclarativeParser::Variant::Variant(double v, const QString &asWritten)
: t(Number), d(v), s(asWritten)
{
}

QDeclarativeParser::Variant::Variant(const QString &v)
: t(String), s(v)
{
}

QDeclarativeParser::Variant::Variant(const QString &v, QDeclarativeJS::AST::Node *n)
: t(Script), n(n), s(v)
{
}

QDeclarativeParser::Variant &QDeclarativeParser::Variant::operator=(const Variant &o)
{
    t = o.t;
    d = o.d;
    s = o.s;
    return *this;
}

QDeclarativeParser::Variant::Type QDeclarativeParser::Variant::type() const
{
    return t;
}

bool QDeclarativeParser::Variant::asBoolean() const
{
    return b;
}

QString QDeclarativeParser::Variant::asString() const
{
    return s;
}

double QDeclarativeParser::Variant::asNumber() const
{
    return d;
}

QString QDeclarativeParser::Variant::asScript() const
{
    switch(type()) { 
    default:
    case Invalid:
        return QString();
    case Boolean:
        return b?QLatin1String("true"):QLatin1String("false");
    case Number:
        if (s.isEmpty())
            return QString::number(d);
        else
            return s;
    case String:
    case Script:
        return s;
    }
}

QDeclarativeJS::AST::Node *QDeclarativeParser::Variant::asAST() const
{
    if (type() == Script)
        return n;
    else
        return 0;
}

bool QDeclarativeParser::Variant::isStringList() const
{
    if (isString())
        return true;

    if (type() != Script || !n)
        return false;

    AST::ArrayLiteral *array = AST::cast<AST::ArrayLiteral *>(n);
    if (!array)
        return false;

    AST::ElementList *elements = array->elements;

    while (elements) {

        if (!AST::cast<AST::StringLiteral *>(elements->expression))
            return false;

        elements = elements->next;
    }

    return true;
}

QStringList QDeclarativeParser::Variant::asStringList() const
{
    QStringList rv;
    if (isString()) {
        rv << asString();
        return rv;
    }

    AST::ArrayLiteral *array = AST::cast<AST::ArrayLiteral *>(n);
    if (!array)
        return rv;

    AST::ElementList *elements = array->elements;
    while (elements) {

        AST::StringLiteral *string = AST::cast<AST::StringLiteral *>(elements->expression);
        if (!string)
            return QStringList();
        rv.append(string->value->asString());

        elements = elements->next;
    }

    return  rv;
}

QT_END_NAMESPACE