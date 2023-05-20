/*=================================================================================
*   @file       Std_Types.h   
*   @details    File Std_Types.h contains the data types defintions that used almostly by all other files
*   @author     Abdelrahman Ahmed Elshenawy 
===================================================================================*/
#ifndef     STD_TYPES_H
#define     STD_TYPES_H

/*Section:	 includes============================================= */



/*Section: Data Types Definitions==================================*/
typedef		unsigned	        char	uint8;
typedef		unsigned	short	int		uint16;
typedef		unsigned			int		uint32;
typedef		unsigned	long	long	uint64;

typedef							float	float32;
typedef							double	float64;

typedef		signed		        char    sint8;
typedef		signed		short	int		sint16;
typedef		signed				int		sint32;
typedef		signed		long	long	sint64;




/*Section: Object Like Macro Definitions===========================*/

#ifndef NULL
#define NULL			0x00
#endif

#ifndef NULL_PTR
#define NULL_PTR		(void *)0
#endif


#define ENABLE          0x01
#define DISABLE         0x00

#define	STD_HIGH		0x01
#define STD_LOW			0x00

#define STD_ON			0x01
#define STD_OFF			0x00

#define STD_ACTIVE		0x01
#define STD_IDLE		0x00



/*Section: Function Like Macro Definitions=========================*/

/*Section: Functions Declarations=================================*/


#endif /*ifndef STD_TYPES_H */
