#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

void setup()
{
  pinMode(10, OUTPUT);

  Serial.begin(9600);
  matrix.begin(0x70);
  
  PORTB_PIN0CTRL |= PORT_PULLUPEN_bm;
  PORTB_PIN1CTRL |= PORT_PULLUPEN_bm;
}

void loop()
{
  while (Serial.available()==0);
  
  int incoming = Serial.parseInt();
  
  digitalWrite(10, HIGH);
  delay(100);
  digitalWrite(10, LOW);
    
  if (incoming == 0){
    //Turn off screen
    DisplayCode(0, 0, 0, 0);
  }
  else if (incoming == 1){
    //Turn on screen
    DisplayCode(1, 2, 3, 4);
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
