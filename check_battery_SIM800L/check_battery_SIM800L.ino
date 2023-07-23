#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

String batteryCapacity = "";
unsigned long Time;
int Num;
void setup() {
  Serial.begin(9600);
  Serial2.begin(9600);
  delay(2000);

  Wire.begin();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("Không tìm thấy màn hình OLED"));
    while (true)
      ;
  }
  display.clearDisplay();
}

void loop() {
  if (millis() - Time >= 5000) {
    Serial2.println("AT+CBC");
    delay(1000);

    while (Serial2.available()) {
      char c = Serial2.read();
      //Serial.write(c);
      if (c == '+') {
        String read1 = Serial2.readStringUntil('\n');
       Serial.println(read1);
        int read2 = read1.indexOf(",");
        batteryCapacity = read1.substring(read2 + 1, read2 + 4);
        Num = batteryCapacity.toInt();
       // Serial.println(batteryCapacity);
      }
    }
    display.clearDisplay();
    display.setCursor(0, 20);
    display.print("Battery: ");
    display.print(Num);
    display.print("%");
    display.display();
    Time = millis();
  }
}
