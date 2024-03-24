/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: GI_private.h        *******/
/*** Date: Mar 23, 2024          ************/
/********************************************/
#ifndef INCLUDE_MCAL_GLOBAL_INTERRRUPT_GI_PRIVATE_H_
#define INCLUDE_MCAL_GLOBAL_INTERRRUPT_GI_PRIVATE_H_

#define SREG (*(volatile u8 *)0x5F)

#define GLOBAL_INTERRUPT_ENABLE_BIT  7

#endif /* INCLUDE_MCAL_GLOBAL_INTERRRUPT_GI_PRIVATE_H_ */
