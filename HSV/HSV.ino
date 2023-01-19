#include "FastLED.h"
CRGB leds[10];
void setup() { FastLED.addLeds<WS2812B, 4>(leds, 10); }

void loop() { 
  static uint8_t hue = 0;
  FastLED.showColor(CHSV(hue++, 255, 255)); 
  delay(1000);
}
