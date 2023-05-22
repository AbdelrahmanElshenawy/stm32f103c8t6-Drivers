//#include "Bit_Math.h"
//#include "RCC_interface.h"
//#include "DIO_interface.h"
//#include "LCD.h"
//#include "KeyPad.h"
//#include "EXTI_interface.h"
//#include "DIO_private.h"
//#include "NVIC_interface.h"
//#include "EXTI_interface.h"
//#include "STK_interface.h"
//#include "SPI_interface.h"
//
//
//
//
//int main(void)
//{
//
//	RCC_voidSysClkInt();
//
//	SPI_voidEnable();
//	SPI_voidInit();
//
//	RCC_voidEnablePerClk(RCC_APB2, IOPCEN);
//	DIO_voidSetPinDirection(PORTC, 13, GPIO_OUTPUT_10MHZ_PP);
//	DIO_voidSetPinValue(PORTC, 13, GPIO_HIGH);
//	uint8 recieved;
//
//
//	while (1)
//	{
//		SPI_TransmitChar('A');
//		recieved = SPI_Recieve();
//		if(SPI_Recieve() == 'A')
//		{
//			DIO_voidSetPinValue(PORTC, 13, (GPIO_LOW ));
//			STK_voidSetBusyWait(2000000);
//		}
//
//		else{
//
//		}
//	}
//}
