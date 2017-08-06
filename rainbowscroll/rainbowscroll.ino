#include "FastLED.h"

#define PIN 6
#define N 300

CRGB strip[N];
int i;

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(strip, N);
  i = 0;
}

void loop() {
  i %= N;
  for (int pos = 0; pos < N; pos++) {
    strip[pos].setHue(map((pos + i) % N, 0, 300, 0, 255));
  }
  FastLED.show();
  i+=2;
  delay(0);
}
