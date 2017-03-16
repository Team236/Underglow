#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_RGBW + NEO_KHZ800);

// CONSTANTS
int HZ = 100;
int DELAY = 1000 / HZ; // delay in ms: 100hz
int PERIOD = 255;
int COLOR[3] = {0, 0, 255};

int i, increment;

void setup() {
  strip.begin();
  strip.show();

  i = 0;
  increment = 1;
}

void loop() {
  if (i == 0) { increment = 1; }
  else if (i == PERIOD) { increment = -1; }
  
  setInRange(strip, 0, 60, scale(i, PERIOD, COLOR[0]), scale(i, PERIOD, COLOR[1]), scale(i, PERIOD, COLOR[2]));
  
  i += increment;
  strip.show();
  delay(DELAY);
}

// Set the pixels from min to max on strip to color
void setInRange(Adafruit_NeoPixel strip, int min, int max, int color[]) {
  for (int i = min; i < max; i++) {
    strip.setPixelColor(i, color[0], color[1], color[2]);
  }
}

// Set the pixels from min to max on strip to color
void setInRange(Adafruit_NeoPixel strip, int min, int max, int r, int g, int b) {
  int color[3] = {r,g,b};
  setInRange(strip, min, max, color);
}

// Re-scale n into a different space
int scale(int n, int max_in, int max_out) {
  double proportion = n / max_in;
  return (int) proportion * max_out;
}

