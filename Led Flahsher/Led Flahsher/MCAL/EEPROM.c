/*
 * EEPROM.c
 *
 * Created: 6/16/2022 8:00:32 AM
 *  Author: Smart
 */ 
#include "EEPROM.h"




void EEPROM_WRITE(u8 address,u8 data)
{
	while(READ_BIT(EECR,EEWE));			//wait for last write to finish
	
	EEAR=address;
	EEDR=data;
	SET_BIT(EECR,EEMWE);  
	SET_BIT(EECR,EEWE);
}

u8 EEPROM_READ(u8 address)
{
	while(READ_BIT(EECR,EEWE));			//wait for last write to finish
	EEAR=address;
	SET_BIT(EECR,EERE);
	return EEDR;
}