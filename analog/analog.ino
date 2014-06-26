int sensorValue1;
int sensorValue2;

void setup() {
  Serial.begin(9600);
  Serial.println("I am working!");
  
}

void loop() {
  sensorValue1 = analogRead(0);
  sensorValue2 = analogRead(1);
  Serial.print(sensorValue1);
  Serial.print(",");
  Serial.println(sensorValue2);
  
  delay(200); 
  
}
