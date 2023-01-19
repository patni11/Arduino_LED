//#define FASTLED_ESP8266_RAW_PIN_ORDER
//#define FASTLED_ESP8266_NODEMCU_PIN_ORDER
//#define FASTLED_INTERNAL
#include <FastLED.h>
#include<ArduinoJson.h>
#define LED_PIN     4
#define Total_LEDS 300
#define NUM_LEDS    300
CRGB leds[Total_LEDS];



void setup() {
  Serial.begin(9600); 
  while(!Serial) {
  }
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, Total_LEDS);
  FastLED.clear();
  
}
//StaticJsonDocument<670> doc;
//bool unreal = true;
void loop() {
  /*
  if (unreal){
  //int     size_ = 0;
  String  payload;
  while ( !Serial.available()  ){}
  if ( Serial.available() )
    payload = Serial.readStringUntil( '\n' );

  DeserializationError   error = deserializeJson(doc, payload);
  if (error) {
    Serial.println(error.c_str()); 
    return;
  }
  if (doc["anger"]["vals"] == 42) {
     Serial.println("{\"Success\":\"True\"}");
  }
  else {
      Serial.println("{\"Success\":\"False\"}");
   }
  //delay(20);
  }
  unreal = false;
  int anger = doc["anger"]["vals"].as<int>();
  int anticipation = anger + doc["anticipation"]["vals"].as<int>();
  */
  //data = {"anger": {"vals": 42, "color": 29}, "anticipation": {"vals": 60, "color": 54}, "joy": {"vals": 48, "color": 74}, "trust": {"vals": 24, "color": 73}, "fear": {"vals": 24, "color": 90}, "surprise": {"vals": 42, "color": 128}, "sadness": {"vals": 18, "color": 200}, "disgust": {"vals": 36, "color": 233}}
  int i = 0;
  int anger = 20;
  int j = anger;
  int anticipation = anger+20;
  int k = anticipation;
  int joy = anticipation + 20;
  int l = joy;
  int trust = joy+20;
  int m = trust;
  int fear = trust + 20;
  int n = fear;
  int surprise = fear+20;
  int o = surprise;
  int sadness = surprise + 20;
  int p = sadness;
  int disgust = sadness + 20;
  
  
  while (anger < NUM_LEDS){
    while (i < anger){
      if (i >= 20){
        leds[i-20] = CHSV (0,0,0);
      }
    leds[i] = CHSV (29, 255, 255);
    FastLED.show();
    delay(10);
    i ++;
    }
    
    while (j<anticipation){
      leds[j] = CHSV (54, 255, 255);
      FastLED.show();
      delay(10);
      j ++;  
    }
    while (k<joy){
      leds[k] = CHSV (74, 255, 255);
      FastLED.show();
      delay(10);
      k ++;  
    }
     while (l<fear){
      leds[l] = CHSV (100, 255, 255);
      FastLED.show();
      delay(10);
      l ++;  
    }
     while (m<trust){
      leds[m] = CHSV (130, 255, 255);
      FastLED.show();
      delay(10);
      m ++;  
    }
     while (n<surprise){
      leds[n] = CHSV (158, 255, 255);
      FastLED.show();
      delay(10);
      n ++;  
    }
     while (o<sadness){
      leds[o] = CHSV (200, 255, 255);
      FastLED.show();
      delay(10);
      o ++;  
    }
     while (p<joy){
      leds[p] = CHSV (233, 255, 255);
      FastLED.show();
      delay(10);
      p ++;  
    }
    
    anger += 1;
    anticipation += 1;
    joy += 1;   
    trust += 1; 
    fear += 1;
    surprise += 1; 
    sadness += 1;
    disgust += 1;
  
  }
  
  /*
  int     size_ = 0;
  String  payload;
  while ( !Serial.available()  ){}
  if ( Serial.available() )
    payload = Serial.readStringUntil( '\n' );
  StaticJsonDocument<670> doc;

  DeserializationError   error = deserializeJson(doc, payload);
  if (error) {
    Serial.println(error.c_str()); 
    return;
  }
  if (doc["anger"]["vals"] == 42) {
     Serial.println("{\"Success\":\"True\"}");
  }
  else {
      Serial.println("{\"Success\":\"False\"}");
   }
  delay(20);

    int anger = doc["anger"]["vals"].as<int>();
    int anticipation = doc["anticipation"]["vals"].as<int>();
    int i = 0;
    int j = anger;
    
  
   * 
     while (true){
   
    
    Serial.println(doc["anger"]["color"].as<int>());
    Serial.println(doc["anticipation"]["color"].as<int>());
    
    while (i < anger){
      leds[i] = CHSV (doc["anger"]["color"], 255, 255);
      FastLED.show(); 
      delay(40);
      i += 1;
      }  
    
    while (j < anticipation){
      leds[j] = CHSV (doc["anticipation"]["color"], 255, 255);
      FastLED.show(); 
      delay(40);
      j += 1;
      }  
  
  
  anger = anger + doc["anger"]["vals"].as<int>();
  anticipation = anticipation + doc["anticipation"]["vals"].as<int>();
  
  
  if (anger >= 300){
    anger = doc["anger"]["vals"];
  }
  if (anticipation >= 300){
    anticipation = doc["anticipation"]["vals"];
  }
  
  if (i >= 300){
    i = 0;
  }
  if (j >= 300){
    j = 0;
  }
  
  }
  */
  
  
 
}
