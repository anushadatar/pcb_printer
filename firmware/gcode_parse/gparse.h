#ifndef GPARSE_H
#include <Arduino.h>
#include "A4988.h"
#include <Encoder.h>

#define LED0 A1
#define LED1 A2
#define AXISCHANGE A3

typedef enum{
  Idle_Entry,
  Idle,
  Idle_Exit,
  Etching,
  Etching_Exit,
  LimitError,
} State;

typedef enum{
  Free,
  X,
  Y,
  Z
} AxisState;

/*
G-Code parser object that takes in G-Code file lines individually and converts them into motor movements.
*/

class GParse
{
    /*
    Outward-facing variables and methods for use over softare abstraction layers.
    */
    public:
        /*
        Constructor - requires inputs detailed more heavily in private fields. One instance of the parser listens over serial
        for G-Code commands, parses them, and converts them to concrete motor movements.
        */
        GParse(const unsigned long baud, A4988* X, A4988* Y, A4988* Z, Encoder* Decoder, uint8_t rpm, uint8_t microstep) :
            baud_(baud), stepperX_(X), stepperY_(Y), stepperZ_(Z), decoder_(Decoder), rpm_(rpm), microstep_(microstep) {}

        /*
        Kicks off serial monitor at specified baud rate, enables microstepping mode, and runs sanity check on gantry.
        
        Sanity check involves moving each stepper motor one rotation (assuming microstepping). Note that if the gantry has 
        run into one of the edges of the frame, manually reset it or this sanity check may cause mechanical failures.
        
        # TODO Could be nice to make the sanity check disable-able, or just have good limit switch things.
        */
        void Initialize();
    
        /*
        Waits over Serial for G-Code commands, and then implements them as needed.
        */
        void Listening(State* state);
        
        /*
        Systematically parses each individual G-Code command as they are heard over Serial.
        */
        void Processing();

        /*
        Prints G-Code syntax for each possible command for user.
        */
        void Help();
    
        /*
        Utility menthod to find number values associated with the specified code.
        
        CHAR code is the individual flag to search for when looking for the following float.
        FLOAT val is the floating-point value associated with the original code. 
        
        RETURNS FLOAT value of flagged character.
        */
        float ParseNum(char code, float val);
    
        /*
        Literally resets character counter. 
        */
        void Reseti();
        
        /*
        Draws straight line from existing point to given x and y coordinates.
        FLOAT newx is x-destination for gantry.
        FLOAT newy is y-destination for gantry.
        */
        void DrawLine(float newx, float newy);
    
        /*
        Draws arc from existing point along given radius to given point in given direction.
        FLOAT cx is the x component of the circle's center.
        FLOAT cy is the y component of the circle's center.
        FLOAT x is the x component of the radius.
        FLOAT y is the y component of the radius.
        FLOAT dir is the direction of the circle. #TODO Double check. 
            1 is clockwise, -1 is counter-clockwise.
        */
        void DrawArc(float cx,float cy,float x,float y,float dir);
    
        /*
        Utility method for calculating sign-adjusted inverse tangent of some number.
        */
        float atangent(float dy,float dx);     

        /*
        Limit Switch triggered error
        */
        void limitSwitchError(); 

        /*
        Enable the stepper and DC motors
        */
        void motorsEnable(); 

        /*
        Disable the stepper and DC motors
        */
        void motorsDisable();     

        /*
        Adjust Z axis stepper motor
        */
        void adjustZ();

        /*
        Adjust X, Y, Z axis stepper motors manually
        */
        void jogAxes(AxisState axis);

    private:
        // const uint8_t max_length;
        const unsigned long baud_;
        A4988* stepperX_;
        A4988* stepperY_;
        A4988* stepperZ_;
        Encoder* decoder_; 
        long posNow_;
        long posLast_;
        bool firstDecode_ = true;
        // BasicStepperDriver* stepperX_;
        // BasicStepperDriver* stepperY_;
        uint8_t rpm_;
        uint8_t microstep_;
        uint8_t i_ = 0;
        char buffer[64];
        float px_=0;
        float py_=0;
        float pz_=0;
        int8_t dirx_, diry_;
        float dx_, dy_;
        uint8_t modeAbs_=1;
};


#endif
