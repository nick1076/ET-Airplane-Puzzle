#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
// Include the required Wire library for I2C<br>#include <Wire.h>
int LED = 13;
int x = 0;
int y = 0;

#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

void setup() {
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  matrix.begin(0x70);
  DisplayCode(0, 0, 0, 0);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {
  if (x == y){
    return;
  }
  y = x;
  //If value received is 0 blink LED for 200 ms
  if (x == 0) {
    Serial.println(1);
    DisplayCode(0, 0, 0, 0);
  }
  //If value received is 3 blink LED for 400 ms
  if (x == 1) {
    Serial.println(2);
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
