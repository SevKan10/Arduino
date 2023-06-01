void read(){
  // Đọc dữ liệu từ EEPROM
  data = EEPROM.read(addr);

  // In dữ liệu ra Serial Monitor
  Serial.print("Data at address ");
  Serial.print(addr);
  Serial.print(": ");
  Serial.println(data);

  // Tăng địa chỉ EEPROM và kiểm tra xem đã đến cuối EEPROM chưa
  addr++;
  if (addr == EEPROM.length()) {
    addr = 0;  // Quay lại đầu EEPROM nếu đã đến cuối
  }

  // Đợi một khoảng thời gian trước khi đọc EEPROM tiếp theo
  delay(500);
}