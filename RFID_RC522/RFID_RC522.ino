#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);  // Tạo đối tượng MFRC522
byte buzz = 2;
byte led = 13;

void setup() {
  Serial.begin(9600);  // Khởi động kết nối Serial
  SPI.begin();  // Khởi động SPI
  rfid.PCD_Init();  // Khởi động module RFID RC522
  Serial.println("HÃY QUÉT THẺ");

  pinMode(led,OUTPUT);
  pinMode(buzz,OUTPUT);
}

void loop() {
  // Kiểm tra nếu có thẻ RFID ở gần
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    // Đọc UID của thẻ
    Serial.print("UID  :");
    String content = "";
    byte letter;
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i] < 0x10 ? " 0" : " ");
      Serial.print(rfid.uid.uidByte[i], HEX);
      content.concat(String(rfid.uid.uidByte[i] < 0x10 ? " 0" : " "));
      content.concat(String(rfid.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Thông báo : ");
    content.toUpperCase();
    if (content.substring(1) == "15 6F AC AC"/* || content.substring(1)== "9D 0F 09 32"*/ ) { // Thay XX XX XX XX bằng UID của thẻ RFID bạn muốn nhận diện
      Serial.println("XÁC NHẬN");

      digitalWrite(led, millis()/1000%2);
      digitalWrite(buzz, 1); delay(200);
      digitalWrite(buzz, 0); 


      // Thêm các công việc cần thực hiện khi thẻ RFID được nhận diện
    } else {
      Serial.println("SAI ĐỊA CHỈ");
      digitalWrite(led,0);
      digitalWrite(buzz, 1);delay(100);
      digitalWrite(buzz, 0);delay(50);
      digitalWrite(buzz, 1);delay(100);
      digitalWrite(buzz, 0);delay(50);
      digitalWrite(buzz, 1);delay(100);
      digitalWrite(buzz, 0);delay(50);
      digitalWrite(buzz, 1);delay(100);
      digitalWrite(buzz, 0);delay(50);





    }
    delay(1500); // Đợi 1,5 giây trước khi tiếp tục quét thẻ tiếp theo
  }
  rfid.PICC_HaltA(); // Dừng thẻ hiện tại
  rfid.PCD_StopCrypto1(); // Tắt mã hóa

    

}
