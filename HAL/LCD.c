#include "LCD.h"

#if LCD_MODE ==_8Bit_LCD							//8Bit mode
static void LCD_Command(u8 command)
{
	DIO_WritePin(RS,LOW);
	DIO_WritePort(LCD_Port,command);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);
	DIO_WritePort(LCD_Port,data);
	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	LCD_Command(0x38);  //2 lines , 5*7
	LCD_Command(0x01);  //LCD Clear
	LCD_Command(0x0c);  //cursor , 0x0f,0x0c
	_delay_ms(1);
	LCD_Command(0x06); //increase DDRAM address no shift
}
#elif LCD_MODE==_4Bit_LCD									//4Bit mode

static void LCD_Command(u8 command)
{
	
	DIO_WritePin(RS,LOW);			//to send command
	///////High  Nibble
	DIO_WritePin(D7,READ_BIT(command,7));
	DIO_WritePin(D6,READ_BIT(command,6));
	DIO_WritePin(D5,READ_BIT(command,5));
	DIO_WritePin(D4,READ_BIT(command,4));

	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	///////Low Nibble
	DIO_WritePin(D7,READ_BIT(command,3));
	DIO_WritePin(D6,READ_BIT(command,2));
	DIO_WritePin(D5,READ_BIT(command,1));
	DIO_WritePin(D4,READ_BIT(command,0 ));

	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	
}
static void LCD_WriteData(u8 data)
{
	DIO_WritePin(RS,HIGH);							//to send data
	///////High  Nibble
	DIO_WritePin(D7,READ_BIT(data,7));
	DIO_WritePin(D6,READ_BIT(data,6));
	DIO_WritePin(D5,READ_BIT(data,5));
	DIO_WritePin(D4,READ_BIT(data,4));

	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
	///////Low Nibble
	
	DIO_WritePin(D7,READ_BIT(data,3));
	DIO_WritePin(D6,READ_BIT(data,2));
	DIO_WritePin(D5,READ_BIT(data,1));
	DIO_WritePin(D4,READ_BIT(data,0));

	DIO_WritePin(EN,HIGH);
	_delay_ms(1);
	DIO_WritePin(EN,LOW);
	_delay_ms(1);
}
void LCD_Init(void)
{
	_delay_ms(50);
	LCD_Command(0x02);
	LCD_Command(0x28);  //2 lines , 5*7
	LCD_Command(0x01);  //LCD Clear
	LCD_Command(0x0c);  //cursor , 0x0f,0x0c
	_delay_ms(1);
	LCD_Command(0x06); //increase DDRAM address no shift
}
#endif
/***************************************************************************/

void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}


void LCD_Clear()
{
	LCD_Command(0x01);
}
void LCD_WriteString(u8* str)
{	
u8 i;
for(i=0;str[i];i++)
{
	LCD_WriteData(str[i]);
}	
}

void LCD_WriteNumber(s32 number)
{
	u8 str[250];
	u8 r=0,i=0;
	
	
	if(number==0)
	{
		LCD_WriteChar('0');
		return;
	}
	if(number<0)
	{
		number=number*-1;
		LCD_WriteChar('-');
	}
	
	while(number>0)
	{
		r=number%10;
		str[i]=r+'0';
		number=number/10;
		i++;
	}
	for(s8 j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
	
	
}


void LCD_WriteBinary(u8 number) //5
{
	s8 i,flag=0;
	for(i=7; i>=0; i--)
	{
		if((number>>i)&1)
		{
			LCD_WriteNumber(1);
			flag=1;
		}
		else if(flag==1)
		{
			LCD_WriteNumber(0);
		}
	}
	
}

void LCD_WriteHex(u8 number)  
{
	u8 r=0,i=0;
	u8 str[2];
	while(number>0)
	{
	r=number%16;
										//A8 >> 168
	if(r<10)
	str[i]=	r+'0';
	else
	{
	str[i]=r+55;	
	}
	
	number/=16;
	i++;
	}
	
	for(s8 j=i-1;j>=0;j--)
	{
		LCD_WriteChar(str[j]);
	}
	
	
	
	
}

void LCD_Go_to(u8 LineNum,u8 CellNum)
{
	if(LineNum==0)
	{
		LCD_Command(0x80+CellNum);
	}
	else if(LineNum==1)
	{
		LCD_Command(0x80+0x40+CellNum);
	}
}

void LCD_WriteNumber_4D(u16 number) //1000,000 >> 56651 >>6651
{
LCD_WriteChar(((number%10000)/1000)+'0');		//first dig
LCD_WriteChar(((number%1000)/100)+'0')	;	//second
LCD_WriteChar(((number%100)/10)+'0')	;	//third
LCD_WriteChar(((number%10)/1)+'0')	;	//forth
}


void LCD_Go_toClear(u8 LineNum,u8 CellNum,u8 CellNumber)
{
	u8 i;
	LCD_Go_to(LineNum,CellNum);
	for(i=0;i>=CellNumber;i--)
	{
		LCD_WriteChar(' ');
	}
	
	
}

void LCD_GoToWriteString(u8 LineNum,u8 CellNum,u8* str)
{
	LCD_Go_to(LineNum,CellNum);
	LCD_WriteString(str);
}

void LCD_Create_Character(u8 *pattern,u8 address)
{
	u8 i;
	LCD_Command(0x40+(address*8));	//Send address of CGRAM
	for(i=0;i<8;i++)
	{
		LCD_WriteChar(pattern[i]);		
	}
	LCD_Command(0x80);		//To go back to DDRAM
}

void LCD_WriteHex2(u8 number)
{
	u8 H_Nibble=number>>4;
	u8 L_Nibble=number&0x0f;
	

if(H_Nibble<=9)	
	LCD_WriteChar(H_Nibble+'0');
else
LCD_WriteChar(H_Nibble-10+'A');
	
	if(L_Nibble<=9)
	LCD_WriteChar(L_Nibble+'0');
	else
	LCD_WriteChar(L_Nibble-10+'A');
	 
}