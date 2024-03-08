
/*
 * Spi_program.c
 *
 * Created: 3/5/2024 9:25:15 AM
 *  Author: lenovo
 */ 
#include "Spi_interface.h"
#include "Spi_private.h"

void SPI_vInit(SPI_Mode_t Copy_enumMode)
{
	
   if(Copy_enumMode==MASTER)
   {
	    //DISABLE INTERRUPT
	   	CLR_BIT(SPI_REGS->SPCR,SPIE);
	    //DATA ORDER LSB
	    SET_BIT(SPI_REGS->SPCR,DORD);
	    //MASTER
	    SET_BIT(SPI_REGS->SPCR,MSTR);
	    //POLARITY
	    CLR_BIT(SPI_REGS->SPCR,CPOL);
	    //PHASE
	    CLR_BIT(SPI_REGS->SPCR,CPHA);
	    //PRESCALLER
    	SET_BIT(SPI_REGS->SPCR,SPR0);
    	SET_BIT(SPI_REGS->SPCR,SPR1);
    	CLR_BIT(SPI_REGS->SPSR,SPI2X);
    	//ENABLE SPI
    	SET_BIT(SPI_REGS->SPCR,SPE);
    }
    else
    {
    	//DISABLE INTERRUPT
    	CLR_BIT(SPI_REGS->SPCR,SPIE);
    	//DATA ORDER LSB
    	SET_BIT(SPI_REGS->SPCR,DORD);
    	//SLAVE
    	CLR_BIT(SPI_REGS->SPCR,MSTR);
    	//POLARITY
    	CLR_BIT(SPI_REGS->SPCR,CPOL);
    	//PHASE 
    	CLR_BIT(SPI_REGS->SPCR,CPHA);
    	//ENABLE SPI
    	SET_BIT(SPI_REGS->SPCR,SPE);
    }
}

void SPI_vTransieve(u8 Copy_u8TxData,u8* Copy_pu8RxData)
{
	if(Copy_pu8RxData!=NULL)
	{
		SPI_REGS->SPDR=Copy_u8TxData;
		while(READ_BIT(SPI_REGS->SPSR,SPIF)==0);
		*Copy_pu8RxData=SPI_REGS->SPDR;
	}
	else
	{
		//RETURN ERROR
	}
}
	
	