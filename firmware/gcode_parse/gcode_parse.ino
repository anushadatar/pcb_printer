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
AxisState axis=Free;

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
      // parser.adjustZ();
      Serial.println(axis);
      parser.jogAxes(axis);
      break;
    case Idle_Exit:
      parser.motorsEnable();
      Serial.write("?");
      state = Etching;
      analogWrite(5, 105);
      break;
    case Etching:
      parser.Listening(&state);
      break;
    case Etching_Exit:
      parser.motorsDisable();
      state = Idle;
      axis = Free;
      break;
    case LimitError:
      if(!(PINC&_BV(PC0))){
        state = Idle;
        axis = Free;
      }
      delay(100);
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

ISR(PCINT1_vect){
  delay(3);
  if((PINC&_BV(PC3))&&state==Idle){
    if(axis==Free){
      axis = X;
    }else if(axis==X){
      axis = Y;
    }else if(axis==Y){
      axis = Z;
    }else if(axis==Z){
      axis = Free;
    }

    switch(axis){
      case Free:
        // Axis State Free
        PORTC &= ~_BV(PC1) & ~_BV(PC2); //Turn off LED 0 and 1
        break;
      case X:
        // Axis State X
        PORTC &= ~_BV(PC2); //Turn off LED 0
        PORTC |= _BV(PC1); //Turn on LED 1
        break;

      case Y:
        // Axis State Y
        PORTC &= ~_BV(PC1); //Turn off LED 1
        PORTC |= _BV(PC2); //Turn on LED 0
        break;

      case Z:
        // Axis State Z
        PORTC |= _BV(PC1) | _BV(PC2); //Turn on LED 0 and 1
        break;
    }
  }
  if(PINC&_BV(PC0)){
    parser.motorsDisable();
    state = LimitError;
  }
}
