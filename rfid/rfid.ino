#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
 
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.

int outcome = 0;
 
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  Wire.begin(); 

}
void loop() 
{
  bool continueOn = true;
  int prevOutcome = outcome;
  // Look for new cards
  // Select one of the cards
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) {
    Serial.println("Piece no longer in place!");
    outcome = 0;
    continueOn = false;
  }
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    continueOn = false;
  }

  if (continueOn == false){
    if (prevOutcome == 1 && outcome == 0){
      return;
    }
    delay(300);
    Wire.beginTransmission(1); // transmit to device #9
    Wire.write(outcome);              // sends x 
    Wire.endTransmission(true);    // stop transmitting
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  Serial.println();
  Serial.print("Message : ");
  content.toUpperCase();
  if (content.substring(1) == "93 0C 78 92") //change here the UID of the card/cards that you want to give access
  {
    Serial.println("Piece is in place!");
    outcome = 1;
    Serial.println();
    delay(300);
  }
 
 else   {
    Serial.println("Wrong piece is in place!");
    outcome = 0;
    delay(300);
  }
  
   Wire.beginTransmission(1); // transmit to device #9
   Wire.write(outcome);              // sends x 
   Wire.endTransmission(true);    // stop transmitting
} 
