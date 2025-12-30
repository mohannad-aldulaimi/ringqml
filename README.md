<p align="center">
  <img src="RingQML.jpg" width="40%" style="border-radius: 10%;">
</p>

# RingQML Extension

A simple-to-use library used to interact with QML (Qt Meta-object Language) using the [Ring programming language](https://ring-lang.net/).

## 📋 Requirements

### Build Requirements
To build the extension from source, you need:
* **[Ring Programming Language](https://ring-lang.net/)**
* **Qt 5.15**
* **MSVC Compiler**
* Good experience in C/C++ and Operating Systems.

### Usage Requirements
To use the library in your projects:
* **[Ring Programming Language](https://ring-lang.net/)**
* Good experience in general coding (Understanding scopes, functions, variables, and comments).

> **📱 Note:** All Android applications have been tested using the **Samsung Galaxy S25 Ultra**.

## 📥 Installation

### Option 1: Using RingPM (Recommended)
You can install the package directly using the Ring Package Manager:

```bash
ringpm install ringqml from mohannad-aldulaimi
```

### Option 2: Manual Installation
1.  Download this repository.
2.  Load the library in your code from `lib/ringQML.ring`.
3.  Ensure the DLL is accessible. Use `loadlib` to load `src/Build/RingQML.dll`.

## 💻 Usage Example

Here is a simple example showing how to load the library, create a Qt Application, and render a QML window with a green rectangle and text.

### main.ring

<pre style="background-color: #111; padding: 10px; border-radius: 5px; overflow-x: auto; color: #fff;">
<span style="color: #0b59ac;">load</span> <span style="color: #7a5004;">'guilib.ring'</span>
<span style="color: #0b59ac;">load</span> <span style="color: #7a5004;">'ringQML.ring'</span>

<span style="color: #0b59ac;">new</span> qApp <span style="color: #ffff00;">{</span>
    oQML = <span style="color: #0b59ac;">new</span> <span style="color: #ffff00;">RingQML</span><span style="color: #fff;">(</span><span style="color: #fff;">NULL</span><span style="color: #fff;">)</span> <span style="color: #ffff00;">{</span>
        <span style="color: #f07fe0; font-style: italic;">loadContent</span><span style="color: #fff;">(</span><span style="color: #f07fe0; font-style: italic;">getMainQml</span><span style="color: #fff;">())</span>
    <span style="color: #ffff00;">}</span>
    <span style="color: #f07fe0; font-style: italic;">exec</span><span style="color: #fff;">()</span>
<span style="color: #ffff00;">}</span>

<span style="color: #0b59ac;">func</span> <span style="color: #f07fe0; font-style: italic;">getMainQml</span>
    <span style="color: #0b59ac;">return</span> <span style="color: #7a5004;">"
        <span style="color: #0b59ac;">import</span> <span style="color: #ffff00;">QtQuick</span> <span style="color: #fff;">2.15</span>
        <span style="color: #0b59ac;">import</span> <span style="color: #ffff00;">QtQuick.Controls</span> <span style="color: #fff;">2.15</span>
        <span style="color: #0b59ac;">import</span> <span style="color: #ffff00;">QtQuick.Window</span> <span style="color: #fff;">2.15</span>
            
        <span style="color: #ffff00;">Window</span> <span style="color: #ffff00;">{</span>
            <span style="color: #fff;">visible:</span> <span style="color: #fff;">true</span>
            <span style="color: #fff;">width:</span> <span style="color: #fff;">400</span>
            <span style="color: #fff;">height:</span> <span style="color: #fff;">400</span>
            <span style="color: #fff;">title:</span> <span style="color: #7a5004;">'Ring QML Loaded'</span>
            
            <span style="color: #ffff00;">Rectangle</span> <span style="color: #ffff00;">{</span> 
                <span style="color: #fff;">anchors.fill:</span> <span style="color: #fff;">parent;</span>
                <span style="color: #fff;">id:</span> myRedBoxRoot
                <span style="color: #fff;">width:</span> <span style="color: #fff;">500</span>
                <span style="color: #fff;">height:</span> <span style="color: #fff;">500</span>
                <span style="color: #fff;">color:</span> <span style="color: #7a5004;">'green'</span>
                
                <span style="color: #ffff00;">Text</span> <span style="color: #ffff00;">{</span>
                    <span style="color: #fff;">id:</span> myText 
                    <span style="color: #fff;">text:</span> <span style="color: #7a5004;">'Ring QML Is Loaded'</span>
                    <span style="color: #fff;">font.pointSize:</span> <span style="color: #fff;">20</span>
                <span style="color: #ffff00;">}</span>
            <span style="color: #ffff00;">}</span>
        <span style="color: #ffff00;">}</span>
    "</span>
</pre>

## 📂 File Structure

* **libraries/RingQML**: Contains `*.ring` files (Ring library).
* **src**: Contains C/C++ and Qt project files for the extension.
* **bin**: Contains `RingQML.dll` file.
* **tests**: Contains simple `*.ring` files for testing.
* **projects**: Contains applications developed using the RingQML extension.
* **QMLClasses**: Contains `*.cf` files for the Ring code generator that generates code independent of the `guilib.ring` library.

## 📄 License

This project is licensed under the **MIT License**.

## ✍️ Author

**Mohannad Alayash**

* **E-Mail**: mohannadazazalayash@gmail.com
* **Website**: https://mohannad-aldulaimi.github.io