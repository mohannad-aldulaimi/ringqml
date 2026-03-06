# Interactivity and Data in RingQML

Communication between Ring and QML happens bidirectionally. You can call QML functions from Ring, and you can invoke Ring functions from your QML layouts. You can also share existing C++ widgets and images directly into the QML canvas.

## 1. Calling QML from Ring

You can invoke a JavaScript function that lives in your parsed QML file in two distinct ways.

### Method A: Direct Native Call (Recommended)

When you load QML, RingQML automatically parses your QML root functions and attaches them natively to the `oQML.root` object. You can call these functions exactly like standard Ring methods, passing native Ring data types (numbers, strings, lists, and tables/dictionaries).

```ring
// Calls the QML function directly with native Ring parameters
oQML.root.myQmlFunction("Parameter 1", 100, ["Item 1", "Item 2"])
```

### Method B: Using `callQMLFunc`

Alternatively, you can use the lower-level `callQMLFunc` method exposed by the `ringQML` engine instance, passing parameters as a list.

```ring
oQML.callQMLFunc("myQmlFunction", ["Parameter 1", 100, ["Item 1", "Item 2"]])
```

Inside your QML, make sure your function is accessible at the root item, regardless of which method you use:
```qml
Rectangle {
    id: root

    function myQmlFunction(textVar, numericVar, listVar) {
        console.log("Called from Ring:", textVar)
        console.log("Array parameter:", listVar[0])
        root.width = numericVar
    }
}
```


## 2. Calling Ring from QML

When you need to alert Ring of user interaction or trigger backend logic, use the globally injected `Ring.callFunc()` method inside QML.

```qml
Button {
    text: "Click Me"
    onClicked: {
        // Will call the Ring function named `buttonPressHandler`
        Ring.callFunc("buttonPressHandler", ["Button 1 Clicked", true])
    }
}
```

In your Ring file:
```ring
func buttonPressHandler cMessage, lStatus
    ? "QML Says: " + cMessage
    if lStatus = true
        // Handle logic
    ok
```


## 3. Sharing C++ Widgets

Sometimes you want to embed powerful, native Qt Widgets directly inside QML without rewriting them. `ShareWidget` (or `exposeQWidget`) handles this.

```ring
myDial = new QDial(NULL) {
    setMinimum(0)
    setMaximum(100)
    setValue(50)
}

// Expose the QDial to QML under the ID "ringDial"
oQML.ShareWidget(myDial, "ringDial")
```


## 4. Sharing Images via RingProvider

If you have a `QPixmap` or image generated in Ring code (for example, taking a snapshot of a widget), you can expose it using `shareImage`. 

```ring
oImage = new QPixmap("background.jpg")
nCacheId = oQML.shareImage(oImage)

// Store nCacheId so QML can grab it!
```

In QML, use the custom `image://RingProvider/` scheme. 
*Note: A common pattern is combining `getimage(nId)` and evaluating it dynamically inside QML or returning it from a `Ring.callFunc` request.*

```qml
Image {
    // Assume `fetchBackgroundId` is a Ring function returning the cache ID string.
    source: Ring.callFunc("fetchImageSourceString", [])
}
```

Ring code:
```ring
func fetchImageSourceString
    return oQML.getimage(nCacheId)  // Returns "image://RingProvider/1"
```

---

**[⬅️ Previous: RingQML Class Reference](RingQML_Class_Reference.md)**  |  **[Next: Components and Snapshots ➔](Components_and_Snapshots.md)**
