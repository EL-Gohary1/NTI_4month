
/*
 * EXTI_interface.h
 *
 * Created: 3/3/2024 1:25:25 PM
 *  Author: lenovo
 */ 

#ifndef  EXTI_INTERFACE_H_
#define  EXTI_INTERFACE_H_

#include "Utils.h"
#include "StdType.h" 

typedef enum{
	EX_INT0=0,
	EX_INT1,
	EX_INT2
}EXTINT_Source_t;


typedef enum{
	LOW_LEVEL=0,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE
}EXTI_senseControl_t;

void EXINT_voidEnable(EXTINT_Source_t copy_enum_InterruptSrc, EXTI_senseControl_t copy_enum_SenseControl);


void EXINT_voidDisable(EXTINT_Source_t copy_enum_InterruptSrc);


#endif
