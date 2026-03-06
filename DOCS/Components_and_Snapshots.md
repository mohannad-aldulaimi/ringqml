# Components and Snapshots

RingQML allows you to generate completely independent UI components on the fly, and grab instantaneous visual snapshots of UI elements.

## 1. Creating Dynamic Components

If you need to load ad-hoc QML segments programmatically during runtime, you can use `NewComponent()`. 

The function parses a string into a QML object, registers it locally under the specified name, and returns a pointer reference `ringQMLComponentRoot` to it.

```ring
cCustomButtonQml = `
import QtQuick 2.15
import QtQuick.Controls 2.15

Button {
    text: "Dynamic Instance"
    width: 100
    height: 40
}
`

// Instantiates the string into a live QML component
oNewItem = oQML.NewComponent("MyCoolButton", cCustomButtonQml)

// You can interact directly with oNewItem 
```
*Tip: Under the hood, RingQML assigns a dynamic class wrapper (e.g. `ringQmlComponenetRoot_1`) to cleanly manage multiple instantiated ad-hoc objects without namespace collisions.*


## 2. Taking Snapshots

When utilizing QML for animations, graphing, or data visualization, you might want to export the layout as an image. 

RingQML lets you snapshot any rendered element by referencing its defined `objectName` (not its `id`). 

```qml
// In your QML...
Rectangle {
    id: myVisual
    objectName: "exportTarget" // <--- Required!
    width: 300; height: 300
    color: "blue"
    
    Text { text: "Hello snapshot" }
}
```

Inside your Ring UI handler:

```ring
// Returns a QImage holding the pixel buffer
oImage = oQML.grabItemsnapshot("exportTarget")

// Using standard QImage library methods:
lSuccess = oImage.save("C:/output/snapshot.png", "PNG", 80)

if lSuccess
    ? "Successfully exported item to disk!"
ok
```

*Note: `TakeSnapshot` and `grabItemsnapshot` are aliased to the same underlying functionality.*


---

**[⬅️ Previous: Interactivity and Data](Interactivity_and_Data.md)**
