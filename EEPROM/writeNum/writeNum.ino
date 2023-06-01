#include <EEPROM.h>

int addr = 0;  // Địa chỉ EEPROM đang ghi
int data = 0;  // Dữ liệu đọc từ Serial

void setup() {
  Serial.begin(9600);
}

void loop() {
  while(Serial.available() > 0) {
    data = Serial.parseInt();  // Đọc số từ Serial

    // Ghi số vào EEPROM
    EEPROM.write(addr, data);

    // Tăng địa chỉ EEPROM và kiểm tra xem đã đến cuối EEPROM chưa
    addr++;
    if (addr == EEPROM.length()) {
      addr = 0;  // Quay lại đầu EEPROM nếu đã đến cuối
    }

    // In thông báo thành công
    Serial.println("Saved to EEPROM.");
  }
  delay(5000);
  //read();
}
