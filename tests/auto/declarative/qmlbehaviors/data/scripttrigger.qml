import Qt 4.6
Rectangle {
    width: 400
    height: 400

    onColorChanged: {
        rect.x = 200
    }

    Rectangle {
        id: rect
        objectName: "MyRect"
        width: 100; height: 100; color: "green"
        x: Behavior { NumberAnimation { duration: 500; } }
    }
}