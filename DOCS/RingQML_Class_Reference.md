# RingQML Class Reference

The `ringQML` class is the main bridge between your Ring logic and the dynamic QML context.

---

### `init(oParent)`
Initializes the QML environment.

* **Parameters:** `oParent` can be `QQuickWidget`, `QQuickView`, or `NULL` (if using `QQmlApplicationEngine`).
* **Returns:** `self` (Object)
* **Usage:** `oQML = new RingQML(win)`

---

### `setWinIcon(cIcon)`
Sets the application or window icon dynamically based on the engine type.

* **Parameters:** `cIcon` (String path to icon)
* **Returns:** `NULL`
* **Usage:** 
  ```ring
  oQML.setWinIcon("assets/app_icon.png")
  ```

---

### `loadContent(cQML)`
Parses and loads QML source code strings into the current view/engine context. *Note: this can only be called once per main window.*

* **Parameters:** `cQML` (String containing QML code)
* **Returns:** `0` or `1` (Success integer flag)
* **Usage:** 
  ```ring
  oQML.loadContent('import QtQuick 2.15; Rectangle{ width: 100; height: 100; color: "red" }')
  ```

---

---

### `root` (Dynamic Object Property)
An automatically generated object that maps to the root element of your QML. Whenever you define a JavaScript function inside the root item of your loaded QML context, a matching native method is bound to `oQML.root`.

* **Usage:** 
  ```ring
  // Assuming a function 'updateUI(title, count, dataList)' exists in the root QML item
  oQML.root.updateUI("Status", 100, ["Item 1", "Item 2"])
  ```

---

### `callQMLFunc(cFunc, aPara)`
Invokes a JavaScript/QML function located at the root of your loaded QML context.

* **Parameters:** 
  * `cFunc` (String) Name of the QML function.
  * `aPara` (List) List of parameters to pass.
* **Returns:** Result of the Javascript function evaluation.
* **Usage:** 
  ```ring
  oQML.callQMLFunc("updateTextAndColor", ["New text", "#ff0000"])
  ```

---

### `ShareWidget(pWidget, cName)`
*(Alias of `exposeQWidget`)* Exposes an existing RingQt C++ widget to the QML rendering engine so it can be embedded directly.

* **Parameters:** 
  * `pWidget` (Object/Pointer) The Ring Qt Widget Instance.
  * `cName` (String) ID exposed to the QML context.
* **Returns:** `NULL`
* **Usage:** 
  ```ring
  btn = new QPushButton(NULL) { setText("C++ Button") }
  oQML.ShareWidget(btn, "cppButton")
  ```

---

### `shareImage(pImage)`
Loads a standard `QPixmap` graphic into the custom RingProvider QML Image cache.
* **Parameters:** `pImage` (QPixmap / Object Pointer)
* **Returns:** `nId` (Number) An integer ID referring to the image hash.
* **Usage:** 
  ```ring
  img = new QPixmap("image.png")
  nId = oQML.shareImage(img)
  ```

---

### `getimage(nId)`
Generates the specific URL to load the `shareImage` graphic from within QML.
* **Parameters:** `nId` (Number) returned from `shareImage()`.
* **Returns:** String formatted as `"image://RingProvider/" + nId`
* **Usage (Inside QML):**
  ```qml
  Image { source: Ring.callFunc("getImageUrl", []) }
  ```

---

### `NewComponent(cComponentName, cQml)`
Instantiates isolated ad-hoc QML components dynamically inside the running engine without breaking the original loaded view.
* **Parameters:** 
  * `cComponentName` (String) Custom Object ID.
  * `cQML` (String) Valid QML string representing an Item/Component.
* **Returns:** `ringQmlRoot` Object pointer mapping to the component.

---

### `TakeSnapshot(cObjectName)` / `grabItemsnapshot(cObjectName)`
Grabs an immediate visual render of an active QML element by its `objectName` attribute.
* **Parameters:** `cObjectName` (String)
* **Returns:** `QImage` Object container.
* **Usage:** 
  ```ring
  mySnap = oQML.grabItemsnapshot('myRectangleId')
  mySnap.save("output_screenshot.png", "PNG", 80)
  ```

---

**[⬅️ Previous: Getting Started](Getting_Started.md)**  |  **[Next: Interactivity and Data ➔](Interactivity_and_Data.md)**
