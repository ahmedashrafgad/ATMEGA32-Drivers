/*
 * LCD.h
 *
 * Created: 12/3/2020 10:13:13 AM
 *  Author: Ahmed Ashraf
 */ 


#ifndef LCD_H_
#define LCD_H_


#define F_CPU 8000000
#include <util/delay.h>
#include "utlis.h"
#include "StdTypes.h"
#include "DIO_Interface.h"
#include "util/delay.h"

#define LCD_PORT PA
#define RS       PINA1
#define EN       PINA2
#define _4_BIT 0
#define _8_bit 1

/*********************************8_BIT******************************/
#define LCD_PORT PA
/*********************************4_BIT******************************/
#define D4 PINA3
#define D5 PINA4
#define D6 PINA5
#define D7 PINA6

/*
void LCD_Init(void);
void LCD_WriteChar(u8 ch);
void LCD_WriteString(u8 *str);
void LCD_WriteNumber(s64 num);
void LCD_WriteBinary(u32 num);
void LCD_WriteHex(u32 num);
void LCD_WriteNumber4D(u16 num);
void LCD_WriteNumber2D(u16 num);
void LCD_SetCursor(u8 Line , u8 cell);
void LCD_Clear(void);
void LCD_WriteCommand(u8 command);
*/


void LCD_Init(void);
void LCD_Init_8Bit(void);
void LCD_WriteData(u8 data);
void LCD_WriteCommand(u8 command);
void LCD_WriteChar(u8 ch);
void LCD_WriteNumber(s64 num);
void LCD_WriteNumber4D(u16 num);
void LCD_WriteNumber3D(u16 num);
void LCD_WriteNumber2D(u16 num);
void LCD_WriteBinary16D(u32 num);
void LCD_WriteBinary8D(u32 num);
void LCD_WriteBinary(u16 num);
void LCD_WriteHex(u8 num);
void LCD_SetCursor(u8 line,u8 coloumn);
void LCD_Clear(void);
void LCD_AsciCount(void);
void LCD_StringAnimation(u8*str);
void LCD_WriteString(u8*str);
void LCD_Create_Character(u8* pattern,u8 location);
u8 Is_Change(u32 num);


#endif /* LCD_H_ */