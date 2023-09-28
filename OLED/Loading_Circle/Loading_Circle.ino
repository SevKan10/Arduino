#include <EEPROM.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);


static float angle = 0.0;
int radius = 20;
int centerX = 64;
int centerY = 32;
int numDots = 7;
void setup() {
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Không tìm thấy màn hình OLED"));
    while (true)
      ;
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(23, 8);
  display.println("WELCOME");
  display.display();
  delay(3000);
  display.clearDisplay();
  // for (int i = 200; i >= 0; i--) {
  //   display.setTextSize(1);
  //   display.setCursor(0, 0);
  //   display.println("SMART HELMET BOOTING");
  //   delay(1000);
  // }
}
void loop() {
  for (int i = 0; i < numDots; i++) {

    float dotAngle = radians(angle + i * 360.0 / numDots);
    int x = centerX + radius * cos(dotAngle);
    int y = centerY + radius * sin(dotAngle);

    display.drawPixel(x, y, SSD1306_WHITE);
  }
  angle += 15.0;  //Tốc độ quay
  if (angle >= 360.0) {
    angle = 0.0;
  }
  display.display();
  delay(50);
  display.clearDisplay();
}

