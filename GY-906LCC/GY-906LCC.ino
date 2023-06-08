#include <Wire.h>
#include <Adafruit_MLX90614.h>

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);

  // Khởi tạo đối tượng cảm biến
  mlx.begin();
}

void loop() {
  // Đọc nhiệt độ từ cảm biến
  float temp = mlx.readObjectTempC();

  // In nhiệt độ
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  // Đợi 1 giây trước khi đọc lại dữ liệu
  delay(1000);
}
