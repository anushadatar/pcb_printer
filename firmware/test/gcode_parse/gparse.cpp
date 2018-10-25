#include "gparse.h"

#define CM_PER_SEGMENT 1

void GParse::Initialize(){
    // Enable Serial Communication with the given baud rate
    Serial.begin(baud_);
    Help();

    stepperX_->begin(rpm_);
    stepperX_->enable();
    stepperY_->begin(rpm_);
    stepperY_->enable();

    stepperX_->setMicrostep(8);   // Set microstep mode to 1:8
    // In 1:8 microstepping mode, one revolution takes 8 times as many microsteps
    stepperX_->move(8 * 360);    // forward revolution
    stepperX_->move(-8 * 360);   // reverse revolution

    stepperY_->setMicrostep(8);   // Set microstep mode to 1:8
    // In 1:8 microstepping mode, one revolution takes 8 times as many microsteps
    stepperY_->move(8 * 360);    // forward revolution
    stepperY_->move(-8 * 360);   // reverse revolution
    
    Reseti();
    // stepperX_->begin(rpm_, microstep_);stepperY_->begin(rpm_, microstep_);
}

void GParse::Help(){
    // Print the help message for gcode parser once Serial
    // configuration is done
    Serial.println(F("Commands:"));
    Serial.println(F("G00 [X(steps)] [Y(steps)] [F(feedrate)]; - Fast linear move"));
    Serial.println(F("G01 [X(steps)] [Y(steps)] [F(feedrate)]; - linear move"));
}

void GParse::Listening(){
    // Print the help message for gcode parser once Serial
    // configuration is done
    if(Serial.available()){
        char c = Serial.read();
        // Serial.print(c);

        buffer[i_++] = c;

        if(c=='$') {
            Serial.print(F("\r\n")); // optional: send back a return for debugging

            // strings must end with a \0.
            buffer[i_]=(char)0;
            Processing(); // do something with the command
            Reseti();
        }
    }
}

void GParse::Processing(){
    Serial.println(buffer);
    Serial.print("i ");Serial.println(i_);
    int cmd=(int)ParseNum('G',-1);
    Serial.print("cmd ");Serial.println(cmd);
    switch(cmd){
        case 0: // move in a line
        case 1: // move in a line
        {
            // set_feedrate(ParseNumber('F',fr));
            // Serial.println("????");
            int temp = ParseNum('X',(modeAbs_?px_:0)) + (modeAbs_?0:px_);
            DrawLine( temp,
                      ParseNum('Y',(modeAbs_?py_:0)) + (modeAbs_?0:py_) );
            break;
        }
        case 2: // clockwise arc
        {
            float cx = ParseNum('I', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float cy = ParseNum('J', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            float x =  ParseNum('X', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float y =  ParseNum('Y', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            DrawArc(cx, cy, x, y, 1); 
            break;
        }
        case 3: // counter-clockwise arc
        { 
            float cx = ParseNum('I', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float cy = ParseNum('J', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            float x =  ParseNum('X', (modeAbs_?px_:0)) + (modeAbs_?0:px_);
            float y =  ParseNum('Y', (modeAbs_?py_:0)) + (modeAbs_?0:py_);
            DrawArc(cx, cy, x, y, 0);        
            break;
        }
        case 4: delay(ParseNum('P', 0)); break; // wait a while
        case 90: modeAbs_=1; break; // absolute mode
        case 91: modeAbs_=0; break; // relative mode
      //  case 92: // set logical position
        //    SetPosition( ParseNum('X',0),
          //               ParseNum('Y',0) );
           // break;
        default: break;
    }
}

float GParse::ParseNum(char code,float val) {
  char *ptr=buffer;  // start at the beginning of buffer
  while((long)ptr > 1 && (*ptr) && (long)ptr < (long)buffer+i_) {  // walk to the end
    if(*ptr==code) {  // if you find code on your walk,
      return atof(ptr+1);  // convert the digits that follow into a float and return it
    }
    ptr=strchr(ptr,' ')+1;  // take a step from here to the letter after the next space
  }
  return val;  // end reached, nothing found, return default val.
}

void GParse::Reseti(){
    // Reset i to be 254, to be overflown at 254+2
    // this number allows to counter to keep working correctly
    i_ = 0;
}

void GParse::DrawLine(float newx, float newy){
    dx_ = newx - px_;
    dy_ = newy - py_;
    Serial.print("dx "); Serial.println(dx_); 
    Serial.print("dy "); Serial.println(dy_);
    dirx_ = (dx_>0) ? 1:-1;
    diry_ = (dy_>0) ? 1:-1;
    dx_ = abs(dx_);
    dy_ = abs(dy_);
    Serial.print("dx "); Serial.print(dx_); Serial.print("; dirx "); Serial.println(dirx_);
    Serial.print("dy "); Serial.print(dy_); Serial.print("; diry "); Serial.println(diry_);

    unsigned long counts;
    long over = 0;
    if(dx_ > dy_){ // Stepping in the x direction dx times, step once if y for every dy/dx steps in x direction
        for(counts=0; counts < dx_; counts++){
            stepperX_->move(dirx_);
            over += dy_;
            if(over>=dx_){
                over -= dx_;
                stepperY_->move(diry_);
            }
            // Serial.println(counts);
            // delay(500);
        }
    }else{ // Stepping in the y direction dy times, step once if x for every dx/dy steps in y direction
        for(counts=0; counts < dy_; counts++){
            stepperY_->move(diry_);
            over += dx_;
            if(over>=dy_){
                over -= dy_;
                stepperX_->move(dirx_);
            }
            // delay(500);
        }
    }

    px_ = newx;
    py_ = newy;
}
float GParse::atangent(float dy,float dx) {
    float a = atan2(dy,dx);
    if(a<0) a = (PI*2.0)+a;
    return a;
}

void GParse::DrawArc(float cx,float cy,float x,float y,float dir) {
    // get radius
    float dx = px_ - cx;
    float dy = py_ - cy;
    float radius=sqrt(dx*dx+dy*dy);

    // find the sweep of the arc
    float angle1 = atangent(dy,dx);
    float angle2 = atangent(y-cy,x-cx);
    float sweep = angle2-angle1;

    if(dir>0 && sweep<0) angle2+=2*PI;
    else if(dir == 0) angle1+=2*PI;

    sweep=angle2-angle1;

    // get length of arc
    // float circumference=PI*2.0*radius;
    // float len=sweep*circumference/(PI*2.0);
    // simplifies to
    float len = abs(sweep) * radius;

    int i, num_segments = floor(len / CM_PER_SEGMENT);

    // declare variables outside of loops because compilers can be really dumb and inefficient some times.
    float nx, ny, nz, angle3, fraction;

    for(i=0;i<num_segments;++i) {
        // interpolate around the arc
        fraction = ((float)i)/((float)num_segments);
        angle3 = ( sweep * fraction ) + angle1;

        // find the intermediate position
        nx = cx + cos(angle3) * radius;
        ny = cy + sin(angle3) * radius;
        // make a line to that intermediate position
        DrawLine(nx,ny);
    }

    // one last line hit the end
    DrawLine(x,y);
}

void serialEvent(){
    //statements
}
