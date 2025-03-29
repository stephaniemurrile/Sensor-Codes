#include <LiquidCrystal.h>

// Define LCD pins
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// MQ-5 sensor pin
const int mq5Pin = A0;

void setup() {
    lcd.begin(16, 2); // Initialize 16x2 LCD
    lcd.print("MQ-5 Gas Sensor");

    pinMode(mq5Pin, INPUT);
    delay(2000);  // Display the message for 2 seconds
    lcd.clear();
}

void loop() {
    int gasValue = analogRead(mq5Pin);  // Read MQ-5 sensor value

    lcd.setCursor(0, 0);
    lcd.print("Gas Level: ");
    lcd.print(gasValue); // Display raw gas sensor value

    delay(1000); // Update every second
}
