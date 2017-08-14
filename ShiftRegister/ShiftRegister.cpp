#include "ShiftRegister.h"
#include <math.h>
#include <string.h>
#include <Arduino.h>

ShiftRegister::ShiftRegister(uint8_t outputPin,
                             uint8_t bits,
                             uint8_t clockPin,
                             uint8_t serialParallelPin,
                             uint8_t serialValue,
                             uint8_t parallelValue)
    : _outputPin(outputPin)
    , _bits(bits)
    , _clockPin(clockPin)
    , _serialParallelPin(serialParallelPin)
    , _serialValue(serialValue)
    , _parallelValue(parallelValue)
    , _outputSize(byte(ceil(bits / 8.0)))
{
    _output = new uint8_t[_outputSize];

    pinMode(outputPin, INPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(serialParallelPin, OUTPUT);
}

ShiftRegister::~ShiftRegister()
{
    delete [] _output;
}

bool ShiftRegister::read(uint8_t* output, uint8_t size)
{
    if (!output) {
        return false;
    }
    if (size == 0) {
        return false;
    }
    if (_outputSize == 0) {
        return false;
    }

    memset(_output, 0, _outputSize);

    digitalWrite(_serialParallelPin, _parallelValue);
    digitalWrite(_serialParallelPin, _serialValue);

    for (int i = _bits - 1; i >= 0; i--) {
        digitalWrite(_clockPin, LOW);
        auto result = digitalRead(_outputPin);

        if (result == HIGH) {
            int arrayIndex = i / 8;
            int bitIndex = i % 8;
            _output[arrayIndex] |= 1 << bitIndex;
        }

        digitalWrite(_clockPin, HIGH);
    }

    memcpy(output, _output, min(size, _outputSize));

    return true;
}
