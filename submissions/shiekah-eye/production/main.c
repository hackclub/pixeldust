#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN    2
#define NEOPIXEL_COUNT  40
#define BRIGHTNESS      100    
#define COLOR_DELAY     20  

Adafruit_NeoPixel pixels(NEOPIXEL_COUNT, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

float brightness = 0.20;
int direction = 1; 
unsigned long lastColorUpdate = 0;

void setup() {
  Serial.begin(115200);
  pixels.begin();
  pixels.setBrightness(map(BRIGHTNESS, 0, 100, 0, 255)); 
  pixels.clear();
  pixels.show();
  Serial.println("Pulsing Red LEDs");
}

void loop() {
  if (millis() - lastColorUpdate > COLOR_DELAY) {
    lastColorUpdate = millis();
    updateLEDs();
  }
}

void updateLEDs(){
  brightness += direction * 0.005;

  if (brightness >= 1) {
    brightness = 1;
    direction = -1;
  } else if (brightness <= 0.5) {
    brightness = 0.5;
    direction = 1;
  }

  uint8_t scaled = brightness * 255;

  for (int i = 0; i < NEOPIXEL_COUNT; i++) {
    pixels.setPixelColor(i, pixels.Color(scaled, 0, 0));
  }

  pixels.show();
}
