#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
ESP8266WebServer webServer(80);
char* ssid = "MINH KHA";
char* pass = "0855508877";

//--------------------------------------Trang chính
const char MainPage[] PROGMEM = R"=====(
<html>
<head>
<meta charset="UTF-8">
<head>
    <title>iFarme</title> 
    <style> 
       body {text-align:center;}
       h1 {color:#003399;}
        .flow {
        border-radius: 25px;
        background: lightblue;
        padding: 5px;
        width: 100px;
        height: 50px;
        }
       .add {
        border-radius: 25px;
        background:orange;
        padding: 5px;
        width: 100px;
        height: 50px;
        }
       h3{
           text-align: right;
        }
    </style>
</head>
<body>
    <h1>
        <div style="width: 300px; margin-left: auto; margin-right: auto;">
             Welcome to <a style="color:red">iFarme </a><br>
            <button class="flow" onclick="window.location.href='flow.html'"><a><b>Xem tiến trình trồng</b></a></button>
            <button class="add" onclick="window.location.href='add.html'"><a><b>Thêm cây trồng</b></a></button>
            <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
        </div>
    </h1> 
    <h3>
        <a><i>Design by Giai Xuan's student</i></a>
    </h3>
</body>
</html>
)=====";
//--------------------------------------------Trang theo dõi
const char flowPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Progress tracking</title>
    <style>
        .circle {
            fill: #456BD9;
            stroke: #0F1C3F;
            stroke-width: 0.1875em;
          }
    </style>
</head>
<body>
    <svg viewBox="0 0 80 80" width="80" height="80">
        <circle class="circle" cx="40" cy="40" r="38"/>
    </svg>
</body>
</html>

)=====";
const char addPage[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add vegetable</title>
</head>
<body>
    <a>Hello</a>
</body>
</html>
)=====";
//=========================================//
void setup() {

  WiFi.begin(ssid, pass);
  Serial.begin(9600);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print("...");
  }
  Serial.println(WiFi.localIP());

   webServer.on("/", [] {
    String s = MainPage;
    webServer.send(200, "text/html", s);
  });
  webServer.on("/flow.html", []() {
    String s = flowPage;
    webServer.send(200, "text/html", s);
  });
  webServer.on("/add.html", []() {
    String s = addPage;
    webServer.send(200, "text/html", s);
  });
  webServer.begin();
}
void loop() {
  webServer.handleClient();
}

