#include <FastLED.h>

#define LED_PIN     50
#define NUM_LEDS    250

int PreviousRed = 0;
int PreviousGreen = 0;
int PreviousBlue = 0;

CRGB leds[NUM_LEDS]; 

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  set_color(100, 100, 100);
  delay(3000);
  set_color(0, 0, 0);
}

void loop() {
  if (Serial.available() > 0) {
    String description = Serial.readStringUntil('\n');

    if (description.indexOf("play") >= 0) {
      play();
    }

    if (description.indexOf("pause") >= 0) {
      pause();
    }

    if (description.indexOf("rivière") >= 0) {
      set_color(0, 0, 255);
    }
    else if (description.indexOf("forêt") >= 0) {
      set_color(0, 255, 0);
    }
    
  }
}

void set_color(uint8_t red, uint8_t green, uint8_t blue) {
  
  PreviousRed = red;
  PreviousGreen = green;
  PreviousBlue = blue;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(PreviousRed, PreviousGreen, PreviousBlue);
  }
  FastLED.show();
}

void pause() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(0, 0, 0);
  }
  FastLED.show();
}

void play() {
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(PreviousRed, PreviousGreen, PreviousBlue);
  }
  FastLED.show();
}
