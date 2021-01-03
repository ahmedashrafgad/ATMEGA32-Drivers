/*
 * Sensors.c
 *
 * Created: 12/10/2020 9:42:46 AM
 *  Author: Ahmed Ashraf
 */ 
#include "Sensors.h"

u16 POT_VoltRead(void)
{
	u16 adc=ADC_Read(POT_CH);
	u64 volt = (adc*5000)/1024;
	return volt;
}

u16 LM35_TempRead()
{
	u16 adc=ADC_Read(POT_CH);
	u16 volt = (adc*5000)/1024;
	u16 temp = volt/10;
	return temp;
}
u16 POT_VoltReadPercentage(void)
{
		u16 adc=ADC_Read(POT_CH);
		u16 Percent = (adc*100)/1024;
		
	return Percent;
}
//u16 PTX_Pressure
u16 MPX_GetPressure(void)
{
	 u16 pressureValue = ADC_Read(CH_0);	 
	 float pressure=((pressureValue/1024.0)+0.095)/0.000009;
	 return pressure;
}