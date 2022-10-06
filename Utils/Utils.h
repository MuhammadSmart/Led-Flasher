/*
 * Utils.h
 *
 * Created: 5/11/2022 3:09:07 PM
 *  Author: Smart
 */ 


#ifndef UTILS_H_
#define UTILS_H_

#define  F_CPU 8000000
#define  SET_BIT(reg,bit)  (reg|=(1<<bit))
#define  CLR_BIT(reg,bit)  (reg&=~(1<<bit))		
#define  TOG_BIT(reg,bit)  (reg^=(1<<bit))
#define  WRITE_BIT(reg,bit,value)  (reg|=(value<<bit))
#define  READ_BIT(reg,bit)  ((reg>>bit)&1)




#endif /* UTILS_H_ */