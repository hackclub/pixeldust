#include <Adafruit_NeoPixel.h>

#define LED_PIN   0    // NeoPixel Data Pin
#define NUM_LEDS  20    // Number of NeoPixels
#define BUTTON_PIN 1   // Button Pin (pulled down)

Adafruit_NeoPixel strip(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

int mode = 0;   
bool lastButtonState = LOW; 
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50; 

unsigned long previousMillis = 0;
const int animationSpeed = 100;    
int animationStep = 0;   

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP); 
  Serial.begin(9600); 
  strip.begin();
  strip.show();  
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);
  Serial.println(buttonState);

    if (buttonState == HIGH && lastButtonState == LOW) {
      mode = (mode + 1) % 3;  // Cycle through 3 modes
      strip.clear();  
      strip.show();
      delay(100); 
    }

  lastButtonState = buttonState;

  switch (mode) {
    case 0: rainbowCycle(); break;   // Rainbow animation
    case 1: chasingLights(); break;  // Running lights animation
    case 2: solidColorFade(); break; // Smooth color fading
  }
}

// -------------------- LED ANIMATIONS --------------------

void rainbowCycle() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= animationSpeed) {
    previousMillis = currentMillis;

    for (int i = 0; i < NUM_LEDS; i++) {
      strip.setPixelColor(i, Wheel((i * 256 / NUM_LEDS + animationStep) & 255));
    }
    strip.show();
    animationStep = (animationStep + 1) % 256;
  }
}

void chasingLights() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= animationSpeed) {
    previousMillis = currentMillis;

    strip.clear();
    strip.setPixelColor(animationStep, strip.Color(255, 0, 0)); 
    strip.show();
    
    animationStep = (animationStep + 1) % NUM_LEDS;
  }
}

void solidColorFade() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= animationSpeed) {
    previousMillis = currentMillis;

    strip.fill(Wheel(animationStep));  
    strip.show();
    
    animationStep = (animationStep + 1) % 256;
  }
}

// -------------------- COLOR FUNCTION --------------------
uint32_t Wheel(byte pos) {
  if (pos < 85) {
    return strip.Color(pos * 3, 255 - pos * 3, 0);  // Red -> Green
  } else if (pos < 170) {
    pos -= 85;
    return strip.Color(255 - pos * 3, 0, pos * 3);  // Green -> Blue
  } else {
    pos -= 170;
    return strip.Color(0, pos * 3, 255 - pos * 3);  // Blue -> Red
  }
}
