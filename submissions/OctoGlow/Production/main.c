// This code was created by @DynamicWhiteHat and @Origamism
#include <Adafruit_NeoPixel.h>

#define LED_PIN     1      
#define NUM_LEDS    37    // Number of NeoPixels
#define BRIGHTNESS  100     
#define LED_TYPE    NEO_GRB 
#define LED_FREQ_HZ 800000

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, LED_TYPE + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(BRIGHTNESS);
  strip.show(); 
}

void loop() {
  rainbowCycle(5); 
}

// Rainbow cycle along whole strip
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { 
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
