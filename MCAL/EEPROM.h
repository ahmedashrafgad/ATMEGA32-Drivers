/*
 * EEPROM.h
 *
 * Created: 12/23/2020 1:40:16 AM
 *  Author: Ahmed Ashraf
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "StdTypes.h"
#include "utlis.h"
#include "MemMap.h"

void EEPROM_write(u32 uiAddress, u8 ucData);
u8 EEPROM_read(u32 uiAddress);

#endif /* EEPROM_H_ */