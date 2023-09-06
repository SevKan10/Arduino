String ADMIN = "0866235503";  //Số ĐT ADMIN
#define button
void setup() {
  pinMode(button, INPUT_PULLUP);
  Serial.begin(9600);
  Serial.println("Test Module SIM7680CE");
  for (int i = 15; i > -2; i--) {
    Serial.println(i);
    delay(1000);
  }
  lcd.clear();
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
  Serial2.println("AT+CMGF=1");
  delay(100);
  Serial2.println("AT+CNMI=2,2,0,0,0");
  delay(100);
  Serial2.println("AT+CMGL=\"REC UNREAD\"");
  delay(100);
  Serial2.println("AT+CMGD=1,4");
  delay(100);

  //   Serial2.println("AT+CMGF=1"); delay(500);
  //  Serial2.println("AT+CMGS=\"" + ADMIN + "\"\r"); delay(500);
  //  Serial2.println("SIM OK");
  //  Serial2.println((char)26); delay(5000);
  //
}

void loop() {
  while (Serial2.available()) {
    String inputString;
    while (Serial2.available()) { inputString = Serial2.readString(); }
    Serial.println(inputString);
  }

  while (Serial.available()) {
    Serial2.println(Serial.readString());
  }

  boolean state = digitalRead(button);
  Serial.println(state);
  if (state == 0) {
    Serial2.print(F("ATD"));
    Serial2.print(ADMIN);
    Serial2.print(F(";\r\n"));
    delay(20000);
    Serial2.print(F("ATH"));
    Serial2.print(F(";\r\n"));
    delay(500);
  }
}
