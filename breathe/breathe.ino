#include "FastLED.h"

#define PIN 6
#define N 300
#define NUM_COLORS 3

CRGB strip[N];
CHSV colors[NUM_COLORS];
int i, color, increment;

void setup() {
  FastLED.addLeds<NEOPIXEL, PIN>(strip, N);
  i = 0;
  color = 0;

  colors[0] = CHSV(0,255,255);
  colors[1] = CHSV(96,255,255);
  colors[2] = CHSV(160,255,255);

}

void loop() {
  if (i == 0) {
    increment = 1;
    color += 1;
  }
  else if (i >= 255) {
    increment = -1;
  }
  color %= NUM_COLORS;

  for(int j = 0; j < N; j++) {
    strip[j] = CHSV(colors[color].h, colors[color].s, i);
  }
  
  i += increment;
  FastLED.show();
  delay(0);
}
