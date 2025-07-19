#ifndef _7SEG_INTERFACE_H
#define _7SEG_INTERFACE_H

#include "../../MCAL/DIO/DIO_interface.h"
#include"_7SEG_private.h"
#include"_7SEG_CONFIG.h"




void _7SEG_INIT_PORT(DIO_PORT);
void _7SEG_DISPLAY_VALUE(DIO_PORT,_7SEG_TYPE,unsigned char,unsigned char);



#endif