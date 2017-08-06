#include <FastLED.h>

#define PIN 6
#define N 300
CRGB strip[N];


void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(strip, N);
  CRGB color = CRGB::Navy;

  for(int i = 0; i < N; i++) {
    strip[i] = color;
  }
  FastLED.show();
}

void loop() {
  delay(0);
}
