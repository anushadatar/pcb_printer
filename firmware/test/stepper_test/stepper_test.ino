#include <Stepper.h>
 
const int stepsPerRevolution = 199;  // change this to fit the number of steps per revolution
                                     // for your motor
 
// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution,9,8,11,10);            
 
int stepCount = 0;         // number of steps the motor has taken
 
void setup() {
  // initialize the serial port:
  Serial.begin(9600);
}
 
void loop() {
  // step one step:
  myStepper.step(200);
  Serial.print("steps:" );
  Serial.println(stepCount);
  stepCount++;
  delay(10000);
}

