#include <virtuabotixRTC.h>
// Creation of the Real Time Clock Object
virtuabotixRTC myRTC(6, 7, 8);
void setup() {
Serial.begin(9600);
// seconds, minutes, hours, day of the week, day of the month, month, year
myRTC.setDS1302Time(18, 10, 10, 7, 18, 9, 2020);

}

void loop() {


    myRTC.updateTime();
    Serial.print("Current Date / Time: ");
    Serial.print(myRTC.dayofmonth);
    Serial.print("/");
    Serial.print(myRTC.month);
    Serial.print("/");
    Serial.print(myRTC.year);
    Serial.print(" ");
    Serial.print(myRTC.hours);
    Serial.print(":");
    Serial.print(myRTC.minutes);
    Serial.print(":");
    Serial.println(myRTC.seconds);
    delay(500);

}