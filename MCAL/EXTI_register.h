


/***************************************************************
       NAME    :EXTI_register.h
	   create  :03/03/2024 1:24:36 PM
	   version :_v1_
	   Author  :mahmoud elgohary
****************************************************************/

#ifndef  _EXTI_REGISTER_H_
#define  _EXTI_REGISTER_H_

#include "Utils.h"
#include "StdType.h"

#define  MCUCR_REG    (*(volatile u8 *)0x55)
#define  ISC00     0
#define  ISC01     1
#define  ISC10     2
#define  ISC11     3

#define  MCUCSR_REG   (*(volatile u8 *)0x54)
#define  ISC2      6

#define  GICR_REG     (*(volatile u8 *)0x5B)
#define  INT0     6
#define  INT1     7
#define  INT2     5

#define  GIFR_REG     (*(volatile u8 *)0x5A)
#define  INTF0    6
#define  INTF1    7
#define  INTF2    5


#endif

