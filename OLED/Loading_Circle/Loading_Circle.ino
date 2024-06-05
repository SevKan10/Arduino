#include <EEPROM.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

static float angle = 0.0;
int radius = 15;
int centerX = 64;
int centerY = 32;
int numDots = 7;

unsigned long Time;
int button = 13;
String ADMIN = "";
int count = 6;
void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  Wire.begin(21, 19);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Không tìm thấy màn hình OLED"));
    while (true)
      ;
  }
  Serial.println("Booting time...");
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(23, 8);
  display.println("WELCOME");
  display.display();
  delay(3000);
  display.clearDisplay();

  for (int i = 200; i >= 0; i--) {
    display.setTextSize(1);
      display.setCursor(0, 0);
    display.println("SMART HELMET BOOTING");

    for (int i = 0; i < numDots; i++) {
      display.setTextSize(2);
      float dotAngle = radians(angle + i * 360.0 / numDots);
      int x = centerX + radius * cos(dotAngle);
      int y = centerY + radius * sin(dotAngle);
      display.drawPixel(x, y, SSD1306_WHITE);
    }

    angle += random(5, 15);  //Tốc độ quay
    if (angle >= 360.0) {
      angle = 0.0;
    }

    display.display();
    delay(50);
    display.clearDisplay();
  }

  if (millis() - Time >= 2000) {
    for (int i = 0; i < 12; ++i) {
      ADMIN += char(EEPROM.read(i));  //Check ADMIN
    }
    Serial.println(ADMIN);
    while (ADMIN == "") {  // Thay đổi điều kiện này
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.println("No ADMIN");
      display.setCursor(0, 10);
      display.println("Press ADMIN button");
      display.display();
      delay(500);
      if (digitalRead(button) == 0) {
        while (digitalRead(button) == 0) {
          count--;
          display.clearDisplay();
          display.setTextSize(1);
          display.setCursor(35, 16);
          display.print("Waitting: ");
          display.print(count);
          display.display();
          delay(1000);
          if (count <= 0) {
            display.clearDisplay();
            display.setTextSize(2);
            display.setTextColor(SSD1306_WHITE);
            display.setCursor(23, 8);
            display.println("WELCOME");
            display.display();
            delay(2000);  // Hiển thị "WELCOME" trong 2 giây
          }
        }
        if (digitalRead(button) == 1) { count = 6; }
      }
    }
  }

  Time = millis();
}


void loop() {
}
