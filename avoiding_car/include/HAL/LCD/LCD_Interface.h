/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: LCD_Interface.h    ********/
/*** Date: Mar 23, 2024          ************/
/********************************************/
#ifndef INCLUDE_HAL_LCD_LCD_INTERFACE_H_
#define INCLUDE_HAL_LCD_LCD_INTERFACE_H_
typedef enum{
	LCD_ROW1=1,
	LCD_ROW2
}LCD_ROW_E;
typedef enum
{
	LCD_COL1=1,
	LCD_COL2,
	LCD_COL3,
	LCD_COL4,
	LCD_COL5,
	LCD_COL6,
	LCD_COL7,
	LCD_COL8,
	LCD_COL9,
	LCD_COL10,
	LCD_COL11,
	LCD_COL12,
	LCD_COL13,
	LCD_COL14,
	LCD_COL15,
	LCD_COL16
}LCD_COL_E;
typedef enum
{
	LCD_PATTERN0,
	LCD_PATTERN1,
	LCD_PATTERN2,
	LCD_PATTERN3,
	LCD_PATTERN4,
	LCD_PATTERN5,
	LCD_PATTERN6,
	LCD_PATTERN7
}LCD_PATTERN_E;

void HLCD_void_GOTO_POS(LCD_ROW_E A_ROW,LCD_COL_E A_COL);
void HLCD_void_SEND_COMMEND(u8 A_COMAND);
void HLCD_void_SEND_DATA(u8 A_DATA);
void HLCD_void_init(void);
void HLCD_void_Clear_Display(void);
void HLCD_void_DISPLAY_NUMBER(u32 A_number);
void HLCD_void_DISPLAY_STRING( u8 *A_string);
void HLCD_void_LEFT_SHIFT();
void HLCD_void_RIGHT_SHIFT();
void HLCD_void_send_spicial_sympol(u8 *A_sympol_array,LCD_PATTERN_E A_pattern_num,LCD_ROW_E A_ROW,LCD_COL_E A_COL);

#endif /* INCLUDE_HAL_LCD_LCD_INTERFACE_H_ */
