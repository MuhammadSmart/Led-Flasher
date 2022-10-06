/*
 * Sensors.c
 *
 * Created: 5/18/2022 11:49:31 AM
 *  Author: Smart
 */ 

#include "Sensors.h"
/**************************PinConfig*************************************/
#define LM35_CH CH_6
#define POT_CH CH_1

u16 LM35_GetTemp(void)
{
	
	u16 volt=ADC_GetVolt(LM35_CH);	
	
	
	return volt;
}

u16 POT_GetValue()
{
	u16 pot;
	u16 adcres=ADC_Read(POT_CH);
	pot=((u32)100*adcres)/1023;

	
	return pot;
}