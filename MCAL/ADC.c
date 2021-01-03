/*
 * ADC.c
 *
 * Created: 12/9/2020 10:22:36 AM
 *  Author: Ahmed Ashraf
 */ 

#include "ADC.h"

/* flag for dynamic design of reading ADC */
static u8 flagConversionEnd = 1;

void ADC_Init(ADC_VREF_type vref,ADC_SCALER_type scaler)
{
	//scaler 
	ADCSRA=ADCSRA&0xf8;  //to use bitwise this no. is 1111 1000 to make first 3 zeros so i can put the numbers by or the next step
	ADCSRA=ADCSRA|scaler;
	//ref
	switch(vref)
	{
		case VREF_AREF:
		CLR_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		case VREF_AVCC:
		SET_BIT(ADMUX,REFS0);
		CLR_BIT(ADMUX,REFS1);
		break;
		
		case VREF_256:
		SET_BIT(ADMUX,REFS0);
		SET_BIT(ADMUX,REFS1);
		break;				
	}
	//adc enable
	SET_BIT(ADCSRA,ADEN);
}
u16 ADC_Read(ADC_Channel_type ch)
{
	//select channel
	ADMUX &= 0xE0;
	ADMUX |= ch;
	//start conversion
	SET_BIT(ADCSRA,ADSC);
	while(GET_BIT(ADCSRA,ADSC));
	//read reg ADC=ADCL+ADCH
	return ADC;
}


/* dynamic designs. devide the above function into two parts
   It doesn't wait to ADC end. */
void ADC_StartConversion(ADC_Channel_type ch)
{
	if(flagConversionEnd)		// check if no conversion processing.
	{
		// select channel
		ADMUX &= 0xe0;		// first 5 bit = zero.
		ADMUX |= ch;
			
		// start conversion
		SET_BIT(ADCSRA, ADSC);				// ADC CLK is lower than MC CLK.you should wait.
		flagConversionEnd = 0;
	}

}
/* first dynamic design busy wait poling */
u16 ADC_GetRead(void)
{
	while(GET_BIT(ADCSRA, ADSC));		// (busy wait poling). wait until conversion ends. after end ADSC = 0.
		
	// read register high & low
	flagConversionEnd = 1;
	return ADC;
}

/* second dynamic design, check before return */
u8 ADC_ReadPerodicCheck(u16 * adcValue)
{
	if(GET_BIT(ADCSRA, ADSC) == 0)
	{
		flagConversionEnd = 1;
		*adcValue = ADC;
		return 1;
	}
	else 
		return 0;
}


/* another dynamic design
   Pre: must check before read  */
u8 ADC_ConversionEnd(void)
{
	if(GET_BIT(ADCSRA, ADSC) == 0)
		return 1;
	else
	return 0;
}
u16 ADC_GetReadNoWait(void)
{
	return ADC;
}

