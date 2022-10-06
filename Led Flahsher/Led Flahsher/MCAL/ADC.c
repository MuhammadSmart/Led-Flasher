/*
 * ADC.c
 *
 * Created: 5/18/2022 1:45:31 AM
 *  Author: Smart
 */ 
#include "ADC.h"

void ACD_Init(ADC_Vref_type vref,ADC_PreScaler_type Scaler)
{
	
	//1- vref
	switch(vref)
	{
		case ADC_AREF:
		CLR_BIT(ADMUX,REFS1);
		CLR_BIT(ADMUX,REFS0);
		break;
		case ADC_VCC:
		CLR_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;
		case ADC_V256:
		SET_BIT(ADMUX,REFS1);
		SET_BIT(ADMUX,REFS0);
		break;	
	}
	
	//2- prescaler  (clock)
	ADCSRA=ADCSRA&0xF8; //  >> 11111000
	Scaler=Scaler&0x07; //  >> 00000111
	ADCSRA=ADCSRA|Scaler;
	
	//3- Adjust Read to the right
	CLR_BIT(ADMUX,ADLAR);  //high accuracy 
	//4- ADC enable
	SET_BIT(ADCSRA,ADEN);
	
	
}
static u8 read_flag=1;
u16 ADC_Read(ADC_Channel_type channel)
{
	// select pin (channel)
	ADMUX=ADMUX&0xe0;  //0b11100000
	ADMUX=ADMUX|channel;
	
	
	// start conversion
	SET_BIT(ADCSRA,ADSC);
	while(READ_BIT(ADCSRA,ADSC));  //busy polling wait  wait until conversion finish 
	
	//get read

	return ADC;	
}

u16 ADC_GetVolt(ADC_Channel_type channel)
{
	u16 adcRead=ADC_Read(channel);
	
	u16 volt=((u32)adcRead*5000)/1024 ;
	
	return volt;
	
}

void ADC_StartConversion(ADC_Channel_type channel)
{
	if(read_flag==1)
	{
		// select pin (channel)
		ADMUX=ADMUX&0xe0;  //0b11100000
		ADMUX=ADMUX|channel;
		
		
		// start conversion
		SET_BIT(ADCSRA,ADSC);
		read_flag=0;
		
	}
	
	
}

u16 ADC_GetRead(void)
{
	while(READ_BIT(ADCSRA,ADSC));  //busy polling wait  wait until conversion finish
	read_flag=1; 
	return ADC;
	
}



u16 ADC_GetReadPeriodicCheck(u16 *pdata)
{
	if(READ_BIT(ADCSRA,ADSC)==0)
	{
	*pdata=ADC;
	read_flag=1;
	return 1;
	} 
	else
	{
		return 0;
	}
}

u16 ADC_GetReadNoBlock()
{
	return ADC;
}