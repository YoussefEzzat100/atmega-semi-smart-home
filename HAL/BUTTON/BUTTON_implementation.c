#include "BUTTON_interface.h"
#include<util/delay.h>

// This button driver uses internal pull-up resistors to eliminate the need for external hardware.
// Connect the button between the pin and GND.
// When the button is pressed, the input reads LOW (0) — and that is considered a 'pressed' state.
//optimized for debouncing delay



void BUTTON_init(DIO_PORT port, DIO_PIN pin)
{
    DIO_set_pin_direction(port, pin, INPUT);
    DIO_set_pin_value(port, pin, HIGH);  // Enable internal pull-up
    // this combination of making the direction as input and then set as high this wouldn't overwrite the direction but the 
    // hardware will interpret it as enable pull up 
}




//this type of function because int takes 4 btyte but char only 1 byte so conserve more space
unsigned char BUTTON_read(DIO_PORT port, DIO_PIN pin)
{
    if (DIO_get_pin_value(port, pin) == 0)
    {
        _delay_ms(20);  // debounce
        if (DIO_get_pin_value(port, pin) == 0)
        {
            return 1;
        }
    }

    return 0;
}