#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(300, PIN, NEO_GRB + NEO_KHZ800);

// CONSTANTS
int HZ = 255;
int DELAY = 1000 / HZ; // delay in ms: 100hz
int PERIOD = 255;

int i, increment, color;

void setup() {
  strip.begin();
  strip.show();

  i = 0;
  increment = 1;
  color = 0;
}

void loop() {
  if (i == 0) {
    increment = 1;
    color += 1;
  }
  else if (i >= PERIOD) {
    increment = -1;
  }

  if (color % 3 == 0) {
    setInRange(0, 150, i, 0, 0);
  } else if (color % 3 == 1) {
    setInRange(0, 150, 0, i, 0);
  } else if (color % 3 == 2) {
    setInRange(0, 150, 0, 0, i);
  } else {
    setInRange(0, 150, i, i, i);
  }
  
  i += increment;
  strip.show();
  delay(DELAY);
}

// Set the pixels from min to max on strip to color
void setInRange(int min, int max, int color[]) {
  for (int i = min; i < max; i++) {
    strip.setPixelColor(i, color[0], color[1], color[2]);
  }
}

// Set the pixels from min to max on strip to color
void setInRange(int min, int max, int r, int g, int b) {
  int color[3] = {r, g, b};
  setInRange(min, max, color);
}

// Re-scale n into a different space
int scale(int n, int max_in, int max_out) {
  double proportion = n / max_in;
  return (int) proportion * max_out;
}

