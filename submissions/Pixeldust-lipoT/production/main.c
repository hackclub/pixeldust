#include <Adafruit_NeoPixel.h>

#define PIN_NEO_PIXEL 23
#define NUM_PIXELS 4

Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

void setup() {
  NeoPixel.begin();
}

void loop() {
  NeoPixel.clear();

  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 255, 0));
    NeoPixel.show(); 

    delay(500);
  }
}