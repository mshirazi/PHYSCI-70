//Code to transmit
//Microcontroller has a button input and a digital output.
//The digital output can be connected to a digital input of a receiving microcontroller to make a simple network.
//The wired-together devices must share a common ground!

const int out_pin = 14;
const int button_pin = 8;

void setup() {
  pinMode(button_pin, INPUT_PULLUP);  //This is the button pin.
  pinMode(out_pin, OUTPUT);         // pin 5 for digital Write

  Serial.begin(9600);        //for the USB serial devices, this baud rate is meaningless - can be "0"
}

void loop() {
  int buttonState = digitalRead(button_pin);
  Serial.println(buttonState);
  digitalWrite(out_pin, buttonState);
  delay(10);
  }
