/*
 * Application.c
 *
 * Created: 10/6/2022 9:02:22 AM
 *  Author: Smart
 */ 
#include "Application.h"
#include "avr/delay.h"
void allLedsFlash(void)
{
	u8 i;
	for(i=0;i<=7;i++)
	{
		DIO_WritePin(i,HIGH);
		_delay_ms(200);
	}
	
	
	for(i=PINA7;i>=PINA0;i--)
	{
		DIO_WritePin(i,LOW);
		_delay_ms(200);
	}
	
}