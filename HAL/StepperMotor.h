/*
 * StepperMotor.h
 *
 * Created: 5/17/2022 4:32:58 PM
 *  Author: Smart
 */ 


#ifndef STEPPERMOTOR_H_
#define STEPPERMOTOR_H_
#include "DIO_Interface.h"
#include <util/delay.h>
/************************Config****************************/
#define COIL1A	PINC0
#define COIL1B	PINC1
#define COIL2A	PINC2
#define COIL2B	PINC3
#define Delay	100
/***********************************************************/
void STEPPER_BipolarCW(void);
void STEPPER_BipolarCCW(void);

void STEPPER_UnipolarCW(void);
void STEPPER_UniolarCCW(void);



#endif /* STEPPERMOTOR_H_ */