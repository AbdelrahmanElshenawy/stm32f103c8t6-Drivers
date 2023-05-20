#include "Std_Types.h"
#include "Bit_Math.h"
#include "RCC_interface.h"
#include "DIO_interface.h"


#include "I2C_config.h"
#include "I2C_private.h"
#include "I2C_interface.h"


void I2C_voidInit(void){


	RCC_voidEnablePerClk(RCC_APB2, AFIOEN);	//enable AFIO
	RCC_voidEnablePerClk(RCC_APB1, I2C1EN);  //enable I2C
	RCC_voidEnablePerClk(RCC_APB2, IOPBEN);	//enable GPIOB


	DIO_voidSetPinDirection(PORTB, PIN6, GPIO_OUTPUT_50MHZ_AFOD);   //output or master
	DIO_voidSetPinDirection(PORTB, PIN7, GPIO_OUTPUT_50MHZ_AFOD);	//output or master

//6 clk

	//7 datab
	I2C->I2C_CR1 |= (1<<15);  // reset the I2C
	I2C->I2C_CR1 &= ~(1<<15);  // Normal operation


//	I2C1->CR2 |= 8;
//	I2C1->CCR |= 0x28;
//	I2C1->TRISE |= 9;
//
	I2C->I2C_CR2 |= 0b00001000;  //8 MHz

	I2C->I2C_CCR |= 0x28;		//due to make the SCL generates 100k

	I2C->I2C_TRISE |= 9;			//feedback and rise time (ask the instructor)

	//I2C->I2C_OAR1 |= 1<<15;



	SET_BIT(I2C->I2C_CR1,0);  //PE : prepheral enable

}


void I2C_voidSendStart(void){

	SET_BIT(I2C->I2C_CR1,10);		//enable Ack
	SET_BIT(I2C->I2C_CR1,8);     //send Start

	while(!(GET_BIT(I2C->I2C_SR1 ,0)));  //SB

	volatile uint8 temp = I2C->I2C_SR1;
}

void I2C_voidSendStop(void){

	SET_BIT(I2C->I2C_CR1,9);     //send Stop

}
void I2C_voidEnable(void){

	RCC_voidEnablePerClk(RCC_APB1, I2C1EN);
}


void I2C_voidDisable(void){
	RCC_voidDisablePerClk(RCC_APB1, I2C1EN);
}


void I2C_voidSelectSlave(uint8 Address){

//	I2C->I2C_DR = (Address);  //  send the address
//	while (!(GET_BIT(I2C->I2C_SR1, 1)));  // wait for ADDR bit to set
//
////	volatile uint8 temp = I2C->I2C_SR1;   // read SR1 and SR2 to clear the ADDR bit
////		temp =  I2C->I2C_SR2;

	I2C->I2C_DR = Address;  //  send the address

	//volatile uint8 x = 1;
	while (!(GET_BIT(I2C->I2C_SR1, 1)));  // wait for ADDR bit to set

	volatile uint8 temp = I2C->I2C_SR1;   // read SR1 and SR2 to clear the ADDR bit
	temp =  I2C->I2C_SR2;

}


void I2C_voidWriteByte(uint8 byte){

	//volatile uint8 temp = I2C->I2C_DR;
	while(!(GET_BIT(I2C->I2C_SR1, 7)));	// wait for TXE bit to set
	I2C->I2C_DR = byte;


	while(!(GET_BIT(I2C->I2C_SR1, 2)));	// wait for BTF bit to set
}

void I2C_voidReadByte(volatile uint8 * ptr){

	while(!(GET_BIT(I2C->I2C_SR1, 6)));	// wait for BTF bit to set

	*ptr = (uint8)I2C->I2C_DR;

}



//start
//send MSB of eeprom add
//send LSB of eeprom
//write byte
//stop


//stat
//write
//write
//start
//write EEPROM address + 1 (for read)
//read
//stop
