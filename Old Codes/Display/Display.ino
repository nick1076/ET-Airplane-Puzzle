#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include "Adafruit_LEDBackpack.h"

int x = 0;
int y = 0;

int screenID = 9; //9 if screen 1, 10 if screen 2!

//Adafruit_7segment matrix = Adafruit_7segment(); //Initialize screen

void setup() {
  Wire.begin(screenID); 
  Wire.onReceive(receiveEvent);
  //matrix.begin(0x70);
  //DisplayCode(0, 0, 0, 0);
  pinMode(10, OUTPUT);
  blinkL(3, 10, 200);
}

void blinkL(int iter, int led, int timeL){
  for (int i = 0; i < iter; i++){
    digitalWrite(led, HIGH);
    delay(timeL);
    digitalWrite(led, LOW);
    delay(timeL);
  }
}

void receiveEvent(int bytes) {
  x = Wire.read();
}

void loop() {
  //Check if new bytes have been recieved
  if (x == y){
    return;
  }
  
  blinkL(2, 10, 100);
  
  y = x;
  
  if (x == 0) {
    //DisplayCode(0, 0, 0, 0);
  }
  if (x == 1) {
    //DisplayCode(1, 2, 3, 4);
  }
}

  /*void DisplayCode(int num1, int num2, int num3, int num4){
    matrix.writeDigitNum(0, num1, false);
    matrix.writeDigitNum(1, num2, false);
    matrix.drawColon(false);
    matrix.writeDigitNum(3, num3, false);
    matrix.writeDigitNum(4, num4, false);
    matrix.writeDisplay();
  }*/
