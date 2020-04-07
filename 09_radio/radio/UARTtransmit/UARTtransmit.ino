//Code to transmit
//Microcontroller has a potentiometer input:  wiper pin attached to analog in.
//Sends a signal to receiver through the USART transmit pin (TX)  (or TX1 for some boards)

//Can receive  a signal throught the USART receive pin (RX), but this is not
// implemented in this simplest sketch.

//The wired-together devices must share a common ground!

const int pot_pin = 2;


void setup() {
  Serial.begin(0);        //for the USB serial devices, this baud rate is meaningless - can be "0"
  Serial1.begin(9600);      //this is the USART SERIAL.  On SAM boards, like ItsyBitsy and D11, this is called "Serial1"
                  //Baud rate is important on this one!
}

void loop() {

int pot_value = analogRead(pot_pin);
Serial.println(pot_value);          //This is for diagnostic purposes
Serial1.write(pot_value/4);     //This one is data sent to the other board.  divide by four to make the range 0-255.
delay(10);

}
