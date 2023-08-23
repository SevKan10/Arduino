String ADMIN = "0866235503";            //Số ĐT ADMIN

void setup() {
  
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial.println("Test Module SIM800L"); 
  Serial2.begin(9600);
  Serial2.println("AT+CMGF=1");   delay(500);  
  Serial2.println("AT+CNMI=2,2,0,0,0");   delay(500);
  Serial2.println("AT+CMGL=\"REC UNREAD\"");   delay(500);   

 while(Serial2.available())
  {
    String inputString;
    while(Serial2.available()){inputString = Serial2.readString();}
    delay(65);
    Serial.println(inputString);
  }

  Serial2.println("AT+CMGF=1"); delay(500);
  Serial2.println("AT+CMGS=\"" + ADMIN + "\"\r"); delay(500);
  Serial2.println("SIM OK");
  Serial2.println((char)26); delay(5000);

  Serial2.print (F("ATD"));
  Serial2.print (ADMIN);
  Serial2.print (F(";\r\n"));
  delay(20000);
  Serial2.print (F("ATH"));
  Serial2.print (F(";\r\n"));
  delay(500);
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
