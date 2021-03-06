/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#include "config.h"
#include "JSNode.h"

#include "Document.h"
#include "Element.h"
#include "Event.h"
#include "JSDocument.h"
#include "JSElement.h"
#include "JSEvent.h"
#include "JSNamedNodeMap.h"
#include "JSNode.h"
#include "JSNodeList.h"
#include "KURL.h"
#include "NameNodeList.h"
#include "NamedNodeMap.h"
#include "Node.h"
#include "NodeList.h"
#include "RegisteredEventListener.h"
#include <runtime/Error.h>
#include <runtime/JSNumberCell.h>
#include <wtf/GetPtr.h>

using namespace JSC;

namespace WebCore {

ASSERT_CLASS_FITS_IN_CELL(JSNode);

/* Hash table */

static const HashTableValue JSNodeTableValues[19] =
{
    { "nodeName", DontDelete|ReadOnly, (intptr_t)jsNodeNodeName, (intptr_t)0 },
    { "nodeValue", DontDelete, (intptr_t)jsNodeNodeValue, (intptr_t)setJSNodeNodeValue },
    { "nodeType", DontDelete|ReadOnly, (intptr_t)jsNodeNodeType, (intptr_t)0 },
    { "parentNode", DontDelete|ReadOnly, (intptr_t)jsNodeParentNode, (intptr_t)0 },
    { "childNodes", DontDelete|ReadOnly, (intptr_t)jsNodeChildNodes, (intptr_t)0 },
    { "firstChild", DontDelete|ReadOnly, (intptr_t)jsNodeFirstChild, (intptr_t)0 },
    { "lastChild", DontDelete|ReadOnly, (intptr_t)jsNodeLastChild, (intptr_t)0 },
    { "previousSibling", DontDelete|ReadOnly, (intptr_t)jsNodePreviousSibling, (intptr_t)0 },
    { "nextSibling", DontDelete|ReadOnly, (intptr_t)jsNodeNextSibling, (intptr_t)0 },
    { "attributes", DontDelete|ReadOnly, (intptr_t)jsNodeAttributes, (intptr_t)0 },
    { "ownerDocument", DontDelete|ReadOnly, (intptr_t)jsNodeOwnerDocument, (intptr_t)0 },
    { "namespaceURI", DontDelete|ReadOnly, (intptr_t)jsNodeNamespaceURI, (intptr_t)0 },
    { "prefix", DontDelete, (intptr_t)jsNodePrefix, (intptr_t)setJSNodePrefix },
    { "localName", DontDelete|ReadOnly, (intptr_t)jsNodeLocalName, (intptr_t)0 },
    { "baseURI", DontDelete|ReadOnly, (intptr_t)jsNodeBaseURI, (intptr_t)0 },
    { "textContent", DontDelete, (intptr_t)jsNodeTextContent, (intptr_t)setJSNodeTextContent },
    { "parentElement", DontDelete|ReadOnly, (intptr_t)jsNodeParentElement, (intptr_t)0 },
    { "constructor", DontEnum|ReadOnly, (intptr_t)jsNodeConstructor, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSNodeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 4095, JSNodeTableValues, 0 };
#else
    { 68, 63, JSNodeTableValues, 0 };
#endif

/* Hash table for constructor */

static const HashTableValue JSNodeConstructorTableValues[19] =
{
    { "ELEMENT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeELEMENT_NODE, (intptr_t)0 },
    { "ATTRIBUTE_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeATTRIBUTE_NODE, (intptr_t)0 },
    { "TEXT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeTEXT_NODE, (intptr_t)0 },
    { "CDATA_SECTION_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeCDATA_SECTION_NODE, (intptr_t)0 },
    { "ENTITY_REFERENCE_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeENTITY_REFERENCE_NODE, (intptr_t)0 },
    { "ENTITY_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeENTITY_NODE, (intptr_t)0 },
    { "PROCESSING_INSTRUCTION_NODE", DontDelete|ReadOnly, (intptr_t)jsNodePROCESSING_INSTRUCTION_NODE, (intptr_t)0 },
    { "COMMENT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeCOMMENT_NODE, (intptr_t)0 },
    { "DOCUMENT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_NODE, (intptr_t)0 },
    { "DOCUMENT_TYPE_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_TYPE_NODE, (intptr_t)0 },
    { "DOCUMENT_FRAGMENT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_FRAGMENT_NODE, (intptr_t)0 },
    { "NOTATION_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeNOTATION_NODE, (intptr_t)0 },
    { "DOCUMENT_POSITION_DISCONNECTED", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_DISCONNECTED, (intptr_t)0 },
    { "DOCUMENT_POSITION_PRECEDING", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_PRECEDING, (intptr_t)0 },
    { "DOCUMENT_POSITION_FOLLOWING", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_FOLLOWING, (intptr_t)0 },
    { "DOCUMENT_POSITION_CONTAINS", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_CONTAINS, (intptr_t)0 },
    { "DOCUMENT_POSITION_CONTAINED_BY", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_CONTAINED_BY, (intptr_t)0 },
    { "DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC, (intptr_t)0 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSNodeConstructorTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 2047, JSNodeConstructorTableValues, 0 };
#else
    { 67, 63, JSNodeConstructorTableValues, 0 };
#endif

class JSNodeConstructor : public DOMConstructorObject {
public:
    JSNodeConstructor(ExecState* exec, JSDOMGlobalObject* globalObject)
        : DOMConstructorObject(JSNodeConstructor::createStructure(globalObject->objectPrototype()), globalObject)
    {
        putDirect(exec->propertyNames().prototype, JSNodePrototype::self(exec, globalObject), None);
    }
    virtual bool getOwnPropertySlot(ExecState*, const Identifier&, PropertySlot&);
    virtual bool getOwnPropertyDescriptor(ExecState*, const Identifier&, PropertyDescriptor&);
    virtual const ClassInfo* classInfo() const { return &s_info; }
    static const ClassInfo s_info;

    static PassRefPtr<Structure> createStructure(JSValue proto) 
    { 
        return Structure::create(proto, TypeInfo(ObjectType, StructureFlags)); 
    }
    
protected:
    static const unsigned StructureFlags = OverridesGetOwnPropertySlot | ImplementsHasInstance | DOMConstructorObject::StructureFlags;
};

const ClassInfo JSNodeConstructor::s_info = { "NodeConstructor", 0, &JSNodeConstructorTable, 0 };

bool JSNodeConstructor::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticValueSlot<JSNodeConstructor, DOMObject>(exec, &JSNodeConstructorTable, this, propertyName, slot);
}

bool JSNodeConstructor::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticValueDescriptor<JSNodeConstructor, DOMObject>(exec, &JSNodeConstructorTable, this, propertyName, descriptor);
}

/* Hash table for prototype */

static const HashTableValue JSNodePrototypeTableValues[37] =
{
    { "ELEMENT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeELEMENT_NODE, (intptr_t)0 },
    { "ATTRIBUTE_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeATTRIBUTE_NODE, (intptr_t)0 },
    { "TEXT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeTEXT_NODE, (intptr_t)0 },
    { "CDATA_SECTION_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeCDATA_SECTION_NODE, (intptr_t)0 },
    { "ENTITY_REFERENCE_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeENTITY_REFERENCE_NODE, (intptr_t)0 },
    { "ENTITY_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeENTITY_NODE, (intptr_t)0 },
    { "PROCESSING_INSTRUCTION_NODE", DontDelete|ReadOnly, (intptr_t)jsNodePROCESSING_INSTRUCTION_NODE, (intptr_t)0 },
    { "COMMENT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeCOMMENT_NODE, (intptr_t)0 },
    { "DOCUMENT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_NODE, (intptr_t)0 },
    { "DOCUMENT_TYPE_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_TYPE_NODE, (intptr_t)0 },
    { "DOCUMENT_FRAGMENT_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_FRAGMENT_NODE, (intptr_t)0 },
    { "NOTATION_NODE", DontDelete|ReadOnly, (intptr_t)jsNodeNOTATION_NODE, (intptr_t)0 },
    { "DOCUMENT_POSITION_DISCONNECTED", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_DISCONNECTED, (intptr_t)0 },
    { "DOCUMENT_POSITION_PRECEDING", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_PRECEDING, (intptr_t)0 },
    { "DOCUMENT_POSITION_FOLLOWING", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_FOLLOWING, (intptr_t)0 },
    { "DOCUMENT_POSITION_CONTAINS", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_CONTAINS, (intptr_t)0 },
    { "DOCUMENT_POSITION_CONTAINED_BY", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_CONTAINED_BY, (intptr_t)0 },
    { "DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC", DontDelete|ReadOnly, (intptr_t)jsNodeDOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC, (intptr_t)0 },
    { "insertBefore", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionInsertBefore, (intptr_t)2 },
    { "replaceChild", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionReplaceChild, (intptr_t)2 },
    { "removeChild", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionRemoveChild, (intptr_t)1 },
    { "appendChild", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionAppendChild, (intptr_t)1 },
    { "hasChildNodes", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionHasChildNodes, (intptr_t)0 },
    { "cloneNode", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionCloneNode, (intptr_t)1 },
    { "normalize", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionNormalize, (intptr_t)0 },
    { "isSupported", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionIsSupported, (intptr_t)2 },
    { "hasAttributes", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionHasAttributes, (intptr_t)0 },
    { "isSameNode", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionIsSameNode, (intptr_t)1 },
    { "isEqualNode", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionIsEqualNode, (intptr_t)1 },
    { "lookupPrefix", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionLookupPrefix, (intptr_t)1 },
    { "isDefaultNamespace", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionIsDefaultNamespace, (intptr_t)1 },
    { "lookupNamespaceURI", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionLookupNamespaceURI, (intptr_t)1 },
    { "compareDocumentPosition", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionCompareDocumentPosition, (intptr_t)1 },
    { "addEventListener", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionAddEventListener, (intptr_t)3 },
    { "removeEventListener", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionRemoveEventListener, (intptr_t)3 },
    { "dispatchEvent", DontDelete|Function, (intptr_t)jsNodePrototypeFunctionDispatchEvent, (intptr_t)1 },
    { 0, 0, 0, 0 }
};

static JSC_CONST_HASHTABLE HashTable JSNodePrototypeTable =
#if ENABLE(PERFECT_HASH_SIZE)
    { 4095, JSNodePrototypeTableValues, 0 };
#else
    { 134, 127, JSNodePrototypeTableValues, 0 };
#endif

const ClassInfo JSNodePrototype::s_info = { "NodePrototype", 0, &JSNodePrototypeTable, 0 };

JSObject* JSNodePrototype::self(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMPrototype<JSNode>(exec, globalObject);
}

bool JSNodePrototype::getOwnPropertySlot(ExecState* exec, const Identifier& propertyName, PropertySlot& slot)
{
    return getStaticPropertySlot<JSNodePrototype, JSObject>(exec, &JSNodePrototypeTable, this, propertyName, slot);
}

bool JSNodePrototype::getOwnPropertyDescriptor(ExecState* exec, const Identifier& propertyName, PropertyDescriptor& descriptor)
{
    return getStaticPropertyDescriptor<JSNodePrototype, JSObject>(exec, &JSNodePrototypeTable, this, propertyName, descriptor);
}

const ClassInfo JSNode::s_info = { "Node", 0, &JSNodeTable, 0 };

JSNode::JSNode(NonNullPassRefPtr<Structure> structure, JSDOMGlobalObject* globalObject, PassRefPtr<Node> impl)
    : DOMObjectWithGlobalPointer(structure, globalObject)
    , m_impl(impl)
{
}

JSNode::~JSNode()
{
    impl()->invalidateEventListeners();
    forgetDOMNode(this, impl(), impl()->document());
}

JSObject* JSNode::createPrototype(ExecState* exec, JSGlobalObject* globalObject)
{
    return new (exec) JSNodePrototype(JSNodePrototype::createStructure(globalObject->objectPrototype()));
}

JSValue jsNodeNodeName(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return jsStringOrNull(exec, imp->nodeName());
}

JSValue jsNodeNodeValue(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return jsStringOrNull(exec, imp->nodeValue());
}

JSValue jsNodeNodeType(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return jsNumber(exec, imp->nodeType());
}

JSValue jsNodeParentNode(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->parentNode()));
}

JSValue jsNodeChildNodes(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->childNodes()));
}

JSValue jsNodeFirstChild(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->firstChild()));
}

JSValue jsNodeLastChild(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->lastChild()));
}

JSValue jsNodePreviousSibling(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->previousSibling()));
}

JSValue jsNodeNextSibling(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->nextSibling()));
}

JSValue jsNodeAttributes(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->attributes()));
}

JSValue jsNodeOwnerDocument(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->ownerDocument()));
}

JSValue jsNodeNamespaceURI(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return jsStringOrNull(exec, imp->namespaceURI());
}

JSValue jsNodePrefix(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return jsStringOrNull(exec, imp->prefix());
}

JSValue jsNodeLocalName(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return jsStringOrNull(exec, imp->localName());
}

JSValue jsNodeBaseURI(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return jsStringOrNull(exec, imp->baseURI());
}

JSValue jsNodeTextContent(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return jsStringOrNull(exec, imp->textContent());
}

JSValue jsNodeParentElement(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* castedThis = static_cast<JSNode*>(asObject(slot.slotBase()));
    UNUSED_PARAM(exec);
    Node* imp = static_cast<Node*>(castedThis->impl());
    return toJS(exec, castedThis->globalObject(), WTF::getPtr(imp->parentElement()));
}

JSValue jsNodeConstructor(ExecState* exec, const Identifier&, const PropertySlot& slot)
{
    JSNode* domObject = static_cast<JSNode*>(asObject(slot.slotBase()));
    return JSNode::getConstructor(exec, domObject->globalObject());
}
void JSNode::put(ExecState* exec, const Identifier& propertyName, JSValue value, PutPropertySlot& slot)
{
    lookupPut<JSNode, Base>(exec, propertyName, value, &JSNodeTable, this, slot);
}

void setJSNodeNodeValue(ExecState* exec, JSObject* thisObject, JSValue value)
{
    Node* imp = static_cast<Node*>(static_cast<JSNode*>(thisObject)->impl());
    ExceptionCode ec = 0;
    imp->setNodeValue(valueToStringWithNullCheck(exec, value), ec);
    setDOMException(exec, ec);
}

void setJSNodePrefix(ExecState* exec, JSObject* thisObject, JSValue value)
{
    Node* imp = static_cast<Node*>(static_cast<JSNode*>(thisObject)->impl());
    ExceptionCode ec = 0;
    imp->setPrefix(valueToStringWithNullCheck(exec, value), ec);
    setDOMException(exec, ec);
}

void setJSNodeTextContent(ExecState* exec, JSObject* thisObject, JSValue value)
{
    Node* imp = static_cast<Node*>(static_cast<JSNode*>(thisObject)->impl());
    ExceptionCode ec = 0;
    imp->setTextContent(valueToStringWithNullCheck(exec, value), ec);
    setDOMException(exec, ec);
}

JSValue JSNode::getConstructor(ExecState* exec, JSGlobalObject* globalObject)
{
    return getDOMConstructor<JSNodeConstructor>(exec, static_cast<JSDOMGlobalObject*>(globalObject));
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionInsertBefore(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    return castedThisObj->insertBefore(exec, args);
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionReplaceChild(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    return castedThisObj->replaceChild(exec, args);
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionRemoveChild(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    return castedThisObj->removeChild(exec, args);
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionAppendChild(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    return castedThisObj->appendChild(exec, args);
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionHasChildNodes(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());


    JSC::JSValue result = jsBoolean(imp->hasChildNodes());
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionCloneNode(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());
    bool deep = args.at(0).toBoolean(exec);


    JSC::JSValue result = toJS(exec, castedThisObj->globalObject(), WTF::getPtr(imp->cloneNode(deep)));
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionNormalize(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());

    imp->normalize();
    return jsUndefined();
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionIsSupported(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());
    const UString& feature = args.at(0).toString(exec);
    const UString& version = valueToStringWithNullCheck(exec, args.at(1));


    JSC::JSValue result = jsBoolean(imp->isSupported(feature, version));
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionHasAttributes(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());


    JSC::JSValue result = jsBoolean(imp->hasAttributes());
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionIsSameNode(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());
    Node* other = toNode(args.at(0));


    JSC::JSValue result = jsBoolean(imp->isSameNode(other));
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionIsEqualNode(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());
    Node* other = toNode(args.at(0));


    JSC::JSValue result = jsBoolean(imp->isEqualNode(other));
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionLookupPrefix(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());
    const UString& namespaceURI = valueToStringWithNullCheck(exec, args.at(0));


    JSC::JSValue result = jsStringOrNull(exec, imp->lookupPrefix(namespaceURI));
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionIsDefaultNamespace(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());
    const UString& namespaceURI = valueToStringWithNullCheck(exec, args.at(0));


    JSC::JSValue result = jsBoolean(imp->isDefaultNamespace(namespaceURI));
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionLookupNamespaceURI(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());
    const UString& prefix = valueToStringWithNullCheck(exec, args.at(0));


    JSC::JSValue result = jsStringOrNull(exec, imp->lookupNamespaceURI(prefix));
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionCompareDocumentPosition(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());
    Node* other = toNode(args.at(0));


    JSC::JSValue result = jsNumber(exec, imp->compareDocumentPosition(other));
    return result;
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionAddEventListener(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    return castedThisObj->addEventListener(exec, args);
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionRemoveEventListener(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    return castedThisObj->removeEventListener(exec, args);
}

JSValue JSC_HOST_CALL jsNodePrototypeFunctionDispatchEvent(ExecState* exec, JSObject*, JSValue thisValue, const ArgList& args)
{
    UNUSED_PARAM(args);
    if (!thisValue.inherits(&JSNode::s_info))
        return throwError(exec, TypeError);
    JSNode* castedThisObj = static_cast<JSNode*>(asObject(thisValue));
    Node* imp = static_cast<Node*>(castedThisObj->impl());
    ExceptionCode ec = 0;
    Event* event = toEvent(args.at(0));


    JSC::JSValue result = jsBoolean(imp->dispatchEvent(event, ec));
    setDOMException(exec, ec);
    return result;
}

// Constant getters

JSValue jsNodeELEMENT_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(1));
}

JSValue jsNodeATTRIBUTE_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(2));
}

JSValue jsNodeTEXT_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(3));
}

JSValue jsNodeCDATA_SECTION_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(4));
}

JSValue jsNodeENTITY_REFERENCE_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(5));
}

JSValue jsNodeENTITY_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(6));
}

JSValue jsNodePROCESSING_INSTRUCTION_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(7));
}

JSValue jsNodeCOMMENT_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(8));
}

JSValue jsNodeDOCUMENT_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(9));
}

JSValue jsNodeDOCUMENT_TYPE_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(10));
}

JSValue jsNodeDOCUMENT_FRAGMENT_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(11));
}

JSValue jsNodeNOTATION_NODE(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(12));
}

JSValue jsNodeDOCUMENT_POSITION_DISCONNECTED(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(0x01));
}

JSValue jsNodeDOCUMENT_POSITION_PRECEDING(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(0x02));
}

JSValue jsNodeDOCUMENT_POSITION_FOLLOWING(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(0x04));
}

JSValue jsNodeDOCUMENT_POSITION_CONTAINS(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(0x08));
}

JSValue jsNodeDOCUMENT_POSITION_CONTAINED_BY(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(0x10));
}

JSValue jsNodeDOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC(ExecState* exec, const Identifier&, const PropertySlot&)
{
    return jsNumber(exec, static_cast<int>(0x20));
}

Node* toNode(JSC::JSValue value)
{
    return value.inherits(&JSNode::s_info) ? static_cast<JSNode*>(asObject(value))->impl() : 0;
}

}
