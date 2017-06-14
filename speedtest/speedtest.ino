#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(300, PIN, NEO_GRB + NEO_KHZ800);
int i;
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  i = 0;
  delay(1000);
  strip.setPixelColor(0, 0, 255, 0);
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int j = 0; j < 300; j++) {
    strip.setPixelColor(j, 0,0,0);
  }
  strip.setPixelColor(i, 0,255,255);
  strip.show();
  i++;
}
