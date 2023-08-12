#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid = "MINH KHA";
const char* password = "0855508877";

ESP8266WebServer webServer(80);
//-----------------------------------------------Trang chính
const char MainPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>iFarme</title> 
  <style> 
      body {text-align:center;}
      h1{color:#003399;}
      .flow {
      border-radius: 25px;
      background: lightblue;
      padding: 5px;
      width: 100px;
      height: 50px;
      }
      .add{
      border-radius: 25px;
      background:orange;
      padding: 5px;
      width: 100px;
      height: 50px;
      }
      h3{
         text-align: right;
      }
      body{
          background-image: url('https://4.bp.blogspot.com/-myf1pNS0qco/V2OFtW0vIpI/AAAAAAAAAcw/j4l7ZVbze6I051z-gTW3rrLO7sWO-J0bgCLcB/s1600/Hinh-Nen-Mam-Cay-Hinh-Nen-May-Tinh-Dep-Nhat-HoangTueBlog-7.jpg');
      }
    
  </style>
</head>
<body>
  <script>
    function login() {
      var name = prompt("ADMIN:");
      var pass = prompt("Password:");
        //-----------------đổi tên và mật khẩu
        var user ="khang"; 
        var pin ="1234";
        //-----------------------------------
      if (name === user && pass === pin) {
        showMainContent(); 
      } else {
        alert("Wrong");
        window.location.href = "no.html";
      }
    }
    function showMainContent() {
      var mainContent = document.getElementById("main-content");
    }

    login();
  </script>

  <div id="main-content" >
    <p>
        <h1>
            <div style="width: 300px; margin-left: auto; margin-right: auto;">
                 Welcome to <a style="color:red">iFarme </a><br>
                <button class="flow" onclick="window.location.href='flow.html'"><a><b>Tree process</b></a></button>
                <button class="add" onclick="window.location.href='add.html'"><a><b>More plants</b></a></button>
                 <br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>
            </div>
        </h1> 
        <h3>
            <a><i>Design by Giai Xuan's student</i></a>
        </h3>
        </p>
  </div>
</body>
</html>

)=====";
//------------------------------------------------Trang xem
const char flowPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Progress tracking</title>
    <style>
        body {text-align:center;}
        .circle {
            fill: #456BD9;
            stroke: #0F1C3F;
            stroke-width: 0.1875em;
          }
    </style> 
</head>
<body>
    <font style="color: red;">
        <h1> Plant tracking</h1>
    </font>
    <svg viewBox="0 0 80 80" width="200" height="200">
        <circle class="circle" cx="40" cy="40" r="38"/>
    </svg>
    <table border="2" cellpadding="5" cellspacing="0">
        <tr>
            <td><h1>Temp: </h1></td>
            <td></td>
        </tr>
        <tr>
            <th><h1>Hum: </h1></th>
            <td></td>
        </tr>
        <tr>
            <th><h1>Day: </h1></th>
            <td></td>
        </tr>
    </table>
</body>
</html>
)=====";
//------------------------------------------------Trang thêm
const char addPage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Add vegetable</title>
    <style>
        body {text-align:center;}
    </style>
</head>
<body>
    <font style="color: red;">
        <h1>Add vegetables</h1>
    </font>
    <p>
        <!-- Tên cây -->
        <label for="text">Name vegetable: </label>
        <input type="text" name="txtName" id="txtName"  required onfocus="doico1()" onblur="doilai1()">
        <!-- Nhiệt độ -->
        <p>
        <label for="text">Temp: </label>
        <input type="text" name="txtTemp" id="txtTemp" required onfocus="doico2()" onblur="doilai2()">
        </p>
        <!-- Độ ẩm -->
        <p>
            <label for="text">Hum: </label>
            <input type="text" name="txtHum" id="txtHum" required onfocus="doico3()" onblur="doilai3()">
        </p>
        <label for="text">Day, month, year planting: </label>
        <!-- day -->
        <select class="form-select" id="day" name="day">
            <option value="">Day</option>
            <option value="01">01</option>
            <option value="02">02</option>
            <option value="03">03</option>
            <option value="04">04</option>
            <option value="05">05</option>
            <option value="06">06</option>
            <option value="07">07</option>
            <option value="08">08</option>
            <option value="09">09</option>
            <option value="10">10</option>
            <option value="11">11</option>
            <option value="12">12</option>
            <option value="13">13</option>
            <option value="14">14</option>
            <option value="15">15</option>
            <option value="16">16</option>
            <option value="17">17</option>
            <option value="18">18</option>
            <option value="19">19</option>
            <option value="20">20</option>
            <option value="21">21</option>
            <option value="22">22</option>
            <option value="23">23</option>
            <option value="24">24</option>
            <option value="25">25</option>
            <option value="26">26</option>
            <option value="27">27</option>
            <option value="28">28</option>
            <option value="29">29</option>
            <option value="30">30</option>
            <option value="31">31</option>
        </select>
        <!-- month -->
        <select class="form-select" id="month" name="month">
            <option value="">Month</option>
            <option value="01"> 1</option>
            <option value="02"> 2</option>
            <option value="03"> 3</option>
            <option value="04"> 4</option>
            <option value="05"> 5</option>
            <option value="06"> 6</option>
            <option value="07"> 7</option>
            <option value="08"> 8</option>
            <option value="09"> 9</option>
            <option value="10"> 10</option>
            <option value="11"> 11</option>
            <option value="12"> 12</option>
        </select>
        <!-- years -->
        <select class="form-select" id="year" name="year">
            <option value="">Year</option>
            <option value="2023">2023</option>
        </select>
    </p>
   
    <p>
        <label for="chAcpt">
            <input type="checkbox" name="chAcpt" id="chAcpt"/> You agree to enter informationn </p> <br>
        </label>
    <button onclick="checkDangky()">Send data</button>
    <button type="button" onclick="tai_lai_trang()">Retype</button>


    <div id="ketqua"></div>
    <script>
        function checkDangky(){
            var name = document.getElementById("txtName").value;
            var accept = document.getElementById("chAcpt").checked;
            var temp = document.getElementById("txtTemp").value;
            var hum = document.getElementById("txtHum").value;
            var Day = document.getElementById("day").value;
            var Month = document.getElementById("month").value;
            var Year = document.getElementById("year").value;
            
            <!-- document.getElementById("ketqua").innerHTML = 'Plant name: ' + name + '<br>Check: ' + accept  + "<br>Temp: " + temp +"<br>Hum: " + hum + "<br>Plating date: " + Day +" Month " + Month +" Year "+ Year; -->
            
            if (name === "") {
                alert("Please enter the NAME of the plant");
                
            }
            else if (temp ===""){
                alert("Please enter the TEMPERATURE");
            }
            else if (hum ===""){
                alert("Please enter the HUMIDITY");
            }
            else if (Day ===""){
                alert("Please enter the DAY");
            }
            else if (Month ===""){
                alert("Please enter the MONTH");
            }
            else if (Year ===""){
                alert("Please enter the YEAR");
            }
        }
           //tên cây
           function doico1(){
                document.getElementById('txtName').style.color="black";
                document.getElementById('txtName').style.fontSize="30px";
            }
            function doilai1(){
                document.getElementById('txtName').style.color="red";
                document.getElementById('txtName').style.fontSize="15px";
            }
            //nhiệt
            function doico2(){
                document.getElementById('txtTemp').style.color="black";
                document.getElementById('txtTemp').style.fontSize="30px";
            }
            function doilai2(){
                document.getElementById('txtTemp').style.color="red";
                document.getElementById('txtTemp').style.fontSize="15px";
            }    
            //ẩm
            //
            function doico3(){
                document.getElementById('txtHum').style.color="black";
                document.getElementById('txtHum').style.fontSize="30px";
            }
            function doilai3(){
                document.getElementById('txtHum').style.color="red";
                document.getElementById('txtHum').style.fontSize="15px";
            }   

            function tai_lai_trang(){
            location.reload();
            }
    </script>
   
</body>
</html>
)=====";
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
//-----------------------------------
  startSever();
  webServer.begin();
  Serial.println("Web Server is started!");
}

void loop(void) {
  webServer.handleClient();
}
