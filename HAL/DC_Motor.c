/*
 * DC_Motor.c
 *
 * Created: 12/2/2020 1:25:05 PM
 *  Author: Ahmed Ashraf
 */ 

#include "DC_Motor.h"

void MOTOR_CCW(MOTOR_type motor)
{
	if(motor == MOTOR_1)
	{
		DIO_WritePin(MOTOR1R,HIGH);
		DIO_WritePin(MOTOR1EN,HIGH);
		DIO_WritePin(MOTOR1L,LOW);
	}
	if(motor == MOTOR_2)
	{
		DIO_WritePin(MOTOR2R,HIGH);
		DIO_WritePin(MOTOR2EN,HIGH);
		DIO_WritePin(MOTOR2L,LOW);
	}
}
void MOTOR_CW(MOTOR_type motor)
{
	if(motor == MOTOR_1)
	{
		DIO_WritePin(MOTOR1R,LOW);
		DIO_WritePin(MOTOR1EN,HIGH);
		DIO_WritePin(MOTOR1L,HIGH);
	}
	if(motor == MOTOR_2)
	{
		DIO_WritePin(MOTOR2R,LOW);
		DIO_WritePin(MOTOR2EN,HIGH);
		DIO_WritePin(MOTOR2L,HIGH);
	}
}

void MOTOR_Stop(MOTOR_type motor)
{
	if(motor == MOTOR_1)
		{
		DIO_WritePin(MOTOR1R,LOW);
		DIO_WritePin(MOTOR1L,LOW);
		DIO_WritePin(MOTOR1EN,LOW);
		}
	if(motor == MOTOR_2)
	{
		DIO_WritePin(MOTOR2L,LOW);
		DIO_WritePin(MOTOR2EN,LOW);
		DIO_WritePin(MOTOR2R,LOW);
	}
}

void MOTOR_SERVO(u8 angle)
{
	OCR1A = (((u32)angle*1000)/180)+999;
}





void MOTOR_CCW_Speed(MOTOR_type MOTOR,u8 Speed)
{	
		OCR0 = Speed;
		DIO_WritePin(MOTORR,HIGH);
		DIO_WritePin(MOTORL,LOW);
}
void MOTOR_CW_Speed(MOTOR_type MOTOR,u8 Speed)
{	
		OCR0 = Speed;
		DIO_WritePin(MOTORR,LOW);
		DIO_WritePin(MOTORL,HIGH);
}