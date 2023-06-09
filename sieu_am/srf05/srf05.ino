// #include<Servo.h>
// #include<Wire.h>
// #include<LiquidCrystal_I2C.h>
// Servo se;
// LiquidCrystal_I2C lcd(0x27,16,2);
const int trig = 8;     // chân trig của HC-SR04
const int echo = 7;     // chân echo của HC-SR04
void setup()
{
    
    Serial.begin(9600);     // giao tiếp Serial với baudrate 9600
    // se.attach(6);
    // lcd.init();
    //lcd.backlight();
    pinMode(trig,OUTPUT);   // chân trig sẽ phát tín hiệu
    pinMode(echo,INPUT);    // chân echo sẽ nhận tín hiệu
}
 
void loop()
{
    unsigned long duration; // biến đo thời gian
    int distance;           // biến lưu khoảng cách
    
    /* Phát xung từ chân trig */
    digitalWrite(trig,0);   // tắt chân trig
    delayMicroseconds(2);
    digitalWrite(trig,1);   // phát xung từ chân trig
    delayMicroseconds(5);   // xung có độ dài 5 microSeconds
    digitalWrite(trig,0);   // tắt chân trig
    
    /* Tính toán thời gian */
    // Đo độ rộng xung HIGH ở chân echo. 
    duration = pulseIn(echo,HIGH);  
    // Tính khoảng cách đến vật.
    distance = int(duration/2/29.412);
    /* In kết quả ra Serial Monitor */
    Serial.print(distance);
    Serial.print("cm");
    Serial.print("\t");
    Serial.print(distance/100);
    Serial.println("m");
    delay(100);
    // if (distance<=10)
    // {
    //   se.write(180);
    // }
    // else 
    // {
    //   se.write(0);
    // }    
    //   lcd.setCursor(0,0);
    //   lcd.print(distance);
}
