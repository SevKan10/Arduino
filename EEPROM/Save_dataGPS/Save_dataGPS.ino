 #include "EEPROM.h"
String lat, lng, lat2;
float Lat = 5.234567;
//float Lng = 105.123456;
String sdt = "0866207887";
void setup() {
  Serial.begin(9600);
}
void loop() {

  char buffer[20];
  dtostrf(Lat, 9, 6, buffer);
  lat = buffer;
  for (int i = 0; i < lat.length(); i++) { EEPROM.write(i, lat[i]); }
  //ghi 
  char buffer2[11];
  for (int i = 0; i < sdt.length(); i++) { EEPROM.write(21 + i, sdt[i]); }

//đọc
  delay(5000);
  for (int i = 0; i < 9; i++) {
    Serial.println(lat2 += char(EEPROM.read(i)));
  lat2="";
  }
  for (int i = 21; i < 32; i++) {
    Serial.println(sdt += char(EEPROM.read(i)));
    sdt="";
  }

  // put your main code here, to run repeatedly:
}