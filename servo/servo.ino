#include<Servo.h>
Servo myServo;
Servo myServo1;
int pos = 0;
void setup() 
{
  myServo.attach(6);
  Serial.begin(9600);

}

void loop() 
{
  for(pos=1;pos<=180;pos++)
  {
     Serial.println(pos);
     myServo.write(pos);
     delay(30);
  }   
    for(pos=180;pos>=0;pos--)
  {
     Serial.println(pos);
     myServo.write(pos);
     delay(30);
  }   


}
