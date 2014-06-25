int sensorValue;

void setup() {
  Serial.begin(9600);
  Serial.println("I am working!");
  
}

void loop() {
  sensorValue = analogRead(0);
  Serial.println(sensorValue);
  
  delay(1000); 
  
}
