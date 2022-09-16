#include "DIO.h"
#include "tm4c123gh6pm.h"
#include "bitwise_operations.h"
void DIO_Init(uint8 Port_Number,uint8 Pin_number,uint8 direction){
  switch (Port_Number)
  {
  case 0:
  SYSCTL_RCGCGPIO_R|=(0x00000001);
  while((SYSCTL_PRGPIO_R& 0x00000001==0)){};
  SET_BIT(GPIO_PORTA_CR_R,Pin_number);
  SET_BIT(GPIO_PORTA_PUR_R,Pin_number);
  SET_BIT(GPIO_PORTA_DEN_R,Pin_number);
  if(direction==OUTPUT){
  SET_BIT(GPIO_PORTA_DIR_R,Pin_number);
  }
  else {
    CLEAR_BIT(GPIO_PORTA_DIR_R,Pin_number);
  }
  break;
  case 1:
  SYSCTL_RCGCGPIO_R|=(0x00000002);
  while((SYSCTL_PRGPIO_R& 0x00000002==0)){};
  SET_BIT(GPIO_PORTB_CR_R,Pin_number);
  SET_BIT(GPIO_PORTB_PUR_R,Pin_number);
  SET_BIT(GPIO_PORTB_DEN_R,Pin_number);
  if(direction==OUTPUT){
  SET_BIT(GPIO_PORTB_DIR_R,Pin_number);
  }
  else {
    CLEAR_BIT(GPIO_PORTB_DIR_R,Pin_number);
  }
  break;
  case 2:
  SYSCTL_RCGCGPIO_R|=(0x00000004);
  while((SYSCTL_PRGPIO_R& 0x00000004==0)){};
  GPIO_PORTF_LOCK_R=0x4c4f434b;
  SET_BIT(GPIO_PORTC_CR_R,Pin_number);
  SET_BIT(GPIO_PORTC_PUR_R,Pin_number);
  SET_BIT(GPIO_PORTC_DEN_R,Pin_number);
  if(direction==OUTPUT){
  SET_BIT(GPIO_PORTC_DIR_R,Pin_number);
  }
  else {
    CLEAR_BIT(GPIO_PORTC_DIR_R,Pin_number);
  }
  break;
    case 3:
  SYSCTL_RCGCGPIO_R|=(0x00000008);
  while((SYSCTL_PRGPIO_R& 0x00000008==0)){};
  SET_BIT(GPIO_PORTD_CR_R,Pin_number);
  SET_BIT(GPIO_PORTD_PUR_R,Pin_number);
  SET_BIT(GPIO_PORTD_DEN_R,Pin_number);
  if(direction==OUTPUT){
  SET_BIT(GPIO_PORTD_DIR_R,Pin_number);
  }
  else {
    CLEAR_BIT(GPIO_PORTD_DIR_R,Pin_number);
  }
  break;
  case 4:
  SYSCTL_RCGCGPIO_R|=(0x00000010);
  while((SYSCTL_PRGPIO_R& 0x00000010==0)){};
    //GPIO_PORTF_LOCK_R=0x4c4f434b;

  SET_BIT(GPIO_PORTE_CR_R,Pin_number);
  SET_BIT(GPIO_PORTE_PUR_R,Pin_number);
  SET_BIT(GPIO_PORTE_DEN_R,Pin_number);
  if(direction==OUTPUT){
  SET_BIT(GPIO_PORTE_DIR_R,Pin_number);
  }
  else {
    CLEAR_BIT(GPIO_PORTE_DIR_R,Pin_number);
  }
  break;
  case 5:
  SYSCTL_RCGCGPIO_R|=(0x00000020);
  while((SYSCTL_PRGPIO_R& 0x00000020==0)){};
  GPIO_PORTF_LOCK_R=0x4c4f434b;
  SET_BIT(GPIO_PORTF_CR_R,Pin_number);
  SET_BIT(GPIO_PORTF_PUR_R,Pin_number);
  SET_BIT(GPIO_PORTF_DEN_R,Pin_number);
  if(direction==OUTPUT){
  SET_BIT(GPIO_PORTF_DIR_R,Pin_number);
  }
  else {
    CLEAR_BIT(GPIO_PORTF_DIR_R,Pin_number);
  }
  break;
  }
    }
void DIO_WritePin(uint8 Port_Number,uint8 Pin_Number,uint8 level){
   switch (Port_Number)
  {
  case 0:
    if(level==HIGH_PIN){
    SET_BIT(GPIO_PORTA_DATA_R,Pin_Number);
    }
    else if(level==LOW_PIN){
      CLEAR_BIT(GPIO_PORTA_DATA_R,Pin_Number);
    }
  break;
  case 1:
    if(level==HIGH_PIN){
    SET_BIT(GPIO_PORTB_DATA_R,Pin_Number);
    }
    else if(level==LOW_PIN){
      CLEAR_BIT(GPIO_PORTB_DATA_R,Pin_Number);
    }
    break;
  case 2:
    if(level==HIGH_PIN){
    SET_BIT(GPIO_PORTC_DATA_R,Pin_Number);
    }
    else if(level==LOW_PIN){
      CLEAR_BIT(GPIO_PORTC_DATA_R,Pin_Number);
    }
    break;
  case 3:
    if(level==HIGH_PIN){
    SET_BIT(GPIO_PORTD_DATA_R,Pin_Number);
    }
    else if(level==LOW_PIN){
      CLEAR_BIT(GPIO_PORTD_DATA_R,Pin_Number);
    }
    break;
  case 4:
    if(level==HIGH_PIN){
    SET_BIT(GPIO_PORTE_DATA_R,Pin_Number);
    }
    else if(level==LOW_PIN){
      CLEAR_BIT(GPIO_PORTE_DATA_R,Pin_Number);
    }
    break;
  case 5:
    if(level==HIGH_PIN){
    SET_BIT(GPIO_PORTF_DATA_R,Pin_Number);
    }
    else if(level==LOW_PIN){
      CLEAR_BIT(GPIO_PORTF_DATA_R,Pin_Number);
    }
  break;
    }
}

void DIO_WritePort(uint8 Port_Number,uint8 value){
   switch (Port_Number)
  {
  case 0:
    GPIO_PORTA_DATA_R=value;
  break;
  case 1:
    GPIO_PORTB_DATA_R=value;
    
  break;
  case 2:
   
    GPIO_PORTC_DATA_R=value;
    
  break;
  case 3:
    
    GPIO_PORTD_DATA_R=value;
    
  break;
  case 4:
  
    GPIO_PORTE_DATA_R=value;
    
  break;
  case 5:
 
    GPIO_PORTF_DATA_R=value;
    break;

}
}
uint8 DIO_ReadPin(uint8 Port_Number,uint8 Pin_number){
  uint8 value;
switch (Port_Number)
  {
  case 0:
    value=GET_BIT(GPIO_PORTA_DATA_R,Pin_number);
  break;
  case 1:
    value= GET_BIT(GPIO_PORTB_DATA_R,Pin_number);
  break;
  case 2:
    value= GET_BIT(GPIO_PORTC_DATA_R,Pin_number);
  break;
  case 3:
    value= GET_BIT(GPIO_PORTD_DATA_R,Pin_number);
  break;
  case 4:
   value=GET_BIT(GPIO_PORTE_DATA_R,Pin_number);
  break;
  case 5:
    value= GET_BIT(GPIO_PORTF_DATA_R,Pin_number);
  break;
  }
return value;
}
uint8 DIO_ReadPort(uint8 Port_Number){
  uint8 value;
switch (Port_Number)
  {
  case 0:
    value= GPIO_PORTA_DATA_R;
  break;
  case 1:
     value= GPIO_PORTB_DATA_R;
  break;
  case 2:
     value= GPIO_PORTC_DATA_R;
  break;
  case 3:
     value= GPIO_PORTD_DATA_R;
  break;
  case 4:
     value= GPIO_PORTE_DATA_R;
  break;
  case 5:
     value= GPIO_PORTF_DATA_R;
  break;
 } 
return value;
}
