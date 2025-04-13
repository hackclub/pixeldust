/*

XIAO ESP32-S3 LED Glasses

Made by @turtureanu, available on
    - Github: https://github.com/turtureanu/led-glasses
    - Wokwi: https://wokwi.com/projects/428024875914576897

Usage: press the button for 1-2 seconds then realease, after ~3 seconds the animation will change

Libraries used:
    - FastLED (MIT License, authors and contributors: https://github.com/FastLED/FastLED/graphs/contributors)

Licensed under the GPLv3 license available at https://www.gnu.org/licenses/gpl-3.0.en.html

*/

#include <FastLED.h>

#define DATA_PIN 1
#define NUM_LEDS 62
#define COLS 14
#define ROWS 5
#define SW_PIN_1 3
#define SW_PIN_2 2

CRGBArray<NUM_LEDS> leds;

// map every led to its coordinate (index)
// value: the led's number (1, 2, 3, ...)
// index: led coordinate
// -1 means missing
int ledDictionary[ROWS][COLS] = {
  {24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37},
  {23, 22, 21, 20, 19, 18, 17, 44, 43, 42, 41, 40, 39, 38},
  {11, 12, 13, 14, 15, 16, -1, -1, 45, 46, 47, 48, 49, 50},
  {10, 9, 8, 7, 6, 5, -1, -1, 56, 55, 54, 53, 52, 51},
  {0, 1, 2, 3, 4, -1, -1, -1, -1, 57, 58, 59, 60, 61}
};

int ledGrid[ROWS][COLS][3]; // each cell has 3 values (RGB)

int animationSpeed = 250; // the animation speed

// basically do nothing until the button is pressed
void waitForButton() {
  while(digitalRead(SW_PIN_2) == LOW) {}
}

/*
===================
DISPLAY FUNCTIONS
===================

// showLedGrid(): updates leds[] according to ledGrid using ledDictionary to map the leds,
//                then executes FastLeds.show()

// COLORS
// solidRed, solidGreen, solidBlue: set static corresponding colors

// ANIMATIONS
// halfBlink: blinks one half at a time
// alternateColumns: self-explanatory, light up col %2 == 0 or col %2 == 1
// alternateRows: same as alternateColumns() but for rows
// checkers: alternating checkers pattern
// rainbow: the usual 45 degree top left to bottom right moving rainbow gradient
*/


void showLedGrid() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (ledDictionary[i][j] != -1) {
        leds[ledDictionary[i][j]].setRGB(ledGrid[i][j][0], ledGrid[i][j][1], ledGrid[i][j][2]);
      }
    }
  }

  FastLED.show();
}

void solidRed() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ledGrid[i][j][0] = 255;
      ledGrid[i][j][1] = 0;
      ledGrid[i][j][2] = 0;
    }
  }

  showLedGrid();
  waitForButton();
}

void solidGreen() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ledGrid[i][j][0] = 0;
      ledGrid[i][j][1] = 255;
      ledGrid[i][j][2] = 0;
    }
  }

  showLedGrid();
  waitForButton();
}

void solidBlue() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ledGrid[i][j][0] = 0;
      ledGrid[i][j][1] = 0;
      ledGrid[i][j][2] = 255;
    }
  }

  showLedGrid();
  waitForButton();
}

void halfBlink() {
  while (digitalRead(SW_PIN_2) == LOW) {
    // left half
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (j < COLS / 2) {
          ledGrid[i][j][0] = 0;   // R
          ledGrid[i][j][1] = 80;  // G
          ledGrid[i][j][2] = 255; // B
        } else {
          ledGrid[i][j][0] = 0; // R
          ledGrid[i][j][1] = 0; // G
          ledGrid[i][j][2] = 0; // B
        }
      }
    }

    showLedGrid();
    delay(animationSpeed);

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (j >= COLS / 2) {
          ledGrid[i][j][0] = 0;   // R
          ledGrid[i][j][1] = 80;  // G
          ledGrid[i][j][2] = 255; // B
        } else {
          ledGrid[i][j][0] = 0; // R
          ledGrid[i][j][1] = 0; // G
          ledGrid[i][j][2] = 0; // B
        }
        
      }
    }

    showLedGrid();
    delay(animationSpeed);
  }
}

void alternateColumns() {
  while (digitalRead(SW_PIN_2) == LOW) {
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (j % 2 == 1) {
          ledGrid[i][j][0] = 0;   // R
          ledGrid[i][j][1] = 80;  // G
          ledGrid[i][j][2] = 255; // B
        } else {
          ledGrid[i][j][0] = 0; // R
          ledGrid[i][j][1] = 0; // G
          ledGrid[i][j][2] = 0; // B
        }
      }
    }

    showLedGrid();
    delay(animationSpeed);

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (j % 2 != 1) {
          ledGrid[i][j][0] = 0;   // R
          ledGrid[i][j][1] = 80;  // G
          ledGrid[i][j][2] = 255; // B
        } else {
          ledGrid[i][j][0] = 0; // R
          ledGrid[i][j][1] = 0; // G
          ledGrid[i][j][2] = 0; // B
        }
      }
    }

    showLedGrid();
    delay(animationSpeed);
  }
}

void alternateRows() {
  while (digitalRead(SW_PIN_2) == LOW) {
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (i % 2 == 1) {
          ledGrid[i][j][0] = 0;   // R
          ledGrid[i][j][1] = 80;  // G
          ledGrid[i][j][2] = 255; // B
        } else {
          ledGrid[i][j][0] = 0; // R
          ledGrid[i][j][1] = 0; // G
          ledGrid[i][j][2] = 0; // B
        }
      }
    }

    showLedGrid();
    delay(animationSpeed);

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if (i % 2 != 1) {
          ledGrid[i][j][0] = 0;   // R
          ledGrid[i][j][1] = 80;  // G
          ledGrid[i][j][2] = 255; // B
        } else {
          ledGrid[i][j][0] = 0; // R
          ledGrid[i][j][1] = 0; // G
          ledGrid[i][j][2] = 0; // B
        }
      }
    }

    showLedGrid();
    delay(animationSpeed);
  }
}

void checkers() {
  while (digitalRead(SW_PIN_2) == LOW) {
    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if ((i + j) % 2 == 0) {
          ledGrid[i][j][0] = 0;   // R
          ledGrid[i][j][1] = 80;  // G
          ledGrid[i][j][2] = 255; // B
        } else {
          ledGrid[i][j][0] = 0; // R
          ledGrid[i][j][1] = 0; // G
          ledGrid[i][j][2] = 0; // B
        }
      }
    }

    showLedGrid();
    delay(animationSpeed);

    for (int i = 0; i < ROWS; i++) {
      for (int j = 0; j < COLS; j++) {
        if ((i + j) % 2 != 0) {
          ledGrid[i][j][0] = 0;   // R
          ledGrid[i][j][1] = 80;  // G
          ledGrid[i][j][2] = 255; // B
        } else {
          ledGrid[i][j][0] = 0; // R
          ledGrid[i][j][1] = 0; // G
          ledGrid[i][j][2] = 0; // B
        }
      }
    }

    showLedGrid();
    delay(animationSpeed);
  }
}


void rainbow() {
  int offset = 0;

  while (digitalRead(SW_PIN_2) == LOW) {
    for (int i = 0; i < ROWS; i++) {
      for (int j = COLS - 1; j >= 0; j--) {
        // no idea how this works
        uint8_t hue = (i + j - offset) * (255 / (COLS + ROWS));

        // get the ledColor using the hue
        CRGB ledColor = CHSV(hue, 255, 255);
        ledGrid[i][j][0] = ledColor.r;
        ledGrid[i][j][1] = ledColor.g;
        ledGrid[i][j][2] = ledColor.b;
      }
    }

    showLedGrid();
    delay(animationSpeed / 4);

    offset++;

    // reset offset (perfect loop)
    if (offset >= 255) {
      offset = 0;
    }
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("");
  Serial.println("Hello, XIAO ESP32-S3!");
  Serial.println("Welcome to Wokwi :-)");

  // set SW_PIN_1 to HIGH
  pinMode(SW_PIN_1, OUTPUT);
  digitalWrite(SW_PIN_1, HIGH);
  

  // set SW_PIN_2 as INPUT
  pinMode(SW_PIN_2, INPUT);

  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

  // Boot animation
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;
    FastLED.show();
    delay(10);
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
    FastLED.show();
    delay(10);
  }

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      ledGrid[i][j][0] = 0; // R
      ledGrid[i][j][1] = 0; // G
      ledGrid[i][j][2] = 0; // B
    }
  }
}

void loop() {
  solidRed();
  delay(3000);
  solidGreen();
  delay(3000);
  solidBlue();
  delay(3000);
  halfBlink();
  delay(3000);
  alternateColumns();
  delay(3000);
  alternateRows();
  delay(3000);
  checkers();
  delay(3000);
  rainbow();
  delay(3000);
}