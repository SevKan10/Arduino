#include<Servo.h>
#include<Wire.h>
#include<LiquidCrystal_I2C.h>
int a=3;
int led =12;
Servo se;
boolean val =0;
LiquidCrystal_I2C lcd(0x27, 18,2);
void setup() 
{
se.attach(6);
lcd.init();
lcd.backlight();
Serial.begin(9600);
pinMode(a,INPUT);

}

void loop() 
{
 
  val = digitalRead(a);
Serial.print("giá trị cảm biến ");
Serial.println(val);
  if (val==0)
    {
   
  digitalWrite(led,1);
   
   }
  else 
  {
    digitalWrite(led,0);
   
  }
    
}