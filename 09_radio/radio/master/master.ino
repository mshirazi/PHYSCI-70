int switchPin = 33;                    // switch is connected to pin 2
int ledPin[] = {14,32};                      // led on pin 13
int buttonPresses[] = {0,0};                // how many times the button has been pressed
int switchpress = 0;
int next = 25;


void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);          // Set the switch pin as input
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);

  pinMode(next, INPUT);          // Set the switch pin as input
  //digitalWrite(switchPin, HIGH);      // set pullup resistor
  //digitalWrite(next, HIGH);
  Serial.begin(9600);                 // Set up serial communication at 9600bps
  //Serial.println("initialise");
  //Serial.print("switchpress ");
  //Serial.println(switchpress);
  //Serial.print("first led presses ");
  //Serial.println(buttonPresses[0]);
  //Serial.print("second led presses ");
  //Serial.println(buttonPresses[1]);
}

void loop() {
  // put your main code here, to run repeatedly:
  //while (switchpress < 3)
  //{
  //Serial.print("switchpress ");
  //Serial.println(switchpress);
  //Serial.print("first led presses ");
  //Serial.println(buttonPresses[0]);
  //Serial.print("second led presses ");
  //Serial.println(buttonPresses[1]);
  if (switchpress < 3){
    if (digitalRead(next) == HIGH)  // check if button was pressed
  {
    switchpress++;                  // increment buttonPresses count
    delay(500);                       // debounce switch
    Serial.print("numer of times you switched ");
    Serial.println(switchpress);
  }
   
if (digitalRead(switchPin) == HIGH)  // check if button was pressed
  {
    buttonPresses[switchpress]++;                  // increment buttonPresses count
    delay(500);                      // debounce switch
    Serial.print("numer of times you pressed the button ");
    Serial.println(buttonPresses[0]);
    Serial.println(buttonPresses[1]);

  }

  if (buttonPresses[switchpress] % 2 == 0) digitalWrite(ledPin[switchpress], LOW);        // rollover every fourth press
  if (buttonPresses[switchpress] % 2 == 1) digitalWrite(ledPin[switchpress], HIGH);        // rollover every fourth press

  }
  //delay(5000);
}


  
  
