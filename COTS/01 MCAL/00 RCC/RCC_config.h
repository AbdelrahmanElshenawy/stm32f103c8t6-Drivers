/*=================================================================================
*   @file       RCC_Config.h    
*   @details    File RCC_Config.h contains the precompile configrations of RCC (Reset and control clock) used to control clock 
                input to the CPU and prepherals, enabling and disabling other configrations @ref Reference Manual
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

#ifndef     RCC_CONFIG_H
#define     RCC_CONFIG_H


/*Section:  includes===============================================*/
#include    "Std_Types.h"

/*Section:  Object Like Macro Definitions===========================*/


#define 	SYS_CLK			HSI_CLK
#define  	CLK_SECURITY	DISABLE
#define     HSE_BYPASS      DISABLE

#define 	MAX_CLK_SOURCES		(uint8)0x02
#define     RCC_BUSSES_NUMBER   (uint8)0x02     /*AHB , APB1 , APB2*/






/*Section:  Function Like Macro Definitions=========================*/

/*Section:  Data Types Declarations================================*/





/*Section:  Functions Declarations=================================*/


#endif /*ifndef RCC_CONFIG_H */
