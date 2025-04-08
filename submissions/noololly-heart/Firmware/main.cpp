#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define PIN 3
#define NUMPIXELS 16
#define BUTTONPIN 6

Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int state = 0;

void solid(){
    for (int i = 0; i < NUMPIXELS; i++){
        pixels.setPixelColor(i, pixels.Color(255,0,0)); //change this for a different solid colour
        pixels.show();
    }
    delay(500);
}

void rainbow(){
    for (long pixelHue = 0; pixelHue < 5 * 65536; pixelHue++){
        pixels.rainbow(pixelHue);
        pixels.show();
        delay(10);
    }
}

void setup(){
    Serial.begin(115200);
    pixels.begin();
    pinMode(BUTTONPIN, INPUT_PULLUP);
}

void loop(){
    if (!digitalRead(BUTTONPIN)){
        Serial.println("Button Pressed");
        if (state < 2){
            state++;
            //delay(200); //debounce delay
        } else {
            state = 0;
            //delay(200); //debounce delay
        }
        
    }
    
    switch(state) {
        case 0:
            solid();
            break;
        case 1:
            rainbow();
            break;
    }

}
