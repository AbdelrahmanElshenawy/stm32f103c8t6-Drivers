#ifndef H_KEYPAD_CONFIG_H
#define H_KEYPAD_CONFIG_H

#include "DIO_private.h"
#include "DIO_interface.h"

#define KeyPadDDR  D

#define KeyPadPORT PORTA
#define KeyPadPIN  GPIOA_IDR

#define KP_R1 8
#define KP_R2 9
#define KP_R3 10
#define KP_R4 11

#define KP_C1 12
#define KP_C2 13
#define KP_C3 14


#endif
