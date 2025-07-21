#include <LiquidCrystal.h>

const int rs = 7;
const int en = 8;
const int d4 = 9;
const int d5 = 10;
const int d6 = 11;
const int d7 = 12;

int dt = 1000;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // creates lcd object


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16,2); // 16 columns, 2 rows *why is columns first LOL*

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  lcd.print("Hello World");
  delay(dt);
  lcd.setCursor(0,0);
  lcd.print("My name is Ani");
  delay(dt);
  lcd.clear();

}
