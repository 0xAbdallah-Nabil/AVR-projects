/********************************************/
/*** Author : ABDALLAH NABIL ****************/
/*** Description: ultrasonic_interface.c ******/
/*** Date: 20/3/2024             ************/
/********************************************/

#ifndef INCLUDE_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_
#define INCLUDE_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_


void HULTRASONIC_init();
u64 HULTRASONIC_GET_Distance();
void ISR_ICU(void);
void ISR_OVF(void);


#endif /* INCLUDE_HAL_ULTRASONIC_ULTRASONIC_INTERFACE_H_ */
