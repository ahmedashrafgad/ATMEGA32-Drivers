/*
 * SPI.c
 *
 * Created: 12/29/2020 12:21:41 PM
 *  Author: Ahmed Ashraf
 */ 
#include "SPI.h"

void SPI_InitMaster(void)
{
	//master 
	
	
	//enable
	SET_BIT(SPCR,SPE);
}
void SPI_InitSlave(void)
{
	//slave 
	CLR_BIT(SPCR,MSTR)
	
	//enable
	SET_BIT(SPCR,SPE);
}

void SPI_Send(u8 data)
{
	SPDR=data;
	while(!GET_BIT(SPSR,SPIF));
	return SPDR;
}

void SPI_SendNoBlock(u8 data)
{
	SPDR= data;
}
u8 SPI_ReceiveNoBlock(void)
{
	return SPDR;
}
u8 SPI_ReceivePerodic(u8 *pdata)
{
	if(GET_BIT(SPSR,SPIF))
	{
		*pdata=
	}
}