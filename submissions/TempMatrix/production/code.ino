#include <FastLED.h>
#include <DHT.h>

#define LED_PIN     37
#define NUM_LEDS    84
#define BRIGHTNESS  100
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

#define DHTPIN      45
#define DHTTYPE     DHT22

CRGB leds[NUM_LEDS];
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  dht.begin();
  Serial.begin(115200);
}

void loop() {
  float temp = dht.readTemperature();

  if (isnan(temp)) {
    Serial.println("Failed to read data from sensor :(");
    return;
  }

  Serial.print("The temperature is: ");
  Serial.print(temp);
  Serial.println("°C");

  uint8_t hue = map(constrain(temp, 10, 35), 10, 35, 160, 0);

  fill_solid(leds, NUM_LEDS, CHSV(hue, 255, BRIGHTNESS));
  FastLED.show();
  delay(1000);
}
