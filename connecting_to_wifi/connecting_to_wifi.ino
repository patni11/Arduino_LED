#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsServer.h>

WebSocketsServer webSocket = WebSocketsServer(81);
ESP8266WiFiMulti wifiMulti;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');
  
  WiFi.mode(WIFI_STA);          
  wifiMulti.addAP("Shubh","12345678");
  wifiMulti.addAP("HOME","Abhishek0987");
  wifiMulti.addAP("abcd","89899898");
  
  Serial.print("Connecting to Wifi.... ");
  if (wifiMulti,run() == WL_CONNECTED){
      Serial.println('\n');
      Serial.println("Connection established!");  
      Serial.print("IP address:\t");
      Serial.println(WiFi.localIP());
  }

}


void loop() {
  // put your main code here, to run repeatedly:
  if (wifiMulti.run() != WL_CONNECTED){
     Serial.println("WiFi not connected!, please check wifi password and ssid in the coe");
      delay(100);
  }
}
