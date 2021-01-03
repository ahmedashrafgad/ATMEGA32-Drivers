/*
 * Stepper.h
 *
 * Created: 12/8/2020 10:59:48 AM
 *  Author: Ahmed Ashraf
 */ 



#ifndef STEPPER_H_
#define STEPPER_H_

#include "DIO_interface.h"

#define COIL1_A PINC0
#define COIL1_B PINC1
#define COIL2_A PINC2
#define COIL2_B PINC3

#define DELAY1 50
#define DELAY 500
void STEPPER_BiPoler_CW(void);
void STEPPER_BiPoler_CCW(void);
void STEPPER_UnPoler_CW(void);
void STEPPER_UnPoler_CCW(void);
void STEPPER_RotatByAngel_UnPoler_CW(u16 degre);
void STEPPER_RotatByCycel_UnPoler_CW(u16 cycel);
#endif // STEPPER_H_ // STEPPER_H_ 

