# automatic-fire-detection-and-sprinkler-system
Arduino-based fire detector that turns on a buzzer and water pump automatically when fire is detected. It also shows the system status on an LCD.

# Automatic Fire Detection and Sprinkler System

This project is a simple Arduino-based system that can detect fire and automatically turn on a water pump to help put it out. It also sounds a buzzer as an alarm and shows live status messages on an LCD screen. The goal is to create a low-cost safety prototype that is easy to understand, build, and extend.

---

## 1. Project Overview

This system continuously watches for fire using an IR flame sensor.  
If a flame is detected:

- A **buzzer** turns on to warn people nearby.
- A **relay** switches on a **water pump** to spray water.
- A **16x2 I2C LCD** shows a message like “Fire Detected!”.

If no flame is detected:

- The **pump and buzzer remain OFF**.
- The LCD shows that the system is normal.

This makes it useful as a basic automatic fire response system for small spaces like rooms, labs, or workshops.

---

## 2. Main Features

- Automatic detection of fire using an IR flame sensor  
- Automatic activation of a water pump through a relay  
- Audible alert using a buzzer  
- Real-time messages on a 16x2 I2C LCD  
- Simple, low-cost hardware that is easy to build and understand  
- Good educational project for beginners in electronics and Arduino  

---

## 3. Hardware Components

- **Arduino Uno** – Main microcontroller that reads the sensor and controls outputs  
- **IR Flame Sensor** – Detects infrared light from a flame  
- **Relay Module** – Works as an electronic switch to control the water pump  
- **Water Pump** – Sprays water when a fire is detected  
- **Buzzer** – Gives a loud sound as a fire alarm  
- **16x2 I2C LCD Display** – Shows system status (e.g., “System Normal”, “Fire Detected!”)  
- **Jumper Wires** – For electrical connections  
- **5V Power (for Arduino)** – Powers Arduino, sensor, LCD, buzzer  
- **Separate Power Supply for Pump (e.g., 12V)** – Powers the water pump  

---

## 4. How the System Works

### 4.1 Normal Condition (No Fire)

1. The Arduino powers up and initializes the LCD, flame sensor, relay, and buzzer.
2. The LCD shows a startup message like:
   - Line 1: `System Ready`
   - Line 2: `Awaiting Flame...`
3. In the main loop, the Arduino continuously reads the digital output of the flame sensor.
4. If the sensor output indicates **no flame**:
   - Relay stays OFF → **Pump OFF**
   - Buzzer stays OFF → **No alarm**
   - LCD shows:
     - Line 1: `Regulated Temp.`
     - Line 2: `System Normal`

### 4.2 Fire Detected

1. When the flame sensor detects a flame, its digital output changes (typically goes LOW).
2. The Arduino reads this change and decides that **fire is detected**.
3. The Arduino:
   - Sets the **relay pin LOW** → Relay turns ON → Pump is powered → Water sprays
   - Sets the **buzzer pin HIGH** → Buzzer turns ON → Loud alarm
   - Updates the LCD to:
     - Line 1: `Fire Detected!`
     - Line 2: `Relay and Buzzer ON`

4. As long as the flame is present, the pump and buzzer stay ON.
5. When the flame is no longer detected, the system returns to normal state.

---

## 5. Pin Connections (Suggested)

You can adjust pins if needed, but this is a simple mapping:

- **Flame Sensor**
  - D0 → Arduino **D2**
  - VCC → 5V
  - GND → GND

- **Buzzer**
  - Positive (long leg) → Arduino **D9**
  - Negative → GND

- **Relay Module**
  - Signal → Arduino **D4**
  - VCC → 5V
  - GND → GND  
  - Relay NO/COM → In series with the pump and its external power supply

- **16x2 I2C LCD**
  - SDA → Arduino SDA (A4 on Uno)
  - SCL → Arduino SCL (A5 on Uno)
  - VCC → 5V
  - GND → GND

- **Water Pump**
  - Powered through the relay using a **separate higher voltage supply** (e.g., 12V)
  - Make sure grounds are connected properly and wiring is safe.

---

## 6. Software Logic (High-Level)

The Arduino code follows a simple algorithm:

1. **Setup phase**
   - Initialize LCD via I2C
   - Set pin modes:
     - Sensor pin as INPUT
     - Relay pin as OUTPUT
     - Buzzer pin as OUTPUT
   - Turn OFF relay and buzzer initially
   - Show “System Ready” message on LCD for a short time

2. **Loop phase**
   - Read digital value from flame sensor
   - If **flame detected** (sensor LOW):
     - Turn ON relay (pump ON)
     - Turn ON buzzer
     - Show “Fire Detected!” and “Relay and Buzzer ON” on LCD
   - Else (no flame):
     - Turn OFF relay (pump OFF)
     - Turn OFF buzzer
     - Show “Regulated Temp.” and “System Normal” on LCD
   - Small delay (e.g., 50 ms) to avoid flickering and rapid toggling

## Libraries Used
- LiquidCrystal_I2C.h  
  Used for interfacing the 16x2 I2C LCD display with the Arduino Uno.
  
---

## 7. Project Structure 

```text
automatic-fire-detection-and-sprinkler-system/
├── code/
│   └── automatic_fire_detector.ino
├── diagrams/
│   ├── block_diagram.png
│   ├── wiring_diagram.png
│   └── flowchart.png
├── images/
│   ├── setup_before_fire.jpg
│   ├── setup_after_fire.jpg
│   ├── lcd_system_ready.jpg
│   ├── lcd_fire_detected.jpg
│   ├── relay_module_closeup.jpg
│   └── flame_sensor_closeup.jpg
├── docs/
│   └── report.pdf
└── README.md
```

---

## 8. How to Use This Project

1. **Build the hardware** according to the wiring diagram.
2. **Upload the Arduino sketch** from the `code/` folder using the Arduino IDE.
3. Open the **Serial Monitor** (optional) to see sensor values for debugging.
4. Place a **small controlled flame source** (e.g., lighter or match) near the flame sensor to test.
5. Check that:
   - The buzzer turns ON
   - The pump starts spraying water
   - The LCD shows “Fire Detected!”
6. Remove the flame and verify that the system returns to normal status.

> Important: Always test with **extreme caution** and in a safe environment. Use very small flames and keep water and electronics separated properly.

---

## 9. Possible Improvements

- Add **smoke sensor** or **temperature sensor** for multi-sensor detection
- Add **GSM module** to send SMS alerts
- Add **Wi-Fi / IoT** to monitor status remotely
- Add **manual override switch** to turn off pump or buzzer
- Add **battery backup** for power failures

---

## 10. Summary

This project shows how basic sensors, a relay, and Arduino can be combined to build a simple automatic fire detection and response system. It is a good starting point for learning:

- How to read digital sensors  
- How to control high-power devices using relays  
- How to display real-time status on an LCD  
- How to design simple safety and automation systems

Anyone familiar with basic Arduino can reproduce and extend this project for education and small-scale safety applications.
