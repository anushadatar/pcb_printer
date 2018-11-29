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
const uint8_t DIRZ_pin = 6;
const uint8_t STEPZ_pin = 7;

A4988 stepperX(MOTOR_STEPS, DIRX_pin, STEPX_pin, ENABLE, MS1, MS2, MS3);
A4988 stepperY(MOTOR_STEPS, DIRY_pin, STEPY_pin, ENABLE, MS1, MS2, MS3);
A4988 stepperZ(MOTOR_STEPS, DIRZ_pin, STEPZ_pin, ENABLE, MS1, MS2, MS3);
Encoder myEnc(2, A4);

GParse parser(115200, &stepperX, &stepperY, &stepperZ, &myEnc, RPM, MICROSTEPS);

State state=Idle_Entry;

void setup() {
  // put your setup code here, to run once:
  parser.Initialize();
  // attachInterrupt(digitalPinToInterrupt(2), offlimit, RISING);
  parser.motorsDisable();
  state = Idle;
  parser.Help();
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(state)
  {
    case Idle_Entry:
      parser.Initialize();
      attachInterrupt(digitalPinToInterrupt(2), offlimit, RISING);
      parser.motorsDisable();
      state = Idle;
      break;
    case Idle:
      parser.adjustZ();
      break;
    case Idle_Exit:
      parser.motorsEnable();
      Serial.write("?");
      state = Etching;
      break;
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
  parser.motorsDisable();
  state = LimitError;
}

void serialEvent() {
  switch(state){
    case Etching:
      return;
      break;
    case Idle_Entry:
      return;
      break;
    case Idle:
      if(Serial.available()) {
        char temp;
        temp = Serial.read();
        Serial.println(temp);
        if(temp=='!') {
          state=Idle_Exit;
        }
      }
      break;
    default:
      return;
      break;
  }
  return;
}
