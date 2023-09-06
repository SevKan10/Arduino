#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

const char* ssid = "MINH KHA"; // Tên mạng Wi-Fi
const char* password = "0855508877"; // Mật khẩu Wi-Fi
const long utcOffsetInSeconds = 7 * 3600; // Độ chênh lệch múi giờ, ở đây là UTC+7 (Việt Nam)

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

void setup() {
  Serial.begin(115200);
  
  // Kết nối Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  
  // Bắt đầu kết nối đồng bộ hóa thời gian
  timeClient.begin();
}

void loop() {
  timeClient.update();
 // Serial.println(timeClient.getFormattedTime()); // In ra thời gian đã đồng bộ
   int hours = timeClient.getHours();
  int minutes = timeClient.getMinutes();
  int seconds = timeClient.getSeconds();
  
  Serial.print("Giờ: ");
  Serial.println(hours);
  Serial.print("Phút: ");
  Serial.println(minutes);
  Serial.print("Giây: ");
  Serial.println(seconds);
  
  delay(1000);
}
