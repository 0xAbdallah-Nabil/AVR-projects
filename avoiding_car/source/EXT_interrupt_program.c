/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: EXT_interrupt_program.c ***/
/*** Date: 6/10/2023             ************/
/********************************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/extern_interrupt/EXTI_cfg.h"
#include "../include/MCAL/extern_interrupt/EXTI_interface.h"
#include "../include/MCAL/extern_interrupt/EXTI_private.h"

void (*callback_EXTI0)(void)=NULL;
void (*callback_EXTI1)(void)=NULL;;
void (*callback_EXTI2)(void)=NULL;
void MEXTI_configration(EXTI_e EXTI,state_e state)
{
	if(EXTI<=EXTI2 && state<=RISING_EDGE)
	{
		switch(EXTI)
		{
		case EXTI0:

			MCUCR&=~(Interrupt_Sense_Control_masked);
			MCUCR |=(state);
			break;
		case EXTI1:
			MCUCR&=~(Interrupt_Sense_Control_masked<<Interrupt_Sense_Control_shift);
			MCUCR |=(state<<Interrupt_Sense_Control_shift);
			break;
		case EXTI2:
			switch(state)
			{
			case FALLING_EDGE:
				CLR_BIT(MCUCSR,Interrupt_sense_control_EXTI2_bin);
				break;
			case RISING_EDGE:
				SET_BIT(MCUCSR,Interrupt_sense_control_EXTI2_bin);
				break;
			default:
				break;
			}

		}
	}
}
void MEXTI_void_enaple_PIE(EXTI_e EXTI)
{
	if(EXTI<=EXTI2 )
		{
			switch(EXTI)
			{
			case EXTI0:
				SET_BIT(GICR,External_Interrupt0_Enable_bin);
				break;
			case EXTI1:
				SET_BIT(GICR,External_Interrupt1_Enable_bin);
				break;
			case EXTI2:
				SET_BIT(GICR,External_Interrupt2_Enable_bin);
				break;
			default:
				break;
			}
		}
}
void MEXTI_void_disaple_PIE(EXTI_e EXTI)
{
	if(EXTI<=EXTI2)
	{
		switch(EXTI)
		{
		case EXTI0:
			CLR_BIT(GICR,External_Interrupt0_Enable_bin);
			break;
		case EXTI1:
			CLR_BIT(GICR,External_Interrupt1_Enable_bin);
			break;
		case EXTI2:
			CLR_BIT(GICR,External_Interrupt2_Enable_bin);
			break;
		default:
			break;
		}
	}
}
void MEXTI_void_RESET_PIF(EXTI_e EXTI)
{
	if(EXTI<=EXTI2)
	{
		switch(EXTI)
		{
		case EXTI0:
			SET_BIT(GIFR,External_Interrupt0_Enable_bin);
			break;
		case EXTI1:
			SET_BIT(GIFR,External_Interrupt1_Enable_bin);
			break;
		case EXTI2:
			SET_BIT(GICR,External_Interrupt2_Enable_bin);
			break;
		default:
			break;
		}
	}
}
void MEXTI_void_set_callback_func(EXTI_e EXTI,void (*func) (void))
{
	if(EXTI<=EXTI2 && func!=NULL)
	{
		switch(EXTI)
		{
		case EXTI0:
			if(func !=NULL)
			{
				callback_EXTI0=func;
			}
			break;
		case EXTI1:
			if(func !=NULL)
			{
				callback_EXTI1=func;
			}
			break;
		case EXTI2:
			if(func !=NULL)
			{
				callback_EXTI2=func;
			}
			break;
		default:
			break;
		}
	}
}
void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	callback_EXTI0();
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	callback_EXTI1();
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	callback_EXTI2();
}
