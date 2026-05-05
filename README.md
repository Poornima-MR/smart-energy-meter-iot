# ⚡ Smart Home Energy Meter

**Difficulty:** Hard
**Platform:** Arduino Uno + ACS712-20A + LCD I2C
**Internship:** GlowLogics Solutions Pvt. Ltd., Mysuru
**Author:** Poornima M R — B.E. ECE, GSSSIETW

---

## 📌 Objective
- Measure AC current using ACS712 Hall-effect sensor
- Calculate apparent power (Watts = Current × 220V)
- Display live readings on 16x2 LCD
- Trigger alert LED when power exceeds 500W
- Log all readings to Serial Monitor

---

## 🧰 Components
| Component | Purpose |
|-----------|---------|
| Arduino Uno R3 | Main microcontroller |
| ACS712-20A | Current sensor |
| 16x2 LCD + I2C | Live display |
| Red LED | Overload alert |

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
