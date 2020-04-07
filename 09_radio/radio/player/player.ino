/*
* Simple sketch for nRF24L01+ radios.  Transmit side.
*
*Specifically for  use with ATSAMD11C14 board using 
* 
* CE:  pin 8
* CSN os SS: pin 15 
* Updated: Dec 2014 by TMRh20. Simplified Mar 2019 RMH.
*/
int switchPin = 2;                    // switch is connected to pin 2
int ledPin[] = {7,4};                      // led on pin 13
int buttonPresses[] = {0,0};                // how many times the button has been pressed
int switchpress = 0;
int next = 3;
int index = 0;


#include <SPI.h>
#include "RF24.h"

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus CE and CS */
RF24 radio(4,5);      //CE and CS pins.  This is the change needed when you change to another board.

byte addresses[][6] = {"1Node","2Node"};
byte data[] = {0,0}; 

void setup() {
 Serial.begin(9600);
 // Serial.println("RF24example:  Simple tx");
  
  radio.begin();
  pinMode(switchPin, INPUT);          // Set the switch pin as input
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);

  pinMode(next, INPUT);          // Set the switch pin as input
  digitalWrite(switchPin, HIGH);      // set pullup resistor
  digitalWrite(next, HIGH);

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

   if (switchpress < 2){
    if (digitalRead(next) == LOW)  // check if button was pressed
  {
    switchpress++;                  // increment buttonPresses count
    delay(250);                       // debounce switch
    Serial.print("numer of times you switched ");
    Serial.println(switchpress);
  }
   
if (digitalRead(switchPin) == LOW)  // check if button was pressed
  {
    buttonPresses[switchpress]++;                  // increment buttonPresses count
    delay(250);                       // debounce switch
    Serial.print("numer of times you pressed the button ");
    Serial.println(buttonPresses[0]);
        Serial.println(buttonPresses[1]);

  }

  if (buttonPresses[switchpress] % 2 == 0) digitalWrite(ledPin[switchpress], LOW);        // rollover every fourth press
  if (buttonPresses[switchpress] % 2 == 1) digitalWrite(ledPin[switchpress], HIGH);        // rollover every fourth press

  }
 if (switchpress >= 2){       
data[0] = buttonPresses[0] % 2;
data[1] = buttonPresses[1] % 2;
  
Serial.print("Sent ");
Serial.println(data[0]);
Serial.println(data[1]);
 


delay(100);
 }
} // loop end
