#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>          
#include <SoftwareSerial.h>   
LiquidCrystal_I2C lcd(0x27,16,2);
TinyGPSPlus gps;
#define S_RX    8                
#define S_TX    9                
SoftwareSerial SoftSerial(S_RX, S_TX);  
void setup(void) {
  lcd.init();
  lcd.backlight(); 
  Serial.begin(9600);
  SoftSerial.begin(9600); 
}
void loop() 
{  
  while (SoftSerial.available() > 0) 
  {

    if (gps.encode(SoftSerial.read()))
     {
           if (gps.speed.isValid()) {
        Serial.print("Speed      = ");
        Serial.print(gps.speed.kmph());
        Serial.println(" kmph");
      }
      else
        Serial.println("Speed Invalid"); 
        float kmh = gps.speed.kmph() * 1.15;
        if (gps.encode(SoftSerial.read()))
      {
        lcd.setCursor(0,0);
        lcd.print(gps.speed.kmph());
        lcd.print(" Km/h");
        lcd.clear();
        delay(500);
      }
      else
      {
        lcd.setCursor(0,0);
        lcd.print("0 Km/h");
      }
  } }   
}
