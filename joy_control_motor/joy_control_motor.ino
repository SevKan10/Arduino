int RM1 = 6;
int RM2 = 7; //thuận
int LM1 = 4;
int LM2 = 5;//nghịch

int joyX = A0 ; //
int joyY = A1 ;

int i = 0;
int Speed = 0;
void setup() {
  Serial.begin(9600);
 pinMode(RM1, OUTPUT);
 pinMode(RM2, OUTPUT);
 pinMode(LM1, OUTPUT);
 pinMode(LM2, OUTPUT);

 pinMode(joyX, INPUT);
 pinMode(joyY, INPUT);

}

void loop() {
              int X = analogRead(joyX);  
              int Y = analogRead(joyY);
    
      if (X=140){
      analogWrite(RM1, 0);
      analogWrite(RM2, 0);
      analogWrite(LM1, 0); 
      analogWrite(LM2, 0); 
      }    

      if (X>140){
        if(i<255){
       i++;
      analogWrite(RM1, i);
      analogWrite(RM2, i);
      analogWrite(LM1, 0); 
      analogWrite(LM2, 0); 
      delay(100);
        }
      }

      if (X<140){
        if(i<255){
        i++;
      analogWrite(RM1, 0);
      analogWrite(RM2, 0);
      analogWrite(LM1, i); 
      analogWrite(LM2, i); 
      delay(100);
        }
      }
}

  
