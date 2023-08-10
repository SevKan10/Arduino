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
    <title>Trang web giới thiệu mạng xã hội</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 0;
        }

        h1 {
            text-align: center;
            margin: 20px 0;
        }

        .social-icons {
            display: flex;
            justify-content: center;
            align-items: center;
            margin: 20px;
        }

        .social-icons a {
            display: inline-block;
            margin: 10px;
            color: #fff;
            font-size: 24px;
            width: 40px;
            height: 40px;
            text-align: center;
            line-height: 40px;
            border-radius: 50%;
            transition: background-color 0.3s ease;
        }

        .social-icons a:hover {
            background-color: #333;
        }

        /* Hiệu ứng cho biểu tượng mạng xã hội */
        .social-icons a.github {
            background-color: #333;
        }

        .social-icons a.facebook {
            background-color: #3b5998;
        }

        .social-icons a.zalo {
            background-color: #1ebc4e;
        }
    </style>
</head>
<body>
    <h1>Trang web giới thiệu mạng xã hội</h1>

    <div class="social-icons">
        <a href="https://github.com/SevKan10" target="_blank" class="github"><i class="fab fa-github"></i></a>
        <a href="https://www.facebook.com/khang.khangkhuu" target="_blank" class="facebook"><i class="fab fa-facebook-f"></i></a>
        <a href="https://chat.zalo.me" target="_blank" class="zalo"><i class="fab fa-zalo"></i></a>
    </div>

    <script src="https://kit.fontawesome.com/f09a.js" crossorigin="anonymous"></script>
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
