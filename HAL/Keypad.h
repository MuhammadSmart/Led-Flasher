/*
 * Keypad.h
 *
 * Created: 5/17/2022 12:13:12 AM
 *  Author: Smart
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO_Interface.h"
/***************************CONFIG***********************************/
#define First_Output PINB0
#define First_Input PINB4
#define COL	4
#define ROW	4
#define NO_KEY 'N' 
static const u8 KeysArray[ROW][COL]={ {'7','8','9','/'},
								{'4','5','6','*'},
								{'1','2','3','-'},
								{'C','0','=','+'}
								};
/***********************************************************************/

u8 KEYPAD_GetKey(void);
u32 KEYPAD_GetNumber(void);
u8 KEYPAD_GetHEX(void);
u8 KEYPAD_GetBinary(void);
void KEYPAD_BasicOperation(u32*);
#endif /* KEYPAD_H_ */