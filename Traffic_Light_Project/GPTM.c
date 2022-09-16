#include "GPTM.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"

void Timer0A_Enable(uint32 timer_period){
  SYSCTL_RCGCTIMER_R|=0x01; //Enable clock to GPTM Module
  TIMER0_CTL_R=0x0; //Disable the timer
  TIMER0_CFG_R=0x00; //32-bit Mode
  TIMER0_TAMR_R=0x02; //BIT(0-1)   Periodic Mode
  TIMER0_TAILR_R=timer_period;
  TIMER0_ICR_R|=(1<<0);
  TIMER0_IMR_R|=(1<<0);
  NVIC_PRI4_R=(NVIC_PRI4_R & TIMER0A_PRIORITY_MASK) | (TIMER0A_INTERRUPT_PRIORITY<<TIMER0A_PRIORITY_BITS_POS);
  NVIC_EN0_R|=(1<<19);
  TIMER0_CTL_R=0x03; //Enable the timer
}
void Timer1A_Enable(uint32 timer_period){
  SYSCTL_RCGCTIMER_R|=0x02; //Enable clock to GPTM Module
  TIMER1_CTL_R=0x0; //Disable the timer
  TIMER1_CFG_R=0x00; //32-bit Mode
  TIMER1_TAMR_R=0x02; //BIT(0-1)   Periodic Mode
  TIMER1_TAILR_R=timer_period;
  TIMER1_ICR_R|=(1<<0);
  TIMER1_IMR_R|=(1<<0);
  NVIC_PRI5_R=(NVIC_PRI5_R & TIMER1A_PRIORITY_MASK) | (TIMER1A_INTERRUPT_PRIORITY<<TIMER1A_PRIORITY_BITS_POS); 
  NVIC_EN0_R|=(1<<21);
  TIMER1_CTL_R=0x03; //Enable the timer  Bit 0-TAEN
                     //                  Bit 1-TSTALL Enable
                     //                  Bit (2-3)-Interrupt on both edges
}
void timer1A_delay1000MS()
{
    //disbale the timer
    
    TIMER1_CTL_R=0x0; //Disable the timer
    //load the value which is equivalent to 1 sec
    
    TIMER1_TAILR_R=16000000-1;
    //clear interrupt that arised when the timer timed out
    TIMER1_ICR_R = 0x01;
    
    //enable the timer
    
   TIMER1_CTL_R=0x03;
   //wait for the timer to time out
    while((TIMER1_RIS_R & 0x01) == 0);
}
