#include "EXTI_interface.h"
#include "EXTI_private.h"
#include "Bit_Math.h"
#include "DIO_interface.h"

#ifndef		NULL
#define		NULL			((void *)0)
#endif




#ifndef NULL_PTR
#define NULL_PTR  (void *)0
#endif

static	void	(*EXTI0_CallBack)	(void)	= NULL_PTR;

void		EXTI0_voidInit(void)
{
	#ifndef AFIO

#define AFIO_BASE_ADD	0x40010000

#define AFIO_EXTICR1   (*((volatile uint32 *)(AFIO_BASE_ADD + 0x08 )))
#define AFIO_EXTICR2   (*((volatile uint32 *)(AFIO_BASE_ADD + 0x0C )))
#define AFIO_EXTICR3   (*((volatile uint32 *)(AFIO_BASE_ADD + 0x10 )))
#define AFIO_EXTICR4   (*((volatile uint32 *)(AFIO_BASE_ADD + 0x14 )))

#endif
}




void EXTI_voidChoosePinInPort(uint8 line , uint8 pinnumber ,uint8 port){

	if(line < 4){
		switch(pinnumber){
		case 0:
			SET_BIT(AFIO_EXTICR1 , port);
			break;
		case 1:
			SET_BIT(AFIO_EXTICR1 , (port<< 4));
			break;
		case 2:
			SET_BIT(AFIO_EXTICR1 , (port<< 8));
			break;
		case 3:
			SET_BIT(AFIO_EXTICR1 , (port<< 12));
			break;
		}
	}
}

void		EXTI_voidEnableInt(uint8 line_num )
{
	SET_BIT( EXTI->IMR,line_num);
	SET_BIT(EXTI->PR , line_num);
}

void		EXTI_voidDisableInt(uint8 line_num)
{
	CLR_BIT(EXTI->IMR,line_num);
}


void		EXTI_voidEnableSWI(uint8 line_num)
{
	SET_BIT(EXTI->SWIER,line_num);
}


void		EXTI_voidChangeSenseMode(uint8 line_num, uint8 Sense_Mode)
{
	switch(Sense_Mode)
	{
		case	RISING_EDGE		:	SET_BIT(EXTI->  RTSR,line_num);
									CLR_BIT(EXTI -> FTSR,line_num);		break;

		case	FALLING_EDGE	:	SET_BIT(EXTI -> FTSR,line_num);
									CLR_BIT(EXTI -> RTSR,line_num);		break;

		case	IOC				:	SET_BIT(EXTI -> RTSR,line_num);
									SET_BIT(EXTI -> FTSR,line_num);		break;
	}

}

void		EXTI0_voidSetCallBack(void (*Fptr)(void))
{
	if(Fptr != NULL_PTR)
	{
		EXTI0_CallBack = Fptr;
	}
}

void	EXTI0_IRQHandler(void)
{

	DIO_voidSetPinValue(PORTB, 11, 1);
	EXTI0_CallBack();
	/*	Clear the Flag			*/
}




