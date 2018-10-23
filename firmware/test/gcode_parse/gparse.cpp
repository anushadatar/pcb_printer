#include "gparse.h"

void GParse::Initialize(){
    // Enable Serial Communication with the given baud rate
    Serial.begin(baud_);
    Help();
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
    // Serial.println(F("State listening"));
    if(Serial.available()){
        char c = Serial.read();
        // Serial.print(c);

        buffer[i++] = c;

        if(c=='$') {
            Serial.print(F("\r\n")); // optional: send back a return for debugging

            // strings must end with a \0.
            buffer[i]=(char)0;
            Processing(); // do something with the command
            Reseti();
        }
    }
    // i=0;
    // Serial.print(i);
}

void GParse::Processing(){
    Serial.println(buffer);
    Serial.println(i);
    float cmd=parseNum('G',-1);
    Serial.println(cmd);
}

float GParse::parseNum(char code,float val) {
  char *ptr=buffer;  // start at the beginning of buffer
  while((long)ptr > 1 && (*ptr) && (long)ptr < (long)buffer+i) {  // walk to the end
    if(*ptr==code) {  // if you find code on your walk,
      return atof(ptr+1);  // convert the digits that follow into a float and return it
    }
    ptr=strchr(ptr,' ')+1;  // take a step from here to the letter after the next space
  }
  return val;  // end reached, nothing found, return default val.
}

void GParse::Reseti(){
    i = 255;
}

void serialEvent(){
    //statements
}