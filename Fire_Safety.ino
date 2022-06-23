/*
  This code is for the Project of Industrial Gas Leakage Detection, Smoke Detection,
  Air Pollution Detection, Fire Detection and Autometic Fire Extenguish.
  This code is developed by Md. Rezaul Islam Khan, in Dec 2021.
*/

#include<LiquidCrystal.h>
int mq02=0, mq04=0, mq135=0, ir=0, tmp=0;
int pump = 7, buzz = 6, fan = 5;

LiquidCrystal lcd(13, 12, 8, 9, 10, 11);

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);

  pinMode(fan, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(pump, OUTPUT);
  
  digitalWrite(pump, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(buzz, LOW);

  lcd.begin(16, 2);
  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print("Wait for Sensor-");
  lcd.setCursor(0,1);
  lcd.print("Heating & Ready");
  //delay(30000);
  

}

void loop() {
  mq02 = analogRead(A2);
  mq04 = analogRead(A1);
  mq135 = analogRead(A0);
  ir = analogRead(A3);
  tmp = analogRead(A4);

if(ir<500)
{
  lcd.setCursor(0,0);
  lcd.print("Fire! Fire! Fire");
  digitalWrite(pump, HIGH);
  digitalWrite(buzz, HIGH);
  delay(5000);
}

if(mq04>350)
{
  lcd.setCursor(0,0);
  lcd.print("Danger! Gas Leak");
  digitalWrite(buzz, HIGH)
  delay(1000);
}

if(mq02>150)
{
  lcd.setCursor(0,0);
  lcd.print("  Smoke Found!  ");
  digitalWrite(buzz, HIGH);
  delay(500);
}

if((mq02<150)&&(mq04<350)&&(ir>200))
{
  lcd.setCursor(0,0);
  digitalWrite(pump, LOW);
  digitalWrite(buzz, LOW);
  lcd.print("Work,No any Risk");
}

if(mq135<250)
{
  lcd.setCursor(0,1);
  lcd.print(" Air is Normal  ");
  digitalWrite(buzz, LOW);
  digitalWrite(fan, LOW);
}
else if((mq135>250) && (mq135<400))
{
  lcd.setCursor(0,1);
  lcd.print("Air is Polluted!");
  digitalWrite(fan, HIGH);
}
else if(mq135>400)
{
  lcd.setCursor(0,1);
  lcd.print(" Air is Danger! ");
  digitalWrite(buzz, HIGH);
}
delay(500);
}
