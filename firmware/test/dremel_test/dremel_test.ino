int pwm;
void setup() {
  // put your setup code here, to run once:
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  pwm = map(analogRead(A5), 0, 1023, 0, 100);
  analogWrite(5, pwm);
}
