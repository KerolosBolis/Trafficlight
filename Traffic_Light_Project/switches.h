#ifndef SWITCHES_H_
#define SWITCHES_H_

#include "types.h"
#include "bitwise_operations.h"




#define GPIO_PORTF_PRIORITY_MASK      0xFF1FFFFF
#define GPIO_PORTF_PRIORITY_BITS_POS  21
#define GPIO_PORTF_INTERRUPT_PRIORITY 2

void SW1_Init(void);
void SW2_Init(void);

#endif