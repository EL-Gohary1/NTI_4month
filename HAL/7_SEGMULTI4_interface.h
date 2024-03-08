/*
 * _7_SEGMULTI4_interface.h
 *
 * Created: 3/1/2024 12:56:04 PM
 *  Author: lenovo
 */ 
#ifndef _7_SEGMULTI4_
#define _7_SEGMULTI4_
#include "Utils.h"
#include "StdType.h"


#define  F_CPU 16000000
#include "util\delay.h"

#define SEVENSEGMENT1_ENABLE   PINA3
#define SEVENSEGMENT2_ENABLE   PINA2
#define SEVENSEGMENT3_ENABLE   PINB5
#define SEVENSEGMENT4_ENABLE   PINB6


void SEVENSEGMENT_vSevenSegmentinit(void);

void SEVENSEGMENT_vWrite_In_One_SEVENSEGMENT(u8 local_u8number);

void SEVENSEGMENT_vWrite_In_Four_SevenSegment(u16 local_u16number);
#endif
