const int readPin = 2;
const int setPin = 12;

int buttonState;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  
  pinMode(readPin, INPUT);
  pinMode(setPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(readPin);

  if(buttonState == HIGH){
    digitalWrite(setPin, HIGH);
    Serial.println("ON");
  }

  else{
    digitalWrite(setPin, LOW);
    Serial.println("OFF");
  }


}
