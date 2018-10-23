#ifndef GPARSE_H
#include <Arduino.h>
#include "fsm.h"
#include "A4988.h"


class GParse// : private Fsm
{
    public:
    GParse(const unsigned long baud, A4988* X, A4988* Y) :
        baud_(baud), stepperX_(X), stepperY_(Y) {}

        void Initialize();
        void Listening();
        void Processing();

        void Help();
        float parseNum(char code, float val);
        void Reseti();
        

    private:
        // const uint8_t max_length;
        const unsigned long baud_;
        A4988* stepperX_;
        A4988* stepperY_;
        uint8_t i = 0;
        char buffer[64];
};


#endif