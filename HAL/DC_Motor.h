/*
 * DC_Motor.h
 *
 * Created: 12/2/2020 1:25:23 PM
 *  Author: Ahmed Ashraf
 */ 


#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

#include "StdTypes.h"
#include "DIO_interface.h"
#include "Timers.h"

/*************** Choose your Motor PINS ********************/
/*Motor1*/
#define MOTOR1R  PINA0
#define MOTOR1L  PINA1
#define MOTOR1EN PINA3
/*Motor2*/
#define MOTOR2R  PINA2
#define MOTOR2L  PINA3
#define MOTOR2EN PINA7

/*MotorSpeed*/
#define MOTORR  PINC0
#define MOTORL  PINC1
#define MOTOREN PINB3

typedef enum
{
	MOTOR_1,
	MOTOR_2,
	MOTOR
}MOTOR_type;


void MOTOR_CCW(MOTOR_type motor);
void MOTOR_CW(MOTOR_type motor);
void MOTOR_Stop(MOTOR_type motor);
void MOTOR_SERVO(u8 angle);
void MOTOR_CCW_Speed(MOTOR_type motor,u8 Speed);
void MOTOR_CW_Speed(MOTOR_type motor,u8 Speed);

#endif /* DC_MOTOR_H_ */