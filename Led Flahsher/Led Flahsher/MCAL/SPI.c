/*
 * SPI.c
 *
 * Created: 5/29/2022 1:27:29 AM
 *  Author: Smart
 */ 
#include "SPI.h"


void SPI_Init(MasterSlave_Type mode)
{
	//master/slave
	if(mode==MASTER)
	{
		SET_BIT(SPCR,MSTR);
	}
	else
	CLR_BIT(SPCR,MSTR);
	//clock if master
	
	//SPI Enable
	SET_BIT(SPCR,SPE);
}

u8 SPI_SendRecive(u8 data)
{
	SPDR=data;		//send data to slave to be able to receive
	while(!READ_BIT(SPSR,SPIF));//wait 8 cycles for the data at slave being transfered
	return SPDR;	//return it
}

u8 SPI_SendRecive_runTimeOut(u8 data)
{
	SPDR=data;		//send data to slave to be able to receive
	while(!READ_BIT(SPSR,SPIF));//wait 8 cycles for the data at slave being transfered
	return SPDR;	//return it
}



void SPI_Send(u8 data)
{
	SPDR=data;
}

u8 SPI_RecivePeriodic(u8* pdata)
{
	if(READ_BIT(SPSR,SPIF))  //if there is a data and the SPI flag is set
	{
		*pdata=SPDR;   // put the data in the pointer to the data
		return 1;
	}
	return 0;
}