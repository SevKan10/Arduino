#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <TinyGPS++.h>          
#include <SoftwareSerial.h>   
LiquidCrystal_I2C display(0x27,16,2);
TinyGPSPlus gps;
#define S_RX    8                
#define S_TX    9                
SoftwareSerial SoftSerial(S_RX, S_TX);  
void setup()
{
  display.init();
  display.backlight(); 
  Serial.begin(9600);
  SoftSerial.begin(9600); 
}
 
void loop()
{
  boolean newData = false;
  for (unsigned long start = millis(); millis() - start < 300;)
  {
    while (SoftSerial.available() > 0)
    {
      if (gps.encode(SoftSerial.read()))
      {
        newData = true;
      }
    }
  }
 
  //If newData is true
  if (newData == true)
  {
    newData = false; 
    (gps.location.isValid() == 1);
    {
      //String gps_speed = String(gps.speed.kmph());
      display.setCursor(0, 0);
      display.print(gps.speed.kmph());
      delay(100);
      Serial.print("Speed ");
      Serial.println(gps.speed.kmph());
      display.print(" km/h");
 
      display.setCursor(0, 1);
      display.print(gps.satellites.value());
      display.print(" SAT");
      delay(100);
      Serial.print("Sat ");
      Serial.println(gps.satellites.value());
     
    }
  }
 
  else
  {
    display.setCursor(0, 0);
    display.print("No Data");
    display.clear();
  }
}
//Code by SevKan