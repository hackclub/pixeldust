#include <Adafruit_NeoPixel.h>

#define LED_PIN    0
#define LED_COUNT  20

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial1.begin(115200);
  Serial1.println("Hello, Raspberry Pi Pico!");

  strip.begin();
  strip.setBrightness(100); // Brightness set to 100 (out of 255) so it doesn't blind you.
  strip.clear();

  uint32_t colors[10] = {
    strip.Color(255, 0, 0),    // Red
    strip.Color(0, 255, 0),    // Green
    strip.Color(0, 0, 255),    // Blue
    strip.Color(255, 255, 0),  // Yellow
    strip.Color(255, 0, 255),  // Magenta
    strip.Color(0, 255, 255),  // Cyan
    strip.Color(255, 128, 0),  // Orange
    strip.Color(128, 0, 255),  // Purple
    strip.Color(255, 255, 255), // White
    strip.Color(128, 128, 128) // Gray
  };

  for (int i = 0; i < 10; i++) {
    strip.setPixelColor(i, colors[i]);
    strip.setPixelColor(i + 10, colors[i]);
  }

  strip.show();
}

void loop() {
  delay(1);
}
