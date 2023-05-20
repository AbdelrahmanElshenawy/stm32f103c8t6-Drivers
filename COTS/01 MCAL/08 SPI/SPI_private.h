#ifndef		SPI_PRIVATE_H
#define		SPI_PRIVATE_H


#include "Std_Types.h"



typedef struct{

	uint32 SPI_CR1;
	uint32 SPI_CR2;
	uint32 SPI_SR;
	uint32 SPI_DR;
	uint32 SPI_CRCPR;
	uint32 SPI_RXCRCR;
	uint32 SPI_TXCRCR;
	uint32 SPI_I2SCFGR;
	uint32 SPI_I2SPR;

}SPI_type;


#define 	SPI		((volatile SPI_type*)0x40013000)

#endif
