#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H

#include "Std_Types.h"


#define 	DMA_CHANNEL_EN  	(uint8)0
#define 	DMA1_DIR			(uint8)4
#define 	DMA1_CIRC			(uint8)5
#define 	DMA1_PINC			(uint8)6
#define 	DMA1_MINC			(uint8)7
#define		DMA1_PER_SIZE_BIT_0	(uint8)8
#define		DMA1_PER_SIZE_BIT_1	(uint8)9
#define		DMA1_MEM_SIZE_BIT_0	(uint8)10
#define		DMA1_MEM_SIZE_BIT_1	(uint8)11
#define 	DMA1_PRIORITY_BIT_0	(uint8)12
#define 	DMA1_PRIORITY_BIT_1	(uint8)13
#define 	DMA1_MEM2MEM_MODE	(uint8)14

typedef enum{
	CHANNEL1 = 0,
	CHANNEL2,
	CHANNEL3,
	CHANNEL4,
	CHANNEL5,
	CHANNEL6,
	CHANNEL7
}DMA1_Channel_t;

typedef enum{
	GIF = 0,
	TCIF,
	HTIF,
	TEIF
}DMA1_Flag_t;

typedef enum{
	TCIE = 1,
	HTIE = 2,
	TEIE = 3
}DMA1_Int_t;

typedef enum{
	READ_FROM_PER = 0x0,
	READ_FROM_MEM
}DMA1_dir_t;

typedef enum{
	CIRCUILAR_MODE_DISABLED = 0,
	CIRCUILAR_MODE_ENABLED = 1
}DMA1_circuilar_mode_t;


typedef enum{
	PER_INC_MODE_DISABLED = 0,
	PER_INC_MODE_ENABLED
}DMA1_per_inc_mode_t;

typedef enum{
	MEM_INC_MODE_DISABLED = 0,
	MEM_INC_MODE_ENABLED
}DMA1_mem_inc_mode_t;

typedef enum{

	PER_SIZE_8_BITS = 0,
	PER_SIZE_16_BITS,
	PER_SIZE_32_BITS
}DMA1_per_size_t;

typedef enum{

	MEM_SIZE_8_BITS = 0,
	MEM_SIZE_16_BITS,
	MEM_SIZE_32_BITS
}DMA1_mem_size_t;


typedef enum{

	CHANNEL_LOW_PRIORITY = 0,
	CHANNEL_MEDIUM_PRIORITY,
	CHANNEL_HIGH_PRIORITY,
	CHANNEL_V_HIGH_PRIORITY
}DMA1_priority_t;


typedef enum{

	MEM2MEM_MODE_DISABLED = 0,
	MEM2MEM_MODE_ENABLED

}DMA1_mem2mem_mode_t;


void DMA1_voidChannelInit(
		DMA1_Channel_t channel,
		DMA1_dir_t,
		DMA1_circuilar_mode_t,
		DMA1_per_inc_mode_t,
		DMA1_mem_inc_mode_t,
		DMA1_per_size_t,
		DMA1_mem_size_t,
		DMA1_priority_t,
		DMA1_mem2mem_mode_t
);

void DMA1_voidStartChannel(DMA1_Channel_t channel,uint32 *SrcAdd , uint32 *DestAdd , uint16 Block);
void DMA1_voidEnableChannel(DMA1_Channel_t Channel);
void DMA1_voidDisableChannel(DMA1_Channel_t Channel);

void DMA1_voidEnableableChannelInt(DMA1_Channel_t Channel , DMA1_Int_t InterruptType);
void DMA1_voidDisableChannelInt(DMA1_Channel_t Channel, DMA1_Int_t InterruptType);
void DMA1_voidClearIntFlag(DMA1_Channel_t Channel, DMA1_Flag_t FlagType);

//void DMA1_voidDisableAllChannels(void);

#endif
