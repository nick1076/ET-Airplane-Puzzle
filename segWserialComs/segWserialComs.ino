#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();
int x = 0;
 
void setup() 
{
#ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
#endif
  matrix.begin(0x70);
  DisplayCode(0, 1, 0, 0);
  Wire.begin(9);
  Wire.onReceive(receiveEvent);
}

void loop(){
  if (x == 1){
    DisplayCode(4, 6, 1, 8);
    Serial.println("here 1");
  }
  else if (x == 0){
    DisplayCode(0, 0, 0, 0);
    Serial.println("here 2");
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

void receiveEvent( int bytes ){
  x = Wire.read(); // read one character from the I2C
  Wire.endTransmission(); // stop transmitting
}
