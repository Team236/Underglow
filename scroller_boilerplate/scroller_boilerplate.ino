#include <FastLED.h>

#define PIN 6
#define N 300
#define DELAY 0

CRGB strip[N];

int i;

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(strip, N);
  generate();
  
  i = 0;
}

void loop() {
  i %= N;
  for (int led = 0; led < N; led++) {
    strip[led] = strip[(led + 1) % N];
  }
  
  FastLED.show();
  i++;
  delay(DELAY);
}

/*
 * Set the strip's initial colors
 */
void generate() {
}

