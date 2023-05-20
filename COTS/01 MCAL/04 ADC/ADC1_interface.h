#ifndef ADC1_INTERFACE_H
#define ADC1_INTERFACE_H

#include "ADC1_private.h"

typedef enum {
	ADC1_IN0 = 0,
	ADC1_IN1,
	ADC1_IN2,
	ADC1_IN3,
	ADC1_IN4,
	ADC1_IN5,
	ADC1_IN6,
	ADC1_IN7,
	ADC1_IN8 = 0,
	ADC1_IN9 = 1
}ADC1_channel_t;

typedef enum {
	ADC1_EOCI_DISABLE = 0,
	ADC1_EOCI_ENABLE
}ADC1_EOCIE_t;


typedef enum{
	ADC1_SINGLE_CONV_MODE,
	ADC1_CONTINOUS_CONV_MODE
}ADC1_CONV_MODE_t;


#if 	ADC1_MODE==SINGLE_CHANNEL_MODE

void ADC1_voidInit(ADC1_channel_t channel,ADC1_EOCIE_t conv_interrupt_status, ADC1_CONV_MODE_t mode);
void ADC1_voidStart(void);
void ADC1_voidEnable(void);
void ADC1_voidDisable(void);
uint16 ADC1_uint16GetData(void);

#elif

#elif

#endif





#endif
