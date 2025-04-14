#include <Arduino.h>
#include <I2S.h>
#include "FastLED.h"

#define FRONT_LED_PIN 26
#define BACK_LED_PIN 27
#define BASS_LED_PIN 4

#define NUM_LEDS 80
#define NUM_EXTRA_LEDS 2

#define INPUT_DETECTION_PIN 28
#define LRCK_PIN 29
#define BCK_PIN 3
#define SCK_PIN 2
#define DIN_PIN 0
#define DOUT_PIN 1
#define ROTARY_A_PIN 6
#define ROTARY_B_PIN 7



CRGB front_leds[NUM_LEDS];
CRGB back_leds[NUM_LEDS];
CRGB bass_leds[NUM_EXTRA_LEDS];


int brightness = 255;

void setup()
{
  Serial.begin(9600);

  FastLED.addLeds<WS2812B, FRONT_LED_PIN, GRB>(front_leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, BACK_LED_PIN, GRB>(back_leds, NUM_LEDS);
  FastLED.addLeds<WS2812B, NUM_EXTRA_LEDS, GRB>(bass_leds, NUM_LEDS);
  FastLED.setBrightness(brightness);

  pinMode(INPUT_DETECTION_PIN, INPUT_PULLDOWN);
  
}

float hue = 0;
float velocity = 8;

void rainbowLeds()
{
  hue += velocity;
  if (hue >= 360) {
    hue = 0;
  }

  Serial.print("Hue: ");
  Serial.println(hue);
}

int currentLed = 0;

void cycleLeds()
{
  for (int pixel = 0; pixel < NUM_LEDS; pixel++) {
    float h = (hue + ((255.0 / NUM_LEDS) * pixel));
    if (h > 255) {
      h -= 255;
    }
    h /= 255.0;

    front_leds[pixel] = CHSV(h, 255, 255);
  }

  FastLED.show();
}

void loop()
{
  // getButtonState();

  rainbowLeds();

  cycleLeds();

  delay(50);
}
