#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment(); //Initialize screen

void setup() {
  pinMode(10, OUTPUT);
  matrix.begin(0x70);
  DisplayCode(5, 2, 7, 0);
}

void loop() {
  digitalWrite(10, HIGH);
}

  void DisplayCode(int num1, int num2, int num3, int num4){
    matrix.writeDigitNum(0, num1, false);
    matrix.writeDigitNum(1, num2, false);
    matrix.drawColon(false);
    matrix.writeDigitNum(3, num3, false);
    matrix.writeDigitNum(4, num4, false);
    matrix.writeDisplay();
  }
