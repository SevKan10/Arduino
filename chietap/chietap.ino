#include<Servo.h>
Servo se1;
void setup()
{
  Serial.begin(9600);
  se1.attach(6);
}

void loop()
{
  int val = analogRead(A0);//val nằm trong 0 1203
 // Serial.println(val);
  int gtr = map(val, 0,1023, 0,180);
  Serial.println(gtr);
  se1.write(gtr);
  delay(20);
}
