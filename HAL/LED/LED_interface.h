#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


#include"../../MCAL/DIO/DIO_interface.h"
#include"LED_private.h"

void LED_LED_INIT(DIO_PORT,DIO_PIN);



void LED_SET_LED_PIN(DIO_PORT,DIO_PIN,DIO_STATE);



void LED_SET_LED_PORT(DIO_PORT,unsigned char);



void LED_TOGGLE_LED_PIN(DIO_PORT,DIO_PIN);



void LED_TOGGLE_LED_PORT(DIO_PORT);






#endif