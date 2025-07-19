#ifndef KPAD_INTERFACE_H
#define KPAD_INTERFACE_H
#include "../../MCAL/DIO/DIO_interface.h"



#define KPAD_KEYS {              \
    {'7','8','9','/'},            \
    {'4','5','6','*'},            \
    {'1','2','3','-'},            \
    {'c','0','=','+'}             \
}

#define  KPD_NOT_PRESSED   0xff // random high number because cannot return null as conflicting types will happen

void KPAD_INIT();
unsigned char KPAD_GET_PRESS_VALUE();


#endif
