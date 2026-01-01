# Pray Times (مواقيت الصلاة)

A comprehensive, cross-platform prayer times application built using the **Ring** programming language and **RingQML**. Designed for the city of Ash-Shirqat and its suburbs, this application features a modern, adaptive user interface with dynamic visual elements and full customization support.

## 🌟 Features

* **Real-Time Tracking:** Displays the current date, time, and automatically highlights the next upcoming prayer.
* **Countdown Timer:** Shows the precise time remaining until the next prayer call (Adhan).
* **Visual Indicators:** Features a custom "Minute Circle" component that visualizes the progress of the current minute.

### Adaptive UI
* **Portrait Mode:** Optimized vertical layout with a bottom drawer for settings.
* **Landscape Mode:** Split-screen layout with a side list and a popup for settings.

### Customization
* **Themes:** Switch between *Dark*, *Light*, *Sepia*, and *Forest* visual styles.
* **Typography:** Adjustable font size slider to suit user preference.
* **Backgrounds:** Smooth fade animations between background images.
* **Arabic Support:** Built-in Right-to-Left (RTL) layout direction and font handling (using Segoe UI/Tahoma) for perfect Arabic text rendering.
* **Glassmorphism:** Modern "glassy" semi-transparent popups and controls.

## 🛠️ Technologies Used

* **[Ring Programming Language](http://ring-lang.net/):** The core logic and application control.
* **[RingQML](https://github.com/ring-lang/ringqml):** A wrapper enabling Ring to utilize Qt Quick.
* **Qt Quick / QML:** Used for the fluid, hardware-accelerated user interface and animations.
* **Canvas API:** Used for drawing custom shapes like the Minute Circle.

## ⚙️ How to Run

1. Ensure you have **Ring** and the **RingQML** extension installed on your system.
2. Verify the `images/` folder contains your background images.
3. Run the application using the following command:

```bash
ring pray_times.ring