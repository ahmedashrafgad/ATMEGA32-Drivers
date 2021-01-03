/*
 * WatchDog.h
 *
 * Created: 12/22/2020 2:28:59 PM
 *  Author: Ahmed Ashraf
 */ 


#ifndef WATCHDOG_H_
#define WATCHDOG_H_


#include "StdTypes.h"#include "MemMap.h"#include "utlis.h"typedef enum{	timeout_16ms=0,	timeout_32ms,	timeout_65ms,	timeout_130ms,	timeout_260ms,	timeout_520ms,	timeout_1000ms,	timeout_2100ms,}TimeOut_type;void WDT_Set(TimeOut_type time);void WDT_Stop(void);



#endif /* WATCHDOG_H_ */