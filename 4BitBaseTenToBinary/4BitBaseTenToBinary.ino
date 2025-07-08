const int bit4 = 5;
const int bit3 = 4;
const int bit2 = 3;
const int bit1 = 2;
int userNum;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
  Serial.setTimeout(5000);

  for(int i = 2; i<=5; i++){
    pinMode(i, OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Enter a base ten number 0-15: ");

  while(Serial.available() == 0){}

  String input = Serial.readStringUntil('\n');
  input.trim();

  if(input.length() == 0 || !isInteger(input)){
    Serial.println("This is not an integer");
    return;
  }

  userNum = constrain(input.toInt(), 0, 15);

  if(userNum & 8) digitalWrite(bit4, HIGH);
  if(userNum & 4) digitalWrite(bit3, HIGH);
  if(userNum & 2) digitalWrite(bit2, HIGH);
  if(userNum & 1) digitalWrite(bit1, HIGH);

  delay(5000);

  for(int i = 2; i<=5; i++) digitalWrite(i, LOW);
  

}

bool isInteger(String s){
  for(int i = 0; i < s.length(); i++){
    if(!isDigit(s.charAt(i))) return false;
  }

  return true;
}
