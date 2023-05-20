#ifndef		SPI_INTERFACE_H
#define		SPI_INTERFACE_H




#include "Std_Types.h"


//enable SPI
void SPI_voidEnable(void);

//disable SPI
void SPI_voidDisable(void);
//init

void SPI_voidInit(void);
//Transmit
void SPI_TransmitChar(uint8 data);

//recieve
uint8 SPI_Recieve(void);


#endif
