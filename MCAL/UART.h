/*
 * UART.h
 *
 * Created: 12/24/2020 11:25:26 AM
 *  Author: Ahmed Ashraf
 */ 


#ifndef UART_H_
#define UART_H_

#include "StdTypes.h"
#include "MemMap.h"
#include "utlis.h"

void UART_Init(void);
void UART_Send(u8 data);
u8 UART_Receive(void);
void UART_ReceivePerodic(u8 *Pdata);


#endif /* UART_H_ */