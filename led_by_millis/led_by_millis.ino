void setup() {
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

 digitalWrite(13, (millis()/1000)%2);


}
