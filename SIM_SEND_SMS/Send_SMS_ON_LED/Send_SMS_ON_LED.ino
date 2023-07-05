#include <EEPROM.h>

#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3D
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int led = 27;
int ledSOS = 26;
int state = 25;
int button = 18;
int value = 0;
int str2,str3;
String Num = "0866207887";
String val, phone, val2, check, val3,str;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ledSOS, OUTPUT);
  pinMode(state, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial2.begin(9600);
  delay(100);
  Serial2.println("AT");
  delay(200);
  Serial2.println("AT+CMGF=1");
  delay(200);
  Serial2.println("AT+CNMI=1,2,0,0,0");
  delay(200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  for (int i = 15; i > -1; i--) {
    display.setCursor(0, 1);
    display.print("Ready in Second: ");
    display.print(i);
    display.display();
    delay(1000);
    display.clearDisplay();
  }
}

void loop() {
  display.clearDisplay();
  display.setCursor(48, 2);
  display.print("READY");
  display.display();

  digitalWrite(state, 1);
  Serial.println(digitalRead(button));
  value = digitalRead(button);

  if (value == 0) {
    digitalWrite(state, 0);
    display.clearDisplay();
    display.setCursor(48, 2);
    display.print("CALLING...");
    display.display();
    send_SOS();
  } else {
    digitalWrite(state, 1);
    display.clearDisplay();
  }

  if (Serial.available()) {
    Serial2.write(Serial.read());
  }
  if (Serial2.available() > 0) {
    // Serial.println(str.indexOf("#", 0));  //trả về vị trí tìm dc dấu #
    //tách
    str = Serial2.readStringUntil('\n');
    str2 = str.indexOf("#", 0);
    val2 = str.substring(str2 + 2, str2 + 11);  // tách từ vị trí tìm được
    Serial.println(val2);
    String sdt = val2.c_str();
    //ghi
    for (int i = 0; i < sdt.length(); i++) {
      String tach = sdt.substring(i, i + 1);  // tách từng số
      int32_t A = tach.toInt();               // chuyển về kiểu int
      EEPROM.write(i, A);                     //gi vào eeprom
      delay(500);
    }

    check = Serial2.readStringUntil('\n');
    str3 = str.indexOf("+", 7);
    val3 = str.substring(str3 + 2, str3 + 9);  // tách từ vị trí tìm được
    Serial.println(val3);
    String sdt2 = val3.c_str();
    //đọc
    for (int i = 0; i < 10; i++) {
      phone += String(EEPROM.read(i));
      String Num = phone;
      Serial.println(Num);
      delay(500);
    }

    if (sdt2 == Num) {

      val = Serial2.readStringUntil('\n');
      Serial.println(val);
      boolean giatri = val.startsWith("ON");  // Chạy quét chuỗi từ đầu đến cuối xem có ON không
      if (giatri == 1)                        // có thì trả 1 không thì trả 0
      {
        digitalWrite(led, 1);
        display.setCursor(0, 30);
        display.print("LED ON");
        display.display();
        Serial2.println("AT+CMGF=1");
        delay(500);
        Serial2.println("AT+CMGS=\"" + Num + "\"\r");
        delay(500);
        Serial2.println("LED ON");
      }
      boolean giatri1 = val.startsWith("OFF");
      if (giatri1 == 1) {
        digitalWrite(led, 0);
        display.setCursor(0, 30);
        display.print("LED OFF");
        display.display();
        Serial2.println("AT+CMGF=1");
        delay(500);
        Serial2.println("AT+CMGS=\"" + Num + "\"\r");
        delay(500);
        Serial2.println("LED OFF");
      }
      delay(100);
      Serial2.println((char)26);
      delay(1000);
    }
  }
}
