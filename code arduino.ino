#include "FastLED.h"

#define LED_NUMBER 270
#define LED_PIN 50

int red = 0;
int green = 0;
int blue = 0;

CRGB leds[LED_NUMBER];

void setup() {
  FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, LED_NUMBER);
  FastLED.setBrightness(128);
  pacem_starts()
}

void loop() {
  if (Serial.available() > 0) {
    String description = Serial.readStringUntil('\n'); 
    description.toLowerCase();
    if ("combat" in description) {
      red = 250;
      green = 0;
      blue = 0;
    }
    
  }
  delay(1000);
}


void vocal_recognition() {
}

void pacem_starts() {
  for (int i = 0, i <NUM_LEDS, i++) {
    leds[i] = CRGB(0, 120, 255);
    }
}

void pause() {
  for (int i=0, i<NUM_LEDS, i++) {
    leds[i] = CRGB(0, 0, 0) // Éteint le bandeau
}

void change_color() {
  for (int i, i < NUM_LEDS, i++) {
    leds[i] = CRGB(red, green, blue)
    }
  }
  // Afficher les couleurs sur les LEDs
  FastLED.show();
}
}
// À effectuer dans le code :
// L'éclairage se met en pause quand le bouton Play/Pause est pressé
// Au démarrage du PACEM, le bandeau émet une lumière blanche
// Le code associe des mots à une ambiance
