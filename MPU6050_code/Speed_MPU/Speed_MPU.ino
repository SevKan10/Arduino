#include <Wire.h>
#include <MPU6050.h>

MPU6050 mpu;

int16_t ax, ay, az; // Gia tốc theo trục x, y, z (int16_t)


int vx, vy, vz; // Vận tốc theo trục x, y, z (km/h)
float v0x, v0y, v0z; // Vận tốc ban đầu theo trục x, y, z (km/h)
unsigned long t0, t1; // Thời gian ban đầu và hiện tại (ms)
float dt;

void setup() {
  Wire.begin();
  mpu.initialize();
  Serial.begin(9600);
  v0x = 0;
  v0y = 0;
  v0z = 0;
  t0 = millis();
}

void loop() {
  mpu.getAcceleration(&ax, &ay, &az);
  ax = ax / 16384.0 * 9.81;
  ay = ay / 16384.0 * 9.81;
  az = az / 16384.0 * 9.81;
  t1 = millis();
  dt = (t1 - t0) / 1000.0 / 3600.0; // Chuyển đổi từ ms sang h
  vx = v0x + ax * dt * 3.6; // Chuyển đổi từ m/s sang km/h
  vy = v0y + ay * dt * 3.6;
  vz = v0z + az * dt * 3.6;
  Serial.print("Vx = ");
  Serial.print(vx);
  Serial.print(" km/h, ");
  Serial.print("Vy = ");
  Serial.print(vy);
  Serial.print(" km/h, ");
  Serial.print("Vz = ");
  Serial.print(vz);
  Serial.println(" km/h");
  v0x = vx;
  v0y = vy;
  v0z = vz;
  t0 = t1;
  delay(100);
}