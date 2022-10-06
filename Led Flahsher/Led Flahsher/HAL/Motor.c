/*
 * Motor.c
 *
 * Created: 5/13/2022 1:40:57 AM
 *  Author: Smart
 */ 
#include "Motor.h"


void Motor1_CW(void)
{
		DIO_WritePin(IN1_M1,HIGH);
		DIO_WritePin(IN2_M1,LOW);
}

void Motor1_CCW(void)
{
	DIO_WritePin(IN1_M1,LOW);
	DIO_WritePin(IN2_M1,HIGH);
}

void Motor1_Stop(void)
{
	DIO_WritePin(IN1_M1,LOW);
	DIO_WritePin(IN2_M1,LOW);
}

void Motor2_CW(void)
{
	DIO_WritePin(IN1_M2,HIGH);
	DIO_WritePin(IN2_M2,LOW);
}

void Motor2_CCW(void)
{
	DIO_WritePin(IN1_M2,LOW);
	DIO_WritePin(IN2_M2,HIGH);
}

void Motor2_Stop(void)
{
	DIO_WritePin(IN1_M2,LOW);
	DIO_WritePin(IN2_M2,LOW);
}

void Motor3_CW(void)
{
	DIO_WritePin(IN1_M3,HIGH);
	DIO_WritePin(IN2_M3,LOW);
}

void Motor3_CCW(void)
{
	DIO_WritePin(IN1_M3,LOW);
	DIO_WritePin(IN2_M3,HIGH);
}

void Motor3_Stop(void)
{
	DIO_WritePin(IN1_M3,LOW);
	DIO_WritePin(IN2_M3,LOW);
}

void Motor4_CW(void)
{
	DIO_WritePin(IN1_M4,HIGH);
	DIO_WritePin(IN2_M4,LOW);
}

void Motor4_CCW(void)
{
	DIO_WritePin(IN1_M4,LOW);
	DIO_WritePin(IN2_M4,HIGH);
}

void Motor4_Stop(void)
{
	DIO_WritePin(IN1_M4,LOW);
	DIO_WritePin(IN2_M4,LOW);
}
