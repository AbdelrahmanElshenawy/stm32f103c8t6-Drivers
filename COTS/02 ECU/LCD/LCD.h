#ifndef H_LCD_H
#define H_LCD_H

#include "LCD_Configration.h"
#include "DIO_interface.h"


#ifndef BIT_MASK
#define BIT_MASK 1U
#endif
void LCD_Init(void);

void LCD_Command(uint8 cmd);

void LCD_ClearDisplay(void);

void LCD_DisplayChar(uint8 Character);

void LCD_DisplayWord(volatile uint8 *PtrToWord, uint8 LengthInclude_NullEnd);

void delay_ms(void);

#endif
