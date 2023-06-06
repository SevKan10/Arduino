


void setup() {
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,1);
  delay(2000);
  digitalWrite(13,0);
  delay(1000);

 //digitalWrite(led, (millis()/1000)%2);


}
