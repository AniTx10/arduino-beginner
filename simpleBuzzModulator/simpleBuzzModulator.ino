const int readPin = A0;
const int ledPin = 9;
int sensorVal;
int calcVal;

void setup() {
  // put your setup code here, to run once:

  pinMode(readPin, INPUT);
  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  

}

void loop() {
  // put your main code here, to run repeatedly:

  sensorVal = analogRead(readPin);

  calcVal = sensorVal / 4;

  analogWrite(ledPin, calcVal);

  Serial.print("Analog: ");
  Serial.print(sensorVal);
  Serial.print(", ");

  Serial.print("PWM Value: ");
  Serial.println(calcVal);

  delay(500);

  


  
  

}
