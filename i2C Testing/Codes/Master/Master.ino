
#include <Wire.h>

void setup()
{
  pinMode(10, OUTPUT);
  
  Wire.begin();
  
  PORTB_PIN0CTRL |= PORT_PULLUPEN_bm ;
  PORTB_PIN1CTRL |= PORT_PULLUPEN_bm;
}

void loop()
{
  delay(1500);
  PingStudentOne();
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(10, LOW);
  delay(1500);
  PingStudentTwo();
  digitalWrite(10, HIGH);
  delay(50);
  digitalWrite(10, LOW);
  delay(50);
  digitalWrite(10, HIGH);
  delay(50);
  digitalWrite(10, LOW);
  delay(50);
}


void PingStudentOne()
{
  Wire.beginTransmission(1);
  Wire.write(1);
  Wire.endTransmission();
  delay(1000);
}

void PingStudentTwo()
{
  Wire.beginTransmission(2);
  Wire.write(1);
  Wire.endTransmission();
  delay(1000);
}
