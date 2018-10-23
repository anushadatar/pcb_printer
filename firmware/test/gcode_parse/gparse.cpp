#include "gparse.h"

void GParse::Initialize(){
    // Enable Serial Communication with the given baud rate
    Serial.begin(baud_);
    Help();

    stepperX_->begin(RPM);
    stepperX_->enable();
    stepperY_->begin(RPM);
    stepperY_->enable();
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
    Serial.println(i_);
    float cmd=Parsenum('G',-1);
    Serial.println(cmd);
    // switch(cmd){
    //     case 0:
    //     case 1:
            
    // }
}

float GParse::Parsenum(char code,float val) {
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
    i_ = 254;
}

void GParse::DrawLine(float newx, float newy){
    dx_ = newx - px_;
    dy_ = newy - py_;

    dirx_ = (dx_>0) ? 1:-1;
    diry_ = (dy_>0) ? 1:-1;
    dx_ = abs(dx_);
    dy_ = abs(dy_);

    unsigned long counts;
    long over = 0;
    if(dx_ > dy_){
        for(counts=0; counts < dx_; counts++){
            stepperX_->move(dirx_);
            over += dy_;
            if(over>=dx_){
                over -= dx_;
                stepperY_->move(diry_);
            }
        }
    }else{
        for(counts=0; counts < dy_; counts++){
            stepperY_->move(diry_);
            over += dx_;
            if(over>=dy_){
                over -= dy_;
                stepperX_->move(dirx_);
            }
        }
    }

    px_ = newx;
    py_ = newy;
}

void serialEvent(){
    //statements
}