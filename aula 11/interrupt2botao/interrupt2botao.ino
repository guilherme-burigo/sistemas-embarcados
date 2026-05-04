const int led = 9;
const int interruptPin = 2;
const int interruptPin2 = 3;
bool state = LOW;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  pinMode(interruptPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), liga, FALLING);
  attachInterrupt(digitalPinToInterrupt(interruptPin2), desliga, FALLING);

}

void loop() {
  digitalWrite(led, state);

}
void liga() {
  state = 1;

}
void desliga() {
  state = 0;
}