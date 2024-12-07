#include "FastLED.h"

#define LED_NUMBER 270
#define LED_PIN 50

CRGB leds[LED_NUMBER];

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, LED_NUMBER);
  FastLED.setBrightness(128);
}

void loop() {
  if (Serial.available() > 0) {
    String description = Serial.readStringUntil('\n'); 
  }
  delay(1000);
}


void vocal_recognition() {
}