#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
Servo se1;
LiquidCrystal_I2C lcd(0x27,16,2);
int val = 0;
void setup()
{
  se1.attach(6);
  lcd.init();
}
void loop()
{
  val = analogRead(A0);
  int sau = map(val,0,1023,0,180);
  se1.write(sau);
  lcd.setCursor(0,0);
  lcd.print(sau); 
} 
//code by *SevKan10* 