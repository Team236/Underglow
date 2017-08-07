#include <FastLED.h>

#define PIN 6
#define N 300
#define DELAY 20

CRGB strip[N];
CRGB color;

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(strip, N);

  color = CRGB(0,0,255);
  randomSeed(analogRead(0));
}

void loop() {
  color = CHSV(random8(), 255, 255);
  for(int i = 0; i < 300; i++) {
    strip[i] = color;
  }
  FastLED.show();
  delay(DELAY);

  for(int i = 0; i < 300; i++) {
    strip[i] = CRGB::Black;
  }
  FastLED.show();
  delay(DELAY);
}
