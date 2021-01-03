/*
 * UltraSonic.h
 *
 * Created: 12/21/2020 2:11:10 PM
 *  Author: Ahmed Ashraf
 */ 


#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#define F_CPU 8000000
#include "Timers.h"
#include "DIO_Interface.h"
#include "util/delay.h"

#define ULTRASONICF PINC3
#define ULTRASONICR PINC4
#define ULTRASONICL PINC5
#define ULTRASONICB PINA7


#define ULTRASONIC_PIN DIO_Pin_type

void ULTRASONIC_Init(void);
u16  ULTRASONIC_Read(ULTRASONIC_PIN ultrasonic);



#endif /* ULTRASONIC_H_ */ 