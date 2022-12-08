
//Libraries
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

//Define 7 Segment #1
Adafruit_7segment matrix = Adafruit_7segment();

void setup() {

  //Debug Light Definition & Enabling
  pinMode(1, OUTPUT);

  //Contact Definitions
  pinMode(10, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);

  //Initialize 7 Segment #1
  matrix.begin(0x70);
}

void loop() {
  //Check if all pieces are in place (All Contacts read LOW)
  if (digitalRead(10) == LOW && digitalRead(9) == LOW && digitalRead(8) == LOW && digitalRead(0) == LOW){
    //All pieces are in place!
    DisplayCode(1, 2, 3, 4);
  }
  else{
    //Not all pieces are in place
    DisplayCode(0, 0, 0, 0);
  }

  if (digitalRead(10) == LOW){
    digitalWrite(1, HIGH);
  }
  else{
    digitalWrite(1, LOW);
  }
}

//Function to control code display
void DisplayCode(int num1, int num2, int num3, int num4){
  matrix.writeDigitNum(0, num1, false);
  matrix.writeDigitNum(1, num2, false);
  matrix.drawColon(false);
  matrix.writeDigitNum(3, num3, false);
  matrix.writeDigitNum(4, num4, false);
  matrix.writeDisplay();
}
