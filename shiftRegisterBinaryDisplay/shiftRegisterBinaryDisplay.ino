const int latchPin = 11; // when to accept data LOW = accepting, HIGH = not accepting
const int clockPin = 9; // helps synchronize serial data to the shift register
const int dataPin = 12; // takes input

byte LEDs = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available())Serial.read();
  Serial.println("Enter a number between 0-255: ");
  while(Serial.available() == 0){}

  int temp = Serial.parseInt();
  LEDs = constrain(temp, 0, 255);
  
  

  digitalWrite(latchPin, LOW); // ready for data
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs); // shift out byte of data bit by bit, clock does synchronization, least significant bit comes first, LEDs is data packet being sent.
  digitalWrite(latchPin, HIGH); // done accepting data
  delay(2000); // display value for 5 seconds
}
