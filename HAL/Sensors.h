/*
 * Sensors.h
 *
 * Created: 12/10/2020 9:43:00 AM
 *  Author: Ahmed Ashraf
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_

#include "StdTypes.h"
#include "ADC.h"

#define POT_CH  CH_0
#define LM35_CH CH_6
#define MPX_CH	CH_0

u16 POT_VoltRead(void);
u16 LM35_TempRead(void);
u16 POT_VoltReadPercentage(void);



#endif /* SENSORS_H_ */