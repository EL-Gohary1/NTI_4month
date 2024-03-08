#include "DIO_interface.h"
#include "ADC_interface.h"
#include "EXTI_interface.h"
#include "Spi_interface.h"

#include "LCD_interface.h"
#include "7_SEGMULTI4_interface.h"
#include "KEYPAD.h"

#include "Vector_Table.h"
#include "GI_interface.h"

#include "Utils.h"
#include "StdType.h"

int main(void)
{
	u8 data=0;
	DIO_Init();
	SPI_vInit(MASTER);
	DIO_WritePin(PINA4,LOW);
    while(1)
    {
	    SPI_vTransieve(9,&data);
		if (data==2)
		{
			DIO_WritePin(PINA4,HIGH);
		}

    }
}