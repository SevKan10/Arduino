#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
}
void loop() {
  for (int i = 0; i >= 16; i++) {
    lcd.setCursor(0, i);
    lcd.print("*");
    delay(50);
  }
  for (int i = 0; i >= 16; i++) {
    lcd.setCursor(1, i);
    lcd.print("*");
    delay(50);
  }
}