#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
const char* ssid = "MINH KHA";
const char* password = "0855508877";

const char* host = "TEST";
const char* updatePath = "/update";

ESP8266WebServer webServer(80);
ESP8266HTTPUpdateServer httpUpdater;
//-----------------------------------------//
const char MainPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
    <title>Tài Xỉu</title>
    <style>
        .result {
            font-size: 24px;
            font-weight: bold;
        }
    </style>
</head>
<body>
    <h1>Tài Xỉu</h1>
    <button onclick="rollDice()">Lắc xúc xắc</button>
    <p class="result" id="result"></p>

    <script>
        function rollDice() {
            var dice1 = Math.floor(Math.random() * 6) + 1;
            var dice2 = Math.floor(Math.random() * 6) + 1;
            var sum = dice1 + dice2;
            var resultElement = document.getElementById('result');

            resultElement.innerText = 'Kết quả: ' + sum;

            if (sum === 7 || sum === 11) {
                resultElement.style.color = 'green';
            } else {
                resultElement.style.color = 'red';
            }
        }
    </script>
</body>
</html>


)=====";

int up = 4;
void setup(void){
  Serial.begin(9600);
  Serial.println();
  Serial.println("Booting programs...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while(WiFi.waitForConnectResult() != WL_CONNECTED){
    WiFi.begin(ssid, password);
    Serial.println("WiFi failed, retrying.");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  MDNS.begin(host);
  MDNS.addService("http", "tcp", 80);

  webServer.on("/",[]{
    String s = MainPage;
    webServer.send(200,"text/html",s);
  });
  webServer.begin();
  Serial.println("Web Server is started!");

  //=========Chương trình Chính=====//
  pinMode(up,OUTPUT);
  //============End=================//
}

void loop(void){
  MDNS.update();
  webServer.handleClient();
  //====Chương trình Chính==========//
  digitalWrite(up,!digitalRead(up));
  delay(500);
  //=========End====================//
}
