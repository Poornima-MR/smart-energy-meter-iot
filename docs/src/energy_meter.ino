/*
 * Project 06: Smart Home Energy Meter
 * Platform: Arduino Uno + ACS712 (simulated) + LCD I2C
 * Simulated on: Wokwi.com
 * Author: Poornima M R
 * Internship: GlowLogics Solutions Pvt. Ltd.
 *
 * HOW TO USE:
 * Open Serial Monitor → type a current value (e.g. 2.5) → press Enter
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define ALERT_LED 8

const float MAINS_VOLTAGE = 220.0;
const float POWER_LIMIT   = 500.0;

LiquidCrystal_I2C lcd(0x27, 16, 2);

byte charBolt[8] = {
  0b00010, 0b00110, 0b01110,
  0b11111, 0b00110, 0b01100,
  0b01000, 0b00000
};

float currentValue = 0.0;

void displayReadings(float current, float power) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(0);
  lcd.print(" I=");
  lcd.print(current, 2);
  lcd.print("A");
  lcd.setCursor(0, 1);
  if (power > POWER_LIMIT) {
    lcd.print("!! OVERLOAD !!  ");
  } else {
    lcd.print("   P=");
    lcd.print(power, 1);
    lcd.print("W");
  }
}

void logToSerial(float current, float power) {
  Serial.print("Current: ");
  Serial.print(current, 2);
  Serial.print(" A  |  Power: ");
  Serial.print(power, 1);
  Serial.print(" W  |  Status: ");
  if (power > POWER_LIMIT) {
    Serial.println("!! HIGH POWER ALERT !!");
    digitalWrite(ALERT_LED, HIGH);
  } else {
    Serial.println("Normal");
    digitalWrite(ALERT_LED, LOW);
  }
  Serial.println("Type next value and press Enter:");
}

void setup() {
  Serial.begin(9600);
  pinMode(ALERT_LED, OUTPUT);
  digitalWrite(ALERT_LED, LOW);

  lcd.init();
  lcd.backlight();
  lcd.createChar(0, charBolt);

  lcd.setCursor(0, 0);
  lcd.print("  Energy Meter  ");
  lcd.setCursor(0, 1);
  lcd.print(" Initializing...");
  delay(2000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.write(0);
  lcd.print(" I=0.00A");
  lcd.setCursor(0, 1);
  lcd.print("   P=0.0W");

  Serial.println("=============================");
  Serial.println("  Smart Home Energy Meter");
  Serial.println("  GlowLogics Internship");
  Serial.println("  Author: Poornima M R");
  Serial.println("=============================");
  Serial.println("Type a current value (e.g. 1.5) and press Enter:");
}

void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n'); // Read full line
    input.trim(); // Remove spaces and newline

    // Only process if input is not empty
    if (input.length() > 0) {
      float value = input.toFloat();

      // Only update if valid positive number
      if (value > 0) {
        currentValue = value;
        float power = currentValue * MAINS_VOLTAGE;
        displayReadings(currentValue, power);
        logToSerial(currentValue, power);
      } else {
        Serial.println("Please type a valid number like 1.5 or 10");
        Serial.println("Type next value and press Enter:");
      }
    }
  }
}
