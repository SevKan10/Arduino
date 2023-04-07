void setup()
{
  Serial.begin(9600);
  pinMode(6,OUTPUT);

}

void loop() 
{
  int val = analogRead(A0);
  int dosang = map(val, 0,1023, 0,225);
  Serial.println(dosang);
  analogWrite(6,dosang);
}     