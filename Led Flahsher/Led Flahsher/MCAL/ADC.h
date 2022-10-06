/*
 * ADC.h
 *
 * Created: 5/18/2022 1:45:22 AM
 *  Author: Smart
 */ 


#ifndef ADC_H_
#define ADC_H_	

#include "../Utils/MemMap.h"
#include "../Utils/Utils.h"
#include "../Utils/STD_TYPES.h"
#define  F_CPU 8000000
#include <util/delay.h>
/**********************************************************************/
typedef enum
{
	ADC_AREF=0,
	ADC_VCC,
	ADC_V256=3
	}ADC_Vref_type;

typedef enum
{
	ADC_PreScaler_2=0,
	ADC_PreScaler_4=2, 
	ADC_PreScaler_8,	
	ADC_PreScaler_16,
	ADC_PreScaler_32,
	ADC_PreScaler_64,
	ADC_PreScaler_128,
	
	}ADC_PreScaler_type;

typedef enum{
	CH_0=0,
	CH_1,
	CH_2,
	CH_3,
	CH_4,
	CH_5,
	CH_6,
	CH_7
	}ADC_Channel_type;
	
void ACD_Init(ADC_Vref_type,ADC_PreScaler_type);

u16 ADC_Read(ADC_Channel_type);
u16 ADC_GetVolt(ADC_Channel_type);

void ADC_StartConversion(ADC_Channel_type);
u16 ADC_GetRead(void);
u16 ADC_GetReadPeriodicCheck(u16 *pdata);
u16 ADC_GetReadNoBlock();
#endif /* ADC_H_ */