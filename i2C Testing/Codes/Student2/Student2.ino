#include <Wire.h>

int x = 0;

void setup()
{
  pinMode(13, OUTPUT);
  
  Wire.begin(2);
  Wire.onReceive(readData);
  
  //PORTB_PIN0CTRL |= PORT_PULLUPEN_bm;
  //PORTB_PIN1CTRL |= PORT_PULLUPEN_bm;
}

void loop()
{
  if (x == 1)
  {
    x = 0;
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
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
