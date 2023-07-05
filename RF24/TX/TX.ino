#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "2210";
unsigned long time;
 

void setup() {
  Serial.begin(9600);
  radio.begin();
  if (!radio.begin()) {Serial.print("RF DON'T START");}
  if (radio.begin()) {Serial.print("RF START");}
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setChannel(2);
  radio.setDataRate(RF24_250KBPS);


void loop() {
  if (millis() - time >1000)
  {
    int data1 = 123;
    radio.write(&data1, sizeof(data1));
    Serial.print("Sent data:\t");Serial.print(data1);
    time = millis();
  }  

}
