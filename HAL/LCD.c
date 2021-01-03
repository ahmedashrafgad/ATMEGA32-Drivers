/*
 * LCD.c
 *
 * Created: 12/3/2020 10:12:58 AM
 *  Author: Ahmed Ashraf
 */ 
#include "LCD.h"


int strlength(u8* str)
{
	int i;
	for( i =0 ; str[i] ; i++);
	
	return i;
}
void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePin(D7,GET_BIT(data,7));
	DIO_WritePin(D6,GET_BIT(data,6));
	DIO_WritePin(D5,GET_BIT(data,5));
	DIO_WritePin(D4,GET_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,GET_BIT(data,3));
	DIO_WritePin(D6,GET_BIT(data,2));
	DIO_WritePin(D5,GET_BIT(data,1));
	DIO_WritePin(D4,GET_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_WriteCommand(u8 data)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePin(D7,GET_BIT(data,7));
	DIO_WritePin(D6,GET_BIT(data,6));
	DIO_WritePin(D5,GET_BIT(data,5));
	DIO_WritePin(D4,GET_BIT(data,4));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	DIO_WritePin(D7,GET_BIT(data,3));
	DIO_WritePin(D6,GET_BIT(data,2));
	DIO_WritePin(D5,GET_BIT(data,1));
	DIO_WritePin(D4,GET_BIT(data,0));
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x02);
	_delay_ms(1);
	LCD_WriteCommand(0x28);//this command to make 4bit mode and for 5*7 - 2 lines
	_delay_ms(1);
	LCD_WriteCommand(0x0c);// you can choose 0x0f,0x0c,0x0c display and cursor
	_delay_ms(1);
	LCD_WriteCommand(0x01);//clear screen
	_delay_ms(2);
	LCD_WriteCommand(0x06);//increase DDRam address, no shift
	_delay_ms(1);
	
	
}
void LCD_Init_8Bit(void)
{
	_delay_ms(50);
	LCD_WriteCommand(0x38);//this command to make 8bit mode and for 5*7 - 2 lines
	_delay_ms(1);
	LCD_WriteCommand(0x0c);// you can choose 0x0f,0x0c,0x0c display and cursor
	_delay_ms(1);
	LCD_WriteCommand(0x01);//clear screen
	_delay_ms(2);
	LCD_WriteCommand(0x06);//increase DDRam address, no shift
	_delay_ms(1);
}
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
void LCD_WriteNumber(s64 num)
{
	s64 number[16];
	u8 i = 0;
	s8 j;
	if(num == 0)
	{
		LCD_WriteData('0');
	}
	
	
	else if(num > 0)
	{
		while(!(num == 0))
		{
			number[i] = num%10 + '0';
			num /=10;
			i++;
		}
		for(j=i-1 ; j>=0; j--)
		{
			LCD_WriteData(number[j]);
		}
	}
	
	
	else if(num < 0)
	{
		LCD_WriteData('-');
		num = num*(-1);
		while(!(num == 0))
		{
			number[i] = num%10 + '0';
			num /=10;
			i++;
		}
		for(j=i-1 ; j>=0; j--)
		{
			LCD_WriteData(number[j]);
		}
	}
}
void LCD_WriteNumber4D(u16 num)
{
	u16 num4 = num%10 + '0';
	num /=10;
	u16 num3 = num%10 + '0';
	num /=10;
	u16 num2 = num%10 + '0';
	num /=10;
	u16 num1 = num%10 + '0';
	LCD_WriteChar(num1);
	LCD_WriteChar(num2);
	LCD_WriteChar(num3);
	LCD_WriteChar(num4);
}
void LCD_WriteNumber3D(u16 num)
{
	u16 num3 = num%10 + '0';
	num /=10;
	u16 num2 = num%10 + '0';
	num /=10;
	u16 num1 = num%10 + '0';
	LCD_WriteChar(num1);
	LCD_WriteChar(num2);
	LCD_WriteChar(num3);
}
void LCD_WriteNumber2D(u16 num)
{
	LCD_WriteData((num%100)/10+'0');
	LCD_WriteData((num%1)/1+'0');
}
void LCD_WriteBinary(u16 num)
{
	u8 i;
	for(i=0 ; i<16 ; i++)
	{
		if((((num>>(15-i))&1) == 1))
		{
			LCD_WriteChar('1');
		}
		else
		{
			LCD_WriteChar('0');
		}
	}
}
void LCD_WriteBinary16D(u32 num)
{

	s8 c, k;
	for (c = 15; c >= 0; c--)
	{
		
		k = num >> c;
		if (k & 1)
		LCD_WriteChar('1');
		
		else
		LCD_WriteChar('0');
	}

}
  
void LCD_WriteBinary8D(u32 num)
{

	s8 c, k;
	for (c = 7; c >= 0; c--)
	{
		k = num >> c;
		if (k & 1)
		LCD_WriteChar('1');
		else
		LCD_WriteChar('0');
	}

}
void LCD_WriteHex(u8 num)
{
	u8 Hex[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	u8 High =num>>4;
	u8 Low = num&0x0f;
	LCD_WriteData(Hex[High]);
	LCD_WriteData(Hex[Low]);
	}
void LCD_SetCursor(u8 line,u8 coloumn)
{
	if(line == 0)
	{
		LCD_WriteCommand(0x80 + coloumn);
	}
	else if(line == 1)
	{
		LCD_WriteCommand(0x80 + 0x40 + coloumn);
	}
}
void LCD_Clear(void)
{
	LCD_WriteCommand(0x01);
}
void LCD_WriteString(u8*str)
{
	u8 i=0;
	while(str[i]!=0)
	{
		LCD_WriteChar(str[i]);
		i++;
	}
	
}
void LCD_StringAnimation(u8*str)
{
	for(u8 i =0 ; i<16 ; i++)
	{
		LCD_Clr();
		LCD_SetCursor(0,i);
		if(i<strlength(str))
		{
			LCD_WriteString(str+(strlength(str)-i));
		}
		else if(i>strlength(str))
		{
			LCD_WriteString(str);
		}
		_delay_ms(100);
	}
	for(u8 j =0 ; j<16 ; j++)
	{
		LCD_Clr();
		LCD_SetCursor(1,j-strlength(str));
		LCD_WriteString(str);
		_delay_ms(100);
	}
	
}
void LCD_AsciCount(void)
{
	for(u8 i = 100 ; i>0 ; i--)
	{
		LCD_SetCursor(0,0);
		LCD_WriteString("Char: ");
		LCD_WriteChar(i);
		LCD_SetCursor(1,8);
		LCD_WriteChar(' ');
		LCD_SetCursor(1,0);
		LCD_WriteString("Asci: ");
		LCD_WriteNumber(i);
		_delay_ms(100);
	}
}
void LCD_Create_Character(u8* pattern,u8 location)
{
	u8 i =0;
	LCD_WriteCommand(0x40+(location*8));
	for(i = 0 ; i<8 ; i++)
	{
		LCD_WriteData(pattern[i]);
		LCD_WriteCommand(0x80);
	}
}
u8 Is_Change(u32 num)
{
	static u32 old_data=0;
	if (num !=old_data)
	{
		old_data=num;
		return 1;
	}
	return 0;
}