#include "FastLED.h"

#define PIN 6
#define N 300

CRGB strip[N];
int i;

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(strip, N);
  FastLED.setBrightness(128);
  i = 0;
  strip[0] = CRGB::Green;
  FastLED.show();
  delay(500);
  strip[0] = CRGB::Yellow;
  FastLED.show();
  delay(500);
  strip[0] = CRGB::Green;
  FastLED.show();
  delay(500);
}

void loop() {
  for(int i = 0; i < N; i++){
    strip[i] = CRGB::White;
    FastLED.show();
  }
  
}
