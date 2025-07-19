const int latchPin = 11; // when to accept data LOW = accepting, HIGH = not accepting
const int clockPin = 9; // helps synchronize serial data to the shift register
const int dataPin = 12; // takes input

byte myByte = 0b10000001;

int dt = 1000;

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
  Serial.println(myByte, DEC); // represent in 0s and 1s in serial monitor
  delay(dt); // lets us see the value for 1 second

  myByte = myByte * 128 + myByte/2; // seems counterintuitive but it's fine because if myByte goes over 255 it wraps around (value = value % 255) 
  
}
