#include "scheduler.h"
#include "../../01 MCAL/03 SYSTICK/STK_interface.h"








static task_t  Tasks[3];

void createTask(void(*ptr)(void),uint8 priority, uint32 periodicty){


	Tasks[priority].task_periority = priority;

	Tasks[priority].task_periodicity = periodicty;

	Tasks[priority].task_ptr = ptr;


//	task_type * temp =  tasks_list;
//	if(tasks_list == NULL_PTR){
//
//		tasks_list = malloc(sizeof(task_type));
//		tasks_list->task_ptr = ptr;
//		tasks_list->next = NULL_PTR;
//
//	}
//	else{
//
//		while(temp->next != NULL_PTR){
//
//			temp = temp->next;
//		}
//
//		temp->next = malloc(sizeof(task_type));
//		temp->next->task_ptr = ptr;
//		temp->next->next = NULL_PTR;
//	}

}
//create task(pointer to function ,priotity, periodicty)

void schaduelar(void){

	for(int i =0 ; i<3 ; i++){

		Tasks[i].task_ptr();
		STK_voidSetBusyWait(Tasks[i].task_periodicity);
}

}
//start schaduelar
