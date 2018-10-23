#include "gparse.h"
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 120

#define DIR 8
#define STEP 9
#define ENABLE 13 // optional (just delete ENABLE from everywhere if not used)
#define MS1 10
#define MS2 11
#define MS3 12
A4988 stepper1(MOTOR_STEPS, DIR, STEP, ENABLE, MS1, MS2, MS3);
A4988 stepper2(MOTOR_STEPS, DIR, STEP, ENABLE, MS1, MS2, MS3);
GParse parser(115200, &stepper1, &stepper2);
void setup() {
  // put your setup code here, to run once:
  parser.Initialize();
//  parser.Listening();
}

void loop() {
  // put your main code here, to run repeatedly:
  parser.Listening();
  // parser.Processing();
  // parser.Reseti();
}
