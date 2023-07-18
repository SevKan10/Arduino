#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32_BT"); // Tên của thiết bị Bluetooth
  
  // Đợi cho kết nối Bluetooth
  while (!SerialBT.connected()) {
    delay(100);
  }
}

void loop() {
  if (Serial.available()) {
    char data = Serial.read();
    SerialBT.print(data);
  }
  
  if (SerialBT.available()) {
    char data = SerialBT.read();
    Serial.print(data);
  }
}
