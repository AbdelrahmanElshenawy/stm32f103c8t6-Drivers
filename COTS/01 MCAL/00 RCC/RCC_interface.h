/*=================================================================================
*   @file       RCC_Interface.h    
*   @details    File RCC_Interface.h contains the prototypes or declarations of software interfces used to access RCC(Reset and Control Clock)
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

#ifndef		RCC_INTERFACE_H
#define		RCC_INTERFACE_H

/*Section:	 includes============================================= */
#include "Std_Types.h"
#include "RCC_private.h"


/*Section: Object Like Macro Definitions===========================*/
/*Section: Function Like Macro Definitions=========================*/

#define		RCC_AHB				((uint8)0x00)
#define		RCC_APB1			((uint8)0x01)
#define		RCC_APB2			((uint8)0x02)


/*Section: Data Types Declarations================================*/



/*Section: Functions Declarations=================================*/


void 	RCC_voidSysClkInt(void);
void    RCC_voidEnablePerClk(uint8 BusId , uint32 PerId);
void	RCC_voidDisablePerClk(uint8 BusId , uint32 PerId);

#endif  /*RCC_INTERFACE_H*/
