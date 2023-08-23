const int alcoholSensorPin = A0; // Chân analog dùng để đọc tín hiệu nồng độ cồn
int alcoholValue = 0; // Biến lưu trữ giá trị đọc được từ cảm biến

void setup() {
  Serial.begin(9600); // Bắt đầu giao tiếp Serial để hiển thị giá trị trên Serial Monitor
}

void loop() {
  alcoholValue = analogRead(alcoholSensorPin); // Đọc giá trị analog từ cảm biến
  float voltage = (alcoholValue / 1023.0) * 5.0; // Chuyển giá trị analog sang điện áp (0-5V)

  // In giá trị nồng độ cồn lên Serial Monitor
  Serial.print("Nồng độ cồn: ");
  Serial.print(voltage); // In điện áp
  Serial.println(" V");

  delay(1000); // Chờ 1 giây trước khi đọc lại giá trị
}
