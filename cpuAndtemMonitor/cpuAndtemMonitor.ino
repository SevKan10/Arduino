// T:28°C H:62%         <-- dòng 1: nhiệt độ và độ ẩm
// RAM:80% C:12%        <-- dòng 2: RAM trống và CPU usage (ước lượng)

#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <MemoryFree.h> // Cần cài thư viện MemoryFree

#define DHTPIN A0
#define DHTTYPE DHT11
#define TOTAL_RAM 2048  // Tổng RAM của Arduino Uno/Nano

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte degree[8] = {
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000
};

void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.createChar(1, degree);  // Tạo ký tự độ °
  dht.begin();

  Serial.println("=== SYSTEM DHT11 + RAM + CPU ===");
}

void loop() {
  static unsigned long lastLoopTime = micros();
  unsigned long taskStart = micros();

  // Đọc nhiệt độ và độ ẩm từ DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  unsigned long taskEnd = micros();
  unsigned long taskDuration = taskEnd - taskStart;

  // Tính thời gian mỗi vòng loop
  unsigned long loopNow = micros();
  unsigned long loopDuration = loopNow - lastLoopTime;
  lastLoopTime = loopNow;
  if (loopDuration == 0) loopDuration = 1;

  // Ước lượng CPU usage
  float cpuUsage = (float)taskDuration / loopDuration * 100.0;

  // RAM
  int freeRam = freeMemory();
  float ramUsedPercent = (float)(TOTAL_RAM - freeRam) / TOTAL_RAM * 100.0;

  // Ghi Serial
  Serial.println("------");
  if (isnan(t) || isnan(h)) {
    Serial.println("DHT11 ERROR!");
  } else {
    Serial.print("TEMP: ");
    Serial.print(t);
    Serial.println(" *C");

    Serial.print("HUMI: ");
    Serial.print(h);
    Serial.println(" %");
  }

  Serial.print("RAM (còn lại): ");
  Serial.print(freeRam);
  Serial.print(" bytes (");
  Serial.print(100.0 - ramUsedPercent, 1);
  Serial.println("%)");

  Serial.print("CPU usage: ");
  Serial.print(cpuUsage, 1);
  Serial.println(" %");

  // --- Hiển thị LCD ---
  lcd.clear();

  if (isnan(t) || isnan(h)) {
    lcd.setCursor(0, 0);
    lcd.print("DHT ERROR!");
    lcd.setCursor(0, 1);
    lcd.print("CPU:");
    lcd.print(cpuUsage, 0);
    lcd.print("%");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("T:");
    lcd.print(round(t));
    lcd.write(1); // ° ký tự
    lcd.print("C ");

    lcd.print(" H:");
    lcd.print(round(h));
    lcd.print("%");

    lcd.setCursor(0, 1);
    lcd.print("RAM:");
    lcd.print(100.0 - ramUsedPercent, 0); // phần trăm còn lại
    lcd.print("% ");

    lcd.print("CPU:");
    lcd.print(cpuUsage, 0);
    lcd.print("%");
  }

  delay(1000);
}
