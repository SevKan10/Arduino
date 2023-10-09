#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

float Ax, Ay, Az;
float avg, a, v;
unsigned long t1, t0, t;
void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);

  t0 = millis();
}

void loop() {
  mpu6050.update();

  Ax = mpu6050.getAccX();
  Ay = mpu6050.getAccY();
  Az = mpu6050.getAccZ();

  avg = sqr(Ax) + sqr(Ay) + sqr(Az);

  a = sqrt(avg) / 16384.0 * 9.81;  // m/s^2


  t1 = millis();
  t = (t1 - t0) / 1000;  //Giây

  v = (a * t) * 3.6;  // Km/h
  
  Serial.println(v);
  delay(500);
}
