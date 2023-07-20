#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "01234";
int receivedData1;
int led = 7;  

void setup() {
  Serial.begin(9600);
  radio.begin();
  if (!radio.begin()) {Serial.println("RF Don't Start!");}
  if (radio.begin()) {Serial.println("RF Start!");}
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setChannel(2);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

}

void loop() {
  while (radio.available()) {
    radio.read(&receivedData1, sizeof(receivedData1));
    Serial.print("Received data:  ");
    Serial.println(receivedData1);    
    digitalWrite(led, receivedData1);
  }
}
