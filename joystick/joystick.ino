#include<Servo.h>
int bientroX = A0 ; 
int bientroY = A1 ; 
int button = 2; 
Servo se1;     
void setup ()
{
     se1.attach(6);
     pinMode(2, INPUT);
     pinMode(A0, INPUT);
     pinMode(A1, INPUT);
     Serial.begin(9600);
}
void loop ()
{
              int x = analogRead(bientroX);  // doc gia tri cua truc X
              int y = analogRead(bientroY);  // doc gia tri cua truc Y
              int KEY = digitalRead(button);  // doc gia tri cua nut nhan
              // Xuat ra cong Serial
              int valx = map(x,0,1023,0,180);
              int valy = map(y,0,1023,0,180);
              Serial.print("X="); Serial.println(valx);
              Serial.print("Y="); Serial.println(valy);
              Serial.print("KEY="); Serial.print(KEY); Serial.println();
              delay(200);//delay để ổn định hơn
              se1.write(valx);
              se1.write(valy);      
}