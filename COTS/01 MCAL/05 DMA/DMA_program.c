
#include "Bit_Math.h"
#include "Std_Types.h"
#include "DMA_config.h"
#include "DMA_private.h"
#include "DMA_interface.h"



void DMA1_voidChannelInit(
		DMA1_Channel_t channel,
		DMA1_dir_t direction,
		DMA1_circuilar_mode_t circuilar_mode,
		DMA1_per_inc_mode_t per_inc_mode ,
		DMA1_mem_inc_mode_t  mem_inc_mode,
		DMA1_per_size_t  per_size,
		DMA1_mem_size_t  mem_size,
		DMA1_priority_t  priority,
		DMA1_mem2mem_mode_t  mem2mem_mode
){

	DMA1_voidDisableChannel(channel);

	switch(direction){
	case READ_FROM_PER:
		CLR_BIT(DMA1->Channel[channel].CCR,DMA1_DIR);
		break;
	case READ_FROM_MEM:
		SET_BIT(DMA1->Channel[channel].CCR,DMA1_DIR);
		break;
	default:
		//error
		break;
	}

	switch(circuilar_mode){
		case CIRCUILAR_MODE_DISABLED:
			CLR_BIT(DMA1->Channel[channel].CCR,DMA1_CIRC);
			break;
		case CIRCUILAR_MODE_ENABLED:
			SET_BIT(DMA1->Channel[channel].CCR,DMA1_CIRC);
			break;
		default:
			//error
			break;
	}

	switch(per_inc_mode){
		case PER_INC_MODE_DISABLED:
			CLR_BIT(DMA1->Channel[channel].CCR,DMA1_PINC);
			break;
		case PER_INC_MODE_ENABLED:
			SET_BIT(DMA1->Channel[channel].CCR,DMA1_PINC);
			break;
		default:
			//error
	     	break;
	}


	switch(mem_inc_mode){
		case MEM_INC_MODE_DISABLED:
			CLR_BIT(DMA1->Channel[channel].CCR,DMA1_MINC);
			break;
		case MEM_INC_MODE_ENABLED:
			SET_BIT(DMA1->Channel[channel].CCR,DMA1_MINC);
			break;
		default:
			//error
	     	break;
	}


	switch(per_size){

	case PER_SIZE_8_BITS:
			CLR_BIT(DMA1->Channel[channel].CCR,DMA1_PER_SIZE_BIT_0);
			CLR_BIT(DMA1->Channel[channel].CCR,DMA1_PER_SIZE_BIT_1);
				break;
	case PER_SIZE_16_BITS:
			SET_BIT(DMA1->Channel[channel].CCR,DMA1_PER_SIZE_BIT_0);
			CLR_BIT(DMA1->Channel[channel].CCR,DMA1_PER_SIZE_BIT_1);
				break;
	case PER_SIZE_32_BITS:
				CLR_BIT(DMA1->Channel[channel].CCR,DMA1_PER_SIZE_BIT_0);
				SET_BIT(DMA1->Channel[channel].CCR,DMA1_PER_SIZE_BIT_1);
				break;

	default:
		//error
		break;

	}

	switch(mem_size){

		case MEM_SIZE_8_BITS:
				CLR_BIT(DMA1->Channel[channel].CCR,DMA1_MEM_SIZE_BIT_0);
				CLR_BIT(DMA1->Channel[channel].CCR,DMA1_MEM_SIZE_BIT_1);
					break;
		case MEM_SIZE_16_BITS:
				SET_BIT(DMA1->Channel[channel].CCR,DMA1_MEM_SIZE_BIT_0);
				CLR_BIT(DMA1->Channel[channel].CCR,DMA1_MEM_SIZE_BIT_1);
					break;
		case MEM_SIZE_32_BITS:
					CLR_BIT(DMA1->Channel[channel].CCR,DMA1_MEM_SIZE_BIT_0);
					SET_BIT(DMA1->Channel[channel].CCR,DMA1_MEM_SIZE_BIT_1);
					break;

		default:
			//error
			break;

		}

	switch(priority){

		case CHANNEL_LOW_PRIORITY:
				CLR_BIT(DMA1->Channel[channel].CCR,DMA1_PRIORITY_BIT_0);
				CLR_BIT(DMA1->Channel[channel].CCR,DMA1_PRIORITY_BIT_1);
					break;
		case CHANNEL_MEDIUM_PRIORITY:
				SET_BIT(DMA1->Channel[channel].CCR,DMA1_PRIORITY_BIT_0);
				CLR_BIT(DMA1->Channel[channel].CCR,DMA1_PRIORITY_BIT_1);
					break;
		case CHANNEL_HIGH_PRIORITY:
				CLR_BIT(DMA1->Channel[channel].CCR,DMA1_PRIORITY_BIT_0);
				SET_BIT(DMA1->Channel[channel].CCR,DMA1_PRIORITY_BIT_1);
					break;

		case CHANNEL_V_HIGH_PRIORITY:
				SET_BIT(DMA1->Channel[channel].CCR,DMA1_PRIORITY_BIT_0);
				SET_BIT(DMA1->Channel[channel].CCR,DMA1_PRIORITY_BIT_1);
					break;

		default:
			//error
			break;
		}

	switch(mem2mem_mode){
	case MEM2MEM_MODE_DISABLED:
		CLR_BIT(DMA1->Channel[channel].CCR,DMA1_MEM2MEM_MODE);
		break;
	case MEM2MEM_MODE_ENABLED:
		SET_BIT(DMA1->Channel[channel].CCR,DMA1_MEM2MEM_MODE);
		break;
	default:
		//error
		break;
	}
}
//void DMA1_voidChannelInit(void){
//
//	/*
//	 * MEM to MEM
//	 * Priority very high
//	 * Size (Src and Distination)
//	 * MINC and PINC enabled
//	 * Direction read from Peripheral
//	 * Transfere Complete Interrupt
//	 * Channed disabel //////////////SO IMPORTANT
//	 * */
//
//
//	DMA1->Channel[0].CCR = 0x00007AC2;
//}

void DMA1_voidStartChannel(DMA1_Channel_t channel,uint32 *SrcAdd , uint32 *DestAdd , uint16 Block){

	/*		Make sure that the channel is disabled before enabled 	*/


	CLR_BIT(DMA1->Channel[channel].CCR , DMA_CHANNEL_EN);		//CLR EN bit
	DMA1->Channel[channel].CPAR = SrcAdd;						//CPAD = SrcAdd

	DMA1->Channel[channel].CMAR = DestAdd;					//CMAD = DestAdd

	/*		lOAD The block length*/
	DMA1->Channel[channel].CNDTR = Block;						//CNDTR  numbers of steps or transfers

	/*	Enable Channel*/
	SET_BIT(DMA1->Channel[channel].CCR ,DMA_CHANNEL_EN);
}


void DMA1_voidEnableChannel(DMA1_Channel_t Channel){
	SET_BIT(DMA1->Channel[Channel].CCR , DMA_CHANNEL_EN);
}


void DMA1_voidDisableChannel(DMA1_Channel_t Channel){

	CLR_BIT(DMA1->Channel[Channel].CCR , DMA_CHANNEL_EN); //Clearing 'DMA_CHANNEL_EN bit' or bit0 to disable channel
}


void DMA1_voidEnableableChannelInt(DMA1_Channel_t Channel , DMA1_Int_t InterruptType){

	SET_BIT(DMA1->Channel[Channel].CCR , InterruptType);
}
void DMA1_voidDisableChannelInt(DMA1_Channel_t Channel , DMA1_Int_t InterruptType){

	CLR_BIT(DMA1->Channel[Channel].CCR , InterruptType);
}

void DMA1_voidClearIntFlag(DMA1_Channel_t Channel, DMA1_Flag_t FlagType){


	uint8 FlagBitPosition = Channel * 4 + FlagType;

	DMA1->IFCR = (1<<FlagBitPosition); //writting 0 to ant bit has no effect
}


/*
void DMA1_voidDisableAllChannels(void){
	CLR_BIT(DMA1->Channel[Channel].CCR , InterruptType);


}
*/
