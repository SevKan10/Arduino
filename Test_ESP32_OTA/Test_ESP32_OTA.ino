#include <WiFi.h>
#include <ArduinoOTA.h>
void setup() {
  WiFi.begin("Hoang Cuong.", "99999999");
  ArduinoOTA.begin();
}
void loop() { ArduinoOTA.handle();}
