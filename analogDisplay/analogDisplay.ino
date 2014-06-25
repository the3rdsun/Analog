#define ON LOW
#define OFF HIGH

#define PATTERN_0 0xc0
#define PATTERN_1 0xf9
#define PATTERN_2 0xa4
#define PATTERN_3 0xb0
#define PATTERN_4 0x99
#define PATTERN_5 0x92
#define PATTERN_6 0x82
#define PATTERN_7 0xf8
#define PATTERN_8 0x80
#define PATTERN_9 0x98

int ledA = 8;
int ledB = 9;
int ledC = 2;
int ledD = 3;
int ledE = 4;
int ledF = 5;
int ledG = 6;
int ledDP = 7;

int CM1 = 10;
int CM2 = 11;
int CM3 = 12;
int CM4 = 13;

int digit1 = 8;
int digit2 = 8;
int digit3 = 8;
int digit4 = 8;

int sensorValue;

void allOff() {
  digitalWrite(ledA, OFF);
  digitalWrite(ledB, OFF);
  digitalWrite(ledC, OFF);
  digitalWrite(ledD, OFF);
  digitalWrite(ledE, OFF);
  digitalWrite(ledF, OFF);
  digitalWrite(ledG, OFF);
  digitalWrite(ledDP, OFF);

  digitalWrite(CM1, LOW);
  digitalWrite(CM2, LOW);
  digitalWrite(CM3, LOW);
  digitalWrite(CM4, LOW);
}

// the setup routine runs once when you press reset:
void setup() {
  Serial.begin(9600);
  Serial.println("I am working!");
    
  // initialize the digital pin as an output.
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledDP, OUTPUT);

  pinMode(CM1, OUTPUT);
  pinMode(CM2, OUTPUT);
  pinMode(CM3, OUTPUT);
  pinMode(CM4, OUTPUT);

  allOff();

  Serial.begin(9600);
  Serial.println("Type in 4 digits:");
  
}

void displayDigit(int common, int digit) {
  int pattern = 0xFF;
  int left;

  //First convert a digit into a pattern

  if (digit == 0) {
    pattern = PATTERN_0;

  }

  if (digit == 1) {
    pattern = PATTERN_1; 

  }

  if (digit == 2) {
    pattern = PATTERN_2; 

  }

  if (digit == 3) {
    pattern = PATTERN_3; 

  }

  if (digit == 4) {
    pattern = PATTERN_4; 

  }

  if (digit == 5) {
    pattern = PATTERN_5; 

  }

  if (digit == 6) {
    pattern = PATTERN_6; 

  }

  if (digit == 7) {
    pattern = PATTERN_7; 

  }

  if (digit == 8) {
    pattern = PATTERN_8; 

  }

  if (digit == 9) {
    pattern = PATTERN_9; 

  }

  //Split out the A and B segements and write them to pins 8 and 9
  //Pins 0 and 1 used for serial port

  left = pattern & 0xfc;

  //Now write to the hardware
  PORTD = left;

  //Pattern constants inverted so OFF = ON and ON = OFF
  if ((pattern & 0x01) == 0x01) {
    digitalWrite(ledA, OFF);

  }

  else {
    digitalWrite(ledA, ON); 

  }

  if ((pattern & 0x02) == 0x02) {
    digitalWrite(ledB, OFF);

  }

  else {
    digitalWrite(ledB, ON); 

  }

  if (common == 1) {
    common = CM1; 

  }

  if (common == 2) {
    common = CM2; 

  }

  if (common == 3) {
    common = CM3; 

  }

  if (common == 4) {
    common = CM4; 

  }

  digitalWrite(common, HIGH);
  delayMicroseconds(500);
  digitalWrite(common, LOW);

}

// the loop routine runs over and over again forever:
void loop() {
  sensorValue = analogRead(0);
  Serial.println(sensorValue);
  
  delay(1000);
  
  if (Serial.available() >= 4) {
    digit1 = Serial.read() - 48;
    digit2 = Serial.read() - 48;
    digit3 = Serial.read() - 48;
    digit4 = Serial.read() - 48;
  
  }
  
  displayDigit(1, digit1);
  displayDigit(2, digit2);
  displayDigit(3, digit3);
  displayDigit(4, digit4);

}

