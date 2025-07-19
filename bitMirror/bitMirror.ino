const int dataPin = 12;
const int latchPin = 11;
const int clockPin = 9;

int dt = 1000;
byte myByte = 0b00000001;
byte newByte = 0;

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

  if(myByte & 128) newByte += 1;
  if(myByte & 64) newByte += 2;
  if(myByte & 32) newByte += 4;
  if(myByte & 16) newByte += 8;
  if(myByte & 8) newByte += 16;
  if(myByte & 4) newByte += 32;
  if(myByte & 2) newByte += 64;
  if(myByte & 1) newByte += 128;

  myByte = newByte;
  newByte = 0;
  

}
