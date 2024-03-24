/********************************************/
/*** Author : ABDALLAH NABIL            *****/
/*** Description: servo_program.c        ****/
/*** Date: Mar 23, 2024                   ***/
/********************************************/
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include "../Include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/Timer/TIMER_interface.h"


void HSERVO_angel(u16 A_angel)
{

	if(A_angel==0)
	{
		MTIMER1_SetOCR1B(500);
	}
	else if(A_angel==90)
	{
		MTIMER1_SetOCR1B(1450);
	}
	else if(A_angel==180)
	{
		MTIMER1_SetOCR1B(2450);
	}
	else
	{
		MTIMER1_SetOCR1B(0);
	}
}
