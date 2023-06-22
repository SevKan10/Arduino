#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "2210";
//----------------------------
int joyX1 = A3;  //Chạy tiến, lùi
int joyY2 = A2; // Đánh lái
int led = 7;
unsigned long time;
 

void setup() {
  Serial.begin(9600);
  radio.begin();
  if (radio.begin()) {
    digitalWrite(led,1);delay(5000);
    digitalWrite(led,0);

  }
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);

  pinMode(joyX1,INPUT);
  pinMode(joyY2,INPUT);
}

void loop() {
  if (millis() - time >1000)
  {
    Serial.print("    AngelX: ");Serial.print(analogRead(joyX1));
    Serial.print("    AngelY: ");Serial.println(analogRead(joyY2));
    int data1 = analogRead(joyX1);
    int data2 = analogRead(joyY2);
    radio.write(&data1, sizeof(data1));
    radio.write(&data2, sizeof(data2));
    Serial.print("Sent data:\t");Serial.print(data1);Serial.print("\t");Serial.print(data2);
    time = millis();
  }  
}
