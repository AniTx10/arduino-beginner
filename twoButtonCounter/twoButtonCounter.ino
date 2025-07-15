const int segA = 6;
const int segB = 7;
const int segC = 10;
const int segD = 9;
const int segE = 8;
const int segF = 5;
const int segG = 4;
const int segDP = 11;
const int readUpPin = 2;
const int readDownPin = 3;
const int debounceDelay = 50;
int lastDebounce1 = 0;
int lastDebounce2 = 0;
int x = 0;
bool countUp = true;

void setup() {
  // put your setup code here, to run once:

  for(int i = 4; i <= 11; i++){
    pinMode(i, OUTPUT);
  }

  pinMode(readUpPin, INPUT_PULLUP);
  pinMode(readDownPin, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:


  int readingUp = digitalRead(readUpPin);

  if(readingUp == LOW){

    /*
     * millis() is an inbuilt Arduino function that counts the milliseconds elapsed since the program began. 
     * The new debounce mechanism functions similarly to a simple delay(), but the program doesn't pause, allowing the Arduino to continuously update the display 
     * and poll button readings. 
     */

    if(millis() - lastDebounce1 > debounceDelay){

       if(x + 1 <= 9){
          x++;
       }

       lastDebounce1 = millis();
        
    }


    while(digitalRead(readUpPin) == LOW){
      delay(5); //avoid constant polling
    }
    
    
  }

  int readingDown = digitalRead(readDownPin);

  if(readingDown == LOW){

    /*
     * millis() is an inbuilt Arduino function that counts the milliseconds elapsed since the program began. 
     * The new debounce mechanism functions similarly to a simple delay(), but the program doesn't pause, allowing the Arduino to continuously update the display 
     * and poll button readings. 
     */

    if(millis() - lastDebounce2 > debounceDelay){

       if(x - 1 >= 0){
          x--;
       }

       lastDebounce2 = millis();
        
    }


    while(digitalRead(readDownPin) == LOW){
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
