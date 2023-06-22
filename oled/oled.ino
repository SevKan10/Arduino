#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_SDA 21   
#define OLED_SCL 22  
 #define OLED_RESET 4 
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.println("Hello World!");
  display.display();
}

void loop() {
}