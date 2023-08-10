#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <ESP8266HTTPUpdateServer.h>
const char* ssid = "MINH KHA";
const char* password = "0855508877";

const char* host = "E-SMART";
const char* updatePath = "/update";
const char* updateUsername = "Khang";
const char* updatePassword = "12345678";

ESP8266WebServer webServer(80);
ESP8266HTTPUpdateServer httpUpdater;
//-----------------------------------------//
const char MainPage[] PROGMEM = R"=====(
 <!DOCTYPE html> 
  <html>
   <head> 
       <title>Upload Frimware</title> 
       <style> 
          h1{
            text-align: center;
          }
          h3{
            text-align: right;
          }
       </style>
       <meta name="viewport" content="width=device-width,user-scalable=0" charset="UTF-8">
   </head>
   <body> 
    <h1> 
      <div>
        <img src='' height='330px' width='330px'>
      </div>
      <div>
        <button onclick="window.location.href='/update'">UPLOAD FIRMWARE</button><br><br>
         <a href='https://github.com/SevKan10'>Xem thêm nhiều Code</a> 
        <br><br><br><br><br><br><br><br><br><br><br><br>
    </div>
    <script>
    </script>
    </h1>
    <h3>
    <a ><b><i>Design by Giai Xuan's student</i></b></a>
    </h3>
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

  httpUpdater.setup(&webServer, updatePath, updateUsername, updatePassword);
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
