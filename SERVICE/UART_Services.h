/*
 * UART_Services.h
 *
 * Created: 12/24/2020 1:09:56 PM
 *  Author: Ahmed Ashraf
 */ 


#ifndef UART_SERVICES_H_
#define UART_SERVICES_H_

#include "UART.h"

void UART_SendString(u8 *str);
void UART_ReceiveString(u8 *str);

#endif /* UART_SERVICES_H_ */