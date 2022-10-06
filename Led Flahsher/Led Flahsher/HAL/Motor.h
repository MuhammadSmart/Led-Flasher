/*
 * Motor.h
 *
 * Created: 5/13/2022 1:42:03 AM
 *  Author: Smart
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "../MCAL/DIO_Interface.h"
/*******************************PINS_CONFIG*********************************/
#define IN1_M1 PINC0
#define IN2_M1 PINC1
 
#define IN1_M2 PINC2
#define IN2_M2 PINC3

#define IN1_M3 PINC4
#define IN2_M3 PINC5

#define IN1_M4 PINC6
#define IN2_M4 PINC7 


/***************************************************************************/
//For Motor 1


void Motor1_CW(void);
void Motor1_Stop(void);
void Motor1_CCW(void);

void Motor2_CW(void);
void Motor2_Stop(void);
void Motor2_CCW(void);

void Motor3_CW(void);
void Motor3_Stop(void);
void Motor3_CCW(void);

void Motor4_CW(void);
void Motor4_Stop(void);
void Motor4_CCW(void);


#endif /* MOTOR_H_ */