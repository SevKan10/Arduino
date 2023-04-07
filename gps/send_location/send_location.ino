#include <TinyGPS++.h>  
#include <SoftwareSerial.h>  
TinyGPSPlus gps;
#define S_RX 8  
#define S_TX 9  
SoftwareSerial SoftSerial(S_RX, S_TX);  
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
      url = url + String(gps.location.lat(), DEC) + "," + String(gps.location.lng(), DEC);
      {
      Serial.println(url);
      }
    // Serial.print("Google Maps URL: https://www.google.com/maps/place/");
    // Serial.print(gps.location.lat(), 7);
    // Serial.print(",");
    // Serial.println(gps.location.lng(), 7);
 
}
// Code by SevKan
