#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N 300
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_RGBW + NEO_KHZ800);

uint32_t color = strip.Color(30, 20, 200);

void setup() {
  strip.begin();

  for(int i = 0; i < N; i++) {
    strip.setPixelColor(i, color);
  }
  strip.show();
}

void loop() {
}
