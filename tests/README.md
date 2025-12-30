# RingQML Library Tests
<p align="center">
  <img src="../RingQML.jpg" width="40%" style="border-radius: 10%;">
</p>

This directory contains examples and test scripts demonstrating the integration between the `Ring programming language` and `Qt/QML` via the `RingQML` library. The tests cover content loading, event handling, component creation, and state management.

## Test Files Overview

| Category | Filename | Description |
| :--- | :--- | :--- |
| **Content Loading** | `test1.ring` | Loading QML content using `QQuickView` |
| | `test2.ring` | Loading QML content using `QQuickWidget` |
| | `test3.ring` | Loading QML content using `QQmlApplicationEngine` |
| **Ring Integration** | `test_call_1.ring` | Executing code using `Ring.eval` |
| | `test_call_2.ring` | Handling events using `Ring.callEvent` |
| | `test_call_3.ring` | Using `Ring.callFunc` (No return value, No parameters) |
| | `test_call_4.ring` | Using `Ring.callFunc` (No return value, With parameters) |
| | `test_call_5.ring` | Using `Ring.callFunc` (With return value & parameters) |
| **Components** | `test_coponent_1.ring` | creating a new custom Component |
| | `test_coponent_2.ring` | Creating a new custom Component (with functions) |
| **State Management** | `test_getter_setter_1.ring` | Variable manipulation using `setVar`/`getVar` |

---
*Note: Ensure the RingQML library is correctly linked before running these tests.*
