/*
 * Sensors.h
 *
 * Created: 5/18/2022 11:49:16 AM
 *  Author: Smart
 */ 


#ifndef SENSORS_H_
#define SENSORS_H_
//#include "DIO_Interface.h"
#include "../MCAL/ADC.h"


u16 LM35_GetTemp();
u16 POT_GetValue();

#endif /* SENSORS_H_ */