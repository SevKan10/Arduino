int led = 13;
int sensor = 2;
int sensor1 = 3;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop() {
 Serial.print("Tín hiệu Analog:  ");
 Serial.print(analogRead(sensor)); 
 Serial.print("   |   Tín hiệu Digital:  ");
 Serial.println(digitalRead(sensor1));
 delay(250);
 int value = analogRead(sensor);   /// từ 0-180 thì là không khí, từ khảng 180 trở lên là khí gas
 int value1 = digitalRead(sensor1);
 if ((value>200) || (value1==0) ){
   digitalWrite(led,1);
   Serial.println("CÓ KHÍ GAS ");
   delay(1250);
 }
 else {
   digitalWrite(led,0);
 }


}
