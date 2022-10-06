/*
 * StepperMotor.c
 *
 * Created: 5/17/2022 4:33:09 PM
 *  Author: Smart
 */ 
#include "StepperMotor.h"

void STEPPER_BipolarCW(void)
{
	DIO_WritePin(COIL1A,HIGH);				
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(Delay);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,HIGH);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(Delay);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,HIGH);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,LOW);
	_delay_ms(Delay);
	DIO_WritePin(COIL1A,LOW);
	DIO_WritePin(COIL1B,LOW);
	DIO_WritePin(COIL2A,LOW);
	DIO_WritePin(COIL2B,HIGH);
_delay_ms(Delay);
}

void STEPPER_BipolarCCW(void)
{
	
		
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2A,LOW);
		DIO_WritePin(COIL2B,HIGH);
		_delay_ms(Delay);
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,HIGH);
		DIO_WritePin(COIL2A,LOW);
		DIO_WritePin(COIL2B,LOW);
		_delay_ms(Delay);
		DIO_WritePin(COIL1A,LOW);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2A,HIGH);
		DIO_WritePin(COIL2B,LOW);
		_delay_ms(Delay);
		DIO_WritePin(COIL1A,HIGH);
		DIO_WritePin(COIL1B,LOW);
		DIO_WritePin(COIL2A,LOW);
		DIO_WritePin(COIL2B,LOW);
		_delay_ms(Delay);
}