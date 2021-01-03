
#include "DIO_Interface.h"
extern const DIO_PinStatus_type PinsStatusArray[TOTAL_PINS];

void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	u8 pin_num=pin%8;
	DIO_Port_type port=pin/8;
	switch(status)
	{
		case INFREE:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		case INPLUP:
		switch(port)
		{
			case PA:
			CLR_BIT(DDRA,pin_num);
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			CLR_BIT(DDRB,pin_num);
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			CLR_BIT(DDRC,pin_num);
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			CLR_BIT(DDRD,pin_num);
			SET_BIT(PORTD,pin_num);
			break;
		}
		break;
		case OUTPUT:
		switch(port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			CLR_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			CLR_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			CLR_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			CLR_BIT(PORTD,pin_num);
			break;
		}
		break;
		
	}
}

void DIO_WritePin(DIO_Pin_type pin,DIO_Voltage_type volt)
{
	u8 pin_num=pin%8;
	DIO_Port_type port=pin/8;
	if (volt==HIGH)
	{
		switch(port)
		{
			case PA:
			SET_BIT(PORTA,pin_num);
			break;
			case PB:
			SET_BIT(PORTB,pin_num);
			break;
			case PC:
			SET_BIT(PORTC,pin_num);
			break;
			case PD:
			SET_BIT(PORTD,pin_num);
			break;
		}
	}
		else if (volt==LOW)
		{
				switch(port)
				{
					case PA:
					CLR_BIT(PORTA,pin_num);
					break;
					case PB:
					CLR_BIT(PORTB,pin_num);
					break;
					case PC:
					CLR_BIT(PORTC,pin_num);
					break;
					case PD:
					CLR_BIT(PORTD,pin_num);
					break;
			
		}
	}
}


DIO_Voltage_type DIO_ReadPin(DIO_Pin_type pin)
{
	u8 pin_num=pin%8;
	DIO_Port_type port=pin/8;
	DIO_Voltage_type volt=LOW;
	switch(port)
	{
		case PA:
		volt=GET_BIT(PINA,pin_num);
		break;
		case PB:
		volt=GET_BIT(PINB,pin_num);
		break;
		case PC:
		volt=GET_BIT(PINC,pin_num);
		break;
		case PD:
		volt=GET_BIT(PIND,pin_num);
		break;
	}
	return volt;
}

void DIO_Init(void)
{
	DIO_Pin_type i;
	for (i = PINA0; i <TOTAL_PINS ;i++)
	{
		DIO_InitPin (i,PinsStatusArray[i]);

	}
}

void DIO_WritePort(DIO_Port_type port,u8 data)
{
	switch(port)
	{
		case PA:
		  PORTA = data;
		break;
		case PB:
		 PORTB = data;
		break;
		case PC:
		 PORTC = data;
		break;
		case PD:
		 PORTD = data;
		break;
	}
}


void DIO_TogglePin(DIO_Pin_type pin)
{
	u8 pin_num=pin%8;
	DIO_Port_type port=pin/8;
	switch(port)
	{
		case PA:
		TOG_BIT(PORTA,pin_num);
		break;
		case PB:
		TOG_BIT(PORTB,pin_num);
		break;
		case PC:
		TOG_BIT(PORTC,pin_num);
		break;
		case PD:
		TOG_BIT(PORTD,pin_num);
		break;
	}
}

u8 DIO_ReadPort(DIO_Port_type port)
{ 
	u8 data;
	switch(port)
	{
		case PA:
		PORTA = data;
		break;
		case PB:
		PORTB = data;
		break;
		case PC:
		PORTC = data;
		break;
		case PD:
		PORTD = data;
		break;
	}
	return data;
}