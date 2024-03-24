/********************************************/
/*** Author : ABDALLAH NABIL            *****/
/*** Description: EXTI_interface.h       ****/
/*** Date: 27/9/2023                      ***/
/********************************************/

#ifndef INCLUDE_MCAL_EXTERN_INTERRUPT_EXTI_INTERFACE_H_
#define INCLUDE_MCAL_EXTERN_INTERRUPT_EXTI_INTERFACE_H_

#define NULL 0
typedef enum{
	LOW_LEVEL=0,
	ON_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}state_e; //mode

typedef enum{
	EXTI0,
	EXTI1,
	EXTI2
}EXTI_e;

void MEXTI_void_set_callback_func(EXTI_e EXTI,void (*func) (void));
void MEXTI_void_enaple_PIE(EXTI_e EXTI);
void MEXTI_void_disaple_PIE(EXTI_e EXTI);
void MEXTI_void_RESET_PIF(EXTI_e EXTI);
void MEXTI_configration(EXTI_e EXTI,state_e state);



#endif /* INCLUDE_MCAL_EXTERN_INTERRUPT_EXTI_INTERFACE_H_ */
