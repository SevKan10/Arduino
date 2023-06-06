
byte button = 3;
byte led = 13;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(button,INPUT_PULLUP);

}

void loop() {
  Serial.print("Giá trị nút nhấn:  ");
  Serial.println(digitalRead(button));
  delay(200);
  byte state = digitalRead(button);

    if (state == 1){
      digitalWrite(led,1); 
    }
    else{
      digitalWrite(led,0);
    }

}
