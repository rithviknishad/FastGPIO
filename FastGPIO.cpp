#include "FastGPIO.h"

GPIO::GPIO(uint8_t pin, uint8_t mode, uint8_t initState) 
    : Pin(pin), BitMask ( digitalPinToBitMask(pin) ), InputPort( portInputRegister(digitalPinToPort(pin)) ), OutputPort( portOutputRegister(digitalPinToPort(pin)) )
{
    // initialize the pin
    pinMode(pin, mode);
    // set startup pin state
    if (mode == OUTPUT) Write(initState);
}

uint8_t GPIO::Read() const { return *InputPort & BitMask; }

uint8_t GPIO::WriteLow()  const { *OutputPort &= ~BitMask; return LOW; }
uint8_t GPIO::WriteHigh() const { *OutputPort |=  BitMask; return HIGH; }

uint8_t GPIO::Write(const uint8_t val) const { return val ? WriteHigh() : WriteLow(); }
uint8_t GPIO::Toggle() const { return Write(!Read()); }