const int segA = 6;
const int segB = 7;
const int segC = 10;
const int segD = 9;
const int segE = 8;
const int segF = 5;
const int segG = 4;
const int segDP = 11;
const int readPin = 2;
const int debounceDelay = 50;
int lastDebounce = 0;
int x = 0;
bool countUp = false;

void setup() {
  // put your setup code here, to run once:

  for(int i = 4; i <= 11; i++){
    pinMode(i, OUTPUT);
  }

  pinMode(readPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(x-1 < 0 || x+1 > 9){
    countUp = !countUp;
  }

  int reading = digitalRead(readPin);

  if(reading == LOW){

    delay(debounceDelay); 

    /*
     * when pressing a mechanical button, the electrical connection connects and disconnects briefly before getting to the desired state
     * delaying 50 milliseconds and then rechecking buttonState ensures the unwanted buttonState changes are not accounted for
     */

    if(digitalRead(readPin) == LOW){

      if(countUp){
        x++;
      }

      else{
        x--;
      }
      
    }


    while(digitalRead(readPin) == LOW){
      delay(5); //avoid constant polling
    }
    
    
  }

  switch(x){
    case 0:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, LOW);
      digitalWrite(segDP, LOW);
      break;
      
    case 1:
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      digitalWrite(segDP, LOW);
      break;

    case 2:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, LOW);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
      digitalWrite(segDP, LOW);
      break;

    case 3:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
      digitalWrite(segDP, LOW);
      break;

    case 4:
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      digitalWrite(segDP, LOW);
      break;

    case 5:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, LOW);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      digitalWrite(segDP, LOW);
      break;

    case 6:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, LOW);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      digitalWrite(segDP, LOW);
      break;

    case 7:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
      digitalWrite(segDP, LOW);
      break;

    case 8:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      digitalWrite(segDP, LOW);
      break;

    case 9:
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
      digitalWrite(segDP, LOW);
      break;
  }

  


}
