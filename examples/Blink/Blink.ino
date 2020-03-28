#include <FastGPIO.h>

// Create GPIO object 'Led' of pin 13 as OUTPUT pin initially written to LOW
GPIO Led = GPIO(13, OUTPUT, LOW);

void setup() {

}

void loop() {
    // Toggle the output state of Led pin
    Led.Toggle(); // Toggle returns new state.

    // wait for 500 ms
    delay(500);
}