
#include <Wire.h>

void setup()
{
  pinMode(10, OUTPUT);
  
  Wire.begin(0);
  //PORTB_PIN0CTRL |= PORT_PULLUPEN_bm ;
  //PORTB_PIN1CTRL |= PORT_PULLUPEN_bm;
}

void loop()
{
  delay(3000);
  PingStudentOne();
  digitalWrite(10, HIGH);
  delay(200);
  digitalWrite(10, LOW);
  delay(3000);
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
  delay(1000);
  Wire.endTransmission();
}

void PingStudentTwo()
{
  Wire.beginTransmission(2);
  Wire.write(1);
  delay(1000);
  Wire.endTransmission();
}
