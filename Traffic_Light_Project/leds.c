#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "leds.h"

void traffic1_init(void){
  DIO_Init(PORT_D_ID,PIN_1_ID,OUTPUT);
  DIO_Init(PORT_D_ID,PIN_2_ID,OUTPUT);
  DIO_Init(PORT_D_ID,PIN_3_ID,OUTPUT);
}
void traffic2_init(void){
  DIO_Init(PORT_E_ID,PIN_1_ID,OUTPUT);
  DIO_Init(PORT_E_ID,PIN_2_ID,OUTPUT);
  DIO_Init(PORT_E_ID,PIN_3_ID,OUTPUT);
}
void pedestrian_traffic1(void){
  DIO_Init(PORT_B_ID,PIN_0_ID,OUTPUT);
  DIO_Init(PORT_B_ID,PIN_1_ID,OUTPUT);
}
void pedestrian_traffic2(void){
  DIO_Init(PORT_A_ID,PIN_2_ID,OUTPUT);
  DIO_Init(PORT_A_ID,PIN_3_ID,OUTPUT);
}