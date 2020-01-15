/*
  TscPin.cpp - A library for controlling pins
  Created by The Stem Company, Aug 9, 2019
  Repository: https://github.com/theSTEMcompany/TscPin.git
*/

#ifndef TscPin_h
#define TscPin_h

#include "Arduino.h"

class TscPin
{
    public:
        TscPin(int pinNumber, int pinType = OUTPUT);
        void initialize();
        void setHigh();
        void setLow();
        bool isHigh();
        bool isLow();
        bool read();
        void setHighWithDelays(int beforeDelay = 0, int afterDelay = 0);
        void setLowWithDelays(int beforeDelay = 0, int afterDelay = 0);
        void toggleSignal();
        bool isDebounced(int signal);
        void setDebounceDelay(int debounceDelayMillis);

    protected:
        int pinNumber;
        int pinType;
        bool reverseHighLow;
        int lastDebounceSignal;
        int lastDebounceTime;
        int debounceDelay = 300;
        
};

#endif