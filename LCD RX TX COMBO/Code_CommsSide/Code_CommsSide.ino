#include <Wire.h>

int y = 0;
int x = 0;

void setup()
{
  pinMode(10, OUTPUT);

  Serial.begin(9600);
  
  Wire.begin(1);
  Wire.onReceive(readData);
  
  PORTB_PIN0CTRL |= PORT_PULLUPEN_bm;
  PORTB_PIN1CTRL |= PORT_PULLUPEN_bm;
}

void loop()
{
  if (x != y)
  {
    //We recieved a new value, pass it off to the LCD control board
    y = x;
    Serial.print(x, DEC);
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
  }
}

void readData()
{
  while (0 < Wire.available())
  {
    x = Wire.read();
  }
}
