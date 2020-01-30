/*
   TscSolenoid.cpp -
   Created by The STEM Company, Aug 10, 2019
*/

#include "Arduino.h"
#include "TscPin.h"

TscPin::TscPin(int pinNumber, int pinType)
{
    this->pinNumber = pinNumber;
}

void TscPin::setHigh()
{
    digitalWrite(this->pinNumber, HIGH);
}

void TscPin::setLow()
{
    digitalWrite(this->pinNumber, LOW);
}

void TscPin::toggleSignal()
{
    if (this->isHigh()) {
        this->setLow();
    } else {
        this->setHigh();
    }
}

bool TscPin::isLow()
{
    return digitalRead(this->pinNumber) == LOW;
}

bool TscPin::isHigh()
{
    return digitalRead(this->pinNumber) == HIGH;
}

bool TscPin::read()
{
    return digitalRead(this->pinNumber);
}

void TscPin::setHighWithDelays(int beforeDelay, int afterDelay)
{
    delay(beforeDelay);
    digitalWrite(this->pinNumber, HIGH);
    delay(afterDelay);
}

void TscPin::setLowWithDelays(int beforeDelay, int afterDelay)
{
    delay(beforeDelay);
    digitalWrite(this->pinNumber, LOW);
    delay(afterDelay);
}

bool TscPin::isDebounced(int signal)
{
    int pinSignal = digitalRead(this->pinNumber);

    if (pinSignal != this->lastDebounceSignal) {
        this->lastDebounceTime = millis();
    }

    this->lastDebounceSignal = pinSignal;

    if (((millis() - this->lastDebounceTime) > this->debounceDelay) && (pinSignal == signal)) {
        return true;
    }

    return false;
}

void TscPin::setDebounceDelay(int debounceDelayMillis)
{
    this->debounceDelay = debounceDelayMillis;
}

void TscPin::initialize()
{
    pinMode(this->pinNumber, this->pinType);
}