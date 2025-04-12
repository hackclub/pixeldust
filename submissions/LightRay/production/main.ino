#include <Adafruit_NeoPixel.h>

#define CLK D0
#define DT D1
#define SW D2
#define LED_PIN D6
#define NUMPIXELS 15 // Popular NeoPixel ring size
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

int brightness = 3; // 1 to 5
#define MIN_BRIGHT 5
#define MAX_BRIGHT 1

int currentStateCLK;
int lastStateCLK;

int color_sel = 0;
int colors[][3] = {
  {255, 0, 0},
  {255, 255, 255},
  {255, 255, 0},
  {0, 0, 255}
};
int color_size = sizeof(colors)/sizeof(*colors);

void setup() {
  pinMode(D4, INPUT_PULLUP);
  pinMode(D5, INPUT_PULLUP);
  pinMode(CLK,INPUT);
  pinMode(DT,INPUT);
  pinMode(SW, INPUT_PULLUP);
  pixels.begin();
  lastStateCLK = digitalRead(CLK);
  Serial.begin(115200);
}

void loop() {
  currentStateCLK = digitalRead(CLK);
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1){
  if (digitalRead(DT) != currentStateCLK) {
  brightness--;
  } else {
  brightness++;
  }
  }
  lastStateCLK = currentStateCLK;
  if (brightness > MIN_BRIGHT) brightness = MAX_BRIGHT;
  if (brightness < MAX_BRIGHT) brightness = MIN_BRIGHT;

  if (digitalRead(D4) == LOW) {
    color_sel++; 
    delay(50);
  }
  if (digitalRead(D5) == LOW) {
    color_sel--;
    delay(50);
  }
  color_sel = ((color_sel % color_size) + color_size) % color_size;

      pixels.fill(pixels.Color(
        colors[color_sel][0]/brightness,
        colors[color_sel][1]/brightness,
        colors[color_sel][2]/brightness
      ));
      pixels.show();
      Serial.println(color_sel);
}
