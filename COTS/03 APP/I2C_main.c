#include "Bit_Math.h"
#include "RCC_interface.h"
#include "DIO_interface.h"
#include "LCD.h"
#include "KeyPad.h"
#include "EXTI_interface.h"
#include "DIO_private.h"
#include "NVIC_interface.h"
#include "EXTI_interface.h"
#include "STK_interface.h"
#include "I2C_interface.h"

volatile uint8 Data = 0;
int main(void)
{


volatile uint8 * ptr = &Data;
	RCC_voidSysClkInt();
	I2C_voidInit();

	//Write
	I2C_voidSendStart();				//start

	I2C_voidSelectSlave(0b10100000);	//Address
	//I2C_voidSelectSlave(0x02);			//address
	I2C_voidWriteByte(0x05);

	I2C_voidWriteByte(0xaa);				//byte write

	I2C_voidSendStop();					//stop


	//Read

	I2C_voidSendStart();

	I2C_voidSelectSlave(0b10100000);		//0b	1010 000 0
	I2C_voidWriteByte(0x05);

	I2C_voidSendStart();
	I2C_voidSelectSlave(0b10100001);		//0b	1010 000 1


	I2C_voidSendStop();


	while (1)
	{

	}
}

