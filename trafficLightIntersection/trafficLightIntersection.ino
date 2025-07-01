const int greenPin = 2;
const int yellowPin = 3;
const int redPin = 4;
const int greenPin2 = 5;
const int yellowPin2 = 6;
const int redPin2 = 7;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(yellowPin2, OUTPUT);
  pinMode(redPin2, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Started");

  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin2, HIGH);
  delay(6000);
  digitalWrite(greenPin, LOW);
  digitalWrite(yellowPin, HIGH);
  delay(2000);
  digitalWrite(yellowPin, LOW);
  digitalWrite(redPin, HIGH);
  digitalWrite(redPin2, LOW);
  digitalWrite(greenPin2, HIGH);
  delay(6000);
  digitalWrite(greenPin2, LOW);
  digitalWrite(yellowPin2, HIGH);
  delay(2000);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin2, LOW);
  

}
