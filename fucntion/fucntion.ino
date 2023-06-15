// Khai báo một kiểu dữ liệu con trỏ hàm
typedef void (*FunctionPointer)(int, int);

// Hàm chứa biến chức năng
void performOperation(int a, int b, FunctionPointer operation) {
    (*operation)(a, b); // Gọi biến chức năng thông qua con trỏ hàm
}

// Hàm chức năng (operation function)
void add(int a, int b) {
    int result = a + b;
    Serial.print("Result: ");
    Serial.println(result);
}

void setup() {
    Serial.begin(9600);

    // Gọi hàm chứa biến chức năng và truyền hàm add làm đối số
    performOperation(5, 3, add); // Kết quả: "Result: 8"
}

void loop() {
    // Không làm gì trong hàm loop
}
