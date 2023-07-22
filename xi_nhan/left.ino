void Left() {
  digitalWrite(right, 0);
  digitalWrite(off, 0);
  Serial.println("Turn Left");
  digitalWrite(left, 1);
}