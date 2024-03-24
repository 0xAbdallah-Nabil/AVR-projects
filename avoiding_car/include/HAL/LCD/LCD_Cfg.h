/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: LCD_Cfg.h          ********/
/*** Date: Mar 23, 2024          ************/
/********************************************/
#ifndef INCLUDE_HAL_LCD_LCD_CFG_H_
#define INCLUDE_HAL_LCD_LCD_CFG_H_


#define LCD_DATA_PORT DIO_PORTA
#define LCD_CTRL_PORT DIO_PORTC

#define LCD_RS_PIN PIN0
#define LCD_RW_PIN PIN1
#define LCD_E_PIN  PIN2


/*
 *  1 line---> 0
 *  2 lines--->1
 * */
#define number_of_line_display 1



/*
 * 5x11 type ->1
 * 5x8 type ->0
 * */
#define font_type_display 1





/*
 *	0 --> Right to Left
 *  1 --> Left to Right
 * */
#define DISPLAY_DIRECTION 1




/*
 *  0 --> OFF
 *  1 --> ON
 */
#define SHIFT_ENABLE 0




/*
 *  0 --> OFF
 *  1 --> ON
 */
#define DISPLAY_STATUS 1




/*
 *  0 --> OFF
 *  1 --> ON
 */
#define CURSOR_DISPLAY 0





/*
 *  0 --> OFF
 *  1 --> ON
 */
#define CURSOR_BLINK 0



#endif /* INCLUDE_HAL_LCD_LCD_CFG_H_ */
