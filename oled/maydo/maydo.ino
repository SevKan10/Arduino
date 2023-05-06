#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#include <Adafruit_MLX90614.h>
#define led 6
#define buz 5
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
#define LOGO16_GLCD_HEIGHT 16
#define LOGO16_GLCD_WIDTH  16
int i = 0;
float a;
static const unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000
};

#if (SSD1306_LCDHEIGHT != 64)

#endif

void setup()   {
  Serial.begin(9600);
  digitalWrite(buz,  HIGH);
  pinMode(7, INPUT_PULLUP);
  pinMode( led, OUTPUT);
  pinMode(buz, OUTPUT);
  mlx.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  macdinh();
  moikhach();
  digitalWrite(led,  LOW);
}
void loop() {
  if (digitalRead(7)  == 0) {
    display.clearDisplay();
    a = mlx.readObjectTempC();
    if (i == 0) {
      donhiet();
      if (a > 37) {
        digitalWrite(led, HIGH);
        digitalWrite(buz, LOW);
      }
      i = 1;
    } else {
      digitalWrite(led, LOW);
      digitalWrite(buz,  HIGH);
      macdinh();
      moikhach();
      i = 0;
    }
  }
}
void macdinh() {
  display.clearDisplay();
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(14, 6);
  display.clearDisplay();
  display.println("KENH SANG TAO TRE");
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(14, 18);
  display.println("MAY DO THAN NHIET");
  display.display();
  delay(3000);
  display.clearDisplay();
}
void donhiet() {
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(10, 0);
  display.println("THAN NHIET CUA BAN:");
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(50, 12);
  display.println(a + 1.2);
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(35, 25);
  display.println("XIN CAM ON");
  display.display();
  delay(300);
}
void moikhach() {
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(14, 6);
  display.println("KENH SANG TAO TRE");
  display.display();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(2, 18);
  display.println("MOI BAN DO THAN NHIET");
  display.display();
}
