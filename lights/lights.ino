const int led1 =13;
const int led2 =12;
const int led3 =11;
void setup()
{
 Serial.begin(9600);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
}

void loop() 
{
  if (Serial.available())
  {
      char a = Serial.read();
      switch (a)
      {
        case '1':
        Serial.println("I");
        digitalWrite(led1, 1);
        digitalWrite(led2, 0);
        digitalWrite(led3, 0);
        break;
        case '2':
        Serial.println("LOVE");
        digitalWrite(led1, 0);
        digitalWrite(led2, 1);
        digitalWrite(led3, 0);
        break;      
        case '3':
         Serial.println("YOU");
        digitalWrite(led1, 0);
        digitalWrite(led2, 0);
        digitalWrite(led3, 1);
        break;
        
         // default:
        // Serial.println("0 co");
       // digitalWrite(led1, 0);
       //  digitalWrite(led2, 0);
        // digitalWrite(led3, 0); 
         
        
        
      }
    
   }

}


