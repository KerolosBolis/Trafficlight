#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "switches.h"
#include "GPTM.h"
#include "leds.h"
#include "handlers.h"
/* Enable Exceptions ... This Macro enable IRQ interrupts, Programmble Systems Exceptions and Faults by clearing the I-bit in the PRIMASK. */
#define Enable_Exceptions()    __asm("CPSIE I")

/* Go to low power mode while waiting for the next interrupt */
#define Wait_For_Interrupt()   __asm("WFI")



int main()
{
  Enable_Exceptions();
  traffic1_init();
  traffic2_init();
  pedestrian_traffic1();
  pedestrian_traffic2();
  SW1_Init();
  SW2_Init();
  GPIO_PORTD_DATA_R=0x00;
  GPIO_PORTE_DATA_R=0x00;
  GPIO_PORTB_DATA_R=0x00;
  GPIO_PORTA_DATA_R=0x00;
 Timer0A_Enable(15999999);
 Timer1A_Enable(15999999);
  while(1){
    Wait_For_Interrupt();
     }
    }  

