#include <EEPROM.h>
String PW ="";
void setup() {
  // Khởi tạo Serial Monitor
  Serial.begin(9600);
  EEPROM.begin(16); 
  
  // Reset EEPROM
  resetEEPROM();
}

void loop() {
  // Không cần thực hiện bất kỳ hành động nào trong loop()
}

void resetEEPROM() {
  // Ghi giá trị 0 vào tất cả các địa chỉ trong EEPROM
  for (int i = 0; i < 4; i++) {
    EEPROM.write(i, 0);
  }

  Serial.println("EEPROM đã được reset.");
  for (int i = 0; i < 4; ++i){PW += char(EEPROM.read(i)); Serial.println(PW.toInt()); }

}
