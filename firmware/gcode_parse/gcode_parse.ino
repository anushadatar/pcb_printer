#include "gparse.h"
// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 40
#define MICROSTEPS 8

// #define DIR 8
// #define STEP 9
#define ENABLE 13 // optional (just delete ENABLE from everywhere if not used)
#define MS1 12
#define MS2 11
#define MS3 10

const uint8_t DIRX_pin = 8;
const uint8_t STEPX_pin = 9;
const uint8_t DIRY_pin = 3;
const uint8_t STEPY_pin = 4;

A4988 stepperX(MOTOR_STEPS, DIRX_pin, STEPX_pin, ENABLE, MS1, MS2, MS3);
A4988 stepperY(MOTOR_STEPS, DIRY_pin, STEPY_pin, ENABLE, MS1, MS2, MS3);
// BasicStepperDriver stepperX(MOTOR_STEPS, DIRX_pin, STEPX_pin);
// BasicStepperDriver stepperY(MOTOR_STEPS, DIRY_pin, STEPY_pin);
GParse parser(115200, &stepperX, &stepperY, RPM, MICROSTEPS);

typedef enum{
  Etching,
  LimitError,
} State;

State state=Etching;
void setup() {
  // put your setup code here, to run once:
  parser.Initialize();
  attachInterrupt(digitalPinToInterrupt(2), offlimit, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(state)
  {
    case Etching:
      parser.Listening();
      break;
    case LimitError:
      parser.limitSwitchError();
      break;
    default:
      break;
  }
}

void offlimit(){
  state = LimitError;
}
