#define rx 12 ;
#define tx 13 ;

  // put your main code here, to run repeatedly:
void setup() {
  Serial.begin(9600); // Khởi tạo kết nối Serial
}

void loop() {
  if (Serial.available()) { // Kiểm tra xem có dữ liệu đến không
    String data = Serial.readString(); // Đọc dữ liệu từ cổng Serial
    Serial.print("Received data: ");
    Serial.println(data); // In ra dữ liệu nhận được
  }
}


