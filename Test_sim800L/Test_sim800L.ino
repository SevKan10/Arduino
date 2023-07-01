#include <SoftwareSerial.h>
#include<SoftwareSerial.h>
SoftwareSerial simSerial(2, 3); 

String ADMIN = "0945964083";            //Số ĐT ADMIN

void setup() {
  
  Serial.begin(9600);
  Serial.println("Test Module SIM800L"); 
  simSerial.begin(9600);
  simSerial.println("AT+CMGF=1");   delay(500);  
  simSerial.println("AT+CNMI=2,2,0,0,0");   delay(500);
  simSerial.println("AT+CMGL=\"REC UNREAD\"");   delay(500);   

 while(simSerial.available())
  {
    String inputString;
    while(simSerial.available()){inputString = simSerial.readString();}
    delay(65);
    Serial.println(inputString);
  }

  simSerial.listen();
  simSerial.println("AT+CMGF=1"); delay(500);
  simSerial.println("AT+CMGS=\"" + ADMIN + "\"\r"); delay(500);
  simSerial.println("SIM OK");
  simSerial.println((char)26); delay(5000);

  simSerial.print (F("ATD"));
  simSerial.print (ADMIN);
  simSerial.print (F(";\r\n"));
  delay(20000);
  simSerial.print (F("ATH"));
  simSerial.print (F(";\r\n"));
  delay(500);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
