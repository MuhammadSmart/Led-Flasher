/*
 * Modules.h
 *
 * Created: 6/20/2022 1:59:33 PM
 *  Author: Smart
 */ 


#ifndef MODULES_H_
#define MODULES_H_
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "Motor.h"
#include "LCD.h"
#include "Keypad.h"
#include "StepperMotor.h"
#include "ADC.h"
#include "Sensors.h"
#include "EX_Interrupt.h"
#include "Timers.h"
#include "UART.h"
#include "SPI.h"
#include "EEPROM.h"
#include <util/delay.h>

/************************************************************************/
/* Important variables                                                  */
/************************************************************************/
char buf[100];
volatile char ind,flag,stringReceived,i;
char gpgga[]={'$','G','P','G','G','A'};

char latitude[12];
char logitude[12];
/************************************************************************/

void GPS_Init();
char* GPS_GetLatitude();
char* GPS_GetLogitude();



#endif /* MODULES_H_ */