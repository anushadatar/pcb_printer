#include <Stepper.h>

// Principles of Engineering Etch a Schech
// Stepper motor test code. Useful for sanity checking individual stepper motor functionality.

// Steps per revolution of the stepper motor.
const int stepsPerRevolution = 199; 
// Counter for number of motor steps.
int stepCount = 0;
// Initalize the stepper library.
Stepper myStepper(stepsPerRevolution,9,8,11,10);            
 
void setup() {
  Serial.begin(9600);
}

/* Step a step at some rpm, print the step count, wait, and then continue. */ 
void loop() {
  myStepper.step(200);
  Serial.print("steps:" );
  Serial.println(stepCount);
  stepCount++;
  delay(10000);
}

