/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: TIMER_cfg.hh       ********/
/*** Date: 20/3/2024             ************/
/********************************************/
#ifndef INCLUDE_MCAL_TIMER_TIMER_CFG_H_
#define INCLUDE_MCAL_TIMER_TIMER_CFG_H_


/****************************************************************************************************/
/************************************** THIS CONFIGRATION FOR TIMER0*********************************/
/****************************************************************************************************/
/*
 * FOR CLK PRESCALER CONFIGURATION
 * 000 No clock source (Timer/Counter stopped).
 * 001 CLK/(No PRESCALER)
 * 010 CLK/8 (From PRESCALER)
 * 011 CLK/64 (From PRESCALER)
 * 100 CLK/256 (From PRESCALER)
 * 101 CLK/1024 (From PRESCALER)
 * 110 External clock source on T0 pin. Clock on falling edge.
 * 111 External clock source on T0 pin. Clock on rising edge.
 * */

/* FOR CTC MODE AND NORMAL MODE (OC0 CONFIGURATION)
 * 0 0 Normal port operation, OC0 disconnected.
 * 0 1 Toggle OC0 on compare match
 * 1 0 Clear OC0 on compare match
 * 1 1 Set OC0 on compare match*/

/* FOR FAST PWM MODE (OC0 CONFIGURATION)
 * 0 0 Normal port operation, OC0 disconnected.
 * 0 1 Reserved
 * 1 0 Clear OC0 on compare match, set OC0 at BOTTOM,
 * 1 1 Set OC0 on compare match, clear OC0 at BOTTOM,
*/
#define TIMER0_CLK  0b101 // divided by 8
#define OC0_MODE 2
#define OCR0_value 156

#define NORMAL_MODE			0
#define PHASE_CORRECT_MODE	1
#define CTC_MODE			2
#define FAST_PWM_MODE		3

#define TIMER0_MODE FAST_PWM_MODE


#endif /* INCLUDE_MCAL_TIMER_TIMER_CFG_H_ */
