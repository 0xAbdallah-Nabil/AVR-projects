/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: TIMER_private.h    ********/
/*** Date: 20/3/2024             ************/
/********************************************/
#ifndef INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_
#define INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_

#define TCCR0 		(*(volatile u8 *)0x53)
#define TCNT0 		(*(volatile u8 *)0x52)
#define OCR0  		(*(volatile u8 *)0x5C)
#define TIMSK 		(*(volatile u8 *)0x59)
#define TIFR  		(*(volatile u8 *)0x58)
#define TCCR1A 		(*(volatile u8 *)0x4F)
#define TCCR1B 		(*(volatile u8 *)0x4E)
#define TCNT1H 		(*(volatile u8 *)0x4D)
#define TCNT1L 		(*(volatile u8 *)0x4C)
#define TCNT1 		(*(volatile u16 *)0x4C)
#define OCR1A 		(*(volatile u16 *)0x4A)
#define OCR1B  		(*(volatile u16 *)0x48)
#define ICR1H  		(*(volatile u8 *)0x47)
#define ICR1L  		(*(volatile u8 *)0x46)
#define ICR1   		(*(volatile u16 *)0x46)

/***********to clear some bits***********/
#define TIMER_CLK_MASK 			0b11111000
#define TIMER0_CLK_OCR_MASK 	0b11001000
#define TIMER1_MODE_MASK_TCCR1A 0b00001100
#define TIMER1_MODE_MASK_TCCR1B 0b11000111


/*TCCR1A : Timer/Counter1 Control Register A*/
#define WGM10  		0
#define WGM11  		1
#define FOC1B  		2
#define FOC1A  		3
#define COM1B0 		4
#define COM1B1		5
#define COM1A0 		6
#define COM1A1 		7


/*TCCR1B : Timer/Counter1 Control Register B*/
#define CS10  		0
#define CS11  		1
#define CS12  		2
#define WGM12  		3
#define WGM13 		4
#define ____		5
#define ICES1 		6
#define ICNC1 		7


/*TIMSK : Timer Interrupt Mask Register*/
#define TOIE0  		0
#define OCIE0  		1
#define TOIE1  		2
#define OCIE1B  	3
#define OCIE1A 		4
#define TICIE1		5
#define TOIE2 		6
#define OCIE2 		7


/*TIFR : Timer Interrupt Flag Register*/
#define TOV0  		0
#define OCF0  		1
#define TOV1  		2
#define OCF1B  		3
#define OCF1A 		4
#define ICF1		5
#define TOV2 		6
#define OCF2 		7


#endif /* INCLUDE_MCAL_TIMER_TIMER_PRIVATE_H_ */
