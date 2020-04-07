int switchPin = 2;                    // switch is connected to pin 2
int ledPin[] = {7,4};                      // led on pin 13
int buttonPresses[] = {0,0};                // how many times the button has been pressed
int switchpress = 0;
int next = 3;
int index = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(switchPin, INPUT);          // Set the switch pin as input
  pinMode(ledPin[0], OUTPUT);
  pinMode(ledPin[1], OUTPUT);

  pinMode(next, INPUT);          // Set the switch pin as input
  digitalWrite(switchPin, HIGH);      // set pullup resistor
  digitalWrite(next, HIGH);
  Serial.begin(9600);                 // Set up serial communication at 9600bps
}

void loop() {
  // put your main code here, to run repeatedly:
  //while (switchpress < 3)
  //{
  if (switchpress < 3){
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
    delay(250);          s             // debounce switch
    Serial.print("numer of times you pressed the button ");
    Serial.println(buttonPresses[0]);
        Serial.println(buttonPresses[1]);

  }

  if (buttonPresses[switchpress] % 2 == 0) digitalWrite(ledPin[switchpress], LOW);        // rollover every fourth press
  if (buttonPresses[switchpress] % 2 == 1) digitalWrite(ledPin[switchpress], HIGH);        // rollover every fourth press

  }
}


  
  
