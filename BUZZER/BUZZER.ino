int interval = 100;

void setup() {
  pinMode(D8, OUTPUT);
}

void loop() {
  
  while (interval > 0) {
    digitalWrite(D8, HIGH);
    delay(interval);
    digitalWrite(D8, LOW);
    delay(interval);
    interval -= 10;  // Giảm thời gian chờ giữa các âm thanh
  }
}
