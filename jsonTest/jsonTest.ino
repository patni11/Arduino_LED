#include <ArduinoJson.h>
void setup() {
  Serial.begin(9600); 
  while(!Serial) {
  }
}

void loop() {
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
}
