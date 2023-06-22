void moTor(){
  if ((button==1) && (joyX>512)){
    for(int i=0;i=127;i++){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, i);
    }
    button++;
  }
  if ((button==2) && (joyX>512)){
    for(int i=0;i=255;i++){
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      analogWrite(enA, i);
    }
  }

}