/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: TIMER_program.c    ********/
/*** Date: 20/3/2024             ************/
/********************************************/
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/Timer/TIMER_interface.h"
#include "../include/MCAL/Timer/TIMER_cfg.h"
#include "../include/MCAL/Timer/TIMER_private.h"

#define NULL (void*)0

void (*Timer0_CALLBACK_OVF)(void)=NULL;
void (*Timer0_CALLBACK_CTC)(void)=NULL;
void (*TIMER1_CALLBACK_OVF)(void)=NULL;
void (*TIMER1_CALLBACK_ICU)(void)=NULL;
void (*TIMER1_CALLBACK_COMPA)(void)=NULL;
void (*TIMER1_CALLBACK_COMPB)(void)=NULL;

/****************************************************************************************************/
/*******************************************    TIMER0    *******************************************/
/****************************************************************************************************/


void MTIMER0_voidInit(void)
{
	#if TIMER0_MODE == NORMAL_MODE
	//set wave generation to normal mode
	CLR_BIT(TCCR0,6);
	CLR_BIT(TCCR0,3);
	//enable OVF interrupt and disable CTC
	SET_BIT(TIMSK,0);
	CLR_BIT(TIMSK,1);
	//start timer by setting its clock
	TCCR0&=0b11111000; //clear first 3 bit only == TCCR&= ~(7<<0)
	TCCR0|=TIMER0_CLK;

	/****************************************************************************************************************************/

	#elif TIMER0_MODE == CTC_MODE
	// Set Wave Generation to CTC Mode
		SET_BIT(TCCR0,3);
		CLR_BIT(TCCR0,6);

		// Disable OVF Interrupt, and Enable CTC Interrupt
		SET_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);

		// Set Compare match value
		OCR0 = OCR0_value ;

		// Start Timer by setting its Clock and also set OC0 Pin Mode
		TCCR0 &= TIMER0_CLK_OCR_MASK;
		TCCR0 |= (TIMER0_CLK | (OC0_MODE << 4));


		/****************************************************************************************************************************/
	#elif TIMER0_MODE == FAST_PWM_MODE
		// set wave generation to PWM mode
		SET_BIT(TCCR0,3);
		SET_BIT(TCCR0,6);

		// disable all interrupts
		CLR_BIT(TIMSK,1);
		CLR_BIT(TIMSK,0);

		//set OCR0 value
		OCR0 = OCR0_value ;

		//set oc0 configuration
		//start timer
		TCCR0 &= TIMER0_CLK_OCR_MASK;
		TCCR0 |= (TIMER0_CLK | (OC0_MODE << 4));

		/****************************************************************************************************************************/
	#elif TIMER0_MODE == PHASE_CORRECT_MODE

		/****************************************************************************************************************************/
	#endif
}
void MTIMER0_voidSet_preload_value(u8 A_No_of_tricks)
{
	TCNT0=A_No_of_tricks;
}
void MTIMER0_voidStop_timer(void)
{
	TCCR0&=0b11111000; //clear first 3 bit only
}
void MTIMER0_voidSet_OCR0_value(u8 A_OCR0_value)
{
	OCR0 = A_OCR0_value;
}
void MTIMER0_voidSet_CTC_callback(void (*A_ptr_to_func)(void))
{
	if (A_ptr_to_func != NULL)
	{
		Timer0_CALLBACK_CTC = A_ptr_to_func;
	}
}
void MTIMER0_voidSet_overflow_callback(void (*A_ptr_to_func)(void))
{
	if(A_ptr_to_func != NULL)
	{

		Timer0_CALLBACK_OVF=A_ptr_to_func;
	}
}


/****************************************************************************************************/
/*******************************************    TIMER1    *******************************************/
/****************************************************************************************************/


void MTIMER1_init_FAST_PWM()// for SERVO motor only  it's not configurable
{
	// select wave form of  FASR PWM mode (number 14 in the table)
	CLR_BIT(TCCR1A,0);
	SET_BIT(TCCR1A,1);
	SET_BIT(TCCR1B,3);
	SET_BIT(TCCR1B,4);
	//disable OVF interrupt and ICU interrupt disable CTC interrupts
	CLR_BIT(TIMSK,TICIE1);
	CLR_BIT(TIMSK,TOIE1);
	CLR_BIT(TIMSK,OCIE1A);
	CLR_BIT(TIMSK,OCIE1B);
	// select non inverting mode
	CLR_BIT(TCCR1A,6);
	SET_BIT(TCCR1A,7);
	//set ICR-->19999
	ICR1=19999;
	// set OCR1A -->1000 ==1000 MICRO SEC for 1 m SEC
	OCR1A=500;
	//start timer by setting it's CLK
	CLR_BIT(TCCR1B,0);
	SET_BIT(TCCR1B,1);
	CLR_BIT(TCCR1B,2);
}
void MTIMER1_init_ICU()
{
	/****** normal mode**********/
	//set wave generation mode on normal mode
	CLR_BIT(TCCR1A, 0);
	CLR_BIT(TCCR1A, 1);
	CLR_BIT(TCCR1B, 3);
	CLR_BIT(TCCR1B, 4);
	//enable OVF interrupt and ICU interrupt disable CTC interrupts
	SET_BIT(TIMSK,TICIE1);
	SET_BIT(TIMSK,TOIE1);
	CLR_BIT(TIMSK,OCIE1A);
	CLR_BIT(TIMSK,OCIE1B);
	//select the edge of the ICU
	SET_BIT(TCCR1B,ICES1);
	//start timer by setting it's CLK
	CLR_BIT(TCCR1B, 0);
	SET_BIT(TCCR1B, 1);
	CLR_BIT(TCCR1B, 2);
}
void MTimer1_SetCallBack_OVF(void (*tmr1_ptf)(void)) {
	if (tmr1_ptf != NULL)
	{
		TIMER1_CALLBACK_OVF = tmr1_ptf;
	}
}
void MTimer1_SetCallBack_ICU(void (*(TMR1_ICU))(void)) {
	if (TMR1_ICU != NULL)
	{
		TIMER1_CALLBACK_ICU = TMR1_ICU;
	}
}
void MTimer1_SetCallBack_COMPA(void (*tmr1_ptf)(void)) {
	if (tmr1_ptf != NULL)
	{
		TIMER1_CALLBACK_COMPA = tmr1_ptf;
	}
}
void MTimer1_SetCallBack_COMPB(void (*tmr1_ptf)(void)) {
	if (tmr1_ptf != NULL)
	{
		TIMER1_CALLBACK_COMPB = tmr1_ptf;
	}
}
void MTimer1_Init(TIMER1_MODE_E A_mode,OCRA_PHASE_FAST_PWM_E A_OCRA,OCRB_PHASE_FAST_PWM_E A_OCRB)
{
	if(A_mode<=TIMER1_PWM_FAST_MODE_OCR1A && A_mode>=TIMER1_NORMAL_MODE)
	{
		TCCR1A &= TIMER1_MODE_MASK_TCCR1A;
		TCCR1B &= TIMER1_MODE_MASK_TCCR1B;
		TCCR1A  = TCCR1A | (A_mode & 0b00000011);
		TCCR1B  = TCCR1B | ((A_mode & 0b00001100)<<1);
	}
        TCCR1A = TCCR1A | A_OCRA;
        TCCR1A = TCCR1A | A_OCRB;
}
void MTimer1_Start(Prescalar_E A_value)
{
	TCCR1B&= TIMER_CLK_MASK;
	if(A_value<=EXTERNAL_T0_RISING_EDGE && A_value>=NO_CLOCK_SOURCE )
	TCCR1B|= A_value;
}
void MTimer1_Stop(void)
{
	TCCR1B&= TIMER_CLK_MASK;
}
void MTIMER1_SetOCR1A(u16 A_u16Value)
{
	OCR1A = A_u16Value;
}
void MTIMER1_SetOCR1B(u16 A_u16Value)
{
	OCR1B = A_u16Value;
}
void MTIMER1_SetICR1(u16 A_u16Value)
{
	ICR1 = A_u16Value;
}
void MTIMER1_SetTCNT1(u16 A_u16Value)
{
	TCNT1 = A_u16Value;
}
void MTimer1_InputCpetureEdge(EDGE_E A_Edge)
{
	if(FALLING_EDGE_ICU ==A_Edge)
	{
		CLR_BIT(TCCR1B,ICES1);
	}
	else if(RISING_EDGE_ICU ==A_Edge)
	{
		SET_BIT(TCCR1B,ICES1);
	}
}
void MTIMER1_OVF_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,TOIE1);
}
void MTIMER1_OCMA_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE1A);
}
void MTIMER1_OCMB_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,OCIE1B);
}
void MTIMER1_ICU_Interrupt_Enable(void)
{
	SET_BIT(TIMSK,TICIE1);
}
void MTIMER1_OVF_Interrupt_Disable(void)
{
	CLR_BIT(TIMSK,TOIE1);
}
void MTIMER1_OCMA_Interrupt_Disable(void)
{
	CLR_BIT(TIMSK,OCIE1A);
}
void MTIMER1_OCMB_Interrupt_Disable(void)
{
	CLR_BIT(TIMSK,OCIE1B);
}
void MTIMER1_ICU_Interrupt_Disable(void)
{
	CLR_BIT(TIMSK,TICIE1);
}
/****************************************************************************************************/
/*******************************************    VECTORS   *******************************************/
/****************************************************************************************************/

void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(Timer0_CALLBACK_OVF != NULL)
	{
		Timer0_CALLBACK_OVF();
	}
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(Timer0_CALLBACK_CTC != NULL)
	{
		Timer0_CALLBACK_CTC();
	}
}
void __vector_9(void) __attribute__((signal));
void __vector_9(void)
{
	if( TIMER1_CALLBACK_OVF!= NULL)
	{
		TIMER1_CALLBACK_OVF();
	}
}
void __vector_8(void) __attribute__((signal));
void __vector_8(void)
{
	if( TIMER1_CALLBACK_COMPB!= NULL)
	{
		TIMER1_CALLBACK_COMPB();
	}
}
void __vector_7(void) __attribute__((signal));
void __vector_7(void)
{
	if( TIMER1_CALLBACK_COMPA!= NULL)
		{
		TIMER1_CALLBACK_COMPA();
		}
}
void __vector_6(void) __attribute__((signal));
void __vector_6(void)
{
	if( TIMER1_CALLBACK_ICU!= NULL)
		{
			TIMER1_CALLBACK_ICU();
		}
}
