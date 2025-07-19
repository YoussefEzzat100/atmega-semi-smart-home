# include"LED_interface.h"
#include"../../MCAL/DIO/DIO_interface.h"


void LED_LED_INIT(DIO_PORT PORT_ID,DIO_PIN PIN_ID)
{
    if (PORT_ID < 4 && PIN_ID < 8)
    {
        DIO_set_pin_direction(PORT_ID, PIN_ID, OUTPUT);
    }
}



void LED_SET_LED_PIN(DIO_PORT PORT_ID,DIO_PIN PIN_ID,DIO_STATE STATE)
{
    if(PORT_ID<4&&PIN_ID<8)
    {
        DIO_set_pin_value(PORT_ID,PIN_ID,STATE);
    }
    else{}
}



void LED_SET_LED_PORT(DIO_PORT PORT_ID,unsigned char STATE)
{
    if(PORT_ID<4)
    {
        DIO_set_port_value(PORT_ID,STATE);
    }
    else{}
}



void LED_TOGGLE_LED_PIN(DIO_PORT PORT_ID,DIO_PIN PIN_ID)
{
    if(PORT_ID<4&&PIN_ID<8)
    {
        DIO_Toggle_PIN(PORT_ID,PIN_ID);
    }
    else{}
}



void LED_TOGGLE_LED_PORT(DIO_PORT PORT_ID)
{
    if(PORT_ID<4)
    {
        DIO_Toggle_Port(PORT_ID);
    }
    else{}
}