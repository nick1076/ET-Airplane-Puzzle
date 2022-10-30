#include <Wire.h>
// Include the required Wire library for I2C<br>#include 
int x = 0;
int y = 0;
void setup() {
  // Start the I2C Bus as Master
  Wire.begin(1); 
  Wire.onReceive(receiveEvent);
}
void loop() {
  if (x != y){
    if (x == 0){
      Wire.beginTransmission(9); // transmit to device #9
      Wire.write(0);              // sends x 
      Wire.endTransmission();    // stop transmitting
    }
    else if (x == 1){
      Wire.beginTransmission(9); // transmit to device #9
      Wire.write(1);              // sends x 
      Wire.endTransmission();    // stop transmitting
    }
    y=x;
  }
  delay(500);
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
