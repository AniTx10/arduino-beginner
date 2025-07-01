const int greenPin = 2;
const int yellowPin = 3;
const int redPin = 4;
const int trig = 10;
const int echo = 11;
float duration;
float distance;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

  pinMode(greenPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  float x = getSpeed();
  plot("speed", x, false);
  
  if(x > 30){
    digitalWrite(redPin, HIGH);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, LOW);
  }

  else if(x > 15){
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, HIGH);
    digitalWrite(greenPin, LOW);
  }

  else{
    digitalWrite(redPin, LOW);
    digitalWrite(yellowPin, LOW);
    digitalWrite(greenPin, HIGH);
  }

  delay(200);
  

}

float getDistance(){
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  //amount of time trigger needs to stay on to release ultrasonic wave is 10 microseconds
  delayMicroseconds(10);

  digitalWrite(trig, LOW);

  //measures the amount of time the echoPin stays high (time from when the ultrasonic wave was emitted, to when echo hits receiver), if no signal is received in 30000 ms call is cancelled
  duration = pulseIn(echo, HIGH, 30000);


  //sound = 0.034 centimeters per microsecond. sound multiplied by duration in microseconds gives distance in centimeters from sensor to object x2
  distance = duration * .034/2;

  return distance;
}

float getSpeed(){

  float distance1 = getDistance();
  plot("distance", distance1, true);
  delay(100);
  float distance2 = getDistance();

  float distance = abs(distance2 - distance1);

  float s = distance/0.1;

  return s;
  
}

void plot(String label, float value, bool last){
  Serial.print(label);
  if(label != "") Serial.print(":");
  Serial.print(value);
  if(last == false) Serial.print(",");
  else Serial.println();
}
