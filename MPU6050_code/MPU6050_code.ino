#include <MPU6050_tockn.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
MPU6050 mpu6050(Wire);
LiquidCrystal_I2C lcd (0x27,16,2);
int addr=0;
void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
 }

void loop() 
{

  mpu6050.update();
  float x= mpu6050.getAccX();
  float y = mpu6050.getAccY();
  float z = mpu6050.getAccZ();
  
    if (mpu6050.getAccY() !=0)
  {
    Serial.print("x: "); Serial.print(x);
  Serial.print("\ty: "); Serial.print(y);
  Serial.print("\tz: "); Serial.println(z);
  delay(500);
  if (y>0.90)
  {
    Serial.println("xe bi nga ");
  }
    lcd.setCursor(0,0);
    lcd.print("y: ");lcd.print(y);
  }
  else
  {
    EEPROM.write(addr,x);
 //   Serial.print(addr);
    addr++;
    if (addr == 1024)
    addr = 0;

  delay(5);
  }
}
