#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
void setup()
{ 
  
  lcd.init();
  lcd.backlight();
	Serial.begin(9600); //bật serial monitor ở mức baudrate 9600
}
 
void loop()
{
	int value = analogRead(A0); //A0 là chân analogA0 á
	//nếu mà cảm biến rung đang không rung :3 thì giá trị cảm biến nhảy ở khoảng 1022 - 1023 :)
	if (value < 1021){
		Serial.println("Rung");
    lcd.setCursor(0,0);
    lcd.print("rung");
	} else { 
		Serial.println("Khong Rung");
    lcd.print("khong rung");
	}
	
	Serial.print("Gia tri cam bien: ");
	Serial.println(value);
	delay(100); //delay 100 mới thấy được sự thay đổi
}