/*
 * SPI.h
 *
 * Created: 5/29/2022 1:27:19 AM
 *  Author: Smart
 */ 


#ifndef SPI_H_
#define SPI_H_

#include "../Utils/STD_TYPES.h"
#include "../Utils/Utils.h"
#include "../Utils/MemMap.h"

typedef enum{
	MASTER,
	SLAVE
	}MasterSlave_Type;
	
void SPI_Init(MasterSlave_Type mode);

u8 SPI_SendRecive(u8 data);	
u8 SPI_SendRecive_runTimeOut(u8 data);
u8 SPI_RecivePeriodic(u8* pdata);
void SPI_Send(u8 data);



#endif /* SPI_H_ */