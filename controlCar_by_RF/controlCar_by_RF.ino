#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte addRess[] = "2210";  
//----------------------------
byte button = 2;
byte joyX = 10;
byte joyY = 11;
int enA = 8;
int in1 = 7;
int in2 = 6; 
unsigned long time = 0;
const char Pass = "2210";
void setup(){
  Serial.begin(9600);
  radio.begin();
  pinMode(button,INPUT_PULLUP);
  pinMode(joyX,INPUT);
  pinMode(joyY,INPUT);
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  if (!radio.begin()) { Serial.println("NRF24L01 Don't Start!"); } 
  radio.openReadingPipe(1,addRess);
  radio.setPALevel(RF24_PA_HIGH);
  radio.setDataRate(RF24_250KBPS);
}

void loop(){
  if (millis() - time >500 ){ 
  Serial.print("buttonState: ");Serial.print(digitalRead(button));Serial.print(" \t");
  Serial.print("joyXState: ");Serial.print(analogRead(joyX));Serial.print("\t");
  Serial.print("joyYState: ");Serial.println(analogRead(joyY));
  time = millis();
  }
  radio.write(&Pass, sizeof(Pass));
  Serial.println(Pass);

  moTor();

}