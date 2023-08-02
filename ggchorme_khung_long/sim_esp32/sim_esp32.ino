#define button 18
#define gr  26
#define red 27
#define ye 25
boolean val = 0;
void setup() {
  pinMode(button,INPUT_PULLUP);
  pinMode(gr,OUTPUT);
  pinMode(red,OUTPUT);
  pinMode(ye,OUTPUT);
  Serial.begin(9600);
  Serial2.begin(9600);
  Serial.println("Ready is:");
  for(int i=15;i>-1;i--){
    Serial.println(i);
  }
}
void updateSerial()
{
  delay(500);
  while (Serial.available())
  {
    Serial2.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while (Serial2.available())
  {
    Serial.write(Serial2.read());//Forward what Software Serial received to Serial Port
  }
}

void loop() {
  updateSerial();updateSerial();
  val = digitalRead(button);
  val = val*0;
  digitalWrite(red,1);

 if (val== 1){
  digitalWrite(red,0);
  digitalWrite(gr,1);
  send_SMS();
   val = 1;
   val++;
 }



  }


