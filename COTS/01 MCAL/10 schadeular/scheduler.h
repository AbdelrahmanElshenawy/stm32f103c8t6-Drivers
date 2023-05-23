#ifndef  H_scheduler_H
#define  H_scheduler_H

#include "../../00 LIB/Std_Types.h"
#include "../../00 LIB/Bit_Math.h"
#include "../../01 MCAL/01 GPIO/DIO_interface.h"



typedef struct{

	void (*task_ptr)(void);
	uint8 task_periority;
	uint32 task_periodicity;

}task_t;


void createTask(void(*ptr)(void),uint8 periority, uint32 periodicty);
//create task(pointer to function ,priotity, periodicty)

void schaduelar(void);
//start schaduelar



#endif
