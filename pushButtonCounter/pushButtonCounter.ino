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
bool countUp = true;

void setup() {
  // put your setup code here, to run once:

  for(int i = 4; i <= 11; i++){
    pinMode(i, OUTPUT);
  }

  pinMode(readPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:


  int reading = digitalRead(readPin);

  if(reading == LOW){

    /*
     * millis() is an inbuilt Arduino function that counts the milliseconds elapsed since the program began. 
     * The new debounce mechanism functions similarly to a simple delay(), but the program doesn't pause, allowing the Arduino to continuously update the display 
     * and poll button readings. 
     */

    if(millis() - lastDebounce > debounceDelay){

      /*
       * Previously, direction checking logic was outside of the button press conditional; this led to Arduino constantly changing direction of counting at 0 and 9 even 
       * when the button was not being pressed. 
       * Additionally, checking that the count direction is wrong before changing it saves the program from incorrectly changing direction if the debounce 
       * mechanism fails.
       */

      if((x-1 < 0 && countUp == false) || (x+1 > 9 && countUp == true)){
        countUp = !countUp;
      }

      if(countUp){
        x++;
      }

      else{
        x--;
      }

      lastDebounce = millis();
      
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
