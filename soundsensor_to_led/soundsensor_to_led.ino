int a=13;
int sensorPin=7;
boolean val=0;

void setup()
{
  pinMode(a,OUTPUT);
  pinMode(sensorPin,INPUT);
 Serial.begin(9600);
}
 // mà bị gì ko nhận thư viện lcd với dht á anh
void loop()

{
  val=digitalRead(sensorPin);
 Serial.println(val);
  if (val == 0)
  {
    digitalWrite(a,1 );
  }
 else
  {
      digitalWrite(a,0 );
 }
} // Code by SevKan
