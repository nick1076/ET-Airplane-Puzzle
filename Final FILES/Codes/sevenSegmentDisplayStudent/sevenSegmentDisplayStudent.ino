#include <Wire.h>

int x = 0;

Adafruit_7segment matrix = Adafruit_7segment(); //***

void setup()
{
  pinMode(10, OUTPUT);
  
  Wire.begin(1);
  Wire.onReceive(readData);

  matrix.begin(0x70); //***
  
  PORTB_PIN0CTRL |= PORT_PULLUPEN_bm;
  PORTB_PIN1CTRL |= PORT_PULLUPEN_bm;
}

void loop()
{
  if (x == 1)
  {
    x = 0;
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
    DisplayCode(1, 2, 3, 4); //***
  }
  if (x == 2)
  {
    x = 0;
    digitalWrite(10, HIGH);
    delay(100);
    digitalWrite(10, LOW);
    DisplayCode(0, 0, 0, 0); //***
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

 //***Following Method
void DisplayCode(int num1, int num2, int num3, int num4){
    matrix.writeDigitNum(0, num1, false);
    matrix.writeDigitNum(1, num2, false);
    matrix.drawColon(false);
    matrix.writeDigitNum(3, num3, false);
    matrix.writeDigitNum(4, num4, false);
    matrix.writeDisplay();
  }
