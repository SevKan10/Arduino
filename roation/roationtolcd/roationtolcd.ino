#include<Wire.h>
#include<LiquidCrystal_I2C.h>
  const int LED = 13;
  void setup()
  {
   LiquidCrystal_I2C lcd(0x27,16,2); // 0x27 is the I2C bus address for an unmodified backpack
    lcd.init();
    lcd.backlight();
    Serial.begin(9600); //bật serial monitor ở mức baudrate 9600
    pinMode( LED, OUTPUT);
  }
  
  void loop()
  { 
    LiquidCrystal_I2C lcd(0x27,16,2); // 0x27 is the I2C bus address for an unmodified backpack
    int value = analogRead(A0); //A0 là chân analogA0 á
    //nếu mà cảm biến rung đang không rung :3 thì giá trị cảm biến nhảy ở khoảng 1022 - 1023 :)
    if (value < 1021){
      Serial.println("Rung");
      digitalWrite(LED, HIGH);
      lcd.setCursor(0,0);
      lcd.print("rung");
     
    } else { 
      Serial.println("Khong Rung");
      digitalWrite(LED,LOW);
        lcd.setCursor(0,0);
      lcd.print(" ko rung");
      lcd.clear();
    }
    
    Serial.print("Gia tri cam bien: ");
    Serial.println(value);
    delay(500);
    //delay 100 mới thấy được sự thay đổi
  
}