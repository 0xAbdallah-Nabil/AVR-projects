/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: motor_program.c     *******/
/*** Date: Mar 23, 2024          ************/
/********************************************/

#include "../include/HAL/motor/Hmotor_interface.h"
#include "../include/MCAL/DIO/DIO_Interface.h"
void Forward(void) {
	MDIO_voidSetPinValue(DIO_PORTB, PIN0, DIO_SET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN1, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN2, DIO_SET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN3, DIO_RESET);
}
void Left(void) {
	MDIO_voidSetPinValue(DIO_PORTB, PIN0, DIO_SET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN1, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN2, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN3, DIO_RESET);
}
void Right(void) {

	MDIO_voidSetPinValue(DIO_PORTB, PIN0, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN1, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN2, DIO_SET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN3, DIO_RESET);
}
void stop(void) {
	MDIO_voidSetPinValue(DIO_PORTB, PIN0, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN1, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN2, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN3, DIO_RESET);
}
void Backward(void) {
	MDIO_voidSetPinValue(DIO_PORTB, PIN0, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN1, DIO_SET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN2, DIO_RESET);
	MDIO_voidSetPinValue(DIO_PORTB, PIN3, DIO_SET);
}
