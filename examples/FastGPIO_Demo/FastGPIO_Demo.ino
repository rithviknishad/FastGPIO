#include <FastGPIO.h>

GPIO PushButton     = GPIO( 3, INPUT );
GPIO PushButtonLED  = GPIO( 4, OUTPUT);
GPIO Potentiometer  = GPIO(A7, INPUT );
GPIO LedPWM         = GPIO( 6, OUTPUT);
GPIO StateLED       = GPIO(13, OUPUT, LOW);

void setup() {
    
}

bool flag = true;

void loop() {

    // flips value output of StateLED if PushButton is pressed 
    // and assigns the new state of StatusLED to 'flag'
    if ( PushButton.Read() == HIGH )    // checks if PushButton is pressed.
    {
        flag = StateLED.Toggle();       // toggles the StatusLED and assigns the new state to flag.
        
        PushButtonLED = 0;              // turns off PushButtonLED
        PushButtonLED.Write(LOW);       // alternative way for previous line
        PushButtonLED.WriteLow();       // alternative way for previous line
    }
    else
    {
        PushButtonLED = HIGH;           // turns on PushButtonLED
        PushButtonLED.Write(HIGH);      // alternative way for previous line
        PushButtonLED.WriteHigh();      // alternative way for previous line
    }
    // if GPIO_OBJECT_RETURN_STATE is defined, the above code could be written as:
    //
    //  if ( PushButton ) 
    //      flag = StateLED.Toggle();
    //
    // WARNING :
    // if GPIO_OBJECT_RETURN_STATE is defined,
    // GPIO_Object will not return the pin number, and hence analogWrite(GPIO_Object) / analogRead(...) / pulseIn(...), etc.. will not work
    // alternative for when GPIO_OBJECT_RETURN_STATE is defined:
    // analogRead( GPIO_Object.Pin ); or analogWrite(GPIO_Object.Pin, value);
    // Member variable, Pin stores the Pin number
    
    // reads the potentiometer value
    int pot_value = analogRead( Potentiometer ); // GPIO object returns it's corresponding digital pin if GPIO_OBJECT_RETURN_STATE is not defined

    // controls brightness of LED at LedPWM if flag is true, else dims.
    analogWrite( LedPWM, flag ? pot_value/4 : 0);
}