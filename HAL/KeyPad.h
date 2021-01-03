/*
 * KeyPad.h
 *
 * Created: 12/7/2020 9:58:41 AM
 *  Author: Ahmed Ashraf
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


#include "DIO_interface.h"
#include "StdTypes.h"

#define FIRST_INPUT  PIND2
#define FIRST_OUTPUT PINB4
#define NO_KEY       '.'

u8 KeyPad_GetKey(void);
u8 KeyPad_HexGetKey(void);



#endif /* KEYPAD_H_ */