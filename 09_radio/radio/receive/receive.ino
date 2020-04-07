//Code to move a servomotor in response to a change in input pin.
//Use as a simple example of receiving for a wired network 3/30/20.  Rob Hart.


#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  pinMode(7, INPUT_PULLUP);   // pin 7 for digitial read
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  if (digitalRead(7)) myservo.write(0); // commands the servo to jump to its middle position (90 degrees)
  else myservo.write(90);
}
