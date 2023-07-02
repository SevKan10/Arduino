int led = 12;
String val;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  Serial2.begin(9600);
  delay(100);
  Serial2.println("AT");
  Serial2.println("AT+CMGF=1");
  Serial2.println("AT+CNMI=1,2,0,0,0");
}

void loop() {
  if (Serial.available()) {
    Serial2.write(Serial.read());
  }
  if (Serial2.available() > 0) {
    val = Serial2.readStringUntil('\n');
    Serial.println(val);
    boolean giatri = val.startsWith("ON");
    if (giatri == 1) {
      Serial2.println("AT+CMGF=1");
      delay(1000);
      Serial2.println("AT+CMGS=\"0866207887\"\r");
      delay(1000);
      Serial2.println("LED ON");
    }
    boolean giatri1 = val.startsWith("OFF");
    if (giatri1 == 1) {
      Serial2.println("AT+CMGF=1");
      delay(1000);
      Serial2.println("AT+CMGS=\"0866207887\"\r");
      delay(1000);
      Serial2.println("LED OFF");
    }
    delay(100);
    Serial2.println((char)26);
    delay(1000);
  }
}
