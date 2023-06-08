#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
 
void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // Địa chỉ I2C của màn hình (thường là 0x3C)
  display.display();
  delay(2000);  // Delay để cho màn hình khởi động
  display.clearDisplay();
}
 
void loop() {
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hello tao is Khang");
  display.display();
  delay(1000);
  display.clearDisplay();
  delay(1000);
}
