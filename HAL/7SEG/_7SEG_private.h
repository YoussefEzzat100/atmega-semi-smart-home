#ifndef _7SEG_PRIVATE_H
#define _7SEG_PRIVATE_H



/*typedef enum {
    ZERO, 
    ONE,  
    TWO,  
    THREE,
    FOUR, 
    FIVE, 
    SIX,  
    SEVEN,
    EIGHT,
    NINE, 
} NUMS;*/       


typedef enum{
        COMMON_CATHODE,
        COMMON_ANODE,
}_7SEG_TYPE;



typedef enum{
    OFF,
    ON,

}DOT_STATE;

//0bxgfedcba // x=dot
#define ZERO        0b00111111
#define ONE         0b00000110
#define TWO         0b01011011
#define THREE       0b01001111
#define FOUR        0b01100110
#define FIVE        0b01101101
#define SIX         0b01111101
#define SEVEN       0b00000111
#define EIGHT       0b01111111
#define NINE        0b01101111
#define _7SEG_A     0b01110111 
#define _7SEG_b     0b01111100 
#define _7SEG_C     0b00111001 
#define _7SEG_d     0b01011110 
#define _7SEG_E     0b01111001 
#define _7SEG_F     0b01110001 



#define a       10
#define b       11
#define c       12
#define d       13
#define e       14
#define f       15

#endif

