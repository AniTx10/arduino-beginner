const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  analogWrite(redPin, 164);
  analogWrite(greenPin, 30);
  analogWrite(bluePin, 227);


}

void loop() {
  // put your main code here, to run repeatedly:

}
