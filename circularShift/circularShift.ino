const int latchPin = 11; // when to accept data LOW = accepting, HIGH = not accepting
const int clockPin = 9; // helps synchronize serial data to the shift register
const int dataPin = 12; // takes input

byte myByte = 0b00000001;

int dt = 1000;

bool add1 = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(latchPin, LOW); // ready for data
  shiftOut(dataPin, clockPin, LSBFIRST, myByte); // shift out byte of data bit by bit, clock does synchronization, least significant bit comes first, LEDs is data packet being sent.
  digitalWrite(latchPin, HIGH); // done accepting data
  Serial.println(myByte, BIN); // represent in 0s and 1s in serial monitor
  delay(dt); // lets us see the value for 1 second

  if(myByte >= 128) add1 = true; // checks if digit being looped is 1; if so, add1 is true
  else add1 = false; // if not add1 is false
  myByte = myByte * 2; // logical shift left
  if(add1 == true) myByte = myByte + 1; // accounts for looped digit based off add1 status
  
}
