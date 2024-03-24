/********************************************/
/*** Author : ABDALLAH NABIL            *****/
/*** Description: EXTI_private.h         ****/
/*** Date: 27/9/2023                      ***/
/********************************************/
#ifndef INCLUDE_MCAL_EXTERN_INTERRUPT_EXTI_PRIVATE_H_
#define INCLUDE_MCAL_EXTERN_INTERRUPT_EXTI_PRIVATE_H_

#define MCUCR *((volatile u8 *)0x55)
#define MCUCSR *((volatile u8 *)0x54)
#define GICR *((volatile u8 *)0x5B)
#define GIFR *((volatile u8 *)0x5A)

#define Interrupt_Sense_Control_shift 2 //shift steps
#define Interrupt_Sense_Control_masked 3
#define  Interrupt_sense_control_EXTI2_bin 6
#define External_Interrupt0_Enable_bin 6
#define External_Interrupt1_Enable_bin 7
#define External_Interrupt2_Enable_bin 5


#endif /* INCLUDE_MCAL_EXTERN_INTERRUPT_EXTI_PRIVATE_H_ */
