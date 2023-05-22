#include "../00 LIB/Bit_Math.h"
#include "../01 MCAL/00 RCC/RCC_interface.h"
#include "../01 MCAL/01 GPIO/DIO_interface.h"
#include "../02 ECU/LCD/LCD.h"
#include "../01 MCAL/01 GPIO/DIO_private.h"
#include "../01 MCAL/03 SYSTICK/STK_interface.h"
#include "../01 MCAL/05 DMA/DMA_interface.h"
#include "../01 MCAL/04 ADC/ADC1_interface.h"




uint16 RxData[3];
float Temperature;
uint16 Data;
//uint8 const volatile data = 0;
int main(void)
{

	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, IOPBEN);
	DIO_voidSetPinDirection(PORTB, 5, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 6, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 7, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 8, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 9, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 10, GPIO_OUTPUT_2MHZ_PP);
	DIO_voidSetPinDirection(PORTB, 11, GPIO_OUTPUT_2MHZ_PP);

	STK_voidInit();
	ADC1_voidInit(ADC1_IN0, ADC1_EOCI_DISABLE, ADC1_CONTINOUS_CONV_MODE);
	ADC1_voidEnable();


	while (1)
	{
		ADC1_voidStart();
		STK_voidSetBusyWait(1000);
		Data = ADC1_uint16GetData();
//		if(Data > 1000){
//					//0
//					DIO_voidSetPinValue(PORTB, 5, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 6, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 7, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 8, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 9, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 10, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 11, GPIO_LOW);
//
//				}
//				else if(  (Data > 290) && (Data < 800) ){
//
//					//1
//					DIO_voidSetPinValue(PORTB, 5, GPIO_LOW);
//					DIO_voidSetPinValue(PORTB, 6, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 7, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 8, GPIO_LOW);
//					DIO_voidSetPinValue(PORTB, 9, GPIO_LOW);
//					DIO_voidSetPinValue(PORTB, 10, GPIO_LOW);
//					DIO_voidSetPinValue(PORTB, 11, GPIO_LOW);
//
//				}
//				else if( (Data > 270) && (Data < 299) ){
//					DIO_voidSetPinValue(PORTB, 5, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 6, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 7, GPIO_LOW);
//					DIO_voidSetPinValue(PORTB, 8, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 9, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 10, GPIO_LOW);
//					DIO_voidSetPinValue(PORTB, 11, GPIO_HIGH);
//				}
//				else{
//
//					DIO_voidSetPinValue(PORTB, 5, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 6, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 7, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 8, GPIO_HIGH);
//					DIO_voidSetPinValue(PORTB, 9, GPIO_LOW);
//					DIO_voidSetPinValue(PORTB, 10, GPIO_LOW);
//					DIO_voidSetPinValue(PORTB, 11, GPIO_HIGH);
//				}


	}
}
