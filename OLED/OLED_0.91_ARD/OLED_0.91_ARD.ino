#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {
  Wire.begin();
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Không tìm thấy màn hình OLED"));
    while (true);
  }
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("Hello");
  display.display();
  delay(3000);
}

void loop() {
 /* display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("80 pbm");
  display.display();
  delay(5000);
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("90 spo");
  display.display();
  delay(5000);*/

   for (int x = 0; x < 128; x++) {
    display.clearDisplay();
    display.setCursor(x,8);
    display.print("80 pbm");
    display.display();
    delay(10);
  }
  
   for (int x = 0; x < 128; x++) {
    display.clearDisplay();
    display.setCursor(x,8);
    display.print("90 spo");
    display.display();
    delay(10);
  }

}
