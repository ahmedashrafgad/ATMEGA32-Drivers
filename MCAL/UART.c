/*
 * UART.c
 *
 * Created: 12/24/2020 11:25:09 AM
 *  Author: Ahmed Ashraf
 */ 

#include "UART.h"

void UART_Init(void)
{
	//baud rate 9600 for 8MHZ
	UBRRL = 51;
	//Normal speed
	CLR_BIT(UCSRA,U2X);
	//
	
	//enable TX and RX
	SET_BIT(UCSRA,TXEN);
	SET_BIT(UCSRA,RXEN);
}

void UART_Send(u8 data)
{
	while(!GET_BIT(UCSRA,UDRE));
	UDR=data;
}
u8 UART_Receive(void)
{
	while(!GET_BIT(UCSRA,RXC));
	return UDR;
}

void UART_ReceivePerodic(u8 *Pdata)
{
	if (GET_BIT(UCSRA,RXC))
	{
		*Pdata=UDR;
		return 1;
	}
	return 0;
}