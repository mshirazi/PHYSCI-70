//Code to move a servomotor in response to a change in input pin.
//Use as a simple example of receiving for a wired network 3/30/20.  Rob Hart.


#include <Servo.h>


Servo myservo;  // create servo object to control a servo

void setup() {
  
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  //Serial.begin(0);        //for the USB serial devices, this baud rate is meaningless - can be "0"
  Serial.begin(9600);      //this is the USART SERIAL.  On SAM boards, like ItsyBitsy and D11, this is called "Serial1"
  //Baud rate is important on this one!
}

void loop() {

 // while (!Serial.available()) {      //wait until serial from UART is available.
 // }

  byte rec_byte =  Serial.read();    //Here is where the incoming byte is read.
  //Serial.println(rec_byte);       //for diagnosing using USB serial
  Serial.println(rec_byte);
  int degree = rec_byte*90/255;      //conversion between one byte and 90 degrees.
  Serial.println(degree);           //for diagnosing using USB serial
  myservo.write(degree);
}
