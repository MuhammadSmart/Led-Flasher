/*
 * EEPROM.h
 *
 * Created: 6/16/2022 8:00:21 AM
 *  Author: Smart
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "DIO_Interface.h"
#include "MemMap.h"
#include "Utils.h"

u8 EEPROM_READ(u8 address);
void EEPROM_WRITE(u8 address,u8 data);


#endif /* EEPROM_H_ */