#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N 265
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N, PIN, NEO_GRB + NEO_KHZ800);

int i;
uint32_t matrix[N];

#define SIZE 5

void setup() {
   randomSeed(analogRead(0));
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
  for (int j = 0; j < N; j += 2*SIZE) {
    uint32_t color = hsv_rgb(random(360));
    for (int k = j; k < j + SIZE; k++) {
      mat[k] = color;
    }
  }
}

uint32_t hsv_rgb(int deg) {
  byte X = 255.0 * (1.0 - fabs(fmod(((double) deg / 60.0), 2.0) - 1.0));

  byte _r, _g, _b;
  if (0 <= deg && deg < 60) {
    _r = 255;
    _g = X;
    _b = 0;
  } else if (60 <= deg && deg < 120) {
    _r = X;
    _g = 255;
    _b = 0;
  } else if (120 <= deg && deg < 180) {
    _r = 0;
    _g = 255;
    _b = X;
  } else if (180 <= deg && deg < 240) {
    _r = 0;
    _g = X;
    _b = 255;
  } else if (240 <= deg && deg < 300) {
    _r = X;
    _g = 0;
    _b = 255;
  } else if (300 <= deg && deg < 360) {
    _r = 255;
    _g = 0;
    _b = X;
  }

  return strip.Color((_r), (_g), (_b));
}

