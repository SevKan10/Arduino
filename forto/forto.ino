int a = 13;
int b = 12;

  void setup()
{
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);

}
  void loop()
{
    for(int i=1;i<=3;i++)
    {
      digitalWrite(a,1);
      delay(500);
      digitalWrite(a,0);
      delay(500);
    }
    for(int i=1;i<=10;i++)
    {
      digitalWrite(b,1);
      delay(500);
      digitalWrite(b,0);
      delay(500);
    }

}