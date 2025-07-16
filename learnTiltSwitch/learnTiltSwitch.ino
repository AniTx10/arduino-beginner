const int tiltPin = 2;
const int greenPin = 9;
const int redPin = 10;
int tiltVal;

int dt = 50;

void setup() {
  // put your setup code here, to run once:

  pinMode(tiltPin, INPUT_PULLUP);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  tiltVal = digitalRead(tiltPin);
  Serial.println(tiltVal);

  if(tiltVal == 0){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  }

  else{
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
  }

  delay(dt);

}
