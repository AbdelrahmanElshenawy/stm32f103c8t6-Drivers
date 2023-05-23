#include "../01 MCAL/00 RCC/RCC_interface.h"
#include "../01 MCAL/03 SYSTICK/STK_interface.h"
#include "../01 MCAL/01 GPIO/DIO_interface.h"
#include "../01 MCAL/10 schadeular/scheduler.h"

void LED_1(void);
void LED_2(void);
void LED_3(void);

int main(void){

	RCC_voidSysClkInt();
	RCC_voidEnablePerClk(RCC_APB2, IOPAEN);
	DIO_voidSetPinDirection(PORTA, PIN0, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN1, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN2, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN3, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN4, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN5, GPIO_OUTPUT_10MHZ_PP);
	DIO_voidSetPinDirection(PORTA, PIN6, GPIO_OUTPUT_10MHZ_PP);


	createTask(LED_1, 0, 1000000);
	createTask(LED_2, 1, 1000000);
	createTask(LED_3, 2, 1000000);

	while(1){
	STK_voidSetIntervalSingle(3000000, schaduelar);

	}
}

void LED_1(void){

	DIO_voidSetPinValue(PORTA, PIN0, GPIO_LOW);			 	//a
	DIO_voidSetPinValue(PORTA, PIN1, GPIO_HIGH);			//b  1
	DIO_voidSetPinValue(PORTA, PIN2, GPIO_HIGH);          	//c  1
	DIO_voidSetPinValue(PORTA, PIN3, GPIO_LOW);          	//d
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_LOW);         	//e
	DIO_voidSetPinValue(PORTA, PIN5, GPIO_LOW);          	//f
	DIO_voidSetPinValue(PORTA, PIN6, GPIO_LOW);         	//g


	//STK_voidSetBusyWait(300000);

}

void LED_2(void){


	DIO_voidSetPinValue(PORTA, PIN0, GPIO_HIGH);		 	//a  1
	DIO_voidSetPinValue(PORTA, PIN1, GPIO_HIGH);			//b  1
	DIO_voidSetPinValue(PORTA, PIN2, GPIO_LOW);          	//c
	DIO_voidSetPinValue(PORTA, PIN3, GPIO_HIGH);          	//d  1
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_HIGH);         	//e  1
	DIO_voidSetPinValue(PORTA, PIN5, GPIO_LOW);          	//f
	DIO_voidSetPinValue(PORTA, PIN6, GPIO_HIGH);         	//g  1

//	STK_voidSetBusyWait(300000);

}

void LED_3(void){


	DIO_voidSetPinValue(PORTA, PIN0, GPIO_HIGH);			//a
	DIO_voidSetPinValue(PORTA, PIN1, GPIO_HIGH);			//b
	DIO_voidSetPinValue(PORTA, PIN2, GPIO_HIGH);          	//c
	DIO_voidSetPinValue(PORTA, PIN3, GPIO_HIGH);          	//d
	DIO_voidSetPinValue(PORTA, PIN4, GPIO_LOW);         	//e  0
	DIO_voidSetPinValue(PORTA, PIN5, GPIO_LOW);          	//f  0
	DIO_voidSetPinValue(PORTA, PIN6, GPIO_HIGH);         	//g

	//STK_voidSetBusyWait(200000);
}