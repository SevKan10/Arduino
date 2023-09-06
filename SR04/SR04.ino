const int trig = 26;
const int echo = 25;
int buzzer = 2;
int interval = 100; // Thời gian chờ ban đầu ngắn hơn
int maxInterval = 10000; // Thời gian chờ tối đa

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  unsigned long duration;
  int distance;

  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH);
  distance = int(duration / 2 / 29.412);

  Serial.print(distance);
  Serial.println("cm");
  delay(200);
}
