
#include "DIO.h"
#include "handlers.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"
#include "GPTM.h"
volatile uint8 flag_traffic1=0;
volatile uint8 flag_traffic2=0;
volatile uint8 flag_pedestrian1=0;
volatile uint8 flag_pedestrian2=0;
void traffic_normal_mode(void){
if(flag_traffic1==1){
   GPIO_PORTD_DATA_R=0x02; //traffic 1 red
   GPIO_PORTB_DATA_R=0x02; //pedestrian1 green
   GPIO_PORTE_DATA_R=0x00; //traffic2 wait
   GPIO_PORTA_DATA_R=0x04; //pedstrian 2 green
   }
   else if(flag_traffic1==2){
   GPIO_PORTE_DATA_R=0x08; //traffic2 green
   GPIO_PORTD_DATA_R=0x02; //traffic1 red
   GPIO_PORTA_DATA_R=0x04; //pedstrian2 red
   GPIO_PORTB_DATA_R=0x02; //pedestrian1 green
   }
   else if(flag_traffic1==7){
   GPIO_PORTD_DATA_R=0x04; 
   GPIO_PORTE_DATA_R=0x00;
   }
   else if(flag_traffic1==8){
   GPIO_PORTE_DATA_R=0x02; //traffic 2 red
   GPIO_PORTA_DATA_R=0x08; //pedstrian 2 green
   GPIO_PORTD_DATA_R=0x04; //traffic 1 yellow
   GPIO_PORTB_DATA_R=0x01; //pedestrian1 red
   }
   else if(flag_traffic1==9){
   GPIO_PORTD_DATA_R=0x08;
   GPIO_PORTB_DATA_R=0x01;
   }
   else if(flag_traffic1==14){
   GPIO_PORTE_DATA_R=0x04;
   GPIO_PORTD_DATA_R=0x00;
   }
   else if(flag_traffic1==15){
   GPIO_PORTD_DATA_R=0x02;
   GPIO_PORTB_DATA_R=0x02;
   GPIO_PORTE_DATA_R=0x08; //traffic2 green
   GPIO_PORTA_DATA_R=0x04; //pedstrian 2 red
   flag_traffic1=1;
   }
   }
void pedestrian_mode(void){
  if(flag_pedestrian1==1){
    uint32 ledState1 = DIO_ReadPin(PORT_D_ID,PIN_1_ID) ;
    uint32 ledState2 = DIO_ReadPin(PORT_D_ID,PIN_2_ID) ;
    uint32 ledState3 = DIO_ReadPin(PORT_D_ID,PIN_3_ID) ;
    uint32 ledState4 = DIO_ReadPin(PORT_E_ID,PIN_1_ID) ; 
    uint32 ledState5 = DIO_ReadPin(PORT_E_ID,PIN_2_ID) ; 
    uint32 ledState6 = DIO_ReadPin(PORT_E_ID,PIN_3_ID) ; 
    
    GPIO_PORTB_DATA_R=0x02;//pedestrian1 green
    GPIO_PORTD_DATA_R=0x02;//traffic1 red
    GPIO_PORTA_DATA_R=0x04;//pedestrian2 red
    GPIO_PORTE_DATA_R=0x08;//traffic2 green
    timer1A_delay1000MS();
    timer1A_delay1000MS();
    
    DIO_WritePin(PORT_D_ID,PIN_1_ID,ledState1);
    DIO_WritePin(PORT_D_ID,PIN_2_ID,ledState2);
    DIO_WritePin(PORT_D_ID,PIN_3_ID,ledState3);
    DIO_WritePin(PORT_E_ID,PIN_1_ID,ledState4);
    DIO_WritePin(PORT_E_ID,PIN_2_ID,ledState5);
    DIO_WritePin(PORT_E_ID,PIN_3_ID,ledState6);
     
    DIO_WritePort(PORT_B_ID,0x01);//pedestrian1
    DIO_WritePort(PORT_A_ID,0x08);//green pedestrian2
    
    flag_pedestrian1=0;
    
   }
  else if(flag_pedestrian2==1){
    uint32 ledState1 = DIO_ReadPin(PORT_D_ID,PIN_1_ID) ;
    uint32 ledState2 = DIO_ReadPin(PORT_D_ID,PIN_2_ID) ;
    uint32 ledState3 = DIO_ReadPin(PORT_D_ID,PIN_3_ID) ;
    uint32 ledState4 = DIO_ReadPin(PORT_E_ID,PIN_1_ID) ; 
    uint32 ledState5 = DIO_ReadPin(PORT_E_ID,PIN_2_ID) ; 
    uint32 ledState6 = DIO_ReadPin(PORT_E_ID,PIN_3_ID) ; 
    
    GPIO_PORTB_DATA_R=0x01;//pedestrian1 red
    GPIO_PORTD_DATA_R=0x08;//traffic1 green
    GPIO_PORTA_DATA_R=0x08;//pedestrian2 green
    GPIO_PORTE_DATA_R=0x02;//traffic2 red
    
    timer1A_delay1000MS();
    timer1A_delay1000MS();
    DIO_WritePin(PORT_D_ID,PIN_1_ID,ledState1);
    DIO_WritePin(PORT_D_ID,PIN_2_ID,ledState2);
    DIO_WritePin(PORT_D_ID,PIN_3_ID,ledState3);
    DIO_WritePin(PORT_E_ID,PIN_1_ID,ledState4);
    DIO_WritePin(PORT_E_ID,PIN_2_ID,ledState5);
    DIO_WritePin(PORT_E_ID,PIN_3_ID,ledState6);
    DIO_WritePort(PORT_B_ID,0x02);//pedestrian1
    DIO_WritePort(PORT_A_ID,0x04);//red pedestrian2
    flag_pedestrian2=0;
    //flag_traffic1=1;
  }
}
void Timer0A_Handler(){
   flag_traffic1++;
   traffic_normal_mode();
   TIMER0_ICR_R|= 0x01;
   }
/* GPIO PORTF External Interrupt - ISR */
void GPIOPortF_Handler(void)
{
  
   if(!DIO_ReadPin(PORT_F_ID,4)){
    flag_pedestrian1++;
    pedestrian_mode();
    GPIO_PORTF_ICR_R   |= (1<<4);       /* Clear Trigger flag for PF4 (Interupt Flag) */
   }
   else if(!DIO_ReadPin(PORT_F_ID,0)){
     flag_pedestrian2++;
     pedestrian_mode();
    GPIO_PORTF_ICR_R   |= (1<<0);       /* Clear Trigger flag for PF4 (Interupt Flag) */
 
  }
}
void Timer1A_Handler(){
  flag_traffic2++;
   TIMER1_ICR_R = 0x01;
   }

