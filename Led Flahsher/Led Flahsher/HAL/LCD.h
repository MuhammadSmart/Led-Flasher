#ifndef LCD_H_
#define LCD_H_

#include "../Utils/STD_TYPES.h"
#include "../MCAL/DIO_Interface.h"
#define F_CPU 8000000  
#include <util/delay.h>

#define _4Bit_LCD	1
#define _8Bit_LCD	2

/************************Pins_Config*************************************/

#define LCD_MODE _4Bit_LCD

#define RS				PINA5
#define EN				PINA4
#define LCD_Port		PA

#define D7  PINA3
#define D6	PINA2
#define D5	PINA1
#define D4	PINA0    
                                            
/************************************************************************/


void LCD_Init();
void LCD_Clear();
void LCD_WriteString(u8* str);
void LCD_WriteNumber(s32 number);
void LCD_WriteNumber_4D(u16 number);
void LCD_WriteChar(u8 ch);
void LCD_WriteBinary(u8 number);
void LCD_WriteHex(u8 number);
void LCD_WriteHex2(u8 number);
void LCD_Go_to(u8 LineNum,u8 CellNum);
void LCD_Go_toClear(u8 LineNum,u8 CellNum,u8 CellNumber);
void LCD_GoToWriteString(u8 LineNum,u8 CellNum,u8* str);
void LCD_Create_Character(u8 *pattern,u8 address); 


#endif /* LCD_H_ */