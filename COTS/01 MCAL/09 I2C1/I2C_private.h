#ifndef	I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include	"Std_Types.h"

typedef struct{

	uint32	I2C_CR1;
	uint32 	I2C_CR2;
	uint32	I2C_OAR1;
	uint32	I2C_OAR2;
	uint32	I2C_DR;
	uint32	I2C_SR1;
	uint32	I2C_SR2;
	uint32	I2C_CCR;
	uint32	I2C_TRISE;

}I2C_type;

#define I2C		((volatile I2C_type*)(0x40005400))




#endif
