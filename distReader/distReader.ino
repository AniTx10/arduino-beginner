const int trigPin = 9;
const int echoPin = 10;
long duration;
long distance;


void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  // put your setup code here, to run once:


}


void loop() {
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  // put your main code here, to run repeatedly:


}
