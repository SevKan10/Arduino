#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
const char* ssid = "Hoang Cuong.";
const char* password = "99999999";

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
                <img src="data:image/jpeg;base64,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"  height="150px" width="150px" alt=""/><br>
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
