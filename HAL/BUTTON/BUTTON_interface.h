#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "../../MCAL/DIO/DIO_interface.h"

void BUTTON_init(DIO_PORT port, DIO_PIN pin);
unsigned char BUTTON_read(DIO_PORT port, DIO_PIN pin);

#endif