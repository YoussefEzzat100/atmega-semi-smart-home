#include"DIO_interface.h"
#include"DIO_private.h"
#include"../../LIB/BIT_MATH.h"

// NEED TO MODIFY FUNCTION NAMES ASAP VI IN THE COMMENTED SECTION

//DIO_voidSetPortDirection    
//DIO_voidSetPinDirection        
//DIO_voidSetPortValue
//DIO_voidSetPinValue         
//DIO_u8GetPinValue          
//DIO_u8GetPortValue         
//DIO_voidTogglePinValue     
//DIO_voidTogglePortValue    
//DIO_voidConfig_Pull_Up_Pin 
//DIO_voidConfig_Pull_Up_Port

void DIO_set_port_direction(DIO_PORT PORT_INPUT,DIO_DIRECTION DIRECTION)
{
    if (DIRECTION==OUTPUT)
    {
        switch (PORT_INPUT)
        {
            case PORT_A:DDRA_REG=0xFF;break;
            case PORT_B:DDRB_REG=0xFF;break;
            case PORT_C:DDRC_REG=0xFF;break;
            case PORT_D:DDRD_REG=0xFF;break;
        }
    }
    else
    {
        switch (PORT_INPUT)
        {
            case PORT_A:DDRA_REG=0x00;break;
            case PORT_B:DDRB_REG=0x00;break;
            case PORT_C:DDRC_REG=0x00;break;
            case PORT_D:DDRD_REG=0x00;break;
        }
    }
    }


void DIO_set_pin_direction(DIO_PORT PORT_INPUT,DIO_PIN PIN_INPUT,DIO_DIRECTION DIRECTION)
{
    if ((PORT_INPUT<4)&&(PIN_INPUT<8))
    {
        if (DIRECTION==OUTPUT)
        {
            switch (PORT_INPUT)
            {
                case PORT_A:SET_BIT_VALUE(DDRA_REG,PIN_INPUT);break;
                case PORT_B:SET_BIT_VALUE(DDRB_REG,PIN_INPUT);break;
                case PORT_C:SET_BIT_VALUE(DDRC_REG,PIN_INPUT);break;
                case PORT_D:SET_BIT_VALUE(DDRD_REG,PIN_INPUT);break;
            }
        }
        else
        {
            switch (PORT_INPUT)
            {
                case PORT_A:CLEAR_BIT_VALUE(DDRA_REG,PIN_INPUT);break;
                case PORT_B:CLEAR_BIT_VALUE(DDRB_REG,PIN_INPUT);break;
                case PORT_C:CLEAR_BIT_VALUE(DDRC_REG,PIN_INPUT);break;
                case PORT_D:CLEAR_BIT_VALUE(DDRD_REG,PIN_INPUT);break;
            }
        }
    }
    else{}
}



void DIO_set_port_value(DIO_PORT PORT_INPUT,unsigned char VALUE)
{
    switch (PORT_INPUT)
        {
            case PORT_A:PORTA_REG=VALUE;break;
            case PORT_B:PORTB_REG=VALUE;break;
            case PORT_C:PORTC_REG=VALUE;break;
            case PORT_D:PORTD_REG=VALUE;break;
        }
}   


void DIO_set_pin_value(DIO_PORT PORT_ID,DIO_PIN PIN_ID,DIO_STATE DIO_STATE)
{
    if ((PORT_ID<4)&&(PIN_ID<8))
    {
        if (DIO_STATE==HIGH)
        {
            switch (PORT_ID)
            {
                case PORT_A:SET_BIT_VALUE(PORTA_REG,PIN_ID);break;
                case PORT_B:SET_BIT_VALUE(PORTB_REG,PIN_ID);break;
                case PORT_C:SET_BIT_VALUE(PORTC_REG,PIN_ID);break;
                case PORT_D:SET_BIT_VALUE(PORTD_REG,PIN_ID);break;
            }
        }
        else
        {
            switch (PORT_ID)
            {
                case PORT_A:CLEAR_BIT_VALUE(PORTA_REG,PIN_ID);break;
                case PORT_B:CLEAR_BIT_VALUE(PORTB_REG,PIN_ID);break;
                case PORT_C:CLEAR_BIT_VALUE(PORTC_REG,PIN_ID);break;
                case PORT_D:CLEAR_BIT_VALUE(PORTD_REG,PIN_ID);break;
            }
        }
    }
    else{}
}




DIO_STATE DIO_get_pin_value(DIO_PORT PORT_ID,DIO_PIN PIN_ID)
{
    DIO_STATE PIN_VALUE = LOW;
    if ((PORT_ID<4)&&(PIN_ID<8))
    {
        switch (PORT_ID)
            {
                case PORT_A:PIN_VALUE = GET_BIT_VALUE(PINA_REG,PIN_ID);break;
                case PORT_B:PIN_VALUE = GET_BIT_VALUE(PINB_REG,PIN_ID);break;
                case PORT_C:PIN_VALUE = GET_BIT_VALUE(PINC_REG,PIN_ID);break;
                case PORT_D:PIN_VALUE = GET_BIT_VALUE(PIND_REG,PIN_ID);break;
            }
    }
    else{}
    return PIN_VALUE;
}



void DIO_Toggle_Port (DIO_PORT DIO_ID)
{
    switch (DIO_ID)
    {
        case PORT_A:PORTA_REG^=0x00;break; // THE ^= WOULD TOOGLE THE HOLE EXPRESSION
        case PORT_B:PORTB_REG^=0x00;break;
        case PORT_C:PORTC_REG^=0x00;break;
        case PORT_D:PORTD_REG^=0x00;break;
    }
}



void DIO_Toggle_PIN (DIO_PORT PORT_ID,DIO_PIN PIN_ID)
{
    if ((PORT_ID<4)&&(PIN_ID<8))
    {
        switch (PORT_ID)
        {
            case PORT_A:TOGGLE_BIT_VALUE(PORTA_REG,PIN_ID);break;
            case PORT_B:TOGGLE_BIT_VALUE(PORTB_REG,PIN_ID);break;
            case PORT_C:TOGGLE_BIT_VALUE(PORTC_REG,PIN_ID);break;
            case PORT_D:TOGGLE_BIT_VALUE(PORTD_REG,PIN_ID);break;
        }
    }
}    