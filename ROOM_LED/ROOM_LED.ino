#define FASTLED_ALLOW_INTERRUPTS 0
#include <FastLED.h>
#define LED_PIN     4
#define Total_LEDS 300
#define NUM_LEDS    100
CRGB leds[Total_LEDS];


void setup() {
   Serial.begin(115200); 
  while(!Serial) {
  }
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, Total_LEDS);
  FastLED.setMaxRefreshRate(100);
  FastLED.clear();
  delay(1000);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
 for (i=0;i<=NUM_LEDS;i++){
  leds[i] = CRGB(255,45,0);
 }
 
 delay(10);
 FastLED.show();
}
