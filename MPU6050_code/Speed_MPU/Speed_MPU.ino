//Khai báo thư viện
#include <Wire.h>
#include <MPU6050.h>

//Tạo đối tượng MPU6050
MPU6050 mpu;

//Khai báo các biến
float ax, ay, az; //Gia tốc theo trục x, y, z (m/s^2)
float vx, vy, vz; //Vận tốc theo trục x, y, z (km/h)
float v0x, v0y, v0z; //Vận tốc ban đầu theo trục x, y, z (km/h)
unsigned long t0, t1; //Thời gian ban đầu và hiện tại (ms)
float dt; //Khoảng thời gian giữa các lần đọc giá trị (h)

void setup() {
  //Khởi tạo giao tiếp I2C
  Wire.begin();
  //Khởi tạo MPU6050
  mpu.initialize();
  //Kiểm tra kết nối
  Serial.begin(9600);
  Serial.println(mpu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  //Đặt vận tốc ban đầu bằng 0
  v0x = 0;
  v0y = 0;
  v0z = 0;
  //Lấy thời gian ban đầu
  t0 = millis();
}

void loop() {
  //Đọc giá trị thô từ MPU6050
  mpu.getAcceleration(&ax, &ay, &az);
  //Chuyển đổi giá trị thô sang gia tốc theo m/s^2
  ax = ax / 16384.0 * 9.81;
  ay = ay / 16384.0 * 9.81;
  az = az / 16384.0 * 9.81;
  //Lấy thời gian hiện tại
  t1 = millis();
  //Tính toán khoảng thời gian giữa các lần đọc giá trị
  dt = (t1 - t0) / 1000.0 / 3600.0; //Chuyển đổi từ ms sang h
  //Tính toán vận tốc theo km/h
  vx = v0x + ax * dt * 3.6; //Chuyển đổi từ m/s sang km/h
  vy = v0y + ay * dt * 3.6;
  vz = v0z + az * dt * 3.6;
  //In ra giá trị vận tốc
  Serial.print("Vx = ");
  Serial.print(vx);
  Serial.print(" km/h, ");
  Serial.print("Vy = ");
  Serial.print(vy);
  Serial.print(" km/h, ");
  Serial.print("Vz = ");
  Serial.print(vz);
  Serial.println(" km/h");
  //Cập nhật vận tốc và thời gian ban đầu
  v0x = vx;
  v0y = vy;
  v0z = vz;
  t0 = t1;
  //Đợi 100 ms
  delay(100);
}
