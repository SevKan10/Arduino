// Code : Đỗ Hữu Toan
#include <Wire.h>;
#include <LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27,16,2);
//0x27 là địa chỉ màn hình trong bus I2C. Phần này chúng ta không cần phải quá bận tâm vì hầu hết màn hình (20x4,...) đều như thế này!
//16 là số cột của màn hình (nếu dùng loại màn hình 20x4) thì thay bằng 20
//2 là số dòng của màn hình (nếu dùng loại màn hình 20x4) thì thay bằng 4
byte traitim[8]={
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B00000,
  B00000
}; // Cái này là tạo hình trái tim...đoạn này tham khảo của Thạc Sĩ Huỳnh Minh Phú đó cá

void setup(){
lcd.init();       //Khởi động màn hình. Bắt đầu cho phép Arduino sử dụng màn hình
lcd.backlight();   //Bật đèn nền
lcd.createChar(1, traitim);
}
void loop()
{
  lcd.setCursor(3,0);
  lcd.write(1);
  lcd.setCursor(4,0);
  lcd.write(1);
  lcd.setCursor(5,0);
  lcd.write(1);
  lcd.setCursor(6,0);
  lcd.write(1);

}