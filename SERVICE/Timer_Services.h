/*
 * Timer_Services.h
 *
 * Created: 12/20/2020 10:50:36 PM
 *  Author: Ahmed Ashraf
 */ 


#ifndef TIMERS_SERVICES_H_
#define TIMERS_SERVICES_H_


#include "Timers.h"

void PWM_Init(void);
void PWM_Freq_KHZ(u16 freq);
void PWM_Freq_HZ(u16 freq);
void PWM_Duty(u16 duty);

/*functions to get interrupt after spacific time in miliSec , microSec or Sec*/
void Timer1_SetInterruptTime_ms (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_us (u16 time,void(*LocalFptr)(void));
void Timer1_SetInterruptTime_s(u16 time , void(*LocalFptr)(void));

void PWM_Measure(u32* Pfreq,u8* Pduty);
void PWM_Measure2(u32* Pfreq,u8* Pduty);
static void Func_ICU(void);
#endif /* TIMERS_SERVICES_H_ *//* TIMER_SERVICES_H_ */