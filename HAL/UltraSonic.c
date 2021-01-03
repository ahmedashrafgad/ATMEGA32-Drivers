/*
 * UltraSonic.c
 *
 * Created: 12/21/2020 2:11:26 PM
 *  Author: Ahmed Ashraf
 */ 

#include "UltraSonic.h"

static volatile u16 t1,t2;
static volatile u8 flag=0;

static void ICU_Func(void)
{
	if (flag==0)
	{
		t1=ICR1;
		flag=1;
		Timer1_InputCaptureEdge(FALLING);
	}
	else if(flag==1)
	{
		t2=ICR1;
		flag=2;
	}
}

void ULTRASONIC_Init(void)
{
	Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	Timer1_ICU_SetCallBack(ICU_Func);
}
u16  ULTRASONIC_Read(ULTRASONIC_PIN ultrasonic)
{
	u16 d,time;
	Timer1_ICU_InterruptEnable();
	flag=0;
	TCNT1=0;
	Timer1_InputCaptureEdge(RISING);
	DIO_WritePin(ultrasonic,HIGH);
	_delay_us(10);
	DIO_WritePin(ultrasonic,LOW);
	while(flag<2);
	time=t2-t1;
	d=time/58;
	return d;
}
