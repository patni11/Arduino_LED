uint8_t micPin = A0;
uint16_t micValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(50);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  micValue = analogRead(micPin);
  Serial.println(micValue); 
  delay(200);
}
