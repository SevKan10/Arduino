#include<EEPROM.h>

int value1 = 0;
void setup() {
Serial.begin(9600);


}

void loop() {
  int i = 0;
  for(i=0;i=6;i++){
 value1 = EEPROM.read(i);

  }
  Serial.println(value1);
  delay(500);
 
}
