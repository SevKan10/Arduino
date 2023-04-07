//Code này các bạn nạp vào chiếc hộp lập phương
#include <MPU6050_tockn.h>
#include <Wire.h>
#include<Servo.h>
Servo se;
unsigned long timer;
char previous;
MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  se.attach(6);
//   timer = millis();
//   pinMode(2, OUTPUT);
//   pinMode(3, INPUT_PULLUP);
 }

void loop() {
  // if(digitalRead(3) == 1) {
  //   digitalWrite(2, HIGH);
  // } else digitalWrite(2, LOW);
  // char lenh = ' ';
  mpu6050.update();
  float x= mpu6050.getAccX();
  float y = mpu6050.getAccY();
  float z = mpu6050.getAccZ();
  if (x < 10 && x > 0 && y < 4 && y > -4){
  Serial.println("up");
   int value = map(x,  0, 10, 0, 180);
   se.write(value);
   Serial.print(value);
  }
else if (x > -10 && x < 0 && y < 4 && y > -4){
  Serial.println("down");
  int value = map(x,  -10, 0, 180, 0);
  se.write(value);
  Serial.print(value);
  }

if (y < 10 && y > 0 && x < 4 && x > -4){
  Serial.println("Right");
  int value = map(y,  0, 10, 0, 180);
  se.write(value);
  Serial.print(value);
  }
else if (y > -10 && y < 0  && x < 4 && x > -4){
  Serial.println("left");
  int value = map(y,  -10, 0, 180, 0);
  se.write(value);
  Serial.print(value);
  }
  // if (trucX > 0.9) {
  //   lenh = 'A';
  //   Serial.println("Trai");
  // } else if (trucX < -0.9) {
  //   lenh = 'B';
  //   Serial.println("Phai");
  // }
  // else if (trucY < -0.9) {
  //   lenh = 'C';
  //   Serial.println("Sau");
  // } else if (trucY > 0.9) {
  //   lenh = 'T';
  //   Serial.println("Truoc");
  // } else if (trucZ > 0.9) {
  //   lenh = 'E';
  //   Serial.println("Tren");
  // } else if (trucZ < -0.9) {
  //   lenh = 'F';
  //   Serial.println("Duoi");
  // }
  // if (previous != lenh) {
  //   timer = millis();
  //   previous = lenh;
  // }
  // if ( (unsigned long) (millis() - timer) > 2000) {
  //   Serial.println(lenh);
  //   timer = millis();
  // }
  // delay(200);
}
