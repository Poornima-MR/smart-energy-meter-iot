# ⚡ Smart Home Energy Meter

**Difficulty:** Hard
**Platform:** Arduino Uno + LCD I2C (Simulated Input)
**Internship:** GlowLogics Solutions Pvt. Ltd., Mysuru
**Author:** Poornima M R — B.E. ECE, GSSSIETW

---

## 📌 Objective
- Accept simulated current values through Serial Monitor
- Calculate power using relation (Power = Current × 220V)
- Display real-time current and power on 16x2 LCD
- Trigger alert LED when power exceeds 2000W
- Log readings to Serial Monitor

---

## 🧰 Components
| Component | Purpose |
|-----------|---------|
| Arduino Uno R3 | Main microcontroller |
| 16x2 LCD + I2C | Live display |
| Red LED + Resistor | Overload alert |
| Serial Monitor (PC) | Input current values |

---

## 🖥️ Simulation
🔗 https://wokwi.com/projects/463145194092700673

Type any current value in Serial Monitor to test.
Red LED glows when power exceeds 500W.

---

## 📊 Sample Output

**Normal Load:**
Current: 0.50 A  |  Power: 110.0 W  |  Status: Normal
Current: 1.50 A  |  Power: 330.0 W  |  Status: Normal
**Overload Condition:**
Current: 3.00 A  |  Power: 660.0 W   |  Status: !! HIGH POWER ALERT !!
Current: 10.00 A |  Power: 2200.0 W  |  Status: !! HIGH POWER ALERT !!
**LCD Display:**
Normal:              Overload:
⚡ I=1.50A           ⚡ I=10.00A
P=330.0W          !! OVERLOAD !!
