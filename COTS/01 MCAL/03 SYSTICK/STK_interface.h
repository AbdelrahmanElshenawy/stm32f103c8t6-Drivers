#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

#include "Std_Types.h"


void STK_voidInit();
void STK_voidSetBusyWait(uint32 Ticks);
void STK_voidSetIntervalSingle(uint32 Ticks , void (*pf) (void));
void STK_voidSetIntervalPeriodic(uint32 Ticks , void (*pf) (void));
void STK_voidStopInterval();
uint32 STK_GetElapsedTime();
uint32 STK_GetRemainingTime();

#endif
