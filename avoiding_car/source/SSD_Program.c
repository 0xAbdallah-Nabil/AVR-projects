/********************************************/
/*** Author : ABDALLAH NABIL            *****/
/*** Description: SSD_program.c          ****/
/*** Date: 27/9/2023                      ***/
/********************************************/


// Include LIB
#include "../Include/LIB/STD_TYPES.h"
#include "../Include/LIB/BIT_MATH.h"
#include <util/delay.h>

// Include DIO
#include "../Include/MCAL/DIO/DIO_Interface.h"

// Include SSD
#include "../Include/HAL/SSD/SSD_Interface.h"
#include "../Include/HAL/SSD/SSD_Private.h"
#include "../Include/HAL/SSD/SSD_Cfg.h"

	void HSSD_voidDisplayNumber(u8 A_u8port,u8 A_u8Number)
	{
		//MDIO_voidSetPortDirection(A_u8port,PORT_OUTPUT);
		switch(A_u8Number)
		{
		case 0: MDIO_voidSetPortValue(A_u8port,ZERO);
			break;
		case 1: MDIO_voidSetPortValue(A_u8port,ONE);
			break;
		case 2: MDIO_voidSetPortValue(A_u8port,TWO);
			break;
		case 3: MDIO_voidSetPortValue(A_u8port,THREE);
			break;
		case 4: MDIO_voidSetPortValue(A_u8port,FOUR);
			break;
		case 5: MDIO_voidSetPortValue(A_u8port,FIVE);
			break;
		case 6: MDIO_voidSetPortValue(A_u8port,SIX);
			break;
		case 7: MDIO_voidSetPortValue(A_u8port,SEVEN);
			break;
		case 8: MDIO_voidSetPortValue(A_u8port,EIGHT);
			break;
		case 9: MDIO_voidSetPortValue(A_u8port,NINE);
			break;
		default:
			break;

		}
	}
	void HSSD_voidDisplayNumbersAscending(u8 A_u8port, u16 A_u16delay)
	{
		u8 _7_segmant[]={ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};
		//MDIO_voidSetPortDirection(A_u8port,PORT_OUTPUT);
		for( u8 i=0 ;i<10;i++)
		{
			MDIO_voidSetPortValue(A_u8port,_7_segmant[i]);
			_delay_ms(A_u16delay);
		}
	}
