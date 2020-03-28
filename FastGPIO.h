#ifndef __FAST_GPIO_H
#define __FAST_GPIO_H

#include "Arduino.h"

class GPIO {
public:
    volatile uint8_t *OutputPort; // stores the output port register
    volatile uint8_t *InputPort;  // stores the input  port register
    const uint8_t Pin, BitMask;         // stores the digitalPin number and BitMask of corresponding pin

public:
    // construct a GPIO object by passing digitalPin number, the mode at which it should operator
    // and [optional] initial output state (only for OUTPUT)
    GPIO(uint8_t pin, uint8_t mode, uint8_t initState = LOW);


#ifdef GPIO_OBJECT_RETURN_STATE
    // GPIO_OBJECT_RETURN_STATE can be defined if casting a GPIO_OBJECT should return the current state
    // int var = GPIO_OBJECT; // reutrns GPIO_OBJECT.Read();
    operator uint8_t() const { return Read(); }
#else
    // by default, if GPIO_OBJECT_RETURN_STATE is not defined, it returns digitalPin so that
    // it can be used like analogRead( GPIO_OBJECT ); like how you would normally otherwise.
    operator uint8_t() const { return Pin; }
#endif

    // returns the pin state.
    uint8_t Read() const;

    // Sets the output register bit of the pin to 0 and returns LOW.
    uint8_t WriteLow()  const;

    // Sets the output register bit of the pin to 1 and returns HGIH.
    uint8_t WriteHigh() const;

    // Sets the output register bit of the pin
    uint8_t Write(const uint8_t val) const;

    // Sets the output register but of the pin, (alternative: GPIO_OBJECT.Write(val))
    uint8_t operator= (const uint8_t val) { Write(val); }

    // Toggles the output register bit
    uint8_t Toggle() const;
};

#endif