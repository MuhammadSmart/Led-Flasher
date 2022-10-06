/*
 * KeyPad.c
 *
 * Created: 5/17/2022 12:13:23 AM
 *  Author: Smart
 */ 
#include "Keypad.h"
#include "LCD.h"
u8 KEYPAD_GetKey(void)
{
u8 key=NO_KEY,r,c;	 

DIO_WritePin(First_Output,HIGH);
DIO_WritePin(First_Output+1,HIGH);
DIO_WritePin(First_Output+2,HIGH);
DIO_WritePin(First_Output+3,HIGH);

for(r=0;r<ROW;r++)
{
	DIO_WritePin(First_Output+r,LOW);
	for(c=0;c<COL;c++)
	{
		if(DIO_ReadPin(First_Input+c)==LOW)
		{
		key=KeysArray[r][c];	
		while(DIO_ReadPin(First_Input+c)==LOW);
		}
	}
	DIO_WritePin(First_Output+r,HIGH);
}
	
return key;
}

u32 KEYPAD_GetNumber(void)
{
	u32 SumDigits=0;
	u8 S=0,q=0;
	u8 key=NO_KEY,flag=0;
		while(1)	
		{													//350
			key=KEYPAD_GetKey();
			if(key!=NO_KEY)
			{
				if(key>='0' && key<='9')
				{
				LCD_Go_to(1,q);
				LCD_WriteChar(key);
				q++;
				SumDigits=(SumDigits*10)+(key-'0');
				}
				/*_delay_ms(100);
				LCD_Go_to(1,q);
				LCD_WriteChar('*');
				q++;*/
				if(key=='C')
				{
					LCD_Clear();
					SumDigits=0;
				}
				else if(key=='=')
				{
				LCD_Go_to(1,0);	
				LCD_WriteString("               ");
				return SumDigits;
				}
				
			}
			
		}								
		
		
	
}

u8 KEYPAD_GetHEX(void)
{
	u8 k=0,SumHex=0;
	
	k=KEYPAD_GetKey();
	
	if(k!=NO_KEY)						
	{
	
	
	
	}
	
}



void KEYPAD_BasicOperation(u32* num)
{						
	u32 SumDigitsBefore=0;
	u32 SumDigitsAfter=0;
	u32 res=0;
	u8 S=0,q=0;
	u8 op=0;
	u8 key=NO_KEY,flag=0;
		while(1)	
		{													//350
			key=KEYPAD_GetKey();
			
			if(key!=NO_KEY)
			{
				if(key>='0' && key<='9' &&flag==0)
				{
				LCD_Go_to(0,q);
				LCD_WriteChar(key);
				q++;
				SumDigitsBefore=(SumDigitsBefore*10)+(key-'0');
				//LCD_Go_to(0,0);
				//LCD_WriteString("              ");
				LCD_Go_to(0,0);
				//LCD_WriteNumber(SumDigitsBefore);
				}
				else if(key>='0' && key<='9' &&flag==1)
				{
					LCD_Go_to(0,q);
					LCD_WriteChar(key);
					q++;
					SumDigitsAfter=(SumDigitsAfter*10)+(key-'0');
					/*LCD_Go_to(0,0);
					LCD_WriteString("              ");
					LCD_Go_to(0,8);
					LCD_WriteNumber(SumDigitsAfter);*/
				}
				
				if(key=='+' || key=='-' ||key=='*' ||key=='/')
				{
				flag=1;
					LCD_Go_to(0,q);
					q++;
					LCD_WriteChar(key);
					op=key;
				}
				
				
				
				
				if(key=='C')
				{
					LCD_Clear();
					SumDigitsBefore=0;
					SumDigitsAfter=0;
					flag=0;
				}
				if(key=='=')
				{
				LCD_Go_to(0,q);
				LCD_WriteChar('=');
				
				switch(op)
				{
					case  '+':*num=(SumDigitsBefore+SumDigitsAfter);
					break;
					case  '-':*num=(SumDigitsBefore-SumDigitsAfter);
					break;
					case  '*':*num=(SumDigitsBefore*SumDigitsAfter);
					break;
					case  '/':*num=(SumDigitsBefore/SumDigitsAfter);
					break;
					
				}
				
				return;
				}
			}
			
		}									
}