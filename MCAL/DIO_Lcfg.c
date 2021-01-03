/*
 * DIO_Lcfg.c
 *
 * Created: 12/1/2020 11:32:28 AM
 *  Author: Ahmed Ashraf
 */ 

#include "DIO_Interface.h"
	
const DIO_PinStatus_type  PinsStatusArray[TOTAL_PINS]={
	/* choices (OUTPUT - INPLUP - INFREE)*/
	INFREE,      /* Port A Pin 0 ADC0*/ 
	OUTPUT,      /* Port A Pin 1 ADC1*/
	OUTPUT,      /* Port A Pin 2 */
	OUTPUT,      /* Port A Pin 3 */
	OUTPUT,      /* Port A Pin 4 */
	OUTPUT,      /* Port A Pin 5 */
	OUTPUT,      /* Port A Pin 6 */
	OUTPUT,      /* Port A Pin 7 */
	OUTPUT,      /* Port B Pin 0   / */
	OUTPUT,      /* Port B Pin 1   /*/
	OUTPUT,		 /* Port B Pin 2 / INT2*/
	OUTPUT,		 /* Port B Pin 3   /OC0*/
	OUTPUT,		 /* Port B Pin 4 */
	OUTPUT,		 /* Port B Pin 5 */
	OUTPUT,		 /* Port B Pin 6 */
	OUTPUT,		 /* Port B Pin 7 */
	OUTPUT,		 /* Port C Pin 0 */
	OUTPUT,		 /* Port C Pin 1 */
	OUTPUT,		 /* Port C Pin 2 */
	OUTPUT,		 /* Port C Pin 3 */
	OUTPUT,		 /* Port C Pin 4 */
	OUTPUT,		 /* Port C Pin 5 */
	OUTPUT,		 /* Port C Pin 6 */
	OUTPUT,		 /* Port C Pin 7 */
	OUTPUT,		 /* Port D Pin 0 */
    INPLUP,      /* Port D Pin 2 /INT0*/
	INPLUP,      /* Port D Pin 3 / INT1 */
	INPLUP,		 /* Port D Pin 4 */
	INPLUP,		 /* Port D Pin 5 */
	INFREE,		 /* Port D Pin 6 /   ICP*/
	OUTPUT		 /* Port D Pin 7 */
	
};