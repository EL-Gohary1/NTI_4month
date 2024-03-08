/*
 * TempFilter.c
 *
 * Created: 3/7/2024 12:05:07 PM
 *  Author: lenovo
 */ 
#include "TempFilter.h"
#include "LM35.h"

static u8 TempFilter_Arru8Temp[10]={0};
u8 TempFilter_MeanTemp=30;

void TempFilter_vRunnable(void)
{
	for (int i=0;i<10;i++)
	{
		TempFilter_Arru8Temp[i]=LM35_u8ReadTemp(PVref_AVCC,5000);
	}
}

void TempFilter_vInit(void)
{
	
}

void TempFilter_u8GetFilteredValue(void)
{
	u16 Local_u16SumTemp=0;
	for (int i=0;i<10;i++)
	{
		Local_u16SumTemp+=TempFilter_Arru8Temp[i];
	}
	TempFilter_MeanTemp = Local_u16SumTemp/10;
}

