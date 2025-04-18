#include <Adafruit_NeoPixel.h>

#define PIN_NEOPIXEL D0
#define NUM_PIXELS   12

#define BTN_MODE_1   D3
#define BTN_MODE_2   D1
#define BTN_MODE_3   D2

Adafruit_NeoPixel pixels(NUM_PIXELS, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);

// Timing
unsigned long lastUpdate = 0;
const unsigned long debounceDelay = 300;
unsigned long lastButtonPress = 0;

// Mode control
int currentMode = 1;

// ===== Mode 1 (Rainbow) =====
unsigned long rainbowHue = 0;
const unsigned long rainbowDelay = 20;

// ===== Mode 2 (Theater Chase) =====
int chaseIndex = 0;
int chaseColorIndex = 0;
const unsigned long chaseDelay = 100;
uint32_t chaseColors[] = {
  pixels.Color(255, 0, 0),
  pixels.Color(0, 255, 0),
  pixels.Color(0, 0, 255)
};

// ===== Mode 3 (Spiral Wipe) =====
int spiralIndex = 0;
bool wipingIn = true;
const unsigned long wipeDelay = 200;
int spiralOrder[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

// === Setup ===
void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  pixels.begin();
  pixels.setBrightness(100);
  pixels.clear();
  pixels.show();

  pinMode(BTN_MODE_1, INPUT);
  pinMode(BTN_MODE_2, INPUT);
  pinMode(BTN_MODE_3, INPUT);
}

// === Loop ===
void loop() {
  checkButtons();
  switch (currentMode) {
    case 1: runRainbow(); break;
    case 2: runChase(); break;
    case 3: runSpiral(); break;
  }
}

// === Button Handling with Debounce ===
void checkButtons() {
  unsigned long now = millis();
  
  if (now - lastButtonPress < debounceDelay) return;  // Wait for debounce delay
  
  if (digitalRead(BTN_MODE_1) == HIGH) {
    Serial.println("Button 1 Pressed");
    if (currentMode != 1) {
      switchMode(1);
    }
  } else if (digitalRead(BTN_MODE_2) == HIGH) {
    Serial.println("Button 2 Pressed");
    if (currentMode != 2) {
      switchMode(2);
    }
  } else if (digitalRead(BTN_MODE_3) == HIGH) {
    Serial.println("Button 3 Pressed");
    if (currentMode != 3) {
      switchMode(3);
    }
  }
}

// === Safe Mode Switch ===
void switchMode(int mode) {
  Serial.print("Switching to Mode: ");
  Serial.println(mode);
  
  currentMode = mode;
  pixels.clear();           // Clear the LED strip to reset it
  pixels.show();            // Update the LEDs immediately
  lastUpdate = millis();
  lastButtonPress = millis();

  // Reset all animation states to avoid conflicts between modes
  rainbowHue = 0;
  chaseIndex = 0;
  chaseColorIndex = 0;
  spiralIndex = 0;
  wipingIn = true;
}

// === Mode 1: Rainbow ===
void runRainbow() {
  if (millis() - lastUpdate >= rainbowDelay) {
    lastUpdate = millis();
    for (int i = 0; i < NUM_PIXELS; i++) {
      int hue = rainbowHue + (i * 65536L / NUM_PIXELS);
      pixels.setPixelColor(i, pixels.gamma32(pixels.ColorHSV(hue)));
    }
    pixels.show();
    rainbowHue += 256;
    if (rainbowHue > 65536L * 5) rainbowHue = 0;
  }
}

// === Mode 2: Theater Chase ===
void runChase() {
  if (millis() - lastUpdate >= chaseDelay) {
    lastUpdate = millis();
    for (int i = 0; i < NUM_PIXELS; i++) {
      if ((i + chaseIndex) % 3 == 0) {
        pixels.setPixelColor(i, chaseColors[chaseColorIndex]);
      } else {
        pixels.setPixelColor(i, 0);
      }
    }
    pixels.show();

    chaseIndex = (chaseIndex + 1) % 3;
    if (chaseIndex == 0) {
      chaseColorIndex = (chaseColorIndex + 1) % 3;
    }
  }
}

// === Mode 3: Spiral Wipe ===
void runSpiral() {
  if (millis() - lastUpdate >= wipeDelay) {
    lastUpdate = millis();

    if (spiralIndex < NUM_PIXELS) {
      int idx = spiralOrder[spiralIndex];
      pixels.setPixelColor(idx, wipingIn ? pixels.Color(0, 255, 0) : 0);
      spiralIndex++;
    } else {
      wipingIn = !wipingIn;
      spiralIndex = 0;
    }
    pixels.show();
  }
}
