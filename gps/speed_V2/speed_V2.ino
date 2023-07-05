#include <TinyGPS++.h>          
#include <SoftwareSerial.h>   

TinyGPSPlus gps;
#define S_RX    8                
#define S_TX    9        
SoftwareSerial SoftSerial(S_RX, S_TX);  

void setup()
{
  Serial.begin(9600);
  SoftSerial.begin(9600); 
}
 
void loop(void)
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
      Serial.print("Speed ");
      Serial.println(gps.speed.kmph());
      Serial.print("Sat ");
      Serial.println(gps.satellites.value());
    }
  }
  else{}
}
//Code by SevKan