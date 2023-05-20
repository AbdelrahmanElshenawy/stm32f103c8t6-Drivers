#include "Std_Types.h"
#include "Bit_Math.h"

#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"



#ifndef NULL_PTR

#define NULL_PTR  (void *) 0

#endif

static void (*STk_CallBack) (void) = NULL_PTR;
static uint8   STK_uint8ModeOfInterval;

void STK_voidInit(){

    #if     STK_CLK_SRC == STK_AHB_DIV_8
        STK->CTRL = 0x00000000;   //the enable bit is 0 because i dont want it to be ready 
    #elif   STK_CLK_SRC == STK_AHB
        STK->CTRL = 0x00000004;    //the enable bit is 0 because i dont want it to be ready
    #else
    #endif

}


void STK_voidSetBusyWait(uint32 Ticks){  
    /*  1. Load Ticks to LOAD register          */
    STK->LOAD = Ticks;    //Once it is set the value is gone to VAL register

    /*  2. Start Timer to begin count           */
    SET_BIT(STK->CTRL,0);

    /*  3. Wait till the flag is raised         */
    while(GET_BIT(STK->CTRL,16) == 0){
        asm("NOP");     //just for debugging only to stop here if there is error
    }
    /*  4. Stop the Timer                       */
    CLR_BIT(STK->CTRL,0);
    STK->LOAD   = 0;   
    STK->VAL    = 0;
}


void STK_voidSetIntervalSingle(uint32 Ticks , void (*pf) (void)){
    /*  1. Load Ticks to LOAD register          */
    STK->LOAD = Ticks;

    /*  2. Start Timer to begin count           */
    SET_BIT(STK->CTRL,0);
    
    /*  3. Save Call back function*/
    STk_CallBack = pf;

    /*  4. Enable STK interrupt*/
    SET_BIT(STK->CTRL,1);

    /*  5. Set the mode of interval*/
    STK_uint8ModeOfInterval = STK_SINGLE_INTERVAL;

}
void STK_voidSetIntervalPeriodic(uint32 Ticks , void (*pf) (void)){

     /*  1. Load Ticks to LOAD register          */
    STK->LOAD = Ticks;

    /*  2. Start Timer to begin count           */
    SET_BIT(STK->CTRL,0);
    
    /*  3. Save Call back function*/
    STk_CallBack = pf;

    /*  4. Enable STK interrupt*/
    SET_BIT(STK->CTRL,1);
    
    /*  5. Set the mode of interval*/
    STK_uint8ModeOfInterval = STK_PERIODIC_INTERVAL;

}

void STK_voidStopInterval(){
    /* Disable Interrupt*/
    CLR_BIT(STK->CTRL,1);
    /*  4. Stop the Timer                       */
    CLR_BIT(STK->CTRL,0);
    STK->LOAD   = 0;   
    STK->VAL    = 0;
}

uint32 STK_GetElapsedTime(){

    uint32 Localuint32ElapsedTime = 0;
    Localuint32ElapsedTime = (STK->LOAD) - (STK->VAL);
    return Localuint32ElapsedTime;
}

uint32 STK_GetRemainingTime(){

    uint32 Localuint32Remaining = 0;
    Localuint32Remaining = STK->VAL;
    return Localuint32Remaining;


}


void SysTick_Handler(){

    uint8 volatile Local_uint8Temp = 0;
    if(STK_uint8ModeOfInterval == STK_SINGLE_INTERVAL){
    
    /* Disable Interrupt*/
    CLR_BIT(STK->CTRL,1);

    /*  4. Stop the Timer                       */
    CLR_BIT(STK->CTRL,0);
    STK->LOAD   = 0;   
    STK->VAL    = 0;
    
    }

    STk_CallBack();
    /*To clear Systick flag just read it*/
    Local_uint8Temp ++;
    Local_uint8Temp  =  GET_BIT(STK->CTRL,16);

}
