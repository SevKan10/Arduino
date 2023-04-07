int a=13;
 void setup()
{
  int i=0;// thì i sẽ tính luôn 0, i=1 thì i đếm từ 1
    while(i<=5)
    {
      digitalWrite(a,1);
      delay(3000);
      digitalWrite(a,0);
      delay(3000);
      i++;
    }
}
 void loop()
{
  
}