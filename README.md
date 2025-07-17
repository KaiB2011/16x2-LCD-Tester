**16x2-LCD-Tester**

This is an app (Currently only compatible with Arduino) that allows you to test the FPS of your LCD Display!

## 🚀 Features

- 🔢 Live frame counter (up to 10,000)
- 🎯 Real-time FPS updates (updated once per second)
- 📊 RAM usage display (e.g. `RAM: 753/1024`)
- 📟 Clean layout for 16x2 LCD screens
- 💡 Designed for I2C displays (usually 0x27 address)

## 🛠 Requirements

- Arduino board (Uno, Nano, etc.)
- 16x2 I2C LCD display
- Arduino IDE
- `LiquidCrystal_I2C` library

You can install the `LiquidCrystal_I2C` library via the Arduino Library Manager.

<img width="2625" height="581" alt="image" src="https://github.com/user-attachments/assets/b317ab84-cdac-4244-a07d-6812c3f0f299" />

## 🔧 Wiring

| LCD Pin | Arduino Pin |
|---------|-------------|
| GND     | GND         |
| VCC     | 5V          |
| SDA     | A4          |
| SCL     | A5          |

> Note: SDA/SCL may vary depending on your board.

## 📄 License

This project is released under the [MIT License](LICENSE).  
Feel free to use, modify, and share it!
