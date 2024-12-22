#include <FastLED.h>

#define LED_PIN     50
#define NUM_LEDS    250


int PreviousRed = 0;
int PreviousGreen = 0;
int PreviousBlue = 0;

bool ActiveFire = false;
bool ActiveCombat = false;
bool ActiveRiver = false;
bool ActiveTavern = false;

byte heat[NUM_LEDS];

CRGB leds[NUM_LEDS]; 

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(50);
  for (int i = 0; i < 255; i++) {
    set_color(i, i, i);
    delay(5);
  }
  for (int i = 0; i < 255; i++) {
    set_color(255-i, 255-i, 255-i);
    delay(5);
  }
  
}

void loop() {
  
  if (ActiveTavern) {
    simulate_tavern_effect();
    FastLED.show();
  }

  if (ActiveRiver) {
    simulate_river_effect();
    FastLED.show();
  }

  if (ActiveCombat) {
    simulate_combat_effect();
    FastLED.show();
  }

  if (ActiveFire) {
    simulate_campfire();
    FastLED.show();
  }
  if (Serial.available() > 0) {
    String description = Serial.readStringUntil('\n');

    if (description.indexOf("play") >= 0) {
      play();
    }

    if (description.indexOf("pause") >= 0) {
      pause();
    }

    if (description.indexOf("rivière") >= 0) {
      ActiveRiver = true;
    } else {
      ActiveRiver = false;
    }

    if (description.indexOf("combat") >= 0) {
      ActiveCombat = true;
    } else {
      ActiveCombat = false;
    }

    if (description.indexOf("feu") >= 0) {
      ActiveFire = true;
    } else {
      ActiveFire = false;
    }

    if (description.indexOf("taverne") >= 0) {
      ActiveTavern = true;
    } else {
      ActiveTavern = false;
    }

    if (description.indexOf("forêt") >= 0) {
      set_color(0, 225, 0);
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
    if (description.indexOf("marais") >= 0) {
      set_color(30, 30, 30);
    }
    if (description.indexOf("église") >= 0) {
      set_color(255, 250, 155);
    }
    if (description.indexOf("jungle") >= 0) {
      set_color(62, 250, 69);
    }
    if (description.indexOf("plaine") >= 0) {
      set_color(213, 225, 22);
    }
    if (description.indexOf("prison") >= 0) {
      set_color(50, 50, 50);
    }
    if (description.indexOf("désert") >= 0) {
      set_color(255, 255, 0);
    }

    if (description.indexOf("nuit") >= 0) {
      set_color(PreviousRed / 4, PreviousGreen / 4, PreviousBlue / 4);
    }
    
    if (description.indexOf("sinistre") >= 0) {
      set_color(PreviousRed / 2, PreviousGreen / 2, PreviousBlue / 2);
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


void simulate_river_effect() {
  float wave_length = 10.0;
  static int led_variation = 0;
  static bool increasing_river = false;

  leds[0] = CRGB(0, 0, (sin(led_variation / wave_length) + 1) * 127.5);

  for (int i = NUM_LEDS - 1; i > 0; i--) {
    leds[i] = leds[i - 1];
  }
  delay(40);

  if (increasing_river == true) {
    led_variation += 1;
    if (led_variation >= 255) {
      increasing_river = false;
    }
  } else {
    led_variation -= 1;
    if (led_variation <= 0) { 
      increasing_river = true;
    }
  }

  FastLED.show();
}


void simulate_tavern_effect() {
  static uint8_t blendFactor = 0;       // Facteur de mélange (0-255)
  static bool increasing = true;       // Indique si le facteur augmente ou diminue

  CRGB color1 = CRGB::Yellow;
  CRGB color2 = CRGB(255, 80, 0);

  // Mélange des couleurs selon le facteur actuel
  CRGB blendedColor = blend(color1, color2, blendFactor);

  // Applique la couleur mélangée à toutes les LEDs
  fill_solid(leds, NUM_LEDS, blendedColor);

  // Met à jour l'affichage des LEDs
  FastLED.show();

  // Ajuste le facteur de mélange
  if (increasing) {
    blendFactor++;
    if (blendFactor >= 255) increasing = false;
  } else {
    blendFactor--;
    if (blendFactor <= 0) increasing = true;
  }

  // Pause pour ralentir la transition
  delay(50);
}

void simulate_combat_effect() {
  static uint8_t intensity = 150;
  static bool increasing_combat = true;

  if (increasing_combat == true) {
    intensity += 5;
    if (intensity >= 255) {
      increasing_combat = false;
    }
  } else {
    intensity -= 5;
    if (intensity <= 0) { 
      increasing_combat = true;
    }
  }

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB(intensity, 0, 0);
  }

  FastLED.show();
  delay(20);
}


void simulate_campfire() {
  for (int i = 0; i<NUM_LEDS; i++) {
    
    leds[i] = CRGB(random(150, 255), random(0, 75), 0);
  
  }
  delay(10);
}

