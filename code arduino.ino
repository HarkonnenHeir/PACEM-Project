#include "FastLED.h"

#define LED_NUMBER 270
#define LED_PIN 50

String str = "None";

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

void pacem_starts() {
}

void pause() {
}

void create_immersion(description) {
  if ("combat") in description
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(255, 0, 0); // Rouge pur (255 pour rouge, 0 pour vert et bleu)
  }
  
  // Afficher les couleurs sur les LEDs
  FastLED.show();
}
}
// À effectuer dans le code :
// L'éclairage se met en pause quand le bouton Play/Pause est pressé
// Au démarrage du PACEM, le bandeau émet une lumière blanche
// Le code associe des mots à une ambiance
