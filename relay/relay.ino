const int buttonPin = 13;     // the number of the pushbutton pin
const int relayPin =  2;      // the number of the relay pin

// variables will change:
int buttonState = 1;         // variable for reading the pushbutton status

void setup() {
  pinMode(relayPin, OUTPUT);      // initialize relay pin as output
  pinMode(buttonPin, INPUT);      // initialize button pin as input
}

void loop() {
 /* buttonState = digitalRead(buttonPin);     // read the state of the pushbutton value

  if (buttonState == HIGH) {       // check if the pushbutton is pressed
    digitalWrite(relayPin, 1);   
    delay(100);// turn on relay
  } else {
    digitalWrite(relayPin, 0);   
    delay(100); // turn off relay
  }
}*/
digitalWrite(relayPin, 1);  
delay(400) ;
digitalWrite(relayPin, 0);  
delay(400) ;
}