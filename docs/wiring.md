# Wiring Guide — Smart Home Energy Meter

## Potentiometer (simulates ACS712) → Arduino Uno
| Pot Pin | Arduino Pin |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| SIG     | A1          |

## LCD I2C (16x2) → Arduino Uno
| LCD Pin | Arduino Pin |
|---------|-------------|
| VCC     | 5V          |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

## Alert LED → Arduino Uno
| Component           | Arduino Pin |
|--------------------|-------------|
| LED Anode via 220Ω | Pin 8       |
| LED Cathode         | GND         |
