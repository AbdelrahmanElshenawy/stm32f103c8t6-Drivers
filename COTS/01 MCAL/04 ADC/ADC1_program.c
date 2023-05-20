#include "Std_Types.h"
#include "Bit_Math.h"

#include "DIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

#include "ADC1_private.h"
#include "ADC1_config.h"
#include "ADC1_interface.h"




#if 	ADC1_MODE==SINGLE_CH_SINGLE_CONV

void ADC1_voidInit(ADC1_channel_t channel,ADC1_EOCIE_t conv_interrupt_status, ADC1_CONV_MODE_t mode){

	if(channel < 8){

		RCC_voidEnablePerClk(RCC_APB2, ADC1EN);
		RCC_voidEnablePerClk(RCC_APB2, IOPAEN);
		DIO_voidSetPinDirection(PORTA,channel , GPIO_INPUT_ANALOG);
	}
	else{
		RCC_voidEnablePerClk(RCC_APB2, ADC1EN);
		RCC_voidEnablePerClk(RCC_APB2, IOPBEN);
		DIO_voidSetPinDirection(PORTB,channel , GPIO_INPUT_ANALOG);
	}
	switch(conv_interrupt_status){

	case ADC1_EOCI_ENABLE:
		SET_BIT(ADC1->ADC_CR1 , 5);
		break;
	case ADC1_EOCI_DISABLE:
		CLR_BIT(ADC1->ADC_CR1 , 5);
		break;
	default:
		//error
		break;
	}

	switch(mode){

		case ADC1_SINGLE_CONV_MODE:
			CLR_BIT(ADC1->ADC_CR2 , 1);
			break;
		case ADC1_CONTINOUS_CONV_MODE:
			SET_BIT(ADC1->ADC_CR2 , 1);
			break;
		default:
			//error
			break;
		}

}

void ADC1_voidStart(void){
	//SET_BIT(ADC1->ADC_CR2,22);
	/*	Before start conversion, bit 17, 18, 19 should be choosen
	 * 	as they are determine the source trigger to start conversion
	 * */
	ADC1->ADC_CR2 |= (1<<17);
	ADC1->ADC_CR2 |= (1<<18);
	ADC1->ADC_CR2 |= (1<<19);
	/*
	 * NOTE that this bit is cleared by hardware after setting it immediately, and
	 *	you cant watch its change in the register while debugging
	 *   */
	ADC1->ADC_CR2 |= (1<<22);
}

void ADC1_voidEnable(void){

	SET_BIT(ADC1->ADC_CR2, 0);
	STK_voidSetBusyWait(1000);

}


void ADC1_voidDisable(void){

	CLR_BIT(ADC1->ADC_CR2, 0);
}


uint16 ADC1_uint16GetData(void){
	uint16 Data = (uint16)(ADC1->ADC_DR);
	return Data;
}

#elif

#elif

#endif








