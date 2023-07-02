#include <MPU6050_tockn.h>
#include <Wire.h>
MPU6050 mpu(Wire);
//---------------------
#include <TinyGPS++.h>
TinyGPSPlus gps;
//---------------------
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#define SCREEN_WIDTH 128  
#define SCREEN_HEIGHT 64 
#define OLED_RESET     -1
#define SCREEN_ADDRESS 0x3D
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

float Lat,Lng;
const String numberPhone = "0866207887";
int x,y,z;
int val=0;
int ledCall = 27;
int ledCon = 26;
int ledCon2 = 25;
int button = 2;
int Num = 0;
void setup() {
  Serial2.begin(9600);
  Serial.begin(9600);
  pinMode(ledCall,OUTPUT);
  pinMode(ledCon,OUTPUT);
  pinMode(ledCon2,OUTPUT);
  pinMode(button,INPUT);
  Wire.begin();
  mpu.begin();
  mpu.calcGyroOffsets(true);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  for(int i=15; i>-1; i--){display.setCursor(0,1);display.print("Ready in Second: ");display.print(i);display.display();delay(1000);display.clearDisplay();}
   
}

void loop() {
  display.clearDisplay();
  display.setCursor(48,2);
  display.print("READY");
  display.setCursor(0,35);
  display.print(Lat,6);  
  display.setCursor(0,45);
  display.print(Lng,6);
  display.display();
  updateSerial();
  MPU();
  GPS();
  Serial.println(digitalRead(button));
  val = digitalRead(button);
  if (val==1)
  {
      SOS();
  }



}