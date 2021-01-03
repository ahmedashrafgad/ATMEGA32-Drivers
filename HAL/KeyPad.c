/*
 * KeyPad.c
 *
 * Created: 12/7/2020 9:58:26 AM
 *  Author: Ahmed Ashraf
 */ 
#include "KeyPad.h"

static const Keys[4][4]={ {'7','8','9','/'},
					   	  {'4','5','6','*'},
						  {'1','2','3','-'},
						  {'c','0','=','+'}};
							  
							  
static const HexKeys[4][4]={ {'7','8','9','F'},
					   	     {'4','5','6','E'},
						     {'1','2','3','B'},
						     {'c','0','=','A'}};
					
u8 KeyPad_GetKey(void)
{
	u8 row,col,key=NO_KEY;
	DIO_WritePin(FIRST_OUTPUT  ,HIGH);
	DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	DIO_WritePin(FIRST_OUTPUT+3,HIGH);
	
	for (row = 0 ; row <4 ; row++)
	{
		DIO_WritePin(FIRST_OUTPUT+row,LOW);
		for (col = 0 ; col < 4 ; col ++)
		{
			if(!DIO_ReadPin(FIRST_INPUT+col))	
			{
			key = Keys[row][col];
			while(!DIO_ReadPin(FIRST_INPUT+col));
			//_delay_ms(300);
			}
		}
		DIO_WritePin(FIRST_OUTPUT+row,HIGH);
	}
	return key;
}
		
					
u8 KeyPad_HexGetKey(void)
{
	u8 row,col,HexKey=NO_KEY;
	DIO_WritePin(FIRST_OUTPUT  ,HIGH);
	DIO_WritePin(FIRST_OUTPUT+1,HIGH);
	DIO_WritePin(FIRST_OUTPUT+2,HIGH);
	DIO_WritePin(FIRST_OUTPUT+3,HIGH);
	
	for (row = 0 ; row <4 ; row++)
	{
		DIO_WritePin(FIRST_OUTPUT+row,LOW);
		for (col = 0 ; col < 4 ; col ++)
		{
			if(!DIO_ReadPin(FIRST_INPUT+col))	
			{
			HexKey = HexKeys[row][col];
			while(!DIO_ReadPin(FIRST_INPUT+col));
			//_delay_ms(300);
			}
		}
		DIO_WritePin(FIRST_OUTPUT+row,HIGH);
	}
	return HexKey;
}

					