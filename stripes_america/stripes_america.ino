#include <FastLED.h>

#define PIN 6
#define N 300
#define DELAY 15

#define SIZE 5

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
  for (int j = 0; j < N; j+=0) {
    for(int k = 0; k < SIZE; k++) {
      strip[j] = CRGB::Red;
      j++;
    }
    for(int k = 0; k < SIZE; k++) {
      strip[j] = CRGB::White;
      j++;
    }
    for(int k = 0; k < SIZE; k++) {
      strip[j] = CRGB::Blue;
      j++;
    }
  }
}

