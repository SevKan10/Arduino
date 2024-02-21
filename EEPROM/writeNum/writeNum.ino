#include <EEPROM.h>

int addr = 0;  // Địa chỉ EEPROM đang ghi
int data = 0;  // Dữ liệu đọc từ Serial

void setup() {
  Serial.begin(9600);
  EEPROM.begin(1024);  // Độ dài thực tế của EEPROM trên Arduino Uno
}

void loop() {
  while (Serial.available() > 0) {
    data = Serial.parseInt();  // Đọc số từ Serial

    // Kiểm tra xem dữ liệu có nằm trong phạm vi 0-255 không
    if (data >= 0 && data <= 255) {
      // Ghi số vào EEPROM
      EEPROM.write(addr, data);

      // In thông báo thành công
      Serial.print("Saved ");
      Serial.print(data);
      Serial.print(" to EEPROM at address ");
      Serial.println(addr);

      // Tăng địa chỉ EEPROM và kiểm tra xem đã đến cuối EEPROM chưa
      addr++;
      if (addr == EEPROM.length()) {
        addr = 0;  // Quay lại đầu EEPROM nếu đã đến cuối
      }
    } else {
      // In thông báo lỗi khi dữ liệu không hợp lệ
      Serial.println("Invalid data. Please enter a number between 0 and 255.");
    }
  }

  delay(5000);
  readData();  // Gọi hàm readData để đọc dữ liệu từ EEPROM
}

void readData() {
  Serial.println("Reading data from EEPROM:");
  for (int i = 0; i < EEPROM.length(); i++) {
    // Đọc dữ liệu từ EEPROM
    data = EEPROM.read(i);

    // In dữ liệu ra Serial Monitor
    Serial.print("Data at address ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(data);
  }

  // Đợi một khoảng thời gian trước khi đọc EEPROM tiếp theo
  delay(500);
}
