/*
 * segment.h
 *
 * Created: 12/1/2020 2:39:21 PM
 *  Author: Ahmed Ashraf
 */ 

#include "utlis.h"
#ifndef SEGMENT_H_
#define SEGMENT_H_
#include "DIO_interface.h"

#define NORMAL 1
#define MULTiP 2
/**********************************config segment port***************************/

#define  MODE NORMAL

/********************************* For Normal ***********************************/
#define SEG1_PORT           PC
#define SEG2_PORT           PD
/*                       Choices ( PA - PB -PC - PD)                            */
/********************************* For MUL **************************************/
#define SEG1_EN PINA0
#define SEG2_EN PIND3
#define SEG_PORT PA

void SEG_DISPLAY_D(u8 num);
void SEG_DISPLAY_H(u8 num);





#endif /* SEGMENT_H_ */