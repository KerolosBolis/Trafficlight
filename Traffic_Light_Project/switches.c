
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "switches.h"





void SW1_Init(void)
{
    DIO_Init(PORT_F_ID,PIN_4_ID,INPUT);
    GPIO_PORTF_IS_R   &= ~(1<<4);      /* PF4 detect edges */
    GPIO_PORTF_IBE_R   &= ~(1<<4);      /* PF4 will detect a certain edge */
    GPIO_PORTF_IEV_R   &= ~(1<<4);      /* PF4 will detect a falling edge */
    GPIO_PORTF_ICR_R   |= (1<<4);       /* Clear Trigger flag for PF4 (Interupt Flag) */
    GPIO_PORTF_IM_R    |= (1<<4);       /* Enable Interrupt on PF4 pin */
    /* Set GPIO PORTF priotiy as 2 by set Bit number 21, 22 and 23 with value 2 */
    NVIC_PRI7_R = (NVIC_PRI7_R & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY<<GPIO_PORTF_PRIORITY_BITS_POS); 
    NVIC_EN0_R         |= 0x40000000;   /* Enable NVIC Interrupt for GPIO PORTF by set bit number 30 in EN0 Register */
}
void SW2_Init(void)
{
    DIO_Init(PORT_F_ID,PIN_0_ID,INPUT);
    GPIO_PORTF_IS_R   &= ~(1<<0);      /* PF4 detect edges */
    GPIO_PORTF_IBE_R   &= ~(1<<0);      /* PF4 will detect a certain edge */
    GPIO_PORTF_IEV_R   &= ~(1<<0);      /* PF4 will detect a falling edge */
    GPIO_PORTF_ICR_R   |= (1<<0);       /* Clear Trigger flag for PF4 (Interupt Flag) */
    GPIO_PORTF_IM_R    |= (1<<0);       /* Enable Interrupt on PF4 pin */
    /* Set GPIO PORTF priotiy as 2 by set Bit number 21, 22 and 23 with value 2 */
    NVIC_PRI7_R = (NVIC_PRI7_R & GPIO_PORTF_PRIORITY_MASK) | (GPIO_PORTF_INTERRUPT_PRIORITY<<GPIO_PORTF_PRIORITY_BITS_POS); 
    NVIC_EN0_R         |= 0x40000000;   /* Enable NVIC Interrupt for GPIO PORTF by set bit number 30 in EN0 Register */
}
