#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define LED_PIN     D2
#define NUM_LEDS    11
#define BRIGHTNESS  50

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show();
}

void loop() {
  fadePattern();
}

void fadePattern() {
  for (int i = 0; i < 256; i += 5) {
    for (int j = 0; j < NUM_LEDS; j++) {
      strip.setPixelColor(j, i, 0, 255 - i);
    }
    strip.show();
    delay(20);
  }

  for (int i = 255; i >= 0; i -= 5) {
    for (int j = 0; j < NUM_LEDS; j++) {
      strip.setPixelColor(j, i, 0, 255 - i);
    }
    strip.show();
    delay(20);
  }
}
