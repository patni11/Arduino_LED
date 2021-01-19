#include <FastLED.h>
#include <ESP8266WiFi.h>

#include <WiFiClient.h>
#include <WebSocketsServer.h>
#include <Hash.h>
#include <FS.h>

#define LED_PIN 4
#define ANALOG_READ 0
#define NUM_LEDS 100
CRGB leds[NUM_LEDS];

WebSocketsServer webSocket = WebSocketsServer(81);
const char *ssid       = "abcd";
const char *password   = "12345678";

uint8_t hue            = 0;
uint8_t brightness     = 100;

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(brightness);
  FastLED.clear();
  
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.println("Connected!");
  Serial.print("AP IP address: ");
  Serial.println(myIP);

  webSocket.begin();
  webSocket.onEvent(onWebSocketEvent);
}

void loop() {
  webSocket.loop();
  // put your main code here, to run repeatedly:

}

void onWebSocketEvent(uint8_t connection, WStype_t type, uint8_t * payload, size_t length) {
  switch (type){
    case WStype_DISCONNECTED:
      Serial.printf("[%u] Disconnected!\n", connection);
      break;
    case WStype_CONNECTED: {
      IPAddress ip = webSocket.remoteIP(connection);
      Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", connection, ip[0], ip[1], ip[2], ip[3], payload);
      webSocket.sendTXT(connection, "Connected");
      
    }
    break;
    case WStype_TEXT:
      Serial.printf("[%u] get Text: %s\n", connection, payload);

      if (payload[0] == '-'){
        switch (payload[1]) {
          case 'h': // Request to set hue
            hue = strtoul((const char *) &payload[2], NULL, 16);
            Serial.printf("hueee:   is :: %u",hue);
            //hue = map(hue,0,360,0,255);
            fill_solid(leds,NUM_LEDS,CHSV(hue,255,255));
            FastLED.show();
            Serial.printf("recieved msg hue");
            break;
          case 'b': // Request to set brightness  
            brightness = strtoul((const char *) &payload[2], NULL, 16);
            Serial.printf("brightness:   is :: %u",brightness);
            FastLED.setBrightness(brightness);
            FastLED.show();
            Serial.printf("recieved msg brightness");
            break;
        }
      }
    break;
  }
}
