/*
 * _7_SEGMULTI4_config.h
 *
 * Created: 3/1/2024 2:26:20 PM
 *  Author: lenovo
 */ 
#ifndef _7_SEGMULTI4_config_H
#define _7_SEGMULTI4_config_H



/*
DECODER
NODECODER
*/
#define  CONFIGDECODER    DECODER
//IF THERE IS DECODER
#define A    PINB0
#define B    PINB1
#define C    PINB2
#define D    PINB4
// IF NOT
#define SEVENSEGMENT_PORT    PORTB



#define SEVENSEGMENT1_ENABLE   PINA3
#define SEVENSEGMENT2_ENABLE   PINA2
#define SEVENSEGMENT3_ENABLE   PINB5
#define SEVENSEGMENT4_ENABLE   PINB6


/*
COMMON_ANODE
COMMON_CATHODE
*/
#define SEVENSEGMENT_COMMON   COMMON_ANODE

#define  DECODER       1
#define  NODECODER     0

#define COMMON_ANODE    1
#define COMMON_CATHODE  0







#endif
