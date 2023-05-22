#include "../00 LIB/Bit_Math.h"
#include "../01 MCAL/00 RCC/RCC_interface.h"
#include "../01 MCAL/01 GPIO/DIO_interface.h"
#include "../02 ECU/LCD/LCD.h"
#include "../01 MCAL/01 GPIO/DIO_private.h"
#include "../01 MCAL/02 NVIC/NVIC_interface.h"
#include "../01 MCAL/03 SYSTICK/STK_interface.h"
#include "../01 MCAL/05 DMA/DMA_interface.h"









//
//
//
//#define NVIC_ISRE0  (*((volatile uint32*)0xE000E100))
//
//
//void Toggle_Led(void){
//
//         	DIO_voidSetPinValue(PORTC, 13, GPIO_LOW);
//			STK_voidSetBusyWait(4000000);
//
//			DIO_voidSetPinValue(PORTC, 13, GPIO_HIGH);
//			STK_voidSetBusyWait(4000000);
//
//			DIO_voidSetPinValue(PORTC, 13, GPIO_LOW);
//			STK_voidSetBusyWait(4000000);
//
//}
//
//uint32 P_Arr1[1000];
//uint32 P_Arr2[1000];
//
//uint32 M_Arr3[1000];
//uint32 M_Arr4[1000];
//
//int main(){
//
//
//	for(int i = 0; i<1000 ; i++){
//		P_Arr1[i] = i;
//		M_Arr3[i] = i;
//	}
//
//
//	/*System Init*/
//
//	RCC_voidSysClkInt();
//	RCC_voidEnablePerClk(RCC_APB2, IOPCEN);
//	//DIO_voidSetPinDirection(PORTC, 13, GPIO_OUTPUT_10MHZ_PP);
//	//
//	//	DIO_voidSetPinValue(PORTC, 13, GPIO_LOW);
//	RCC_voidEnablePerClk(RCC_AHB, DMA1EN);
//
//	NVIC_voidEnablePerInt(11);
//
//	DMA1_voidChannelInit(CHANNEL1,
//			READ_FROM_PER,
//			CIRCUILAR_MODE_DISABLED,
//			PER_INC_MODE_ENABLED,
//			MEM_INC_MODE_ENABLED,
//			PER_SIZE_32_BITS,
//			MEM_SIZE_32_BITS,
//			CHANNEL_V_HIGH_PRIORITY,
//			MEM2MEM_MODE_ENABLED );
//
//	/*	DMA1 Channel Transfere Round*/
//	DMA1_voidStartChannel(CHANNEL1,M_Arr3, M_Arr4, 1000);
//	DMA1_voidEnableableChannelInt(CHANNEL1, TCIE);
//	/* Processor Transfere Round*/
//	for(int i = 0; i<1000 ; i++){
//			P_Arr2[i] = P_Arr1[i];
//		}
//
////	/*interrupt initialization*/
////	NVIC_voidInit();
////	/*Enable ETI0*/
////	NVIC_voidEnablePerInt(6);
////
////
////	STK_voidInit();
////	/* EXTI0 Config*/
////
////	EXTI_voidEnableInt(6);
////	EXTI_voidChangeSenseMode(6 , 0x00);
////	EXTI_voidChoosePinInPort(0, 0, 0);
////	EXTI0_voidSetCallBack(Toggle_Led);
////
////	/* CLock for PORTC to use pin 13*/
////	RCC_voidSysClkInt();
//
////	RCC_voidEnablePerClk(RCC_APB2, IOPAEN);
////	RCC_voidEnablePerClk(RCC_APB2, IOPBEN);
////	RCC_voidEnablePerClk(RCC_APB2, AFIOEN);
////
////
////	/*	Setting the directions of pins*/
////	DIO_voidSetPinDirection(PORTA, 0, GPIO_INPUT_PULL_UP_DOWN);
////	DIO_voidSetPinValue(PORTA, 0, 0);
////
////	DIO_voidSetPinDirection(PORTB, 11, GPIO_OUTPUT_2MHZ_PP);
////	DIO_voidSetPinValue(PORTB, 11, 1);
////	DIO_voidSetPinValue(PORTB, 11, 0);
////
////
////
//	while(1){
//
//
//		}
//
//}
//
//
//void DMA1_Channel1_IRQHandler(){
//
//	volatile uint8 x = 100;
//
//	DIO_voidSetPinValue(PORTC, 13, GPIO_HIGH);
//
//}
