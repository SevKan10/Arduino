#include <Wire.h>
#include <Kalman.h>
#define RESTRICT_PITCH
Kalman kalmanX;
Kalman kalmanY;
/* IMU Data */
double accX, accY, accZ;
double gyroX, gyroY, gyroZ;
int16_t tempRaw;
double gyroXangle, gyroYangle;
double compAngleX, compAngleY;
double kalAngleX, kalAngleY;

uint32_t timer;
uint8_t i2cData[14];
//-------------------------------------------
#include <SimpleKalmanFilter.h>
SimpleKalmanFilter locnhieu(2, 2, 0.01);
//------------------------------------------- Chân
#define right 3
#define left 2
#define mode 4
#define bientro A0
//-------------------------------------------
float doc;
int filter; int goc;
int on_r = 1; int off_r;
int on_l = 1; int off_l;
int off_m = 0;
int X;
unsigned long delay_r; unsigned long delay_Off_r;
unsigned long delay_l; unsigned long delay_Off_l;
void setup() {
  Serial.begin(9600);
  pinMode(bientro, INPUT);
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);
  pinMode(mode,OUTPUT);
  //pinMode(off, OUTPUT);
  Wire.begin();
#if ARDUINO >= 157
  Wire.setClock(400000UL);
#else
  TWBR = ((F_CPU / 400000UL) - 16) / 2;
#endif

  i2cData[0] = 7;
  i2cData[1] = 0x00;
  i2cData[2] = 0x00;
  i2cData[3] = 0x00;
  while (i2cWrite(0x19, i2cData, 4, false))
    ;
  while (i2cWrite(0x6B, 0x01, true))
    ;
  while (i2cRead(0x75, i2cData, 1))
    ;
  if (i2cData[0] != 0x68) {
    Serial.print(F("Error reading sensor"));
    while (1)
      ;
  }
  delay(100);
  /* Set kalman and gyro starting angle */
  while (i2cRead(0x3B, i2cData, 6))
    ;
  accX = (int16_t)((i2cData[0] << 8) | i2cData[1]);
  accY = (int16_t)((i2cData[2] << 8) | i2cData[3]);
  accZ = (int16_t)((i2cData[4] << 8) | i2cData[5]);
#ifdef RESTRICT_PITCH  // Eq. 25 and 26
  double roll = atan2(accY, accZ) * RAD_TO_DEG;
  double pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;
#else  // Eq. 28 and 29
  double roll = atan(accY / sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;
  double pitch = atan2(-accX, accZ) * RAD_TO_DEG;
#endif
  kalmanX.setAngle(roll);  // Set starting angle
  kalmanY.setAngle(pitch);
  gyroXangle = roll;
  gyroYangle = pitch;
  compAngleX = roll;
  compAngleY = pitch;
  timer = micros();
}
void loop() {
  /* Update all the values */
  while (i2cRead(0x3B, i2cData, 14))
    ;
  accX = (int16_t)((i2cData[0] << 8) | i2cData[1]);
  accY = (int16_t)((i2cData[2] << 8) | i2cData[3]);
  accZ = (int16_t)((i2cData[4] << 8) | i2cData[5]);
  tempRaw = (int16_t)((i2cData[6] << 8) | i2cData[7]);
  gyroX = (int16_t)((i2cData[8] << 8) | i2cData[9]);
  gyroY = (int16_t)((i2cData[10] << 8) | i2cData[11]);
  gyroZ = (int16_t)((i2cData[12] << 8) | i2cData[13]);
  ;

  double dt = (double)(micros() - timer) / 1000000;  // Calculate delta time
  timer = micros();
#ifdef RESTRICT_PITCH  // Eq. 25 and 26
  double roll = atan2(accY, accZ) * RAD_TO_DEG;
  double pitch = atan(-accX / sqrt(accY * accY + accZ * accZ)) * RAD_TO_DEG;
#else  // Eq. 28 and 29
  double roll = atan(accY / sqrt(accX * accX + accZ * accZ)) * RAD_TO_DEG;
  double pitch = atan2(-accX, accZ) * RAD_TO_DEG;
#endif

  double gyroXrate = gyroX / 131.0;  // Convert to deg/s
  double gyroYrate = gyroY / 131.0;  // Convert to deg/s

#ifdef RESTRICT_PITCH
  // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
  if ((roll < -90 && kalAngleX > 90) || (roll > 90 && kalAngleX < -90)) {
    kalmanX.setAngle(roll);
    compAngleX = roll;
    kalAngleX = roll;
    gyroXangle = roll;
  } else
    kalAngleX = kalmanX.getAngle(roll, gyroXrate, dt);  // Calculate the angle using a Kalman filter

  if (abs(kalAngleX) > 90)
    gyroYrate = -gyroYrate;  // Invert rate, so it fits the restriced accelerometer reading
  kalAngleY = kalmanY.getAngle(pitch, gyroYrate, dt);
#else
  // This fixes the transition problem when the accelerometer angle jumps between -180 and 180 degrees
  if ((pitch < -90 && kalAngleY > 90) || (pitch > 90 && kalAngleY < -90)) {
    kalmanY.setAngle(pitch);
    compAngleY = pitch;
    kalAngleY = pitch;
    gyroYangle = pitch;
  } else
    kalAngleY = kalmanY.getAngle(pitch, gyroYrate, dt);  // Calculate the angle using a Kalman filter

  if (abs(kalAngleY) > 90)
    gyroXrate = -gyroXrate;                           // Invert rate, so it fits the restriced accelerometer reading
  kalAngleX = kalmanX.getAngle(roll, gyroXrate, dt);  // Calculate the angle using a Kalman filter
#endif

  gyroXangle += gyroXrate * dt;  // Calculate gyro angle without any filter
  gyroYangle += gyroYrate * dt;
  //gyroXangle += kalmanX.getRate() * dt; // Calculate gyro angle using the unbiased rate
  //gyroYangle += kalmanY.getRate() * dt;

  compAngleX = 0.93 * (compAngleX + gyroXrate * dt) + 0.07 * roll;  // Calculate the angle using a Complimentary filter
  compAngleY = 0.93 * (compAngleY + gyroYrate * dt) + 0.07 * pitch;

  // Reset the gyro angle when it has drifted too much
  if (gyroXangle < -180 || gyroXangle > 180)
    gyroXangle = kalAngleX;
  if (gyroYangle < -180 || gyroYangle > 180)
    gyroYangle = kalAngleY;

    /* Print Data */
#if 0  // Set to 1 to activate
 // Serial.print(accX); Serial.print("\t");
//  Serial.print(accY); Serial.print("\t");
//  Serial.print(accZ); Serial.print("\t");

 // Serial.print(gyroX); Serial.print("\t");
 // Serial.print(gyroY); Serial.print("\t");
//  Serial.print(gyroZ); Serial.print("\t");

  Serial.print("\t");
#endif

  // Serial.print(roll); Serial.print("\t");
  //Serial.print(gyroXangle); Serial.print("\t");
  // Serial.print(compAngleX);
  // Serial.print("\t");
  // Serial.print(kalAngleX);
  // Serial.print("\t");

#if 0  // Set to 1 to print the temperature
  Serial.print("\t");

  double temperature = (double)tempRaw / 340.0 + 36.53;
  //Serial.print(temperature); Serial.print("\t");    kalAngleY < 53 phải || kalAngleY > 73 trái || filter <= 400 trái || filter >= 623 phải
#endif

  Serial.print("\r\n");
  delay(2);
  doc = analogRead(bientro);
  filter = locnhieu.updateEstimate(doc);
  goc = map(filter,0,1023, 0,180);
  Serial.print("Góc Biến Trở: ");Serial.print(goc); Serial.print("\t"); Serial.print("Góc MPU: "); Serial.println(kalAngleY);

//---------------------------------------------------------------------------------------------- Quẹo Phải 
   if( kalAngleY < 50 and millis() - delay_r >= 1500 )
     { Serial.println("1"); on_right(); off_r = 1; delay_Off_r = millis(); delay_r = millis(); }
//---------------------------------------------------------------------------------------------- Dừng
   if( kalAngleY > 50 and kalAngleY < 70 and goc > 70 && goc < 100) 
     { Serial.println("2"); on_r = 1; off_right(); on_l = 1; off_left(); off_m = 1; delay_r = millis(); delay_l = millis(); }
//---------------------------------------------------------------------------------------------- Quẹo Trái
   if( kalAngleY > 70 and millis() - delay_l >= 1500 ) 
     { Serial.println("3"); on_left(); off_l = 1; delay_Off_l = millis(); delay_l = millis(); }
//---------------------------------------------------------------------------------------------- POT Quẹo Phải
   if( goc < 70 and millis() - delay_r >= 1500 ) 
     { Serial.println("4"); on_right(); off_r = 1; delay_Off_r = millis(); delay_r = millis(); }
//-----------------------------------------------------------------------------------------------POT Quẹo Trái
   if( goc > 100  and millis() - delay_l >= 1500 ) 
     { Serial.println("5"); on_left(); off_l = 1; delay_Off_l = millis(); delay_l = millis(); }
//----------------------------------------------------------------------------------------------- 
   while( kalAngleY < 50 and goc > 100)
     { Serial.println("6"); Mode(); delay_r = millis(); delay_l = millis(); return loop();}
   while( kalAngleY > 70 and goc < 70) 
     { Serial.println("7"); Mode(); delay_r = millis(); delay_l = millis(); return loop();}
   while (X == 1) 
   {
    if(kalAngleY < 50 and goc > 70 && goc < 100)
     {on_r = 1; on_l = 0; X=0;}
    if(kalAngleY > 70 and goc > 70 && goc < 100)
     {on_l = 1; on_r = 0; X=0;} //
    if(kalAngleY > 50 and kalAngleY < 70 and goc < 70)
     {on_r = 1; on_l = 0; X=0;}
    if(kalAngleY > 50 and kalAngleY < 70 and goc > 100)
     {on_l = 1; on_r = 0; X=0;}
   }
}

// || filter >=500 && filter<=599
//filter<=400  || filter>=623
//---------------------------------------------------------------------------------------- Phải 
void on_right() 
{
 if( on_r == 1 )
  { digitalWrite(right,HIGH); delay(50); digitalWrite(right,LOW); on_r = 0; }
}
void off_right() 
{
 if( off_r == 1 )
  { digitalWrite(right,HIGH); delay(50); digitalWrite(right,LOW); off_r = 0; }
}
//---------------------------------------------------------------------------------------- Trái
void on_left() 
{
 if( on_l == 1 )
  { digitalWrite(left,HIGH); delay(50); digitalWrite(left,LOW); on_l = 0; delay_l = millis(); }
}
void off_left() 
{
 if( off_l == 1 )
  { digitalWrite(left,HIGH); delay(50); digitalWrite(left,LOW); off_l = 0; }
}
void Mode() 
{
 if( off_m == 1 )
  { X = 1; digitalWrite(mode,HIGH); delay(50); digitalWrite(mode,LOW); delay(50); digitalWrite(mode,HIGH); delay(50); digitalWrite(mode,LOW); delay(50); digitalWrite(mode,HIGH); delay(50); digitalWrite(mode,LOW); delay(50); digitalWrite(mode,HIGH); delay(50); digitalWrite(mode,LOW);
    off_m = 0;
  }
}
