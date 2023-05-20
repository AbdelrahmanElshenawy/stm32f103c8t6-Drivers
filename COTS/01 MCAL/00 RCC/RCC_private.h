/*=================================================================================
*   @file       RCC_Private.h
*   @details    File RCC_Private.h contains the macros used to access addresses of the registers
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

#ifndef     RCC_PRIVATE_H
#define     RCC_PRIVATE_H


/*Section:	includes============================================= */
//#include    "Std_Types.h"


/*Section:  Data Types Declarations================================*/
#define     HSI_CLK      	0x00U
#define     HSE_CLK      	0x01U
#define     PLL_CLK     	0x02U




/*Section:  Object Like Macro Definitions===========================*/

#define		RCC_BASE_ADD		(0x40021000)

#define		RCC_CR				*((volatile uint32 *)(RCC_BASE_ADD+0x00))
#define		RCC_CFGR			*((volatile uint32 *)(RCC_BASE_ADD+0x04))
#define		RCC_CIR				*((volatile uint32 *)(RCC_BASE_ADD+0x08))
#define		RCC_APB2RSTR		*((volatile uint32 *)(RCC_BASE_ADD+0x0C))
#define		RCC_APB1RSTR		*((volatile uint32 *)(RCC_BASE_ADD+0x10))
#define		RCC_AHBENR			*((volatile uint32 *)(RCC_BASE_ADD+0x14))
#define		RCC_APB2ENR			*((volatile uint32 *)(RCC_BASE_ADD+0x18))
#define		RCC_APB1ENR			*((volatile uint32 *)(RCC_BASE_ADD+0x1C))
#define		RCC_BDCR			*((volatile uint32 *)(RCC_BASE_ADD+0x20))
#define		RCC_CSR				*((volatile uint32 *)(RCC_BASE_ADD+0x24))


/*RCC_CR BITS============================*/ //Modified
#define HSION             ((uint32)0x00000000)
#define HSIRDY            ((uint32)0x00000001)
#define HSEON             ((uint32)0x00000010)
#define HSERDY            ((uint32)0x00000011)

#define HSEBYP            ((uint32)0x00000012)
#define CSSON             ((uint32)0x00000013)
#define PLLON             ((uint32)0x00000018)
#define PLLRDY            ((uint32)0x00000019)
/*AHB-peripheral clock REG BITS==========================*/

#define DMA1EN            ((uint32)0x00000000)
#define DMA2EN            ((uint32)0x00000002)
#define SRAMEN            ((uint32)0x00000003)
#define FLITFEN           ((uint32)0x00000004)
#define CRCEN             ((uint32)0x00000040)
#define FSMCEN            ((uint32)0x00000100)
#define SDIOEN            ((uint32)0x00000400)


/*APB2-peripheral clock REG BITS==========================*/ // Modified

#define AFIOEN       ((uint32)0x00000000)
#define IOPAEN       ((uint32)0x00000002)
#define IOPBEN     	 ((uint32)0x00000003)
#define IOPCEN       ((uint32)0x00000004)
#define IOPDEN       ((uint32)0x00000005)
#define IOPEEN       ((uint32)0x00000006)
#define IOPFEN       ((uint32)0x00000007)
#define IOPGEN       ((uint32)0x00000008)
#define ADC1EN       ((uint32)0x00000009)
#define ADC2EN       ((uint32)0x0000000A)
#define TIM1EN       ((uint32)0x0000000B)
#define SPI1EN       ((uint32)0x0000000C)
#define TIM8EN       ((uint32)0x0000000D)
#define USART1EN     ((uint32)0x0000000E)
#define ADC3EN       ((uint32)0x0000000F)
#define TIM9EN       ((uint32)0x00000013)
#define TIM10EN      ((uint32)0x00000014)
#define TIM11EN      ((uint32)0x00000015)


/*APB1-peripheral clock REG BITS==================*/ // MODIFIED
#define TIM2EN      ((uint32)0x00000000)
#define TIM3EN      ((uint32)0x00000001)
#define TIM4EN   	((uint32)0x00000002)
#define TIM5EN      ((uint32)0x00000003)
#define TIM6EN   	((uint32)0x00000004)
#define TIM7EN   	((uint32)0x00000005)
#define TIM12EN   	((uint32)0x00000006)
#define TIM13EN   	((uint32)0x00000007)
#define TIM14EN   	((uint32)0x00000008)
#define WWDGEN     	((uint32)0x0000000B)
#define SPI2EN     	((uint32)0x0000000E)
#define SPI3EN    	((uint32)0x0000000F)
#define USART2EN 	((uint32)0x00000011)
#define USART3EN 	((uint32)0x00000012)
#define UART4EN  	((uint32)0x00000013)
#define UART5EN 	((uint32)0x00000014)
#define I2C1EN   	((uint32)0x00000015)
#define I2C2EN   	((uint32)0x00000016)
#define USBEN    	((uint32)0x00000017)
#define CANEN    	((uint32)0x00000019)
#define BKPEN    	((uint32)0x0000001B)
#define PWREN    	((uint32)0x0000001C)
#define DACEN    	((uint32)0x0000001D)


/*Section:  Function Like Macro Definitions=========================*/


/*Section:  Functions Declarations=================================*/


#endif /*ifndef RCC_PRIVATE_H*/
