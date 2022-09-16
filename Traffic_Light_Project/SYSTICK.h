#ifndef SYSTICK_H_
#define SYSTICK_H_
#include "types.h"

/*Function to disable the systick timer*/
void SysTickDisable (void);

/*Function to enable the systick timer*/
void SysTickEnable (void);

/*This function set’s the period of timer in ticks*/
void SysTickPeriodSet (uint32 ui32Period);

/*This function check the COUNT register in the NVIC_ST_CTRL_R to make sure that the timer
has finished counting. Refer to page 138*/
uint8 SysTick_Is_Time_out(void);

#endif