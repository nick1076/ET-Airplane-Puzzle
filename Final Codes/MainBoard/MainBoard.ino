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
  //If true, a new set of bytes have been read
  if (x != y){
    blinkL(2, 4, 100);
    if (x >= 0 && x < 10){
      //RFID 1 is trying to communicate
      if (x == 0){
        //RFID 1 is saying the piece is not in place
        piece1 = false;
      }
      else if (x == 1){
        //RFID 1 is saying the piece is in place
        piece1 = true;
      }
    }
    else if (x >= 10 && x < 20){
      //RFID 2
      if (x == 10){
        piece2 = false;
      }
      else if (x == 11){
        piece2 = true;
      }
    }
    else if (x >= 20 && x < 30){
      //RFID 3
      if (x == 20){
        piece3 = false;
      }
      else if (x == 21){
        piece3 = true;
      }
    }
    else if (x >= 30){
      //RFID 4
      if (x == 30){
        piece4 = false;
      }
      else if (x == 31){
        piece4 = true;
      }
    }
    
    if (piece1 && piece2 && piece3 && piece4){
      ShowCodes();
    }
    else{
      HideCodes();
    }
    y=x;
  }
  delay(50); //Wait before checking again for new bytes
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
