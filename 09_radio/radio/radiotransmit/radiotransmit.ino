/*
* Simple sketch for nRF24L01+ radios.  Transmit side.
*
*Specifically for  use with ATSAMD11C14 board using 
* 
* CE:  pin 8
* CSN os SS: pin 15 
* Updated: Dec 2014 by TMRh20. Simplified Mar 2019 RMH.
*/

#include <SPI.h>
#include "RF24.h"

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus CE and CS */
RF24 radio(8,15);      //CE and CS pins.  This is the change needed when you change to another board.

byte addresses[][6] = {"1Node","2Node"};
byte data = 0; 

void setup() {
 // Serial.begin(0);
 // Serial.println("RF24example:  Simple tx");
  
  radio.begin();

 // Set the PA Level low to prevent power supply related issues since this is a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  
  // Open a writing and reading pipe on each radio, with opposite addresses

  radio.openWritingPipe(addresses[0]);
  radio.openReadingPipe(1,addresses[1]);
 
}

void loop() {
  
//Serial.println("Now sending");

  
                           
  if (!radio.write( &data, 1 )){
  //  Serial.println(F("failed"));
   }
        
data = (analogRead(2))/4;
  
Serial.print("Sent ");
Serial.println(data);
   


delay(100);

} // loop end
