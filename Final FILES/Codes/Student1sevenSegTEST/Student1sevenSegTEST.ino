#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

int x = 0;
Adafruit_7segment matrix = Adafruit_7segment();

void setup()
{
  matrix.begin(0x70);
  
  pinMode(10, OUTPUT);
  
  Wire.begin(1);
  Wire.onReceive(readData);
  
  DisplayCode(0, 1, 0, 0);
  
  PORTB_PIN0CTRL |= PORT_PULLUPEN_bm;
  PORTB_PIN1CTRL |= PORT_PULLUPEN_bm;
}

void loop()
{
  if (x == 1)
  {
    x = 0;
    digitalWrite(10, HIGH);
    DisplayCode(1, 2, 3, 4);
    delay(100);
    digitalWrite(10, LOW);
    DisplayCode(0, 2, 0, 0);
  }
  else{
    delay(100);
  }
}

void readData()
{
  while (0 < Wire.available())
  {
    x = Wire.read();
  }
}

void DisplayCode(int num1, int num2, int num3, int num4){
    matrix.writeDigitNum(0, num1, false);
    matrix.writeDigitNum(1, num2, false);
    matrix.drawColon(false);
    matrix.writeDigitNum(3, num3, false);
    matrix.writeDigitNum(4, num4, false);
    matrix.writeDisplay();
  }
