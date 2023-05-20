#ifndef	I2C_INTERFACE_H
#define I2C_INTERFACE_H



void I2C_voidInit(void);
void I2C_voidEnable(void);
void I2C_voidDisable(void);

void I2C_voidSendStart(void);
void I2C_voidSendStop(void);

void I2C_voidSelectSlave(uint8 slave_add);
void I2C_voidWriteByte(uint8 byte);
void I2C_voidReadByte(volatile uint8 * ptr);




#endif
