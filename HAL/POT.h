/*
 * POT.h
 *
 * Created: 3/7/2024 9:49:03 AM
 *  Author: lenovo
 */ 
#ifndef POT_H_
#define POT_H_
#include "Utils.h"
#include "StdType.h"

/*Select Channel of POT
ADC0
ADC1
ADC2
ADC3
ADC4
ADC5
ADC6
ADC7
*/
#define POT_CH   ADC1

typedef enum{
	PVref_AREV,
	PVref_AVCC,
	PVref_265
}POT_Vref_t;


u16 POT_u16ReadVoltmv(POT_Vref_t copy_enumVref, u16 Copy_u16VoltRefmv);

#endif
