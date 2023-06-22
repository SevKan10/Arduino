#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "2210";
//-----------------------------
int receivedData1;
int receivedData2;
int in1 = 2;
int in2 = 3;
int in3 = 4;
int in4 = 7;
int enC = 6;
int enG = 5;
unsigned long time;

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  if (!radio.begin()) {
    Serial.println("NRF24L01 Don't Start!");
  }
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

  pinMode(enG, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT); 
  pinMode(enC,OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void loop() {
  while (radio.available()) {
    radio.read(&receivedData1, sizeof(receivedData1));
    radio.read(&receivedData2, sizeof(receivedData2));
    Serial.print("Received data:  ");
    Serial.print(receivedData1);
    Serial.print("      ");
    Serial.println(receivedData2);
  }
  Run();
}
