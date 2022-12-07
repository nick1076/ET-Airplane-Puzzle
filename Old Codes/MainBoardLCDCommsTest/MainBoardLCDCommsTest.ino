#include <Wire.h>

int x = 0; //Incoming
int y = 0; //Previous Incoming

//Piece vars
bool piece1 = false;
bool piece2 = false;
bool piece3 = false;
bool piece4 = false;

void setup() {
  Wire.begin(1); // Start the I2C Bus as Master
  Wire.onReceive(receiveEvent); //Initialize Recieve Event
  pinMode(4, OUTPUT);
  blinkL(3, 4, 200);
}

void blinkL(int iter, int led, int timeL){
  for (int i = 0; i < iter; i++){
    digitalWrite(led, HIGH);
    delay(timeL);
    digitalWrite(led, LOW);
    delay(timeL);
  }
}

void loop() {
  delay(2000);
  blinkL(2, 4, 100);
  ShowCodes();
  delay(2000);
  blinkL(3, 4, 50);
  HideCodes();
}

void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}

void ShowCodes(){
  Wire.beginTransmission(9); //Begin communication with screen 1
  Wire.write(1); //Turn on screen 1
  Wire.endTransmission(); //End communication with screen 1
  
  Wire.beginTransmission(10); //Begin communication with screen 2
  Wire.write(1); //Turn on screen 2
  Wire.endTransmission(); //End communication with screen 2
}

void HideCodes(){
  Wire.beginTransmission(9); //Begin communication with screen 1
  Wire.write(0); //Turn off screen 1
  Wire.endTransmission(); //End communication with screen 1
  
  Wire.beginTransmission(10); //Begin communication with screen 2
  Wire.write(0); //Turn off screen 2
  Wire.endTransmission(); //End communication with screen 2
}
