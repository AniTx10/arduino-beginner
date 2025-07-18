const int latchPin = 11; // when to accept data LOW = accepting, HIGH = not accepting
const int clockPin = 9; // helps synchronize serial data to the shift register
const int dataPin = 12; // takes input

byte LEDs = 0x1;

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
  shiftOut(dataPin, clockPin, LSBFIRST, LEDs); // shift out byte of data bit by bit, clock does synchronization, least significant bit comes first, LEDs is data packet being sent.
  digitalWrite(latchPin, HIGH); // done accepting data
}
