#include <Adafruit_NeoPixel.h>

#define PIN 6
#define WIDTH 5
#define HEIGHT 6
#define NUM_PIXELS (WIDTH * HEIGHT)

Adafruit_NeoPixel pixels(NUM_PIXELS, PIN, NEO_GRB + NEO_KHZ800);

uint8_t pos = 0;

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return pixels.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return pixels.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    return pixels.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}

void setup() {
  pixels.begin();
  pixels.show();
}

void loop() {
  for (int y = 0; y < HEIGHT; y++) {
    for (int x = 0; x < WIDTH; x++) {
      int i = (y % 2 == 0) ? (y * WIDTH + x) : (y * WIDTH + (WIDTH - 1 - x));
      pixels.setPixelColor(i, Wheel((pos + i * 8) % 255));
    }
  }
  pixels.show();
  pos = (pos + 5) % 255;
  delay(50);
}
