#include "SYSTICK.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"

void SysTickEnable (void){
  NVIC_ST_CTRL_R=0x0000000;
  NVIC_ST_CURRENT_R=0;
  NVIC_ST_CTRL_R|=0x05;
}
void SysTickDisable (void){
    NVIC_ST_CTRL_R=0x00;
}
void SysTickPeriodSet (uint32 ui32Period){
     volatile uint32 tick=0; 
     tick=(ui32Period*16000)-1;
     NVIC_ST_RELOAD_R=tick;
}
uint8 SysTick_Is_Time_out(void){
  uint8 value=0;
  if(GET_BIT(NVIC_ST_CTRL_R,16)==0){
    
    value=0;
  }
  else {
    NVIC_ST_CURRENT_R=0x00;
    value=1;
  }

return value;
     }