#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "2210";
//-----------------------------
struct package_receive{ int TX_Connect; };
package_receive data_receive;

int flag1;
int receivedData1;
int receivedData2;
int led = 5;

unsigned long time;
unsigned long ping = 0;   

void setup() {
  Serial.begin(9600);
  
  radio.begin();
  if (!radio.begin()) {
    Serial.println("NRF24L01 Don't Start!");
  }
  radio.openReadingPipe(1, address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setChannel(2);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();

  pinMode(led, OUTPUT);
}

void loop() {
  while (radio.available()) {
    radio.read(&receivedData1, sizeof(receivedData1));
    radio.read(&receivedData2, sizeof(receivedData2));
    radio.read(&data_receive, sizeof(package_receive)); 
    ping = 0; flag1=0;
    Serial.print("Received data:  ");
    Serial.print(receivedData1);
    Serial.print("\t");
    Serial.println(receivedData2);
    
  }
 if(receivedData1>900){
   if (millis() - time >=10){
   for (int i=0;i<256;i++){
   digitalWrite(led, i);
   time = millis();
   }
   }
 } 

  while(!radio.available())
  {
    ping++; 
    if(ping/1000>50 )
    {
      Serial.println("Disconnected");
    }
  }
}
