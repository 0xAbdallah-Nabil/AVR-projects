/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: TIMER_interface.h  ********/
/*** Date: 20/3/2024             ************/
/********************************************/
#ifndef INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_
#define INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_

/****************************************************************************************************/
/*******************************************    TIMER0    *******************************************/
/****************************************************************************************************/

void MTIMER0_voidInit(void);
void MTIMER0_voidSet_preload_value(u8 A_No_of_tricks);
void MTIMER0_voidSet_overflow_callback(void (*A_ptr_to_func)(void));
void MTIMER0_voidSet_CTC_callback(void (*A_ptr_to_func)(void));
void MTIMER0_voidSet_OCR0_value(u8 A_OCR0_value);
void MTIMER0_voidStop_timer(void);




/****************************************************************************************************/
/*******************************************    TIMER1    *******************************************/
/****************************************************************************************************/
typedef enum{
	TIMER1_NORMAL_MODE=0,
	TIMER1_PWM_PHASE_CORRECT_8BIT_MODE,
	TIMER1_PWM_PHASE_CORRECT_9BIT_MODE,
	TIMER1_PWM_PHASE_CORRECT_10BIT_MODE,
	TIMER1_CTC_OCR1A_MODE,
	TIMER1_PWM_FAST_MODE_8BIT,
	TIMER1_PWM_FAST_MODE_9BIT,
	TIMER1_PWM_FAST_MODE_10BIT,
	TIMER1_PWM_PHASE_FRQ_ICR1_MODE,
	TIMER1_PWM_PHASE_FRQ_OCR1A_MODE,
	TIMER1_PWM_PHASE_CORRECT_ICR1_MODE,
	TIMER1_PWM_PHASE_CORRECT_OCR1A_MODE,
	TIMER1_CTC_ICR1_MODE,
	REVERSED,
	TIMER1_PWM_FAST_MODE_ICR1,
	TIMER1_PWM_FAST_MODE_OCR1A
}TIMER1_MODE_E;

typedef enum{
	OCRA1_DISCONNECTED=0,
	OCRA1_TOGGLE=0X40,
	OCRA1_NON_INVERTING=0X80,
	OCRA1_INVERTING=0XC0
}OCRA_PHASE_FAST_PWM_E;

typedef enum{
	OCRB1_DISCONNECTED=0,
	OCRB1_TOGGLE=0X10,
	OCRB1_NON_INVERTING=0X20,
	OCRB1_INVERTING=0X30
}OCRB_PHASE_FAST_PWM_E;

typedef enum{
	FALLING_EDGE_ICU,
	RISING_EDGE_ICU
}EDGE_E;
typedef enum{
	NO_CLOCK_SOURCE,
	NO_PRESCALER,
 	PRESCALER_8,
	PRESCALER_64,
	PRESCALER_256,
	PRESCALER_1024,
	EXTERNAL_T0_FALLING_EDGE,
	EXTERNAL_T0_RISING_EDGE,
}Prescalar_E;
void MTimer1_SetCallBack_ICU(void (*(TMR1_ICU)) (void));
void MTimer1_SetCallBack_COMPB(void (*tmr1_ptf)(void));
void MTimer1_SetCallBack_COMPA(void (*tmr1_ptf)(void));
void MTimer1_SetCallBack_OVF(void (*tmr1_ptf)(void));
void MTimer1_Init(TIMER1_MODE_E A_mode,OCRA_PHASE_FAST_PWM_E A_OCRA,OCRB_PHASE_FAST_PWM_E A_OCRB);
void MTIMER1_SetOCR1A(u16 A_u16Value);
void MTIMER1_SetOCR1B(u16 A_u16Value);
void MTIMER1_SetICR1(u16 A_u16Value);
void MTIMER1_SetTCNT1(u16 A_u16Value);
void MTIMER1_OVF_Interrupt_Enable(void);
void MTIMER1_OCMA_Interrupt_Enable(void);
void MTIMER1_OCMB_Interrupt_Enable(void);
void MTIMER1_ICU_Interrupt_Enable(void);
void MTIMER1_OVF_Interrupt_Disable(void);
void MTIMER1_OCMA_Interrupt_Disable(void);
void MTIMER1_OCMB_Interrupt_Disable(void);
void MTIMER1_ICU_Interrupt_Disable(void);
void MTimer1_Start(Prescalar_E A_value);
void MTimer1_Stop(void);
void MTIMER1_init_ICU(void);
void MTIMER1_init_FAST_PWM(void);
void MTimer1_InputCpetureEdge(EDGE_E A_Edge);
#endif /* INCLUDE_MCAL_TIMER_TIMER_INTERFACE_H_ */
