/*
 * DIO.c
 *
 * Created: 5/13/2022 3:24:37 AM
 *  Author: Smart
 */ 
#include "DIO_Interface.h"
#include "DIO_Private.h"
static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	
	switch (status)
	{
		case OUTPUT:
		switch (port)
		{
			case PA:
			SET_BIT(DDRA,pin_num);
			break;
			case PB:
			SET_BIT(DDRB,pin_num);
			break;
			case PC:
			SET_BIT(DDRC,pin_num);
			break;
			case PD:
			SET_BIT(DDRD,pin_num);
			break;
		}
		break;
		case INPULL:
		switch (port)
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
		case INFREE:
		switch (port)
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
	}
}


void  DIO_WritePin(DIO_Pin_type pin,DIO_PinVolt_type volt)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;

	if(volt==HIGH)
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
	else if(volt==LOW)
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


DIO_PinVolt_type DIO_ReadPin(DIO_Pin_type pin)
{
	DIO_Port_type port=pin/8;
	u8 pin_num=pin%8;
	DIO_PinVolt_type volt=LOW;
	
	switch(port)
	{
		case PA:
		volt=READ_BIT(PINA,pin_num);
		break;
		case PB:
		volt=READ_BIT(PINB,pin_num);
		break;
		case PC:
		volt=READ_BIT(PINC,pin_num);
		break;
		case PD:
		volt=READ_BIT(PIND,pin_num);
		break;
	}
	
	return volt;
}


void DIO_TogglePin(DIO_Pin_type pin)
{
	switch(pin)
	{
		case PINA0:
		TOG_BIT(PORTA,pin);
		break;
		case PINA1:
		TOG_BIT(PORTA,pin);
		break;
		case PINA2:
		TOG_BIT(PORTA,pin);
		break;
		case PINA3:
		TOG_BIT(PORTA,pin);
		break;
		case PINA4:
		TOG_BIT(PORTA,pin);
		break;
		case PINA5:
		TOG_BIT(PORTA,pin);
		break;
		case PINA6:
		TOG_BIT(PORTA,pin);
		break;
		case PINA7:
		TOG_BIT(PORTA,pin);
		break;
		
		case PINB0:
		TOG_BIT(PORTB,0);
		break;
		case PINB1:
		TOG_BIT(PORTB,1);
		break;
		case PINB2:
		TOG_BIT(PORTB,2);
		break;
		case PINB3:
		TOG_BIT(PORTB,3);
		break;
		case PINB4:
		TOG_BIT(PORTB,4);
		break;
		case PINB5:
		TOG_BIT(PORTB,5);
		break;
		case PINB6:
		TOG_BIT(PORTB,6);
		break;
		case PINB7:
		TOG_BIT(PORTB,7);
		break;
		
		case PINC0:
		TOG_BIT(PORTC,0);
		break;
		case PINC1:
		TOG_BIT(PORTC,1);
		break;
		case PINC2:
		TOG_BIT(PORTC,2);
		break;
		case PINC3:
		TOG_BIT(PORTC,3);
		break;
		case PINC4:
		TOG_BIT(PORTC,4);
		break;
		case PINC5:
		TOG_BIT(PORTC,5);
		break;
		case PINC6:
		TOG_BIT(PORTC,6);
		break;
		case PINC7:
		TOG_BIT(PORTC,7);
		break;
		
		case PIND0:
		TOG_BIT(PORTD,0);
		break;
		case PIND1:
		TOG_BIT(PORTD,1);
		break;
		case PIND2:
		TOG_BIT(PORTD,2);
		break;
		case PIND3:
		TOG_BIT(PORTD,3);
		break;
		case PIND4:
		TOG_BIT(PORTD,4);
		break;
		case PIND5:
		TOG_BIT(PORTD,5);
		break;
		case PIND6:
		TOG_BIT(PORTD,6);
		break;
		case PIND7:
		TOG_BIT(PORTD,7);
		break;
	}
}

void DIO_WritePort(DIO_Port_type port,u8 value)
{
	switch(port)
	{
		case PA:
		PORTA=value;
		break;
		case PB:
		PORTB=value;
		break;
		case PC:
		PORTC=value;
		break;
		case PD:
		PORTD=value;
		break;
	}
	
	
}

void DIO_Init(void)
{
	DIO_Pin_type i;
	for(i=PINA0;i<Total_Pins;i++)
	{
		DIO_InitPin(i,PinsStatusArray[i]);
	}
}