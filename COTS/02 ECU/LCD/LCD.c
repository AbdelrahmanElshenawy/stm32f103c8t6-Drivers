#include "LCD.h"


void LCD_Init(void)
{
	//setting pins used or port as output
	DIO_voidSetPinDirection(PORTB, RS ,GPIO_OUTPUT_2MHZ_PP   );         //PORTB RS = 8
	DIO_voidSetPinDirection(PORTB, RW ,GPIO_OUTPUT_2MHZ_PP	 );			//Rw = 9
	DIO_voidSetPinDirection(PORTB, LCD_EN ,GPIO_OUTPUT_2MHZ_PP	 );         //EN = 10

	DIO_voidSetPinDirection(LCDPORT,PIN4 ,GPIO_OUTPUT_2MHZ_PP	 );
	DIO_voidSetPinDirection(LCDPORT,PIN5 ,GPIO_OUTPUT_2MHZ_PP	 );
	DIO_voidSetPinDirection(LCDPORT,PIN6 ,GPIO_OUTPUT_2MHZ_PP	 );
	DIO_voidSetPinDirection(LCDPORT,PIN7 ,GPIO_OUTPUT_2MHZ_PP	 );
	
	//making 4 bit mode
    LCD_Command(0x02);    //return home
	LCD_Command(0x28);    //cursor moves to right
	LCD_Command(0x0c);   //
	LCD_Command(0x01);   //clear

	//return WORKED_OK;
}

void LCD_Command(volatile uint8 cmd)
{


	    DIO_voidSetPinValue(LCDPORT, PIN4, (((cmd >> 4) & BIT_MASK)));
		DIO_voidSetPinValue(LCDPORT, PIN5, (((cmd >> 5) & BIT_MASK)));
		DIO_voidSetPinValue(LCDPORT, PIN6, (((cmd >> 6) & BIT_MASK)));
		DIO_voidSetPinValue(LCDPORT, PIN7, (((cmd >> 7) & BIT_MASK)));

			DIO_voidSetPinValue(PORTB, RS, GPIO_LOW);
			DIO_voidSetPinValue(PORTB, LCD_EN, GPIO_HIGH);
			delay_ms();
			DIO_voidSetPinValue(PORTB, LCD_EN, GPIO_LOW);

     	DIO_voidSetPinValue(LCDPORT, PIN4, (cmd & BIT_MASK));
	    DIO_voidSetPinValue(LCDPORT, PIN5, (((cmd >> 1) & BIT_MASK)));
	    DIO_voidSetPinValue(LCDPORT, PIN6, (((cmd >> 2) & BIT_MASK)));
	    DIO_voidSetPinValue(LCDPORT, PIN7, (((cmd >> 3) & BIT_MASK)));


	    	DIO_voidSetPinValue(PORTB, RS, GPIO_LOW);
	   		DIO_voidSetPinValue(PORTB, LCD_EN, GPIO_HIGH);
	  		delay_ms();
	   		DIO_voidSetPinValue(PORTB, LCD_EN, GPIO_LOW);




	//LCDPORT = (cmd & 0xf0);   //the High bits from 7 to 4
	//LCDPORT |= (1<<EN);
	//delay_ms(10);
	//LCDPORT &= ~(1<<EN);
	
//	LCDPORT = (( cmd<<4 ) &( 0xf0));   //the High bits from 7 to 4
//	LCDPORT |= (1<<EN);
	//_delay_ms(10);
	//LCDPORT &= ~(1<<EN);
	
	//return WORKED_OK;
}

void LCD_ClearDisplay(void)
{
	LCD_Command(0x01);
	//return WORKED_OK;
}

void LCD_DisplayChar(uint8 Character)
{

	DIO_voidSetPinValue(LCDPORT, PIN4, (((Character >> 4) & BIT_MASK)));
	DIO_voidSetPinValue(LCDPORT, PIN5, (((Character >> 5) & BIT_MASK)));
	DIO_voidSetPinValue(LCDPORT, PIN6, (((Character >> 6) & BIT_MASK)));
	DIO_voidSetPinValue(LCDPORT, PIN7, (((Character >> 7) & BIT_MASK)));

		DIO_voidSetPinValue(PORTB, RS, GPIO_HIGH);
		DIO_voidSetPinValue(PORTB, LCD_EN, GPIO_HIGH);
		delay_ms();
		DIO_voidSetPinValue(PORTB, LCD_EN, GPIO_LOW);

	DIO_voidSetPinValue(LCDPORT, PIN4, (Character & BIT_MASK));
	DIO_voidSetPinValue(LCDPORT, PIN5, (((Character >> 1) & BIT_MASK)));
	DIO_voidSetPinValue(LCDPORT, PIN6, (((Character >> 2) & BIT_MASK)));
	DIO_voidSetPinValue(LCDPORT, PIN7, (((Character >> 3) & BIT_MASK)));

		DIO_voidSetPinValue(PORTB, RS, GPIO_HIGH);
		DIO_voidSetPinValue(PORTB, LCD_EN, GPIO_HIGH);
		delay_ms();
		DIO_voidSetPinValue(PORTB, LCD_EN, GPIO_LOW);

//	LCDPORT = (Character & 0xf0);   //the High bits from 7 to 4
//	LCDPORT |= (1<<RS);		//data
	//LCDPORT |= (1<<EN);		//enable
	//_delay_ms(10);
	//LCDPORT &= ~(1<<EN);
	
//	LCDPORT = (( Character << 4 ) &( 0xf0));   //the High bits from 7 to 4
	//LCDPORT |= (1<<RS);		//data
	//LCDPORT |= (1<<EN);		//enable
	//_delay_ms(10);
	//LCDPORT &= ~(1<<EN);
	
	//return WORKED_OK;
}


void LCD_DisplayWord(volatile uint8 *PtrToWord , uint8 WordLength)
{
	for(uint8 count = 0; (count < WordLength) && (PtrToWord[count] != '\0') ; count++)
	{
		LCD_DisplayChar(PtrToWord[count]);
	}
	//return WORKED_OK;
}

void delay_ms(void){


	for(int i = 0; i< 80000 ; i++){
		asm("NOP");
	}
}
