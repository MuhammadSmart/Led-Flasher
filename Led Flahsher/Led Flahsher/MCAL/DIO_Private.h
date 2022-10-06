 /*
 * DIO_Private.h
 *
 * Created: 5/13/2022 3:28:19 AM
 *  Author: Smart
 */ 


#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

extern const DIO_PinStatus_type PinsStatusArray[Total_Pins];
static void DIO_InitPin(DIO_Pin_type pin,DIO_PinStatus_type status);


#endif /* DIO_PRIVATE_H_ */