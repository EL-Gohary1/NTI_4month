
#include "7_SEGMULTI4_config.h"
#include "7_SEGMULTI4_interface.h"
#include "DIO_interface.h"




void SEVENSEGMENT_vSevenSegmentinit(void)
{
	DIO_WritePin(SEVENSEGMENT1_ENABLE,LOW);
	DIO_WritePin(SEVENSEGMENT2_ENABLE,LOW);
	DIO_WritePin(SEVENSEGMENT3_ENABLE,LOW);
	DIO_WritePin(SEVENSEGMENT4_ENABLE,LOW);

}
void SEVENSEGMENT_vWrite_In_One_SEVENSEGMENT(u8 local_u8number)
{
	
	if (local_u8number<=9)
	{
		#if(CONFIGDECODER==DECODER)
		DIO_WritePin(A,READ_BIT(local_u8number,0));
		DIO_WritePin(B,READ_BIT(local_u8number,1));
		DIO_WritePin(C,READ_BIT(local_u8number,2));
		DIO_WritePin(D,READ_BIT(local_u8number,3));
		#else 
		u8 SegNumbers[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};
		switch(local_u8number)
		{
			case 0:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[0]);
			break;
			case 1:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[1]);
			break;
			case 2:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[2]);
			break;
			case 3:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[3]);
			break;
			case 4:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[4]);
			break;
			case 5:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[5]);
			break;
			case 6:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[6]);
			break;
			case 7:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[7]);
			break;
			case 8:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[8]);
			break;
			case 9:
			DIO_WritePort(SEVENSEGMENT_PORT,SegNumbers[9]);
			break;
		}
		
		#endif
	}
	else
	{
		
	}
}

void SEVENSEGMENT_vWrite_In_Four_SevenSegment(u16 local_u16number)
{
	DIO_WritePin(SEVENSEGMENT1_ENABLE,LOW);
	DIO_WritePin(SEVENSEGMENT2_ENABLE,HIGH);
	DIO_WritePin(SEVENSEGMENT3_ENABLE,HIGH);
	DIO_WritePin(SEVENSEGMENT4_ENABLE,HIGH);
	SEVENSEGMENT_vWrite_In_One_SEVENSEGMENT(local_u16number%10);
	_delay_ms(1);
	DIO_WritePin(SEVENSEGMENT1_ENABLE,HIGH);
	DIO_WritePin(SEVENSEGMENT2_ENABLE,LOW);
	DIO_WritePin(SEVENSEGMENT3_ENABLE,HIGH);
	DIO_WritePin(SEVENSEGMENT4_ENABLE,HIGH);
	SEVENSEGMENT_vWrite_In_One_SEVENSEGMENT((local_u16number/10)%10);
	_delay_ms(1);
	DIO_WritePin(SEVENSEGMENT1_ENABLE,HIGH);
	DIO_WritePin(SEVENSEGMENT2_ENABLE,HIGH);
	DIO_WritePin(SEVENSEGMENT3_ENABLE,LOW);
	DIO_WritePin(SEVENSEGMENT4_ENABLE,HIGH);
	SEVENSEGMENT_vWrite_In_One_SEVENSEGMENT((local_u16number/100)%10);
	_delay_ms(1);
	DIO_WritePin(SEVENSEGMENT1_ENABLE,HIGH);
	DIO_WritePin(SEVENSEGMENT2_ENABLE,HIGH);
	DIO_WritePin(SEVENSEGMENT3_ENABLE,HIGH);
	DIO_WritePin(SEVENSEGMENT4_ENABLE,LOW);
	SEVENSEGMENT_vWrite_In_One_SEVENSEGMENT((local_u16number/1000)%10);
	_delay_ms(1);
	
	
}
