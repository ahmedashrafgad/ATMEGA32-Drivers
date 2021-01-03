/*
 * EEPROM.c
 *
 * Created: 12/23/2020 1:40:27 AM
 *  Author: Ahmed Ashraf
 */ 

#include "EEPROM.h"
void EEPROM_write(u32 uiAddress, u8 ucData)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address and data registers */
	EEAR = uiAddress;
	EEDR = ucData;
	/* Write logical one to EEMWE */
	SET_BIT(EECR,EEMWE);          
	/* Start eeprom write by setting EEWE */
	SET_BIT(EECR,EEWE);
}

u8 EEPROM_read(u32 uiAddress)
{
	/* Wait for completion of previous write */
	while(EECR & (1<<EEWE))
	;
	/* Set up address register */
	EEAR = uiAddress;
	/* Start eeprom read by writing EERE */
	SET_BIT(EECR,EERE);
	/* Return data from data register */
	return EEDR;
}