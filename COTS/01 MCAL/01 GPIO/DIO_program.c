#include "Std_Types.h"
#include "Bit_Math.h"
#include "DIO_private.h"
#include "DIO_interface.h"
#include "RCC_interface.h"


static void DIO_voidSetOutputBit(uint8 port,uint8 pin);
static void DIO_voidResetOutputBit(uint8 port,uint8 pin);

void	DIO_voidSetPinDirection(uint8 port, uint8 pin, uint8 Direction){

	if((port > GPIO_PORTS_NUMBER)||
		(pin > PIN15)){
		//error
	}
	else{

		if(pin < 8){

			switch(port){
			case PORTA:

				/*Clear first because you want to write number of bits*/
				GPIOA_CRL &= (~((0b1111)<<(pin*4)));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/
				GPIOA_CRL |= ((Direction)<<(pin*4));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/

				break;

			case PORTB:
				GPIOB_CRL &= (~((0b1111)<<(pin*4)));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/
				GPIOB_CRL |= ((Direction)<<(pin*4));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/

				break;

			case PORTC:

				GPIOC_CRL &= (~((0b1111)<<(pin*4)));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/
				GPIOC_CRL |= ((Direction)<<(pin*4));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/

				break;
			}

		}
		else if(pin < 16){

			pin -= 8; //because pin now has values from 8 to 15 and we want to make (pin * 4) still valid

			switch(port){

			case PORTA:
				/*Clear first because you want to write number of bits*/
				GPIOA_CRH &= (~((0b1111)<<(pin*4)));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/
				GPIOA_CRH |= ((Direction)<<(pin*4));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/

				break;

			case PORTB:
				GPIOB_CRH &= (~((0b1111)<<(pin*4)));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/
				GPIOB_CRH |= ((Direction)<<(pin*4));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/

				break;

			case PORTC:
				GPIOC_CRH &= (~((0b1111)<<(pin*4)));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/
				GPIOC_CRH |= ((Direction)<<(pin*4));    /* pin * 4 because the step in GPIOA_CRL is 4 , we want to access 4 bits at once*/


				break;
			}


		}

	}


}
void	DIO_voidSetPinValue(uint8 port, uint8 pin, uint8 Value){

	if((port > GPIO_PORTS_NUMBER)||
			(pin > PIN15)){
			//error
		}
	else{

		switch(Value){

		case GPIO_HIGH:
			DIO_voidSetOutputBit(port , pin);
			break;
		case GPIO_LOW:
			DIO_voidResetOutputBit(port , pin);
			break;
		default:
			//error
		break;

			}
	}



}
uint8		DIO_u8GetPinValue(uint8 port, uint8 pin){

	uint8 ret = 0x99;
	if((port > GPIO_PORTS_NUMBER)||
				(pin > PIN15)){
				//error
			}
	else{
		switch(port){
		case PORTA:
			ret = GET_BIT(GPIOA_IDR, pin);
			break;
		case PORTB:
			ret = GET_BIT(GPIOB_IDR,pin);
			break;
		case PORTC:
			ret = GET_BIT(GPIOC_IDR,pin);
			break;
		}
	}

	return ret;
}


static void DIO_voidSetOutputBit(uint8 port,uint8 pin){
	switch(port){
	case PORTA:
		GPIOA_BSRR = (BIT_MASK<<pin);
		break;

	case PORTB:
		GPIOB_BSRR = (BIT_MASK<<pin);
		break;

	case PORTC:
		GPIOC_BSRR = (BIT_MASK<<pin);
		break;
	}

}

static void DIO_voidResetOutputBit(uint8 port,uint8 pin){
	switch(port){
	case PORTA:
		GPIOA_BRR = (BIT_MASK<<pin);
		break;

	case PORTB:
		GPIOB_BRR = (BIT_MASK<<pin);
		break;

	case PORTC:
		GPIOC_BRR = (BIT_MASK<<pin);
		break;
	}

}




