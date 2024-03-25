int n = 100;
int *ptr = &n; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print("Địa chỉ của biến n: ");
  Serial.print((int)ptr); // In ra địa chỉ của biến n
  Serial.print(", Giá trị của biến n: ");
  Serial.println(*ptr); // In ra giá trị mà con trỏ trỏ đến
  delay(1000);
}

//---------------------------
int n = 100;
int *ptr = &n; 

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println(n);
}

void loop() {
  *ptr = 200; // Thay đổi giá trị của biến n thông qua con trỏ
  Serial.print("n = ");
  Serial.println(n); // In ra giá trị mới của biến n
  delay(1000);
}