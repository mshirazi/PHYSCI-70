#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#include <Servo.h>

Servo myservo;


RF24 radio(5, 6); // CE, CSN
byte addresses[][6] = {"1Node","2Node"};
boolean button_state = 0;
int led_pin = 3;
int angle;

void setup() {
myservo.attach(9);
Serial.begin(9600);
radio.begin();

radio.openWritingPipe(addresses[1]);
    radio.openReadingPipe(1,addresses[0]);
    radio.setPALevel(RF24_PA_MIN);       //You can set this as minimum or maximum depending on the distance between the transmitter and receiver.
radio.startListening();              //This sets the module as receiver
}
void loop() {
    Serial.println("test");
    byte rec_data;
    Serial.println(radio.available());
    if( radio.available()){
                                                                    // Variable for the received timestamp
      while (radio.available()) {                                   // While there is data ready
        radio.read( &rec_data, 1 );             // Get the payload
      }
     
      
      Serial.print("received ");
      Serial.println(rec_data); 
      angle = map(rec_data, 0, 255, 0, 180); 
      myservo.write(angle);
      //Serial.println(rec_data); 
   }



} // Loop
