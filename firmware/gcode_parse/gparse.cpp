#include "gparse.h"

// Segment length for arc drawing. Relatively arbitrary.
const float SEGMENT_LENGTH = 100;

void GParse::Initialize(){
    // Kick off Serial monitor and print help message.
    Serial.begin(baud_);
    
    pinMode(AXISCHANGE, INPUT);
    PCICR |= _BV(PCIE1);
    PCMSK1 |= _BV(PCINT11);
    sei();
    pinMode(LED0, OUTPUT);
    pinMode(LED1, OUTPUT);

    // Kick of stepper motors and microstepping mode.
    stepperX_->begin(rpm_);
    stepperX_->enable();
    stepperY_->begin(rpm_);
    stepperY_->enable();
    stepperZ_->begin(rpm_);
    stepperZ_->enable();
    stepperX_->setMicrostep(8);   // Set microstep mode to 1:8
    stepperY_->setMicrostep(8);   // Set microstep mode to 1:8
    stepperZ_->setMicrostep(8);
    // In 1:8 microstepping mode, one revolution takes 8 times as many microsteps
        

    // // Sanity check by moving each stepper motor.
    // stepperX_->move(8 * 360);    // forward revolution
    // stepperX_->move(-8 * 360);   // reverse revolution
    // // In 1:8 microstepping mode, one revolution takes 8 times as many microsteps
    // stepperY_->move(8 * 360);    // forward revolution
    // stepperY_->move(-8 * 360);   // reverse revolution

    // stepperX_->disable();
    // stepperY_->disable();
    // stepperZ_->disable();
    Reseti();
}

void GParse::Help(){
    // Includes commands for supported G-Code Commands
    //  Serial.println(F("Commands:"));
    //  Serial.println(F("G00 [X(steps)] [Y(steps)] [F(feedrate)]; - Fast linear move"));
    //  Serial.println(F("G01 [X(steps)] [Y(steps)] [F(feedrate)]; - linear move"));
    //  Serial.println(F("G02 [X(radius)] [Y(radius)] [I(center x component)] [J(center y component)]; Arcs clockwise"));
    //  Serial.println(F("G02 [X(radius)] [Y(radius)] [I(center x component)] [J(center y component)]; Arcs clockwise"));
}

void GParse::Listening(State* state){
    if(Serial.available()){
        char c = Serial.read();
        if(c=='?') {
          *state=Etching_Exit;
        }
        buffer[i_++] = c;
        if(c=='\n') {
            buffer[i_]=(char)0;
            Processing();
            Reseti();
            Serial.print(F("$")); 
        }
    }
}

void GParse::Processing(){
    int cmd=(int)ParseNum('G',-1);
    switch(cmd){
        // Linear motion.
        case 0: 
        case 1: 
        {
            DrawLine(ParseNum('X',(modeAbs_?px_:0)) + (modeAbs_?0:px_), ParseNum('Y',(modeAbs_?py_:0)) + (modeAbs_?0:py_) );
            long z_value = ParseNum('Z', (modeAbs_?pz_:0)) + (modeAbs_?0:pz_);
            if (z_value != -1) {
                stepperZ_->move(pz_ - z_value);
                pz_ = z_value;
                Serial.println(pz_);
            }
        break;
        }
        // Move in a clockwise arc.
        case 2: 
        {
            float cx = ParseNum('I', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float cy = ParseNum('J', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            float x =  ParseNum('X', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float y =  ParseNum('Y', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            DrawArc(cx, cy, x, y, 1); 
            break;
        }
        // Move in a counter-clockwise arc.
        case 3:
        { 
            float cx = ParseNum('I', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float cy = ParseNum('J', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            float x =  ParseNum('X', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float y =  ParseNum('Y', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            DrawArc(cx, cy, x, y, 0);        
            break;
        }
        // Delay.
        case 4: delay(ParseNum('P', 0)); break;
        // Absolute coordinate mode.
        case 90: modeAbs_=1; break; 
        // Relative coordinate mode.
        case 91: modeAbs_=0; break; 
        default: break;
    }

    cmd=(int)ParseNum('M',-1);
    Serial.print("M cmd ");Serial.println(cmd);
    switch(cmd){
        case 2: 
        {
            float cx = ParseNum('I', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float cy = ParseNum('J', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            float x =  ParseNum('X', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float y =  ParseNum('Y', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            DrawArc(cx, cy, x, y, 1); 
            break;
        }
        // Move in a counter-clockwise arc.
        case 3:
            // Enable the spindle here
            break;
        case 5:
            // Disable the spindle here
        default: break;
    }
}

float GParse::ParseNum(char code,float val) {
    char *ptr=buffer; 
    // Search for the character and grab the float if found.
    while((long)ptr > 1 && (*ptr) && (long)ptr < (long)buffer+i_) {
        if(*ptr==code) { 
            return atof(ptr+1);
        }
        ptr=strchr(ptr,' ')+1;
    }
    return val;  
}

void GParse::Reseti(){
    // Reset i for the counter to work.
    i_ = 0;
}

void GParse::DrawLine(float newx, float newy){
    // Calculate and print distances based on directionality.
    dx_ = newx - px_;
    dy_ = newy - py_;
    // Serial.print("dx "); Serial.println(dx_); 
    // Serial.print("dy "); Serial.println(dy_);
    dirx_ = (dx_>0) ? 1:-1;
    diry_ = (dy_>0) ? 1:-1;
    dx_ = abs(dx_);
    dy_ = abs(dy_);
    // Serial.print("dx "); Serial.print(dx_); Serial.print("; dirx "); Serial.println(dirx_);
    // Serial.print("dy "); Serial.print(dy_); Serial.print("; diry "); Serial.println(diry_);
    
    // Step for as long as necessary to move specified distance.
    unsigned long counts;
    long over = 0;
    if(dx_ > dy_) { 
        // Step in the x direction dx times, step once if y for every dy/dx steps in x direction.
        for(counts=0; counts < dx_; counts++){
            stepperX_->move(dirx_);
            over += dy_;
            if(over>=dx_){
                over -= dx_;
                stepperY_->move(diry_);
            }
            delayMicroseconds(1500);
        }
    }
    else { 
        // Step in the y direction dy times, step once if x for every dx/dy steps in y direction.
        for(counts=0; counts < dy_; counts++){
            stepperY_->move(diry_);
            over += dx_;
            if(over>=dy_){
                over -= dy_;
                stepperX_->move(dirx_);
            }
            delayMicroseconds(1500);
        }
    }

    px_ = newx;
    py_ = newy;
}

float GParse::atangent(float dy,float dx) {
    // Calculate arctangent and adjust for signs.
    float a = atan2(dy,dx);
    if(a<0) a = (PI*2.0)+a;
    return a;
}

void GParse::DrawArc(float cx,float cy,float x,float y,float dir) {
    // Calculate distances and sweeps.
    float dx = px_ - cx;
    float dy = py_ - cy;
    float radius=sqrt(dx*dx+dy*dy);
    float angle1 = atangent(dy,dx);
    float angle2 = atangent(y-cy,x-cx);
    float sweep = angle2-angle1;

    // Adjust based on direction specified in G-Code.
    if(dir>0 && sweep<0) angle2+=2*PI;
    else if(dir == 0) angle1+=2*PI;
    sweep=angle2-angle1;

    // Calculate arc length based on sweep value.
    float len = abs(sweep) * radius;

    int i;
    int num_segments = (int)round(len / SEGMENT_LENGTH);
    // Serial.println("Number of Segments: "); Serial.print(num_segments);
    // Variables associated with the arc loop.
    float nx, ny, nz, angle3, fraction;
    for(i=0;i<num_segments;++i) {
        // Interpolate positions around the arc.
        fraction = ((float)i)/((float)num_segments);
        angle3 = ( sweep * fraction ) + angle1;
        // Grab intermeddiate values.
        nx = cx + cos(angle3) * radius;
        ny = cy + sin(angle3) * radius;
        // Draw a line to the intermeddiate position.
        DrawLine(nx,ny);
    }
}

void GParse::limitSwitchError(){
    while(1){
        Serial.println("One of the limit switches is triggered.");
        delay(5000);
    }
}


void GParse::motorsEnable(){
    // PORTB |= _BV(PB5);
    stepperX_->enable();
    stepperY_->enable();
    stepperZ_->enable();
}

void GParse::motorsDisable(){
    // PORTB &= ~_BV(PB5);
    stepperX_->disable();
    stepperY_->disable();
    stepperZ_->disable();
}

void GParse::adjustZ(){
    if(firstDecode_) {
        posNow_ = decoder_->read();
        posLast_ = decoder_->read();
        firstDecode_ = false;
    } else {
        posNow_ = decoder_->read();
        if(posNow_!=posLast_){
            long diff = posNow_-posLast_;
            stepperZ_->move((int)diff<<2);
            posLast_ = posNow_;
        }
    }
}

void GParse::jogAxes(AxisState axis){
    if(firstDecode_) {
        motorsDisable();
        posNow_ = decoder_->read();
        posLast_ = decoder_->read();
        firstDecode_ = false;
    } else {
        switch(axis){
            case Free:
                motorsDisable();
                // firstDecode_ = true;
                break;
            case X:
                motorsEnable();
                posNow_ = decoder_->read();
                if(posNow_!=posLast_){
                    long diff = posNow_-posLast_;
                    stepperX_->move((int)diff*16);
                    posLast_ = posNow_;
                }
                break;
            case Y:
                motorsEnable();
                posNow_ = decoder_->read();
                if(posNow_!=posLast_){
                    long diff = posNow_-posLast_;
                    stepperY_->move((int)diff*16);
                    posLast_ = posNow_;
                }
                break;
            case Z:
                motorsEnable();
                posNow_ = decoder_->read();
                if(posNow_!=posLast_){
                    long diff = posNow_-posLast_;
                    stepperZ_->move((int)diff*4);
                    posLast_ = posNow_;
                }         
                break;
        }
    }
}

void GParse::setupTimerInterrupt(){
    TCCR2B |= _BV(CS22) | _BV(CS21) | _BV(CS20);
    TIMSK2 |= _BV(TOIE2);
}

void GParse::freeTimerInterrupt(){
    TIMSK2 &= ~_BV(TOIE2);
}

void GParse::clearDecoder(){
    firstDecode_ = true;
}