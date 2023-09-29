#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int16_t gx, gy, gz; // Góc quay x, y, z (int16_t)

// Khai báo biến tổng cho các góc
float totalGx = 0;
float totalGy = 0;
float totalGz = 0;

void setup() {
  Wire.begin();
  mpu.initialize();
  Serial.begin(9600);
  Serial.println(mpu.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}

void loop() {
  mpu.getRotation(&gx, &gy, &gz);
  // Chuyển đổi góc từ giá trị int16_t sang đơn vị đo góc (độ) bằng cách chia cho 131.0
  float angleX = gx / 131.0;
  float angleY = gy / 131.0;
  float angleZ = gz / 131.0;
  
  // Cộng dồn các góc
  totalGx += angleX;
  totalGy += angleY;
  totalGz += angleZ;

  // In ra giá trị tổng của các góc
  Serial.print("Total Angle X = ");
  Serial.print(totalGx);
  Serial.print(" degrees, ");
  Serial.print("Total Angle Y = ");
  Serial.print(totalGy);
  Serial.print(" degrees, ");
  Serial.print("Total Angle Z = ");
  Serial.print(totalGz);
  Serial.println(" degrees");

  delay(100);
}
