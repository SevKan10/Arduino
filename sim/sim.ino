#include <SoftwareSerial.h>

//Create software serial object to communicate with SIM800L
SoftwareSerial simSerial(2,3); //SIM800L Tx & Rx is connected to Arduino #3 & #2
String ADMIN= "0332473716";
void setup()
{
  Serial.begin(9600);
  Serial.print("OK");
  simSerial.begin(9600); 
  simSerial.println("AT+CMGF=1");   delay(500);  
  simSerial.println("AT+CNMI=2,2,0,0,0");   delay(500);
  simSerial.println("AT+CMGL=\"REC UNREAD\"");   delay(500); 

 String inputString;
    while(simSerial.available()){inputString = simSerial.readString();}
    delay(65);
    Serial.println(inputString);


  // updateSerial();
  // simSerial.listen();
  // simSerial.println("AT+CMGF=1"); delay(500);//gửi sms
  // simSerial.println("AT+CMGS=\"" + ADMIN + "\"\r"); delay(500);
  // simSerial.println("Help me!");
  // simSerial.println((char)26); delay(5000);

  // simSerial.print (F("ATD"));
  // simSerial.print (ADMIN);
  // simSerial.print (F(";\r\n"));
  // delay(20000);
  // simSerial.print (F("ATH"));
  // simSerial.print (F(";\r\n"));
  // delay(500);

}

void loop()
{
}

void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    simSerial.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(simSerial.available()) 
  {
    Serial.write(simSerial.read());//Forward what Software Serial received to Serial Port
  }
}