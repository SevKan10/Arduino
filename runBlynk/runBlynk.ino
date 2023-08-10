#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "dtalM9cEwgE33cqjvvNUXHNV6h2n2Pup";
char ssid[] = "MINH KHA";
char pass[] = "0855508877";

void setup() {
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop() {
  Blynk.run();

    Blynk.virtualWrite(V0, millis());
    delay(100);  
}
