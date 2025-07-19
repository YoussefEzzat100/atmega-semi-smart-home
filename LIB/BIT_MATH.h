#ifndef BIT_MATH_H
#define BIT_MATH_H


#define SET_BIT_VALUE(REG,POSTION)    ((REG)|=(1<<POSTION))
#define GET_BIT_VALUE(REG, POSTION)    (((REG) >> (POSTION)) & 0x01) // this move of ox01 is to make sure you isolate the lsb wich is the value you are trying to fetch
#define TOGGLE_BIT_VALUE(REG,POSTION)    ((REG)^=(1<<POSTION))
#define CLEAR_BIT_VALUE(REG,POSTION)    ((REG)&=~(1<<POSTION))

#endif