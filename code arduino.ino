#include <FastLED.h>

#define LED_PIN     50
#define NUM_LEDS    250

int PreviousRed = 0;
int PreviousGreen = 0;
int PreviousBlue = 0;

byte heat[NUM_LEDS];

CRGB leds[NUM_LEDS]; 

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  for (int i = 0; i < 250; i++) {
    set_color(i, i, i);
    delay(5);
  }
  for (int i = 0; i < 250; i++) {
    set_color(250-i, 250-i, 250-i);
    delay(5);
  }
  
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
      set_color(40, 147, 250);
    }
    if (description.indexOf("forêt") >= 0) {
      set_color(40, 122, 18);
    }
    if (description.indexOf("montagne") >= 0) {
      set_color(222, 148, 18);
    }
    if (description.indexOf("laboratoire") >= 0) {
      set_color(200, 18, 222);
    }
    if (description.indexOf("océan") >= 0) {
      set_color(0, 74, 231);
    }
    if (description.indexOf("enfer") >= 0) {
      set_color(228, 86, 0);
    }
    if (description.indexOf("église") >= 0) {
      set_color(255, 250, 155);
    }
    if (description.indexOf("jungle") >= 0) {
      set_color(137, 192, 139);
    }
    if (description.indexOf("plaine") >= 0) {
      set_color(213, 225, 22);
    }
    if (description.indexOf("feu") >= 0) {
      simulate_campfire();
    }
    if (description.indexOf("prison") >= 0) {
      set_color(50, 50, 50);
    }
    if (description.indexOf("nuit") >= 0) {
      
    }
    if (description.indexOf("combat") >= 0) {
      set_color(250, 0, 0);
    }
    if (description.indexOf("taverne") >= 0) {
    }
    
  }
}

void set_color(uint8_t red, uint8_t green, uint8_t blue) {
  
  PreviousRed = red;
  PreviousGreen = green;
  PreviousBlue = blue;

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(red, green, blue);
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

void simulate_campfire() {
  
}

