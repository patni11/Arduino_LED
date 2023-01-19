//#define FASTLED_ESP8266_RAW_PIN_ORDER
//#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
//#define FASTLED_INTERNAL
#include <FastLED.h>

#define NUM_LEDS 300
#define DATA_PIN 4
#define CHIPSET WS2812B
#define COLOR_ORDER GRB
#define BRIGHTNESS 255

CRGB leds[NUM_LEDS];

const int proxInPin = 3;

void setup() {
  delay(3000);
  FastLED.addLeds<CHIPSET, DATA_PIN, COLOR_ORDER>(leds,NUM_LEDS);
  FastLED.setTemperature(Tungsten40W);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  

  fill_gradient(leds,150,CHSV(90,255,255),CHSV(230,255,255),SHORTEST_HUES);
 
  FastLED.show();
  delay(10);
  }
