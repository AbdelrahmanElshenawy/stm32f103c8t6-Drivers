#include "Std_Types.h"


typedef uint8 u8;



void		EXTI_voidChoosePinInPort(u8 line , u8 pinnumber ,u8 port);
void		EXTI0_voidInit(void);
void		EXTI_voidEnableInt(u8 line_num);
void		EXTI_voidDisableInt(u8 line_num);

void		EXTI_voidEnableSWI(u8 line_num);
void		EXTI_voidChangeSenseMode(u8 line_num, u8 Sense_Mode);


void		EXTI0_voidSetCallBack(void (*Fptr)(void));
