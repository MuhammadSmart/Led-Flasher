/*
 * UART.c
 *
 * Created: 5/25/2022 1:13:58 AM
 *  Author: Smart
 */ 
#include "UART.h"
static void (*UART_RX_Fptr) (void);
static void (*UART_TX_Fptr) (void);

void UART_Init()
{
		//baud rate 9600 ,f=8mhz , normal speed
	UBRRL=51; // from the table in data sheet
	
	// for normal speed
	CLR_BIT(UCSRA,U2X);
	
	//frame, parity , stop , data
	//(If you didn't change any thing, it will be 8 bit data no parity
	//and one stop one start so 10 bit frame total
	
	//enable the TX and RX (You can use only one for saving)
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);	
}

void UART_SendData(u8 data)

{
	while(!READ_BIT(UCSRA,UDRE));
	UDR=data;
}


void UART_SendString(u8* data)
{
	u8 i;
	for(i=0;data[i];i++)
	{
	UART_SendData(data[i]);
	}
		
}

u8 UART_ReciveData(void)
{
while(!READ_BIT(UCSRA,RXC));
return UDR;
}



u8 UART_ReceivePeriodic(u8* pdata)
{
	if(READ_BIT(UCSRA,RXC))
	{
		*pdata=UDR;
		return 1;
	}
	return 0;
}



void UART_RX_InterruptEnable(void)
{
	SET_BIT(UCSRB,RXCIE);
}

void UART_RX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,RXCIE);
}

void UART_TX_InterruptEnable(void)
{
	SET_BIT(UCSRB,TXCIE);
}

void UART_TX_InterruptDisable(void)
{
	CLR_BIT(UCSRB,TXCIE);
}
/*****************************************Set Call Back Functions*********************************************/
/*void UART_RX_SetCallBack(void (*LocalFptr)(void))
{
	UART_RX_Fptr = LocalFptr;
}*/

void UART_TX_SetCallBack(void (*LocalFptr)(void))
{
	UART_TX_Fptr = LocalFptr;
}
/***********************************************ISR ************************************************************/
/*ISR(USART_RXC_vect)
{
	if (UART_RX_Fptr!=NULLPTR)
	{
		UART_RX_Fptr();
	}
}*/

ISR(USART_TXC_vect)
{
	if (UART_TX_Fptr!=NULLPTR)
	{
		UART_TX_Fptr();
	}
}

/****************************************Send and receive functions with no ckecking********************************/

void UART_SendByteNoBlock(u8 data)
{
	UDR = data;
}

u8 UART_ReceiveByteNoBlock(void)
{
	return UDR;
}