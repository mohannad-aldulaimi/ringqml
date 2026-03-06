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

---

**[Next: RingQML Class Reference ➔](RingQML_Class_Reference.md)**
