#include <EEPROM.h>

int addr = 0;  // Địa chỉ EEPROM mà ta sẽ lưu đầu tiên
float Lat = 5.109232;
float Lng = 105.233548;
long val1, val2;
String lat, lng;
int a1[7];
int a2[9];

void setup(void) {
  Serial.begin(9600);
}

void loop() {
  val1 = Lat * 1000000;
  val2 = Lng * 1000000;
  delay(500);

  // Ghi từng chữ số của val1 vào mảng a1
  int k = 0;
  while (val1 != 0) {
    a1[k] = val1 % 10;
    val1 = val1 / 10;
    k++;
  }
    int h = 0;
  while (val2 != 0) {
    a2[h] = val2 % 10;
    val2 = val2 / 10;
    h++;
  }

  // Lưu từng chữ số vào EEPROM
  for (int i = k - 1; i >= 0; i--) {
    EEPROM.write(addr, a1[i]);
    addr++;
    delay(50);
    Serial.println(a1[i]);
    if (addr == 6)
      addr = 7;
  }
  for (int i = h - 1; i >= 0; i--) {
    EEPROM.write(addr, a2[i]);
    addr++;
    delay(50);
    Serial.println(a2[i]);
    if (addr == 9)
      addr = 0;
  }
}
