#ifndef _SHIFT_REGISTER_H_
#define _SHIFT_REGISTER_H_

#include <Arduino.h>

class ShiftRegister
{
private:
    uint8_t _outputPin;
    uint8_t _bits;
    uint8_t _clockPin;
    uint8_t _serialParallelPin;
    uint8_t* _output;
    uint8_t _outputSize;

public:
    ShiftRegister(uint8_t outputPin, uint8_t bits, uint8_t clockPin, uint8_t serialParallelPin);
    ~ShiftRegister();

    bool read(uint8_t* output, uint8_t size);
};

#endif
