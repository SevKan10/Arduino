#define LED 2

void setup() {
  // Set pin mode
  pinMode(LED,OUTPUT);
}

void loop() {
  delay(2000);
  digitalWrite(LED,HIGH);
  delay(500);
  digitalWrite(LED,LOW);
}