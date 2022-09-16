
#ifndef DIO_H_
#define DIO_H_

#include "types.h"
#include "bitwise_operations.h"



#define HIGH_PIN 1
#define LOW_PIN 0

#define HIGH_PORT 0xFF
#define LOW_PORT 0x00

#define OUTPUT 1
#define INPUT  0

#define PORT_A_ID 0
#define PORT_B_ID 1
#define PORT_C_ID 2
#define PORT_D_ID 3
#define PORT_E_ID 4
#define PORT_F_ID 5

#define PIN_0_ID  0
#define PIN_1_ID  1
#define PIN_2_ID  2
#define PIN_3_ID  3
#define PIN_4_ID  4
#define PIN_5_ID  5
#define PIN_6_ID  6
#define PIN_7_ID  7

#define LOGIC_LOW 0
#define LOGIC_HIGH 1

void DIO_Init(uint8 Port_Number,uint8 Pin_number,uint8 direction);
void DIO_WritePin(uint8 Port_Number,uint8 Pin_Number,uint8 level);
void DIO_WritePort(uint8 Port_Number,uint8 level);
uint8 DIO_ReadPin(uint8 Port_Number,uint8 Pin_number);
uint8 DIO_ReadPort(uint8 Port_Number);
#endif
