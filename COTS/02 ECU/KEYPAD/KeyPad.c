
#include "Bit_Math.h"
#include "KeyPad.h"
#include "KeyPad_Configration.h"
#include "DIO_interface.h"

void KeyPad_init(void)
{

	//R1 --------> OUTPUT
	DIO_voidSetPinDirection(KeyPadPORT, KP_R1 ,GPIO_OUTPUT_2MHZ_PP   );
	//R2
	DIO_voidSetPinDirection(KeyPadPORT, KP_R2 ,GPIO_OUTPUT_2MHZ_PP   );
	//R3
	DIO_voidSetPinDirection(KeyPadPORT, KP_R3 ,GPIO_OUTPUT_2MHZ_PP   );
	//R4
	DIO_voidSetPinDirection(KeyPadPORT, KP_R4 ,GPIO_OUTPUT_2MHZ_PP   );

	//C1--------->INPUT
	DIO_voidSetPinDirection(KeyPadPORT, KP_C1 ,GPIO_INPUT_PULL_UP_DOWN   );
	//C2
	DIO_voidSetPinDirection(KeyPadPORT, KP_C2 ,GPIO_INPUT_PULL_UP_DOWN   );

	//C3
	DIO_voidSetPinDirection(KeyPadPORT, KP_C3 ,GPIO_INPUT_PULL_UP_DOWN   );

	/*
	DIO_SetPinDirection(KeyPadDDR,KP_Pin0,IN);
	DIO_SetPinDirection(KeyPadDDR,KP_Pin1,IN);
	DIO_SetPinDirection(KeyPadDDR,KP_Pin2,IN);
	
	DIO_SetPinDirection(KeyPadDDR,KP_Pin4,OUT);
	DIO_SetPinDirection(KeyPadDDR,KP_Pin5,OUT);
	DIO_SetPinDirection(KeyPadDDR,KP_Pin6,OUT);
	DIO_SetPinDirection(KeyPadDDR,KP_Pin7,OUT);	
	*/

}

uint8 KeyPad_TrackButtons(void)
{
	uint8 ret = '\0';

	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_HIGH);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);

	//KeyPadPORT = 0x10;
	if(GET_BIT(KeyPadPIN , KP_C1)) {ret = '3';}
	if(GET_BIT(KeyPadPIN , KP_C2)) {ret = '2';}
	if(GET_BIT(KeyPadPIN , KP_C3)) {ret = '1';}
//=================================================================
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_HIGH);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
		
		//KeyPadPORT = 0x10;
		if(GET_BIT(KeyPadPIN , KP_C1)) {ret = '6';}
		if(GET_BIT(KeyPadPIN , KP_C2)) {ret = '5';}
		if(GET_BIT(KeyPadPIN , KP_C3)) {ret = '4';}
//===========================================================
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_HIGH);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
			
			//KeyPadPORT = 0x10;
		if(GET_BIT(KeyPadPIN , KP_C1)) {ret = '9';}
		if(GET_BIT(KeyPadPIN , KP_C2)) {ret = '8';}
		if(GET_BIT(KeyPadPIN , KP_C3)) {ret = '7';}
//================================================================
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_LOW);
	DIO_voidSetPinValue(KeyPadPORT, KP_R1, GPIO_HIGH);

				//KeyPadPORT = 0x10;
				if(GET_BIT(KeyPadPIN , KP_C1)) {ret =  '#';}
				if(GET_BIT(KeyPadPIN , KP_C2)) {ret =  '0';}
				if(GET_BIT(KeyPadPIN , KP_C3)) {ret =  '*';}


	return ret;
}
