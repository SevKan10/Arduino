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
String Num = "0866207887";
String val;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(ledSOS, OUTPUT);
  pinMode(state, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial2.begin(9600);
  delay(100);
  Serial2.println("AT");
  Serial2.println("AT+CMGF=1");
  Serial2.println("AT+CNMI=1,2,0,0,0");
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
