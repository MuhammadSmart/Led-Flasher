/*
 * DIO_Lcfg.c
 *
 * Created: 5/13/2022 3:27:56 AM
 *  Author: Smart
 */ 
#include "DIO_Interface.h"
const DIO_PinStatus_type PinsStatusArray[Total_Pins]={
	OUTPUT,   /* Port A Pin 0 */
	OUTPUT,   /* Port A Pin 1 */
	OUTPUT,   /* Port A Pin 2 */
	OUTPUT,   /* Port A Pin 3 */
	OUTPUT,   /* Port A Pin 4 */
	OUTPUT,   /* Port A Pin 5 */
	OUTPUT,   /* Port A Pin 6 */
	OUTPUT,   /* Port A Pin 7 */
	OUTPUT,   /* Port B Pin 0   / */
	OUTPUT,   /* Port B Pin 1   /*/
	OUTPUT,		 /* Port B Pin 2 / INT2*/
	OUTPUT,		 /* Port B Pin 3   /*/
	INPULL,		 /* Port B Pin 4 */
	INPULL,		 /* Port B Pin 5 */
	INPULL,		 /* Port B Pin 6 */ //miso
	INPULL,		 /* Port B Pin 7 */
	OUTPUT,		 /* Port C Pin 0 */
	OUTPUT,		 /* Port C Pin 1 */
	OUTPUT,		 /* Port C Pin 2 */
	OUTPUT,		 /* Port C Pin 3 */
	OUTPUT,		 /* Port C Pin 4 */
	OUTPUT,		 /* Port C Pin 5 */
	OUTPUT,		 /* Port C Pin 6 */
	OUTPUT,		 /* Port C Pin 7 */
	INFREE,		 /* Port D Pin 0 */
	OUTPUT,		 /* Port D Pin 1 */
	INPULL,      /* Port D Pin 2 / INT0 */
	OUTPUT,    /* Port D Pin 3 / INT1 */
	OUTPUT,		 /* Port D Pin 4 */
	OUTPUT,		 /* Port D Pin 5 */
	INFREE,		 /* Port D Pin 6 /   ICP*/
	OUTPUT		 /* Port D Pin 7 */
	};
	
	