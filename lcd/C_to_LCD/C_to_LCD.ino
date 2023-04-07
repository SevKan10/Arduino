#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int DHTPIN = 2;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);
byte degree[8] = {
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000
};


void setup() 
{
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  lcd.init();   
  lcd.backlight();
  lcd.createChar(1, degree);
  dht.begin();  
}
void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (t<=28) 
  {
    digitalWrite(13,1);
  }
  else 
  {
    digitalWrite(13,0);
  }

  if (isnan(t) or  isnan(h)) 
  { 
    lcd.setCursor(0,0);
    lcd.print("no");
    lcd.setCursor(0,1);
    lcd.print("no");
  } 
  else {
    lcd.setCursor(0,0);
    lcd.print(round(t));
    Serial.print(t);
    lcd.write(1);
    Serial.println(" do C");
    lcd.print(" C");
    lcd.setCursor(8,0);
    lcd.print(round(h));
    Serial.print(h); Serial.println(" %"); delay(500);
    lcd.print(" %");    
  }
}