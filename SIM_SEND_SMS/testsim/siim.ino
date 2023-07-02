void SOS(){
      digitalWrite(ledCall,1);
  display.clearDisplay();
  display.setCursor(48,2);
  display.print("CALLING...");
  display.display();
  Serial2.println("AT+CMGF=1");
   updateSerial();
  Serial2.println("AT+CMGS=\"" + numberPhone + "\"\r");
  updateSerial();
  Serial2.print("HELP ME!");
  Serial2.print("http://maps.google.com/maps?z=18&q=");
  Serial2.print(Lat,6);Serial2.print(",");Serial2.print(Lng,6);
  updateSerial();
  Serial2.write(26);
  delay(5000);
  Serial2.print(F("ATD"));
  Serial2.print(numberPhone);
  Serial2.print(F(";\r\n"));
  delay(20000);
  Serial2.print(F("ATH"));
  Serial2.print(F(";\r\n"));
  delay(500);
      digitalWrite(ledCall,0);


}
void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    Serial.write(Serial.read());
  }

}