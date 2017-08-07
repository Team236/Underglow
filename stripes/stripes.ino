#include <FastLED.h>

#define PIN 6
#define N 300
#define DELAY 0

#define SIZE 15

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
 * Fill the matrix with strip.Color values
 */
void generate() {
  for (int j = 0; j < N; j++) {
    if (j % (SIZE*2) < SIZE) {
      strip[j] = CRGB(0, 0, 255);
    } else {
      strip[j] = CRGB(150, 150, 150);
    }
  }
}

