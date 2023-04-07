         #include <Servo.h>
int a=13;
int sensorPin=7;
boolean val=0;
Servo se;

void setup()
{ 
  se.attach(6);
  pinMode(a,OUTPUT);
  pinMode(sensorPin,INPUT);
 Serial.begin(9600);
}
 // mà bị gì ko nhận thư viện lcd với dht á anh
void loop()

{
  int pos =180;
  val=digitalRead(sensorPin);
 Serial.println(val);
  if (val == 0)
  {
    int pos =50;
    se.write(pos);
    digitalWrite(a,1 );
  }
 else
  {   
      se.write(0);
      digitalWrite(a,0 );
 }
} // Code by SevKan
