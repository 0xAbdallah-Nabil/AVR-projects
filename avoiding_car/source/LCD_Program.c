/********************************************/
/*** Author : ABDALLAH NABIL            *****/
/*** Description: LCD_Program.c          ****/
/*** Date: Mar 23, 2024                   ***/
/********************************************/

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/LCD/LCD_Cfg.h"
#include "../include/HAL/LCD/LCD_Private.h"
#include  <util/delay.h>
#include  <stdlib.h>

void HLCD_void_SEND_COMMEND(u8 A_COMAND)
{
	/*to send command RS->0 RW->0*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_RESET);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_RESET);
	/* send command*/
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_COMAND);
	/*E pulse*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_RESET);
}
void HLCD_void_SEND_DATA(u8 A_DATA)
{
	/*to send command RS->1 RW->0*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_SET);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_RESET);
	/* send data*/
	MDIO_voidSetPortValue(LCD_DATA_PORT,A_DATA);
	/*E pulse*/
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_SET);
	_delay_ms(2);
	MDIO_voidSetPinValue(LCD_CTRL_PORT,LCD_E_PIN,DIO_RESET);
}
void HLCD_void_init(void)
{
/* 8bit mode*/

	/*wait for more than 30micro second after VDD rises to 4.5v*/
	_delay_ms(1);
	HLCD_void_SEND_COMMEND(FUNCTION_SET);
	_delay_ms(1);
	HLCD_void_SEND_COMMEND(DISPLAY_ON_OFF_CONTROL);
	_delay_ms(1);
	HLCD_void_SEND_COMMEND(DISPLAY_CLEAR);
	_delay_ms(2);
	HLCD_void_SEND_COMMEND(ENTRY_MODE_SET);


}
void HLCD_void_Clear_Display(void)
{
	// Display Clear Command then wait for more than 1.53ms
	HLCD_void_SEND_COMMEND(DISPLAY_CLEAR);
	_delay_ms(2);
}
void HLCD_void_DISPLAY_STRING( u8 A_string[])
{
	while(*A_string !='\0')
	{
		HLCD_void_SEND_DATA(*A_string);
		A_string++;
		//_delay_ms(200); //for keyboard effiction
	}
}
void HLCD_void_DISPLAY_NUMBER(u32 A_number)
{
	u32 number[sizeof(u32)*8+1] ;
	itoa(A_number,number,10);
	HLCD_void_DISPLAY_STRING(number);
}
/*
 * void HLCD_void_DISPLAY_NUMBER(u32 A_number)
{
	u32 local_num=1;
	if(A_number==0)
	{
		HLCD_void_SEND_DATA('0');
	}
	while(A_number!=0)
	{
		local_num=(local_num * 10) + (A_number % 10);
		A_number=A_number/10;
	}
	while(local_num!=1)
	{
		HLCD_void_SEND_DATA((local_num %10)+48);
		local_num/=10;
	}

}*/
void HLCD_void_GOTO_POS(LCD_ROW_E A_ROW,LCD_COL_E A_COL)
{
	switch(A_ROW)
	{
	case LCD_ROW1:HLCD_void_SEND_COMMEND(ROW1_BASS_ADD+A_COL);
		break;
	case LCD_ROW2:HLCD_void_SEND_COMMEND(ROW2_BASS_ADD+A_COL);
		break;
	default:
		break;
	}

}
void HLCD_void_LEFT_SHIFT()
{
	HLCD_void_SEND_COMMEND(0x18);
}
void HLCD_void_RIGHT_SHIFT()
{
	HLCD_void_SEND_COMMEND(0x1C);
}
 void HLCD_void_send_spicial_sympol(u8 *A_sympol_array,LCD_PATTERN_E A_pattern_num,LCD_ROW_E A_ROW,LCD_COL_E A_COL)
 {
	 u8 locAL_CGRAM_ADDRESS;
	 // CALCULATE CGRAM ADDRESS

	 /* we have only 8 pattern*/
	 locAL_CGRAM_ADDRESS=A_pattern_num * 8 ;
	 SET_BIT(locAL_CGRAM_ADDRESS,6);
	 // send pattern array byte by byte

	 /*pattern is 5*8 pixel (8) is the number of byte and (5)is the number on bits we use from each byte */
	 HLCD_void_SEND_COMMEND(locAL_CGRAM_ADDRESS);
	 for( u8 i=0;i<8;i++)
	 {
		 HLCD_void_SEND_DATA(A_sympol_array[i]);
	 }
	 // set DDRAM address
	 HLCD_void_GOTO_POS(A_ROW,A_COL);
	 HLCD_void_SEND_DATA(A_pattern_num);

 }
