void Run(){
  digitalWrite(in3, 0);
  digitalWrite(in1, 0);
  digitalWrite(in4, 0);
  digitalWrite(in2, 0);

  if(receivedData1>900){
    for(int i=0;i<=255;i=i+10){
        digitalWrite(in1, 1);
        digitalWrite(in2, 0);
        analogWrite(enG, i);
    }
  }
  else{
      for(int i=255;i>=0;i=i-10){
        digitalWrite(in1, 1);
        digitalWrite(in2, 0);
        analogWrite(enG, i);
    }
  }
  if(receivedData1<100){
    for(int i=0;i<=255;i=i+10){
        digitalWrite(in1, 0);
        digitalWrite(in2, 1);
        analogWrite(enG, i);
    }
  }
  else{
      for(int i=255;i>=0;i=i-10){
        digitalWrite(in1, 0);
        digitalWrite(in2, 1);
        analogWrite(enG, i);
    }
  }
  if(receivedData2>900){
    for(int i=0;i<=255;i=i+10){
        digitalWrite(in3, 1);
        digitalWrite(in4, 0);
        analogWrite(enC, i);
    }
  }
  else{
      for(int i=255;i>=0;i=i-10){
        digitalWrite(in3, 1);
        digitalWrite(in4, 0);
        analogWrite(enC, i);
    }
  }
  if(receivedData2<100){
    for(int i=0;i<=255;i=i+10){
        digitalWrite(in3, 0);
        digitalWrite(in4, 1);
        analogWrite(enC, i);
    }
  }
  else{
      for(int i=255;i>=0;i=i-10){
        digitalWrite(in3, 0);
        digitalWrite(in4, 1);
        analogWrite(enC, i);
    }
  }
  
}