#ifndef GPTM_H_
#define GPTM_H_

#include "types.h"
#include "bitwise_operations.h"

#define TIMER0A_PRIORITY_MASK      0x1FFFFFFF
#define TIMER0A_PRIORITY_BITS_POS  29
#define TIMER0A_INTERRUPT_PRIORITY 4

#define TIMER1A_PRIORITY_MASK      0xFFFF1FFF
#define TIMER1A_PRIORITY_BITS_POS  13
#define TIMER1A_INTERRUPT_PRIORITY 2

void Timer0A_Enable(uint32 timer_period);
void Timer1A_Enable(uint32 timer_period);
void timer1A_delay1000MS();


#endif
