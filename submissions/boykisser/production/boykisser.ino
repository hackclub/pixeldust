#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN      0     
#define NEOPIXEL_PIN    1    
#define NEOPIXEL_COUNT  8     
#define BRIGHTNESS      100    
#define COLOR_DELAY     20    

Adafruit_NeoPixel pixels(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
bool lastButtonState = HIGH;  
bool buttonState = HIGH;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;  
uint8_t currentProfile = 0;   
uint16_t colorOffset = 0;     
unsigned long lastColorUpdate = 0;

void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pixels.begin();
  pixels.setBrightness(map(BRIGHTNESS, 0, 100, 0, 255)); 
  pixels.clear();
  pixels.show();
  Serial.println("Boykisser");
  Serial.println("Press button to cycle profiles");
}

void loop() {
  int reading = digitalRead(BUTTON_PIN);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        currentProfile = (currentProfile + 1) % 4;
        Serial.print("Switched to Profile ");
        Serial.println(currentProfile + 1);
        colorOffset = 0;
      }
    }
  }
  lastButtonState = reading;
  if (millis() - lastColorUpdate > COLOR_DELAY) {
    lastColorUpdate = millis();
    updateLEDs();
    colorOffset += 256; 
  }
}

void updateLEDs() {
  pixels.clear();

  switch (currentProfile) {
    case 0: 
      pixels.setPixelColor(0, pixels.Color(255, 0, 0)); 
      pixels.setPixelColor(1, pixels.Color(255, 0, 0)); 
      break;

    case 1:
      pixels.setPixelColor(0, pixels.Color(255, 0, 0)); 
      pixels.setPixelColor(1, pixels.Color(255, 0, 0)); 
      for (int i = 2; i < NEOPIXEL_COUNT; i++) {
        uint16_t pixelHue = colorOffset + (i * 65536 / (NEOPIXEL_COUNT - 2));
        pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
      }
      break;

    case 2:
      for (int i = 0; i < 2; i++) {
        uint16_t pixelHue = colorOffset + (i * 65536 / 2);
        pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
      }
      break;

    case 3:
      for (int i = 0; i < NEOPIXEL_COUNT; i++) {
        uint16_t pixelHue = colorOffset + (i * 65536 / NEOPIXEL_COUNT);
        pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(pixelHue)));
      }
      break;
  }

  pixels.show();
}