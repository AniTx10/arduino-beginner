#include <Servo.h>
int servoPin = 9;
int servoPos = 0;
Servo myServo;
bool countUp = true;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:

  myServo.write(servoPos);

  delay(1000);

  if((servoPos == 180 && countUp == true) || (servoPos == 0 && countUp == false)) countUp = !countUp;

  if(countUp == true) servoPos += 10;

  if(countUp == false) servoPos -= 10;

  

  

}
