# Getting Started with RingQML

RingQML allows you to seamlessly integrate QML with the Ring programming language using Qt Quick. It combines Ring's powerful logic capabilities with the fluid, hardware-accelerated user interfaces of QML.

## Basic Setup

To use RingQML, you must load the necessary Ring GUI libraries and the `ringQML.ring` package:

```ring
load 'guilib.ring'
load 'stdlibcore.ring'
load 'ringQML.ring'
```

### The Event Loop
Like any standard Qt application, you need to initiate the application event loop using `qApp`.

```ring
new qApp {
    // Application setup goes here
    exec()
}
```

### Initializing the Window

RingQML supports `QQuickView`, `QQuickWidget`, or `QQmlApplicationEngine` backends. The most common setup involves spawning a `QQuickView` and passing it to the `ringQML` class constructor.

```ring
win = new QQuickView() {
    setWidth(500)
    setHeight(600)
    setTitle("RingQML Application")
}
```

### Loading QML Content

You attach an instance of `RingQML` to your parent window/engine using `new RingQML(win)`. To load interface instructions, use the `loadContent()` method.

```ring
oQML = new RingQML(win) {
    loadContent(getMainQml())
}
```

## Complete Example

Here is a full `Hello World` example running a minimal QML block:

```ring
load 'guilib.ring'
load 'stdlibcore.ring'
load 'ringQML.ring'

new qApp {
    win = new QQuickView() {
        setWidth(500) setHeight(600)
        setTitle("RingQML : Hello World")
        
        oQML = new RingQML(win) {
            loadContent(getMainQml())
        }

        show()
    }
    exec()
}

func getMainQml
return `
import QtQuick 2.15
import QtQuick.Controls 2.15

Rectangle {
    id: root
    width: 500
    height: 500
    color: "transparent"
    anchors.centerIn: parent
    
    Text {
        id: myText 
        anchors.fill: parent
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        text: "Hello World"
        font.pointSize: 40
    }
}
`
```

## Using Qt 6 with RingQML

By default, the Ring programming language uses Qt 5.15. If you want to use a newer version like Qt 6.10.2, you will need to download and install this Qt 6 version yourself.

Once installed on your machine, you can use the `useQt6(path)` function. Passing the path of your Qt 6 MSVC compiler to this function allows RingQML to automatically handle all the paths and run your application using Qt 6.

### Qt 6 Hello World

```ring
load 'ringQML.ring'
load 'ring_qt_qml.ring'

// Pass the path to your Qt 6 installation
useQt6("C:\Qt\6.10.2\msvc2022_64")

oApp = new qApp
oQMl = new ringQML(NULL)
oQMl.loadcontent(getQt6SimpleCodeContent())

oApp.exec()

func getQt6SimpleCodeContent()
return `
    import QtQuick
    import QtQuick.Controls.Basic

    ApplicationWindow {
        id: window
        width: 500
        height: 850
        visible: true
        title: "RingQML Pro - Qt 6.10"
        color: "#08090a" 
        
        Text {
            text: "Hello From RingQML \n   this is a Qt 6.10.2"
            anchors.centerIn: parent
            color: "white"
            font.pixelSize: 30
        }
    } 
`
```

---

**[Next: RingQML Class Reference ➔](RingQML_Class_Reference.md)**
