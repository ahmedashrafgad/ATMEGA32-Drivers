/*
 * ADC.h
 *
 * Created: 12/9/2020 10:22:24 AM
 *  Author: Ahmed Ashraf
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "StdTypes.h"
#include "utlis.h"
#include "MemMap.h"



typedef enum
{
	VREF_AREF,
	VREF_AVCC,
	VREF_256
	}ADC_VREF_type;
	
typedef enum
{
	ADC_SCALER2=1,
	ADC_SCALER4,
	ADC_SCALER8,
	ADC_SCALER16,
	ADC_SCALER32,
	ADC_SCALER64,
	ADC_SCALER128,
}ADC_SCALER_type;
	
typedef enum
{
	CH_0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7,
	}ADC_Channel_type;
void ADC_Init(ADC_VREF_type vref,ADC_SCALER_type scaler);

/* busy wait poling */
u16 ADC_Read(ADC_Channel_type ch);

/* dynamic designs */
void ADC_StartConversion(ADC_Channel_type ch);
/* busy wait poling but you can do something after start conversion */
u16 ADC_GetRead(void);
/* another dynamic design */
u8 ADC_ReadPerodicCheck(u16 * adcValue);

/* another dynamic desigh */
u8 ADC_ConversionEnd(void);
u16 ADC_GetReadNoWait(void);





#endif /* ADC_H_ */