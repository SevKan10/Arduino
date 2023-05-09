
#include <EEPROM.h>
int addr = 0;  //địa chỉ EEPROM mà ta sẽ lưu đầu tiên

#include <TinyGPS++.h>  // Include TinyGPS++ library

#include <SoftwareSerial.h>  // Include software serial library

TinyGPSPlus gps;

#define S_RX 8  // Define software serial RX pin

#define S_TX 9  // Define software serial TX pin
int Lat, Lng = 0;
String lt, lg;
SoftwareSerial SoftSerial(S_RX, S_TX);
void setup(void) {

  Serial.begin(9600);

  SoftSerial.begin(9600);
}

void loop() {



  while (SoftSerial.available() > 0) {

    if (gps.encode(SoftSerial.read())) {

      if (gps.location.lat() == 0) {
        Lat = lt.toInt();
        Lng = lg.toInt();
      }
      if (gps.location.lat() != 0) {

        //Serial.print("Latitude   = ");

        //Serial.println(gps.location.lat(), 6);
        EEPROM.write(Lat, (gps.location.lat(), 6));
        Lat++;
        if (Lat == 512)
          Lat = 0;
        delay(5);
        Serial.print(Lat);

        Serial.println(gps.location.lng(), 6);
        EEPROM.write(Lng, (gps.location.lng(), 6));
                Serial.print(Lng);
        Lng++;
        if (Lng == 512)
          Lng = 0;
        delay(5);
      }
    }
  }  
}