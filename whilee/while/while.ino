#include<Servo.h>
Servo a;
int pos = 0;
void setup()
{
  a.attach(6);
  Serial.begin(9600);
}

void loop() 
{
  pos=0;
  while(pos<=180)
  {
    pos++;
    Serial.println(pos);
    a.write(pos);
    delay(30);
  }
  while(pos>=1)
  {
    pos--;
    Serial.println(pos);
    a.write(pos);
    delay(30);
  }
}
