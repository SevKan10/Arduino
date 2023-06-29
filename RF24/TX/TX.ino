#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "2210";
//--------------------------------------------------------Cấu trúc Data
struct package_send{ int TX_Connect; };
package_send data_send;

unsigned long interrupt;
int joyX1 = A3;  //Chạy tiến, lùi
int joyY2 = A2; // Đánh lái
int led = 7;
unsigned long time;
 

void setup() {
  Serial.begin(9600);
  radio.begin();n
  if (!radio.begin()) {Serial.print("RF DON'T START");}
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setChannel(2);
  radio.setDataRate(RF24_250KBPS);

  pinMode(joyX1,INPUT);
  pinMode(joyY2,INPUT);
}

void loop() {
  if (millis() - time >1000)
  {
    //Serial.print("    AngelX: ");Serial.print(analogRead(joyX1));
    //Serial.print("    AngelY: ");Serial.println(analogRead(joyY2));
    int data1 = analogRead(joyX1);
    int data2 = analogRead(joyY2);
    radio.write(&data1, sizeof(data1));
    radio.write(&data2, sizeof(data2));
    Serial.print("Sent data:\t");Serial.print(data1);Serial.print("\t");Serial.println(data2);
    time = millis();
  }  
    if(millis() - interrupt >= 1000) 
  {
   data_send.TX_Connect = 5;
   radio.write(&data_send, sizeof(package_send));
   interrupt = millis();
  } 
}
