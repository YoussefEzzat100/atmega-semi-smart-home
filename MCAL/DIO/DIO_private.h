#ifndef DIO_PRIVATE_H
#define DIO_PRIVATE_H

// REGISTER DEFINING

# define PORTA_REG      *((volatile unsigned char*)0x3B)
# define PORTB_REG      *((volatile unsigned char*)0x38)
# define PORTC_REG      *((volatile unsigned char*)0x35)  
# define PORTD_REG      *((volatile unsigned char*)0x32)


# define PINA_REG       *((volatile unsigned char*)0x39)
# define PINB_REG       *((volatile unsigned char*)0x36)
# define PINC_REG       *((volatile unsigned char*)0x33)
# define PIND_REG       *((volatile unsigned char*)0x30)


# define DDRA_REG       *((volatile unsigned char*)0x3A)
# define DDRB_REG       *((volatile unsigned char*)0x37)      
# define DDRC_REG       *((volatile unsigned char*)0x34)
# define DDRD_REG       *((volatile unsigned char*)0x31)


//DEFINTIONS AND TYPEDEF
typedef enum{
    LOW,
    HIGH
}DIO_STATE;


typedef enum{
    INPUT,
    OUTPUT

}DIO_DIRECTION;


typedef enum{
    PIN_0,
    PIN_1,
    PIN_2,
    PIN_3,
    PIN_4,
    PIN_5,
    PIN_6,
    PIN_7,    

}DIO_PIN;

typedef enum{
    PORT_A,
    PORT_B,
    PORT_C,
    PORT_D,   

}DIO_PORT;

#endif