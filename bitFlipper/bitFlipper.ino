const int dataPin = 12;
const int latchPin = 11;
const int clockPin = 9;

int dt = 1000;
byte myByte = 0b01001001;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte);
  digitalWrite(latchPin, HIGH);
  Serial.println(myByte, DEC);
  
  delay(dt);

  myByte = 255 - myByte;

  
  

}
