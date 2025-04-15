#include <Wire.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>
#include <LiquidCrystal.h>

// Photoresistor on A0
#define LDR_PIN A0

// LCD pins: RS, EN, D4
LiquidCrystal lcd(2, 3, 4);  // GPIO2, GPIO3, GPIO4

// Accelerometer
Adafruit_LIS3DH lis = Adafruit_LIS3DH();

void setup() {
  Serial.begin(115200);

  // LCD init
  lcd.begin(16, 2);  // Assuming a 16x2 LCD
  lcd.print("Init...");

  // Accelerometer init
  if (!lis.begin(0x18)) { // Default I2C address
    Serial.println("No LIS3DH found");
    lcd.setCursor(0, 1);
    lcd.print("Accel fail");
    while (1);
  }
  lis.setRange(LIS3DH_RANGE_2_G);  // +-2g

  lcd.clear();
  lcd.print("System Ready");
  delay(1000);
  lcd.clear();
}

void loop() {
  // 1. Read photoresistor
  int lightValue = analogRead(LDR_PIN);
  float voltage = lightValue * (3.3 / 4095.0);

  // 2. Read accelerometer
  lis.read();
  float x = lis.x_g;
  float y = lis.y_g;
  float z = lis.z_g;

  // 3. Display on Serial Monitor
  Serial.print("Light: ");
  Serial.print(lightValue);
  Serial.print(" | Voltage: ");
  Serial.print(voltage, 2);
  Serial.print(" V | Accel: ");
  Serial.print(x, 2); Serial.print(", ");
  Serial.print(y, 2); Serial.print(", ");
  Serial.println(z, 2);

  // 4. Display on LCD
  lcd.setCursor(0, 0);
  lcd.print("L:");
  lcd.print(lightValue);
  lcd.print(" V:");
  lcd.print(voltage, 1);

  lcd.setCursor(0, 1);
  lcd.print("X:");
  lcd.print(x, 1);
  lcd.print(" Y:");
  lcd.print(y, 1);

  delay(500);
}
