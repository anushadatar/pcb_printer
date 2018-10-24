#include "gparse.h"
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 20

// #define DIR 8
// #define STEP 9
#define ENABLE 13 // optional (just delete ENABLE from everywhere if not used)
#define MS1 10
#define MS2 11
#define MS3 12

const uint8_t DIRX_pin = 8;
const uint8_t STEPX_pin = 9;
const uint8_t DIRY_pin = 7;
const uint8_t STEPY_pin = 6;

A4988 stepperX(MOTOR_STEPS, DIRX_pin, STEPX_pin, ENABLE, MS1, MS2, MS3);
A4988 stepperY(MOTOR_STEPS, DIRY_pin, STEPY_pin, ENABLE, MS1, MS2, MS3);
GParse parser(115200, &stepperX, &stepperY, RPM);
void setup() {
  // put your setup code here, to run once:
  parser.Initialize();
}

void loop() {
  // put your main code here, to run repeatedly:
  parser.Listening();
}
