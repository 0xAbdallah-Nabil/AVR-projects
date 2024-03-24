/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: ultrasonic_program.c ******/
/*** Date: 20/3/2024             ************/
/********************************************/

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/extern_interrupt/EXTI_interface.h"
#include "../include/MCAL/global_interrrupt/GI_interface.h"
#include "../include/MCAL/Timer/TIMER_interface.h"
#include "../include/MCAL/Timer/TIMER_private.h"
#include "../include/HAL/ultrasonic/ultrasonic_cfg.h"
#include "../include/HAL/ultrasonic/ultrasonic_interface.h"
#include "../include/HAL/ultrasonic/ultrasonic_private.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include <stdlib.h>
#include <util/delay.h>


static u8 Global_Flag,Global_OVF_Counts;
static u16 	Global_T1	,	Global_T2  ,Global_Ticks;
static u64 Global_Distance;
void HULTRASONIC_init()
{
	MTimer1_Init(TIMER1_PWM_FAST_MODE_OCR1A,OCRA1_DISCONNECTED,OCRB1_NON_INVERTING);
	MTIMER1_SetOCR1A(19999);
	MTimer1_SetCallBack_ICU(ISR_ICU);
	MTimer1_SetCallBack_OVF(ISR_OVF);
	MTIMER1_OVF_Interrupt_Enable();
	MTimer1_Start(PRESCALER_8);

}
u64 HULTRASONIC_GET_Distance()
{
		Global_Distance=0;
		Global_Ticks=0;
		Global_Flag=0;
		TCNT1=0;

		MTimer1_InputCpetureEdge(RISING_EDGE_ICU);
		MTIMER1_ICU_Interrupt_Enable();

		MDIO_voidSetPinValue(ultrasoinc_port,trig_pin,DIO_SET);
		_delay_us(15);
		MDIO_voidSetPinValue(ultrasoinc_port,trig_pin,DIO_RESET);

		while(Global_Flag<2);
		Global_Ticks=abs(Global_T2-Global_T1) + 0* ((u32) 19999*Global_OVF_Counts);

		Global_Distance=Global_Ticks/58;
		MTIMER1_ICU_Interrupt_Disable();
		return Global_Distance-1;
	/*
	 * why 58 ?
	 * D=V*T
	 * V=34300 CM/SEC
	 * T=(number_of_ticks *(1/FREQ))
	 * (1/FREQ)= 1 MICRO SEC;
	 * V= number_of_ticks* 0.01715 = number_of_ticks/58
	 */
}
void ISR_ICU(void)
{
	if(Global_Flag==0)
	{

		Global_T1=ICR1;
		Global_Flag=1;
		Global_OVF_Counts=0;
		MTimer1_InputCpetureEdge(FALLING_EDGE_ICU);

	}
	else
	{


		Global_T2=ICR1;
		Global_Flag=2;
		MTimer1_InputCpetureEdge(RISING_EDGE_ICU);
		MTIMER1_ICU_Interrupt_Disable();


	}

}
void ISR_OVF(void)
{

	Global_OVF_Counts++;
}

