
/*
 * ADC_interface.h
 *
 * Created: 3/4/2024 11:09:25 AM
 *  Author: lenovo
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_
#include "StdType.h"
#include "Utils.h"


#define ADC_LEFT_ADJUST  0
#define ADC_RIGTH_ADJUST 1


typedef enum{
    Free_Running_mode=0,
	Analog_Comparator,
	External_Interrupt_Request_0,
	Timer_Counter0_Compare_Match,
	Timer_Counter0_Overflow,
	Timer_Counter_Compare_Match_B,
	Timer_Counter1_Overflow,
	Timer_Counter1_Capture_Event,
	  
}Trigger_Source_t;

typedef enum{
	ADC_Prescaler2=1,
	ADC_Prescaler4,
	ADC_Prescaler8,
	ADC_Prescaler16,
	ADC_Prescaler32,
	ADC_Prescaler64,
	ADC_Prescaler128,
}ADC_Prescaler_t;

typedef enum{
	Vref_AREV,
	Vref_AVCC,
	Vref_265
}ADC_Vref_t;


typedef enum{
	ADC0=0,
	ADC1,
	ADC2,
	ADC3,
	ADC4,
	ADC5,
	ADC6,
	ADC7,
	ALL_Channel
}ADC_Channel_t;

/*extern const u16* const ADC_pu16_ArrayReadFreeRunningModed;
                                                             - pointer to array of 8 element to read 8 channel 
                                                             - channel 0   in ADC_pu16_ArrayReadFreeRunningModed[0]
													         - channel 1   in ADC_pu16_ArrayReadFreeRunningModed[1]
                                                             - channel 2   in ADC_pu16_ArrayReadFreeRunningModed[2]
                                                             - channel 3   in ADC_pu16_ArrayReadFreeRunningModed[3]
                                                                to channel 7
*/
/*extern const u16* const ADC_pu16AutoTriggerRead; 
                                                      - pointer to u16 to read ADC in auto trigger mode
													  - *ADC_pu16AutoTriggerRead
*/

void ADC_vInit(ADC_Prescaler_t Copy_enumPrescaler, ADC_Vref_t Copy_enumVoltRef  );

u16 ADC_vReadDigitalValueSingleConversionBlocking(ADC_Channel_t Copy_enumChannel);

void ADC_vFreeRunningModeInit(void);

void ADC_vDisableAutoTrigger(void);

void ADC_vEnableAutoTrigger(Trigger_Source_t Copy_enumTriggermode,ADC_Channel_t Copy_enumChannel);  //should enable interrupt after use this function

void ADC_vEnableInterrupt(void);

void ADC_vDisableInterrupt(void);

void ADC_SetCallBack(void(*LocalPtr)(void));  //should enable interrupt after use this function

 void ADC_vFreeRunningModeORAutiTriggerInit(void);  //should enable interrupt after use this function

void ADC_vSetVoltReference(ADC_Vref_t copy_enumVref); //If these bits are changed during a conversion, the change will not go in effect until this conversion is complete

void ADC_vStartSingleConversionNoBlocking(ADC_Channel_t Copy_enumChannel);

void ADC_vEnableADC(void);

void ADC_vDisableADC(void);

#endif