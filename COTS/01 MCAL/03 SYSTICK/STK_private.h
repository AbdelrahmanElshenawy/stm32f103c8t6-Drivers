#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

#include "Std_Types.h"


#define STK_AHB_DIV_8   0x00
#define STK_AHB         0x01


#define STK_SINGLE_INTERVAL     0
#define STK_PERIODIC_INTERVAL   1

typedef struct{
    
    uint32 CTRL;
    uint32 LOAD;
    uint32 VAL;
}STK_TYPE;


#define STK ((volatile STK_TYPE*)(0xE000E010))

#endif