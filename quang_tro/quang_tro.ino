#include <Servo.h>
Servo se;
int b = A0;
boolean val =1;
void setup()
{
  se.attach(6);
  pinMode(b,INPUT);
  Serial.begin(9600);

  
}

void loop()

{
  val=analogRead(b);
  Serial.println(b);
 // delay(1000);
 if (val ==0)
 {
  se.write(80);
 }
 else
 {
   se.write(0);
 }
}
