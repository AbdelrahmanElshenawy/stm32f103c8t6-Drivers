#include "../00 LIB/Bit_Math.h"
#include "../01 MCAL/00 RCC/RCC_interface.h"
#include "../01 MCAL/01 GPIO/DIO_interface.h"
#include "../02 ECU/LCD/LCD.h"
#include "../01 MCAL/01 GPIO/DIO_private.h"
#include "../01 MCAL/03 SYSTICK/STK_interface.h"
#include "../01 MCAL/05 DMA/DMA_interface.h"
#include "../01 MCAL/08 SPI/SPI_interface.h"
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
