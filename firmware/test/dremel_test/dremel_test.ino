// Etch a Schech
// Dremel Motor test script

int pwm;
void setup() {
}

void loop() {
  pwm = map(analogRead(A5), 0, 1023, 0, 100);
  analogWrite(5, pwm);
}
