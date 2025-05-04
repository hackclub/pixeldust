// This is a simple example of controlling will improve aftering getting the PCB to test the code
#include <FastLED.h>

#define LED_PIN     13      
#define NUM_LEDS    100
#define BRIGHTNESS  50
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define NUM_ROWS    10       
#define NUM_COLS    10      

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDChip );
  FastLED.setBrightness( BRIGHTNESS );
}

// Function to set the color of an LED based on row and column
void setLedColor(int row, int col, CRGB color) {
  int index = col + row * NUM_COLS; 
  if (index >= 0 && index < NUM_LEDS) {
    leds[index] = color;
  }
}

void loop() {
  setLedColor(2, 3, CRGB::Green);
  FastLED.show();
  delay(1000);

  for (int col = 0; col < NUM_COLS; col++) {
    setLedColor(0, col, CRGB::Blue);
  }
  FastLED.show();
  delay(1000);


  for (int row = 0; row < NUM_ROWS; row++) {
    for (int col = 0; col < NUM_COLS; col++) {
      setLedColor(row, col, CRGB::Black);
    }
  }
  FastLED.show();
  delay(1000);

}