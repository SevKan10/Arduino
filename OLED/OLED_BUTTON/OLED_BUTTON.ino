#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

int button = 2;
int press = 0;
void setup() {
  Serial.begin(9600);
  pinMode(button,INPUT_PULLUP);

}

void loop() {
  if (button = 0){press=press++;}
  switch(press){
    case 1:  
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("80 pbm");
  display.display();
    case 2:
  display.clearDisplay();
  display.setTextSize(3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);
  display.println("90 spo");
  display.display();
    case 3:
    press=0;
  }
}
