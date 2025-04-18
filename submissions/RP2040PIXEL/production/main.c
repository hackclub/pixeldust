#include <Adafruit_NeoPixel.h>

#define PIN 19
#define NUMPIXELS 8

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int effect = 2;
float tick = 0;
int trailPos = 0;

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  if (effect == 0) {
    for (int i = 0; i < NUMPIXELS; i++) {
      float wave = tick + i * 0.4;
      uint8_t r = (sin(wave) + 1) * 127.5;
      uint8_t g = (sin(wave + 2) + 1) * 127.5;
      uint8_t b = (sin(wave + 4) + 1) * 127.5;
      strip.setPixelColor(i, strip.Color(r, g, b));
    }
    strip.show();
    tick += 0.1;
    delay(50);
  } else if (effect == 1) {
    strip.clear();
    int trailLength = 4;
    uint8_t brightness[] = {255, 100, 40, 10};

    for (int i = 0; i < trailLength; i++) {
      int idx = trailPos - i;
      if (idx < 0 || idx >= NUMPIXELS) continue;
      strip.setPixelColor(idx, strip.Color(brightness[i], brightness[i] / 2, 0));
    }

    strip.show();
    delay(100);
    trailPos++;
    if (trailPos >= NUMPIXELS + trailLength) trailPos = 0;
  } else if (effect == 2) {
    strip.clear();

    int groupSize = 2;
    int trainLength = 3;
    uint8_t brightness[] = {200, 100, 30};

    for (int g = 0; g < trainLength; g++) {
      int groupStart = trailPos - g * groupSize;
      if (groupStart >= NUMPIXELS) continue;
      if (groupStart < 0 - groupSize) continue;

      for (int i = 0; i < groupSize; i++) {
        int idx = groupStart + i;
        if (idx < 0 || idx >= NUMPIXELS) continue;
        uint8_t b = brightness[g];
        strip.setPixelColor(idx, strip.Color(0, b, b));
      }
    }

    strip.show();
    delay(150);
    trailPos++;
    if (trailPos >= NUMPIXELS + groupSize * trainLength) trailPos = 0;
  }
}
