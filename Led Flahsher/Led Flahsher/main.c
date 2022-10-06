/*
 * Led Flahsher.c
 *
 * Created: 10/6/2022 8:52:42 AM
 * Author : Smart
 */ 

//#include "Application/Application.h"
#include "MCAL/DIO_Interface.h"
#include "avr/delay.h"
int main(void)
{
	
	
	DIO_Init();
    /* Replace with your application code */
	u8 i;
    while (1) 
    {
		
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
}

