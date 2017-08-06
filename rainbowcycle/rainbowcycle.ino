#include "FastLED.h"

#define PIN 6
#define N 300

#define SIZE 10

CRGB strip[N];
byte i;

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(strip, N);
  i = 0;
}

void loop() {
  for(int j = 0; j < N; j++) {
    strip[j].setHue(i);
  }
  i++;
  FastLED.show();
  delay(20);
}
