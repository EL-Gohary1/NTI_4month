/*
 * TempFilter.h
 *
 * Created: 3/7/2024 12:05:30 PM
 *  Author: lenovo
 */ 


#ifndef TEMPFILTER_H_
#define TEMPFILTER_H_


#include "Utils.h"
#include "StdType.h"
/*extern in your app
u8 TempFilter_MeanTem
*/
void TempFilter_vRunnable(void);

void TempFilter_vInit(void);

void TempFilter_u8GetFilteredValue(void);


#endif /* TEMPFILTER_H_ */