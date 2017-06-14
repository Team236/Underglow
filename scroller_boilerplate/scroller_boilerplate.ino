#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N 300
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N, PIN, NEO_GRB + NEO_KHZ800);

int i;
uint32_t matrix[N];

void setup() {
  generate(matrix);
  i = 0;
  
  strip.begin();
  strip.show();
}

void loop() {
  i++;
  i %= N;
  for (int led = 0; led < N; led++) {
    strip.setPixelColor(led, matrix[(led + i) % N]);
  }
  strip.show();
}

/*
 * Fill the matrix with strip.Color values
 */
void generate(uint32_t *mat) {
  //mat[0] = strip.Color(0,255,0);
}

