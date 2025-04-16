#include <Adafruit_NeoPixel.h>

#define MIC_PIN A0
#define LED_PIN 1
#define NUM_LEDS 12      
#define SENSITIVITY 1.5
#define STEP 5

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

// === STATE ===
int volume = 0;
int last_volume = 0;

void setup() {
  Serial1.begin(115200);
  strip.begin();
  strip.show(); 
}

void loop() {
  int micValue = analogRead(MIC_PIN);  

  volume = abs(micValue - 511); 
  volume = constrain(volume, 0, 511);  

  if (last_volume < volume){
    last_volume += volume * 0.1;
  } else {
    last_volume -= volume * 0.1;
  };

  int numLit = map(volume * SENSITIVITY, 0, 512, 0, NUM_LEDS/2);

  for (int i = 0; i < NUM_LEDS / 2; i++) {
    if (i < numLit) {
      strip.setPixelColor(i, strip.Color(last_volume / 2, 0, i * 16)); 
      strip.setPixelColor(NUM_LEDS - (i+1), strip.Color(last_volume / 2, 0, i * 16));
    } else {
      strip.setPixelColor(i, 0);
      strip.setPixelColor(NUM_LEDS - (i+1), 0);
    }
  }

  strip.show();
  
  Serial1.print("Mic: ");
  Serial1.print(micValue);
  Serial1.print(" | Volume: ");
  Serial1.println(volume);
  
  delay(15);
}