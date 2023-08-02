#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "2210"; 
//-----------------------------
#include<Servo.h>
Servo se;
Servo se1;

int rdata1;
int rdata2;
int x;
int y;
unsigned long time;
void setup() {
  Serial.begin(9600);
  se.attach(6);
  se1.attach(5);
  radio.begin();
  if (!radio.begin()){Serial.print("Don't Connected");}
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);
  radio.setChannel(8);

}

void loop() {
  while (radio.available()) {
    if(millis() - time >= 1000){
   radio.startListening();
   radio.read(&rdata1,sizeof(rdata1));
   radio.read(&rdata2,sizeof(rdata2));
   Serial.print("Data\t");
   Serial.print(rdata1);
   Serial.print("\t");
   Serial.print(rdata2);
   time = millis();
    }
  }
  // x = map(rdata1, 0, 1023,0,180);
  // y = map(rdata2, 0, 1023,0,180);

  se.write(rdata1);
  se1.write(rdata2);
  millis() - 100;
}
