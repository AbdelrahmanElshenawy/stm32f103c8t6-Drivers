#include "Bit_Math.h"
#include "RCC_interface.h"
#include "DIO_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"

void SPI_voidEnable(void){
	//enable peripheral
	RCC_voidEnablePerClk(RCC_APB2, SPI1EN);

	RCC_voidEnablePerClk(RCC_APB2, AFIOEN);
	RCC_voidEnablePerClk(RCC_APB2, IOPAEN);
	//Setupt the GPIO
	DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_50MHZ_PP);			//ss
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_50MHZ_AFPP);		//CLK
	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_INPUT_FLOATING);			//MISO
	DIO_voidSetPinDirection(PORTA, PIN7, GPIO_OUTPUT_50MHZ_AFPP); //MOSI

}

void SPI_voidDisable(void){

	RCC_voidDisablePerClk(RCC_APB2, SPI1EN);

}

void SPI_voidInit(void){

	//Enable UNIdirection
	CLR_BIT(SPI->SPI_CR1,15);

	//SET_BIT(SPI->SPI_CR1,14);
	//enable transmit and recieve
	CLR_BIT(SPI->SPI_CR1,10);

	//SW slave management
	SET_BIT(SPI->SPI_CR1,9);


	//BAUD rate : 000 for clk/2

	//Master Selection
	SET_BIT(SPI->SPI_CR1,2);

	//CLK Polarity , phase
	CLR_BIT(SPI->SPI_CR1,1);
	CLR_BIT(SPI->SPI_CR1,0);


	//SS output enable, SPI_CR2
//	SET_BIT(SPI->SPI_CR2,2);

	//SPI enable
	SET_BIT(SPI->SPI_CR1,6);

}

void SPI_TransmitChar(uint8 data){

	//check Transmit buffer "not empty 0" ?
	//while(GET_BIT(SPI->SPI_SR,1) == 0);

	SPI->SPI_DR = data;
	//check on flag to make sure of transmission
	//while(GET_BIT(SPI->SPI_SR,1) == 0); //TXE
}

uint8 SPI_Recieve(void){

	uint8 data;
	data = (uint8)(SPI->SPI_DR);
		//check on flag to make sure of transmission
		//while(GET_BIT(SPI->SPI_SR,7) == 1); //BSY
	return data;
}



