#include <TinyGPS++.h>  
#include <SoftwareSerial.h>  
TinyGPSPlus gps;
#define RX 8  
#define TX 9  
SoftwareSerial SoftSerial(RX, TX);  

void setup(void) 
{
  Serial.begin(9600);
  SoftSerial.begin(9600);
}
void loop() 
{
  while (SoftSerial.available() > 0) 
  {
    if (gps.encode(SoftSerial.read())) 
    {
      if (gps.location.isValid()) 
      {
        Serial.print("Latitude   = ");
        Serial.println(gps.location.lat(), 6);
        Serial.print("Longitude  = ");
        Serial.println(gps.location.lng(), 6);
      }
       else
       {
       Serial.println("Location Invalid");
       }
      if (gps.satellites.isValid()) {
        Serial.print("Satellites = ");
        Serial.println(gps.satellites.value());
      }
      else
        Serial.println("Satellites Invalid");
      }  }
      String url = "http://maps.google.com/maps?q=loc:";
      url = url + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6);
      {
      Serial.println(url);
      } 
}
// Code by SevKan
