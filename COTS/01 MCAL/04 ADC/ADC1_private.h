#ifndef ADC1_PRIVATE_H
#define ADC1_PRIVATE_H


#include "Std_Types.h"


typedef struct{
	uint32 ADC_SR;
	uint32 ADC_CR1;
	uint32 ADC_CR2;
	uint32 ADC_SMPR1;
	uint32 ADC_SMPR2;
	uint32 ADC_JOFR1;
	uint32 ADC_JOFR2;
	uint32 ADC_JOFR3;
	uint32 ADC_JOFR4;
	uint32 ADC_HTR;
	uint32 ADC_LTR;
	uint32 ADC_SQR1;
	uint32 ADC_SQR2;
	uint32 ADC_SQR3;
	uint32 ADC_JSQR;
	uint32 ADC_JDR1;
	uint32 ADC_JDR2;
	uint32 ADC_JDR3;
	uint32 ADC_JDR4;
	uint32 ADC_DR;
}ADC1_type;


#define		 ADC1    ((volatile ADC1_type *)(uint32)0x40012400)


#endif
