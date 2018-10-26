#ifndef GPARSE_H
#include <Arduino.h>
#include "A4988.h"
// #include "BasicStepperDriver.h"

class GParse// : private Fsm
{
    public:
    GParse(const unsigned long baud, BasicStepperDriver* X, BasicStepperDriver* Y, uint8_t rpm, uint8_t microstep) :
        baud_(baud), stepperX_(X), stepperY_(Y), rpm_{rpm}, microstep_{microstep} {}

        void Initialize();
        void Listening();
        void Processing();

        void Help();
        float ParseNum(char code, float val);
        void Reseti();
        void DrawLine(float newx, float newy);
        void DrawArc(float cx,float cy,float x,float y,float dir);
        float atangent(float dy,float dx);
        void SetPosition(float newx, float newy);
        

    private:
        // const uint8_t max_length;
        const unsigned long baud_;
        A4988* stepperX_;
        A4988* stepperY_;
        // BasicStepperDriver* stepperX_;
        // BasicStepperDriver* stepperY_;
        uint8_t rpm_;
        uint8_t microstep_;
        uint8_t i_ = 0;
        char buffer[64];
        float px_=0;
        float py_=0;
        int8_t dirx_, diry_;
        float dx_, dy_;
        uint8_t modeAbs_=0;
};


#endif
