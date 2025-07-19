//#include""
#include"_7SEG_interafce.h"


unsigned char NUM_VALUES[16] = {ZERO, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,_7SEG_A, _7SEG_b, _7SEG_C, _7SEG_d, _7SEG_E, _7SEG_F};



void _7SEG_INIT_PORT(DIO_PORT PORT_ID)
{
    if (PORT_ID<8)
    {
        switch (PORT_ID)
        {
            case PORT_A:DIO_set_port_direction(PORT_A,OUTPUT);break;
            case PORT_B:DIO_set_port_direction(PORT_B,OUTPUT);break;
            case PORT_C:DIO_set_port_direction(PORT_C,OUTPUT);break;
            case PORT_D:DIO_set_port_direction(PORT_D,OUTPUT);break;
        } 
    }
}




void _7SEG_DISPLAY_VALUE(DIO_PORT PORT_ID,_7SEG_TYPE TYPE,unsigned char VALUE,unsigned char DOT)
{
    if (PORT_ID<8&& VALUE < 16)
    {
        unsigned char pattern = NUM_VALUES[VALUE];
        if (DOT==OFF)
        {
            if (TYPE==COMMON_CATHODE)
            {
                DIO_set_port_value(PORT_ID,pattern);
            }
            else if(TYPE==COMMON_ANODE)
            {
                DIO_set_port_value(PORT_ID,~pattern);
            }
        }
        if (DOT==ON)
        {
            pattern = pattern | 0b10000000;
            if (TYPE==COMMON_CATHODE)
            {
                DIO_set_port_value(PORT_ID,pattern);
            }
            else if(TYPE==COMMON_ANODE)
            {
                DIO_set_port_value(PORT_ID,~pattern);
            }   
        }
    }
}