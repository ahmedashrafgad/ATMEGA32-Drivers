/*
 * UART_Services.c
 *
 * Created: 12/24/2020 1:09:28 PM
 *  Author: Ahmed Ashraf
 */ 
#include "UART_Services.h"

void UART_SendString(u8 *str)
{
	  while(*str)
	  { //if there is a char
		  UART_Send(*str); //process it as a byte data
		  str++;
		  if(*str == '\n')
		  {
			  break;
		  }
	  }
}

void UART_ReceiveString(u8 *str)
{
	u8 i=0;
	str[i]=UART_Receive();
	while(str[i]!= 13)
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]=0;
}