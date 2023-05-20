#ifndef DMA_PRIVATE_H
#define DMA_PRIVATE_H

#include "Std_Types.h"



typedef struct{

	 	uint32 	CCR;
	 	uint32 	CNDTR;
	 	uint32 	CPAR;
	 volatile	uint32 	CMAR;
	 	uint32 	Reserved;
}DMA1_Channel_type;


typedef struct{
	volatile 	uint32		 		ISR;
	volatile 	uint32		 		IFCR;
	volatile 	DMA1_Channel_type	Channel[7];
}DMA1_type;


#define 	DMA1			((volatile DMA1_type *)(0x40020000))




#endif
