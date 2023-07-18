
const int trig = 25;
const int echo = 26;
void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  unsigned long duration;
  float distance;

  digitalWrite(trig, 0);
  delayMicroseconds(2);
  digitalWrite(trig, 1);
  delayMicroseconds(5);
  digitalWrite(trig, 0);

  duration = pulseIn(echo, 1);
  distance = int(duration / 2 / 29.412);
  Serial.print(distance);
  Serial.print("cm");
  Serial.print("\t");
  float m = distance / 100;
  Serial.print(m);
  Serial.println("m");
  delay(100);
}
