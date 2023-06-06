byte buttonPin = 3;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  byte state = digitalRead(buttonPin);
  Serial.println(state);
  delay(200);
}
