#include "Std_Types.h"

#define		EXTI_BASE_ADD			0x40010400


typedef struct
{
	volatile	uint32		IMR;
	volatile	uint32		EMR;
	volatile	uint32		RTSR;
	volatile	uint32		FTSR;
	volatile	uint32		SWIER;
	volatile	uint32		PR;
	
}EXTI_Type;

#define			EXTI				((volatile EXTI_Type *)(EXTI_BASE_ADD))

#define RISING_EDGE		0x00
#define FALLING_EDGE 	0x01
#define IOC	 			0x02






