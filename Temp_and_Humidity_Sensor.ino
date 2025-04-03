#include <DHT.h>
#include <LiquidCrystal.h>

// Define the pins
#define DHTPIN 7           // DHT11 sensor data pin connected to pin 7
#define DHTTYPE DHT11      // Define sensor type as DHT11

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE);

// Initialize LCD (RS, EN, D4, D5, D6, D7)
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);

  // Initialize the DHT sensor
  dht.begin();

  // Initialize the LCD screen
  lcd.begin(16, 2);
  lcd.print("DHT11 Sensor");
  delay(2000);  // Show initial message for 2 seconds
  lcd.clear();
}

void loop() {
  // Wait a few seconds between readings
  delay(2000);

  // Read humidity and temperature from the DHT11 sensor
  float humidity = dht.readHumidity();
  float temperatureC = dht.readTemperature();  // Temperature in Celsius

  // Convert the temperature from Celsius to Fahrenheit
  float temperatureF = (temperatureC * 9.0 / 5.0) + 32;

  // Check if any readings failed and exit early (NaN means invalid data)
  if (isnan(humidity) || isnan(temperatureC)) {
    lcd.clear();
    lcd.print("Failed to read");
    lcd.setCursor(0, 1);
    lcd.print("DHT11 sensor");
    return;
  }

  // Print the temperature and humidity values to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureF);
  Serial.print(" °F, Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Display temperature and humidity on the LCD
  lcd.clear();
  lcd.print("Temp: ");
  lcd.print(temperatureF);
  lcd.print(" F");

  lcd.setCursor(0, 1);  // Move cursor to the second row
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print(" %");
}
