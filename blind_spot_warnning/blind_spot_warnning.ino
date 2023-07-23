const int tR = 5;
const int eR = 6;
const int tL = 12;
const int eL = 11;
int ledR = 10;
int ledL = 9;

void setup() {
  Serial.begin(9600);
  pinMode(tR, OUTPUT);
  pinMode(eR, INPUT);
  pinMode(tL, OUTPUT);
  pinMode(eR, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledL, OUTPUT);
}

void loop() {
  unsigned long duraRight;
  float disRight;
  unsigned long duraLeft;
  float disLeft;
  //Phải
  digitalWrite(tR, 0);
  delayMicroseconds(2);
  digitalWrite(tR, 1);
  delayMicroseconds(5);
  digitalWrite(tR, 0);
  duraRight = pulseIn(eR, 1);
  disRight = int(duraRight / 2 / 29.412);  // giá trị theo hệ cm
  //Trái
  digitalWrite(tL, 0);
  delayMicroseconds(2);
  digitalWrite(tL, 1);
  delayMicroseconds(5);
  digitalWrite(tL, 0);
  duraLeft = pulseIn(eL, 1);
  disLeft = int(duraLeft / 2 / 29.412);  // giá trị theo hệ cm
  //Hiển thị led
  if (disRight <= 100) {
    digitalWrite(ledR, 1);
    digitalWrite(ledL, 0);
  } else {
    digitalWrite(ledR, 0);
    digitalWrite(ledL, 0);
  }
  if (disLeft <= 100) {
    digitalWrite(ledL, 1);
    digitalWrite(ledR, 0);
  } else {
    digitalWrite(ledR, 0);
    digitalWrite(ledL, 0);
  }
  if (disRight <= 100 && disLeft <= 100) {
    digitalWrite(ledL, 1);
    digitalWrite(ledR, 1);
  } else {
    digitalWrite(ledR, 0);
    digitalWrite(ledL, 0);
  }
}
