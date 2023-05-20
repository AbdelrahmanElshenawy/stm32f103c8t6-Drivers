/*=================================================================================
*   @file       Bit_Math.h      
*   @details    File Bit_Math.h contains the definitions of macro function and macros that help in 
                accessing the register bits
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/

#ifndef     BIT_MATH_H
#define		BIT_MATH_H
      


/*Section:	 includes============================================= */
#include "Std_Types.h"

/*Section: Object Like Macro Definitions===========================*/
#define     BIT_MASK                (uint32)(0x1)

/*Section: Function Like Macro Definitions=========================*/
#define		SET_BIT(REG,BIT)		(REG) |= ((BIT_MASK)<<(BIT))      /*Set bit to 1 in a specific register*/
#define		CLR_BIT(REG,BIT)		(REG) &=  (~((BIT_MASK)<<(BIT)))   /*clear bit, or put 0 in a specific bit in a specific register*/
#define		TOG_BIT(REG,BIT)		(REG) ^=  ((BIT_MASK)<<(BIT))      /*toggle a specific bit in a specific register*/
#define		GET_BIT(REG,BIT)		(((REG)>>(BIT)) & (BIT_MASK))       /*read the value of a specif bit in a specific register*/
/*Section: Data Types Declarations================================*/
/*Section: Functions Declarations=================================*/


#endif /*ifndef BIT_MATH_H */

		
