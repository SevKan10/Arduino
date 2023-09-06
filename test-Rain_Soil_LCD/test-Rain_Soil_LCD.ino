#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

int soilSensor = 35;
int rainSensor = 0;
boolean scrClear = 0;

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 0);
  lcd.print("Creative KIDS");
  lcd.setCursor(2, 1);
  lcd.print("Sang tao tre");
  delay(3000);
  lcd.clear();
}

void loop() {
  int stateSoil = analogRead(soilSensor);
  int stateRain = analogRead(rainSensor);

  Serial.print("Soil Level:\t");
  Serial.println(stateSoil);
  Serial.print("Rain Level:\t");
  Serial.println(stateRain);
  Serial.println("=====================");
  delay(500);

  if (stateRain < 1000 || stateSoil < 1000 || stateRain < 100 || stateSoil < 100 || stateRain < 10 || stateSoil < 10) {
    if (!scrClear) {
      lcd.clear();
      scrClear = 1;
    }
    lcd.setCursor(0, 0);
    lcd.print("Soil: ");
    lcd.print(stateSoil);
    lcd.setCursor(0, 1);
    lcd.print("Rain: ");
    lcd.print(stateRain);
  } else {
    scrClear = 0;
    lcd.setCursor(0, 0);
    lcd.print("Soil: ");
    lcd.print(stateSoil);
    lcd.setCursor(0, 1);
    lcd.print("Rain: ");
    lcd.print(stateRain);
  }
}
