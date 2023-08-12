#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
const char* host = "Kan";
const char* ssid = "Hoang Cuong.";
const char* password = "99999999";

ESP8266WebServer webServer(80);
ESP8266HTTPUpdateServer httpUpdater;
//-----------------------------------------------Trang chính
const char MainPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>iFrame</title>
<style>
    h1{
        text-align: center;
        text-shadow: 0cap;

    }
    h3{
        text-align: right;
    }
</style>
</head>
<body>
    <h1>
        <div style="width: 300px; margin-left: auto; margin-right: auto;">
             Welcome to <a style="color:red">iFarme </a>
            <button onclick="window.location.href='button.html'">Click here to continue</button>
            <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
        </div>
    </h1> 
    <h3>
        <a><i>Design by Giai Xuan's student</i></a>
    </h3>
</body>
</html>
)=====";
//--------------------------------------------Trang phụ
const char PoPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Control device</title>
</head>
<body>
    <a>Hello</a>
</body>
</html>

)=====";
int up = 4;
void setup(void) {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Booting programs...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    Serial.println("WiFi failed, retrying.");
  }
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  MDNS.begin(host);
  MDNS.addService("http", "tcp", 80);

  webServer.on("/", [] {
    String s = MainPage;
    webServer.send(200, "text/html", s);
  });
  webServer.on("/button.html", []() {
    String s = PoPage;
    webServer.send(200, "text/html", s);
  });
  webServer.begin();
  Serial.println("Web Server is started!");
}

void loop(void) {
  MDNS.update();
  webServer.handleClient();
}
