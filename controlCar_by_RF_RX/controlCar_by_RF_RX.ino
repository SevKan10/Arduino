#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte addRess[] = "2210"; 
unsigned long time;
void setup()
{
  Serial.begin(9600);
  radio.begin();
  if (!radio.begin()) { Serial.println("NRF24L01 Don't Start!"); } 
  radio.openReadingPipe(1,addRess);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();


}

void loop() 
{
  while(radio.available())
  {
    char data =" ";
    radio.read(&data, sizeof(data)); 
    Serial.println(data);
 
  }

}
