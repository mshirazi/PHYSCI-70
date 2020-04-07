int switchPin = 33;                    // switch is connected to pin 2
int next = 25;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(switchPin, INPUT);          // Set the switch pin as input
  pinMode(next, INPUT);          // Set the switch pin as input
  digitalWrite(switchPin, HIGH);      // set pullup resistor
  digitalWrite(next, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.print("top button ");
  Serial.println(digitalRead(switchPin));
  //Serial.print("bottom button ");
  //Serial.println(digitalRead(next));
  //delay(5000);
}
