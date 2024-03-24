/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: GI_program.c            ***/
/*** Date: 6/10/2023             ************/
/********************************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/global_interrrupt/GI_cfg.h"
#include "../include/MCAL/global_interrrupt/GI_interface.h"
#include "../include/MCAL/global_interrrupt/GI_private.h"
void MGI_enable_GI(void)
{
	SET_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}
void MGI_disable_GI(void)
{
	CLR_BIT(SREG,GLOBAL_INTERRUPT_ENABLE_BIT);
}
