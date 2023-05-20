
/*=================================================================================
*   @file       RCC_Interface.c    
*   @details    File RCC_Interface.c contains the defintions of software interfces used to access RCC(Reset and Control Clock)
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

/*Section:	 includes============================================= */
#include 	"Std_Types.h"
#include	"Bit_Math.h"

#include	"RCC_Interface.h" 
#include 	"RCC_Private.h"
#include 	"RCC_Config.h"


/*
*	@brief		Initializing the clock source
*	@param		clk_control pointer to clk_cntrl_t to determine configurations @ref	clk_control_t
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/

void		RCC_voidSysClkInt(void){

#if SYS_CLK == HSI_CLK

	SET_BIT(RCC_CR, HSION );
	while( GET_BIT(RCC_CR , HSIRDY) == STD_LOW){
	}

#elif SYS_CLK == HSE_CLK

	SET_BIT(RCC_CR, HSEON );
	while( GET_BIT(RCC_CR , HSERDY) == STD_LOW);


#elif SYS_CLK == PLL_CLK
	SET_BIT(RCC_CR, PLLON );
	while( GET_BIT(RCC_CR , PLLRDY) == STD_LOW);

#endif


#if CLK_SECURITY == ENABLE
	SET_BIT(RCC_CR, CSSON );

#else

	CLR_BIT(RCC_CR, PLLON );

#endif

#if	HSE_BYPASS == ENABLE
	SET_BIT(RCC_CR, HSEBYP );

#else
	CLR_BIT(RCC_CR, HSEBYP );
#endif

}

/*
*	@brief		Enabling the clock peripheral
*	@param		BusId for AHB, APB2, APB1
*				PerId for a peripheral that supported by the chosen Bus
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
void		RCC_voidEnablePerClk(uint8 BusId , uint32 PerId) {
	
	
	if (BusId > RCC_BUSSES_NUMBER) {
		//return error
	}
	else {

		switch (BusId) {

		case RCC_AHB:
			if ((PerId != DMA1EN) && \
				(PerId != DMA2EN) && \
				(PerId != SRAMEN) && \
				(PerId != FLITFEN) && \
				(PerId != CRCEN) && \
				(PerId != FSMCEN) && \
				(PerId != SDIOEN)) {
				
				//return error
			}
			else {
			
				SET_BIT(RCC_AHBENR, PerId);
				
			}
			break;

		case RCC_APB2:
			if ((PerId != AFIOEN) && \
				(PerId != IOPAEN) && \
				(PerId != IOPBEN) && \
				(PerId != IOPCEN) && \
				(PerId != IOPDEN) && \
				(PerId != IOPEEN) && \
				(PerId != IOPFEN) && \
				(PerId != IOPGEN) && \
				(PerId != ADC1EN) && \
				(PerId != ADC2EN) && \
				(PerId != TIM1EN) && \
				(PerId != SPI1EN) && \
				(PerId != TIM8EN) && \
				(PerId != USART1EN) && \
				(PerId != ADC3EN) && \
				(PerId != TIM9EN) && \
				(PerId != TIM10EN) && \
				(PerId != TIM11EN)) {

				//return error
			}
			else {
				SET_BIT(RCC_APB2ENR	, PerId);
			}
			break;

		case RCC_APB1:
			if ((PerId != TIM2EN   ) && \
				(PerId != TIM3EN   ) && \
				(PerId != TIM4EN   ) && \
				(PerId != TIM5EN   ) && \
				(PerId != TIM6EN   ) && \
				(PerId != TIM7EN   ) && \
				(PerId != TIM12EN  ) && \
				(PerId != TIM13EN  ) && \
				(PerId != TIM14EN  ) && \
				(PerId != WWDGEN   ) && \
				(PerId != SPI2EN   ) && \
				(PerId != SPI3EN   ) && \
				(PerId != USART2EN ) && \
				(PerId != USART3EN ) && \
				(PerId != UART4EN  ) && \
				(PerId != UART5EN  ) && \
				(PerId != I2C1EN   ) && \
				(PerId != I2C2EN   ) && \
				(PerId != USBEN    ) && \
				(PerId != CANEN    ) && \
				(PerId != BKPEN    ) && \
				(PerId != PWREN    ) && \
				(PerId != DACEN    )) {
				//return error
			}
			else {
				SET_BIT(RCC_APB1ENR	, PerId);
			}
			break;

		default:
			//return error
			break;
		}

	}
}

/*
*	@brief		Disabling the clock peripheral
*	@param		BusId for AHB, APB2, APB1
*				PerId for a peripheral that supported by the chosen Bus
*	@return		Status of the function
*				(E_OK)		The function works successfully
*				(E_NOT_OK)	The function has some issues
*/
void		RCC_voidDisblePerClk(uint8 BusId , uint32 PerId) {
	
	if (BusId > RCC_BUSSES_NUMBER) {
		//return error
	}
	else {
		switch (BusId) {

		case RCC_AHB:
			if ((PerId != DMA1EN) && \
				(PerId != DMA2EN) && \
				(PerId != SRAMEN) && \
				(PerId != FLITFEN) && \
				(PerId != CRCEN) && \
				(PerId != FSMCEN) && \
				(PerId != SDIOEN)) {
				
				//return error
			}
			else {
			
				CLR_BIT(RCC_AHBENR, PerId);
				
			}
			break;

		case RCC_APB2:
			if ((PerId != AFIOEN) && \
				(PerId != IOPAEN) && \
				(PerId != IOPBEN) && \
				(PerId != IOPCEN) && \
				(PerId != IOPDEN) && \
				(PerId != IOPEEN) && \
				(PerId != IOPFEN) && \
				(PerId != IOPGEN) && \
				(PerId != ADC1EN) && \
				(PerId != ADC2EN) && \
				(PerId != TIM1EN) && \
				(PerId != SPI1EN) && \
				(PerId != TIM8EN) && \
				(PerId != USART1EN) && \
				(PerId != ADC3EN) && \
				(PerId != TIM9EN) && \
				(PerId != TIM10EN) && \
				(PerId != TIM11EN)) {

				//return error
			}
			else {
				CLR_BIT(RCC_APB2ENR	, PerId);
			}
			break;

		case RCC_APB1:
			if ((PerId != TIM2EN   ) && \
				(PerId != TIM3EN   ) && \
				(PerId != TIM4EN   ) && \
				(PerId != TIM5EN   ) && \
				(PerId != TIM6EN   ) && \
				(PerId != TIM7EN   ) && \
				(PerId != TIM12EN  ) && \
				(PerId != TIM13EN  ) && \
				(PerId != TIM14EN  ) && \
				(PerId != WWDGEN   ) && \
				(PerId != SPI2EN   ) && \
				(PerId != SPI3EN   ) && \
				(PerId != USART2EN ) && \
				(PerId != USART3EN ) && \
				(PerId != UART4EN  ) && \
				(PerId != UART5EN  ) && \
				(PerId != I2C1EN   ) && \
				(PerId != I2C2EN   ) && \
				(PerId != USBEN    ) && \
				(PerId != CANEN    ) && \
				(PerId != BKPEN    ) && \
				(PerId != PWREN    ) && \
				(PerId != DACEN    )) {
				//return error
			}
			else {
				CLR_BIT(RCC_APB1ENR	, PerId);
			}
			break;

		default:
			//return error
			break;
		}

	}
}



