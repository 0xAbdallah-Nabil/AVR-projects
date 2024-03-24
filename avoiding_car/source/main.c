/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: calculator.c       ********/
/*** Date: Mar 23, 2024          ************/
/********************************************/

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_TYPES.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
#include "../include/MCAL/extern_interrupt/EXTI_interface.h"
#include "../include/MCAL/global_interrrupt/GI_interface.h"
#include "../include/MCAL/Timer/TIMER_interface.h"
#include "../include/MCAL/Timer/TIMER_private.h"
#include "../include/HAL/LCD/LCD_Interface.h"
#include "../include/HAL/motor/Hmotor_interface.h"
#include "../include/HAL/ultrasonic/ultrasonic_interface.h"
#include "../include/HAL/servo/servo_interface.h"
#include <util/delay.h>
#include <stdlib.h>
#define F_CPU  8000000UL

#define Low_Distance  40


int main() {
	MDIO_voidInit();
	HLCD_void_init();
	MGI_enable_GI();
	HULTRASONIC_init();

	u64 Distance;
	u64 Left_Distance,Right_Distance;

	u8 string[10] = { 0 };

	while (1) {
		HSERVO_angel(90);
		Distance = HULTRASONIC_GET_Distance();
		HLCD_void_GOTO_POS(2, 1);
		HLCD_void_DISPLAY_STRING("dist= ");
		dtostrf(Distance, 2, 2, string);
		HLCD_void_DISPLAY_STRING(string);
		HLCD_void_DISPLAY_STRING(" cm   ");
		if(Distance <Low_Distance)
		{
			stop();
			HLCD_void_GOTO_POS(1, 1);
			HLCD_void_DISPLAY_STRING("Backward     ");
			Backward();
			_delay_ms(500);
			stop();
			_delay_ms(1000);
			HSERVO_angel(180);
			_delay_ms(500);
			Left_Distance = HULTRASONIC_GET_Distance();
			_delay_ms(500);

			HSERVO_angel(0);
			_delay_ms(500);
			Right_Distance = HULTRASONIC_GET_Distance();
			_delay_ms(500);

			HSERVO_angel(90);
			if(Left_Distance>Right_Distance)
			{
				HLCD_void_GOTO_POS(1, 1);
				HLCD_void_DISPLAY_STRING("Left     ");
				Left();
				_delay_ms(750);
			}
			else if(Left_Distance<Right_Distance)
			{
				HLCD_void_GOTO_POS(1, 1);
				HLCD_void_DISPLAY_STRING("Right     ");
				Right();
				_delay_ms(750);
			}
		}
		else
		{
			HLCD_void_GOTO_POS(1, 1);
			HLCD_void_DISPLAY_STRING("Forward    ");
			Forward();
		}




	}
	return 0;
}

