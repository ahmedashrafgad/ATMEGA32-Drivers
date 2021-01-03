#include "segment.h"
#define F_CPU 8000000UL
#include <util/delay.h>
char segment_arr[16]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7C,0x39,0x5E,0x79,0x71};

#if (MODE==NORMAL)
void SEG_DISPLAY_D(u8 num)
{
DIO_WritePort(SEG1_PORT,segment_arr[num%10]);
DIO_WritePort(SEG2_PORT,segment_arr[num/10]);
}
void SEG_DISPLAY_H(u8 num)
{
DIO_WritePort(SEG1_PORT,segment_arr[num%16]);
DIO_WritePort(SEG2_PORT,segment_arr[num/16]);
}
#elif (MODE==MULPLX)

void SEG_DISPLAY_D(u8 num)
{
DIO_WritePin(SEG2_EN,HIGH);
DIO_WritePort(SEG_PORT,segment_arr[num%10]);
DIO_WritePin(SEG1_EN,LOW);
_delay_ms(1);
DIO_WritePin(SEG1_EN,HIGH);
DIO_WritePort(SEG_PORT,segment_arr[num/10]);
DIO_WritePin(SEG2_EN,LOW);
_delay_ms(1);
}
void SEG_DISPLAY_H(u8 num)
{
DIO_WritePin(SEG2_EN,HIGH);
DIO_WritePort(SEG_PORT,segment_arr[num%16]);
DIO_WritePin(SEG1_EN,LOW);
_delay_ms(1);
DIO_WritePin(SEG1_EN,HIGH);
DIO_WritePort(SEG_PORT,segment_arr[num/16]);
DIO_WritePin(SEG2_EN,LOW);
_delay_ms(1);
}
#endif