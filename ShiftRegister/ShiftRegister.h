#ifndef _SHIFT_REGISTER_H_
#define _SHIFT_REGISTER_H_

#include <Arduino.h>

class ShiftRegister
{
private:
    uint8_t const _outputPin;
    uint8_t const _bits;
    uint8_t const _clockPin;
    uint8_t const _serialParallelPin;
    uint8_t const _serialValue;
    uint8_t const _parallelValue;
    uint8_t* _output;
    uint8_t const _outputSize;

public:
    ShiftRegister(uint8_t outputPin,
                  uint8_t bits,
                  uint8_t clockPin,
                  uint8_t serialParallelPin,
                  uint8_t serialValue,
                  uint8_t parallelValue);
    ~ShiftRegister();

    bool read(uint8_t* output, uint8_t size);
};

#endif
