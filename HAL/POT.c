/*
 * POT.c
 *
 * Created: 3/7/2024 9:48:43 AM
 *  Author: lenovo
 */ 
#include "ADC_interface.h"
#include "ADC_SERVICE.h"
#include "POT.h"

u16 POT_u16ReadVoltmv(POT_Vref_t copy_enumVref, u16 Copy_u16VoltRefmv)
{
	
	 return ADC_SERVICE_u16ReadVoltmv(POT_CH, copy_enumVref, Copy_u16VoltRefmv);
}

