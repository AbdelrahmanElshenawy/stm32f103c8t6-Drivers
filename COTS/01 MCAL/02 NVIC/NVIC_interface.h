#ifndef		NVIC_INTERFACE_H
#define		NVIC_INTERFACE_H

#include "STd_Types.h"


void		NVIC_voidInit();

void		NVIC_voidEnablePerInt(uint8 IntNum);
void		NVIC_voidDisablePerInt(uint8 IntNum);

void		NVIC_voidSetPendingFlag(uint8 IntNum);
void		NVIC_voidClrPendingFlag(uint8 IntNum);

uint8			NVIC_u8ReadActiveFlag(uint8 IntNum);

void		NVIC_voidSetSwIntPriority(uint8 IntNum , uint8 priority);

#endif
