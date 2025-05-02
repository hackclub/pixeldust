#include <FastLED.h>
#define NUM_LEDS 85
#define DATA_PIN 21
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
int i = 0;
CRGB leds[NUM_LEDS];
void setup() {
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
  Serial.begin(115200);
  Serial.println("Hello, ESP32-S3!");
}

void setAllOff() {
  for (int j = 0; j<NUM_LEDS; j++) {
    leds[j]=CRGB::Black;
  }
}

void loop() {
  setAllOff();
  leds[i]=CRGB::Red;
  FastLED.show();
  i++;
  if (i>=NUM_LEDS) {
    i=0;
  }
  

  // put your main code here, to run repeatedly:
  delay(100); // this speeds up the simulation
}
