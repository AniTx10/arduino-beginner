const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

int userRed;
int userGreen;
int userBlue;

void setup() {
  Serial.begin(9600);

  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  Serial.println("Enter RGB values between 0 and 255:");
}

void loop() {

  Serial.println("Enter red RGB value(0-255): ");
  while(Serial.available() == 0){
  }
  userRed = Serial.parseInt();

  while(Serial.available()) Serial.read();

  Serial.println("Enter green RGB value(0-255): ");
  while(Serial.available() == 0){
  }
  userGreen = Serial.parseInt();

  while(Serial.available()) Serial.read();


  Serial.println("Enter blue RGB value(0-255): ");
  while(Serial.available() == 0){
  }
  userBlue = Serial.parseInt();

  while(Serial.available()) Serial.read();


  analogWrite(redPin, constrain(userRed, 0, 255));
  analogWrite(greenPin, constrain(userGreen, 0, 255));
  analogWrite(bluePin, constrain(userBlue, 0, 255));
}
