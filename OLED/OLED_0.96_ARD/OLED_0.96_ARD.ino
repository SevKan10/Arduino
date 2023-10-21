#include <EEPROM.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

unsigned long Time;
int count = 6;
String ADMIN;

#define SOS 13   //SOS button
#define SET 14   //ADMIN button
#define Acol 35  //Acol sensor


const unsigned char speed[] PROGMEM = {
  0xff, 0xff, 0xf0, 0xff, 0x6f, 0xf0, 0xf8, 0x61, 0xf0, 0xf0, 0x60, 0xf0, 0xf0, 0x60, 0xf0, 0xd8,
  0xf1, 0xb0, 0x8f, 0xff, 0x10, 0x87, 0xfe, 0x10, 0x0f, 0xff, 0x00, 0x0f, 0xff, 0x00, 0x0f, 0x0f,
  0x00, 0xff, 0x0f, 0xf0, 0x0f, 0x87, 0x00, 0x0f, 0xc3, 0x00, 0x07, 0xe3, 0x00, 0x87, 0xf9, 0x10,
  0x83, 0xfd, 0x90, 0xc7, 0xff, 0x30, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0
};

const unsigned char rate[] PROGMEM = {
  0xff, 0xff, 0xf0, 0xe0, 0xf0, 0x70, 0xce, 0x67, 0x30, 0x9f, 0x9f, 0x90, 0x3f, 0x9f, 0xc0, 0x7f,
  0xff, 0xe0, 0x7f, 0xff, 0xe0, 0x73, 0x9f, 0xe0, 0x73, 0x9f, 0xe0, 0x01, 0x00, 0xc0, 0x8d, 0x60,
  0xd0, 0x9c, 0x7f, 0x90, 0xde, 0xff, 0xb0, 0xef, 0xff, 0x70, 0xf7, 0xfe, 0xf0, 0xf9, 0xf9, 0xf0,
  0xfc, 0xf3, 0xf0, 0xfe, 0x07, 0xf0, 0xff, 0x9f, 0xf0, 0xff, 0xff, 0xf0
};
void setup() {
  Wire.begin(21,19);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Không tìm thấy màn hình OLED"));
    while (true)
      ;
  }

  static float angle = 0.0;
  int radius = 10;
  int centerX = 64;
  int centerY = 32;
  int numDots = 7;

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  display.clearDisplay();
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
  if (millis() - Time >= 2000) {
    for (int i = 0; i < 12; ++i) { ADMIN += char(EEPROM.read(i)); }  //Check ADMIN
    //Serial.print(ADMIN);
    while (ADMIN == 0) {
      display.clearDisplay();
      display.setTextSize(1);
      display.setCursor(0, 0);
      display.println("No ADMIN");
      display.setCursor(0, 10);
      display.println("Press ADMIN button");
      display.display();

      if (digitalRead(SET == 0)) {}
    }
    Time = millis();
  }
}

void loop() {

  display.clearDisplay();
  display.drawBitmap(0, 0, speed, 20, 20, WHITE);
  display.setTextSize(2);
  display.setCursor(50, 0);
  display.print(random(10, 100));

  display.drawBitmap(0, 45, rate, 20, 20, WHITE);
  display.setTextSize(2);
  display.setCursor(50, 45);
  display.print(random(10, 100));
  display.display();

  //     display.clearDisplay();
  //  for ( int i = 0; i < 12; ++i ) { ADMIN += char(EEPROM.read(i)); }
  //   //Serial.print(ADMIN);

  //   while ( ADMIN == 0 ) {
  //     display.setTextSize(1);
  //     display.setCursor(0, 0);
  //     display.println("No ADMIN");
  //     display.setCursor(0, 10);
  //     display.println("Press ADMIN button");
  //     display.display();

  //     if( digitalRead( SET == 0 ) ){ }
  //   }

  // for (int i = 3; i >= 0; i--) {
  //   display.setTextSize(1);
  //   display.setCursor(0, 0);
  //   display.print("Send SOS: ");
  //   display.print(i);
  //   display.display();
  //   delay(1000);
  //   display.clearDisplay();
  // }

  // display.clearDisplay();
  // display.setTextSize(2);
  // display.setCursor(0, 0);
  // display.print("Sent SOS");
  // display.display();
  // delay(3000);
}
