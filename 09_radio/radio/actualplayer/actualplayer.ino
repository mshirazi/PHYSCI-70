
/*
* Simple sketch for nRF24L01+ radios  Receive side.
* 
* Updated: Dec 2014 by TMRh20. Simplified Mar 2019 RMH.
*/

#include <Servo.h>
#include <SPI.h>
#include "RF24.h"

int switchPin = 2;                    // switch is connected to pin 2
int ledPin[] = {7,4};                      // led on pin 13
int buttonPresses[] = {0,0};                // how many times the button has been pressed
int switchpress = 0;
int next = 3;
int index = 0;
int buzzerPin = 10;
String tempdata = "";

Servo myservo;

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(5,6);


byte addresses[][6] = {"1Node","2Node"};
int angle;
void setup() {
    pinMode(buzzerPin, OUTPUT);

pinMode(switchPin, INPUT);          // Set the switch pin as input
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);

  pinMode(next, INPUT);          // Set the switch pin as input
  digitalWrite(switchPin, HIGH);      // set pullup resistor
  digitalWrite(next, HIGH);
  myservo.attach(9);
  Serial.begin(0);
  Serial.println(F("RF24example:  simple receive"));
  
  
  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  
 
    radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
 
  
  // Start the radio listening for data
  radio.startListening();
}

void loop() {
    Serial.println("test");
    byte rec_data;
    Serial.println(radio.available());
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
    if( radio.available()){
                                                                    // Variable for the received timestamp
      while (radio.available()) {                                   // While there is data ready
        radio.read( &rec_data, 1 );             // Get the payload
        
      }
     
      
      Serial.print("received ");
      
      //Serial.println(rec_data);
      tempdata = String(buttonPresses[0] % 2) + String(buttonPresses[1] % 2);
      if (rec_data == tempdata){
        tone(buzzerPin, 1000, 500);
  delay(1000);
      }
      //angle = map(rec_data, 0, 255, 0, 180); 
      //myservo.write(angle);
      //Serial.println(rec_data); 
   }



} // Loop
