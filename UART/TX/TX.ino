#define rx 12 ;
#define tx 13 ;

void setup() {
  Serial.begin(9600); // Khởi tạo kết nối Serial
}

void loop() {
  String data = "Hello from Arduino"; // Dữ liệu bạn muốn gửi
  Serial.println(data); // Gửi dữ liệu qua cổng Serial
  delay(1000); // Đợi 1 giây
}
