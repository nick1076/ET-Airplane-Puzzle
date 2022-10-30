
#include <Wire.h> //include Wire.h library

void setup() {
  Serial.begin(9600);
  Wire.beginTransmission( 0x70);
  int error = Wire.endTransmission();
  if( error != 0)
  {
    Serial.println( "The sensor is not at 0x60");
  }
  else
  {
    Serial.println( "The sensor is found, changing I2C address");
    Wire.beginTransmission( 0x70);
    Wire.write( 0x53);  // password register
    Wire.write( 0xAA);  // password
    Wire.endTransmission();

    delay(10);    // not described somewhere, just for safety

    Wire.beginTransmission( 0x70);
    Wire.write( 0x00);  // I2C address register
    Wire.write( 0x50);  // new I2C address
    Wire.endTransmission();
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}
