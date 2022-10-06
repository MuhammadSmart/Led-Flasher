/*
 * UART.h
 *
 * Created: 5/25/2022 1:14:10 AM
 *  Author: Smart
 */ 


#ifndef UART_H_
#define UART_H_
#include "../Utils/Utils.h"
#include "../Utils/MemMap.h"
#include "../Utils/STD_TYPES.h"

void UART_Init();
void UART_SendData(u8 data);
u8 UART_ReciveData(void);
void UART_SendString(u8* data);
void UART_ReciveString(u8*);
u8 UART_ReceivePeriodic(u8* pdata);
void UART_SendStringCheckSum(u8* str);
u8 UART_ReciveStringCheckSum(u8* str);


void UART_RX_InterruptEnable(void);
void UART_RX_InterruptDisable(void);

void UART_TX_InterruptEnable(void);
void UART_TX_InterruptDisable(void);

void UART_RX_SetCallBack(void (*LocalFptr)(void));
void UART_TX_SetCallBack(void (*LocalFptr)(void));

void UART_SendByteNoBlock(u8 data);
u8 UART_ReceiveByteNoBlock(void);
void UART_SendAsynch(u8* str);




#endif /* UART_H_ */