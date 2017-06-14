#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N 266
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N, PIN, NEO_GRB + NEO_KHZ800);

int i;
uint32_t matrix[N];

#define SIZE 10

void setup() {
  generate(matrix);
  i = 0;
  
  strip.begin();
  strip.show();
}

void loop() {
  i++;
  for (int led = 0; led < N; led++) {
    strip.setPixelColor(led, matrix[(led + i) % N]);
  }
  strip.show();
  delay(15);
}

/*
 * Fill the matrix with strip.Color values
 */
void generate(uint32_t *mat) {
  for (int j = 0; j < N; j++) {
    if (j % (SIZE*2) < SIZE) {
      mat[j] = strip.Color(0, 0, 200);
    } else {
      mat[j] = strip.Color(0, 0, 0);
    }
  }
}

