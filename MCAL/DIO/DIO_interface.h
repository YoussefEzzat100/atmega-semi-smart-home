#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H
#include "DIO_private.h"
#include "DIO_config.h"

void DIO_set_pin_value(DIO_PORT,DIO_PIN,DIO_STATE);  //DONE


void DIO_set_port_value(DIO_PORT,unsigned char);  //DONE


void DIO_set_pin_direction(DIO_PORT,DIO_PIN,DIO_DIRECTION);  //DONE


void DIO_set_port_direction(DIO_PORT,DIO_DIRECTION);  //DONE


DIO_STATE DIO_get_pin_value(DIO_PORT,DIO_PIN); //DONE


unsigned char DIO_get_port_value(DIO_PORT); //NOT NECESSARY


void DIO_Toggle_Port (DIO_PORT);//DONE


void DIO_Toggle_PIN (DIO_PORT,DIO_PIN);//DONE




#endif