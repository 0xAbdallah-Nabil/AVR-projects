/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: LCD_Private.h      ********/
/*** Date: Mar 23, 2024          ************/
/********************************************/
#ifndef INCLUDE_HAL_LCD_LCD_PRIVATE_H_
#define INCLUDE_HAL_LCD_LCD_PRIVATE_H_
/*8bit mode CFG	*/
#define done_care 0
#define FUNCTION_SET CONC_BIT(0,0,1,1,number_of_line_display,font_type_display,done_care,done_care)
#define DISPLAY_ON_OFF_CONTROL CONC_BIT(0,0,0,0,1,DISPLAY_STATUS,CURSOR_DISPLAY,CURSOR_BLINK)
#define DISPLAY_CLEAR 0x01
#define ENTRY_MODE_SET CONC_BIT(0,0,0,0,0,1,DISPLAY_DIRECTION,SHIFT_ENABLE)

#define ROW1_BASS_ADD 127
#define ROW2_BASS_ADD 191

#endif /* INCLUDE_HAL_LCD_LCD_PRIVATE_H_ */
