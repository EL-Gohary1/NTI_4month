

 /***************************************************************
       NAME    :Spi_program.h
	   create  :3/5/2024 9:25:15 AM
	   version :_v1_
	   Author  :mahmoud elgohary
****************************************************************/

#include "Spi_interface.h"
#include "Spi_private.h"
#include "DIO_interface.h"

void SPI_voidInit(SPI_Mode_t Copy_enumMode)
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

void SPI_voidTransieveBlocking(u8 Copy_u8TxData,u8* Copy_pu8RxData)
{
	if(Copy_pu8RxData!=NULLPTR)
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


void SPI_voidTransieveNoBlocking(u8 Copy_u8TxData)
{
	//write data
	SPI_REGS->SPDR=Copy_u8TxData;
}


static volatile u8 SPI_u8RxData;


extern volatile const u8* const SPI_pu8RxData=&SPI_u8RxData;



void SPI_voidEnableInterrupt(void)
{
	SET_BIT(SPI_REGS->SPCR,SPIE);
}

void SPI_voidDisableInterrupt(void)
{
	CLR_BIT(SPI_REGS->SPCR,SPIE);
}

static void SPI_voidResieveNoBlocking(void)
{
	SPI_u8RxData=SPI_REGS->SPDR;
}

/****************************Pointer to functions to be assigned to ISR*********************************/
static void (*SPI_FPtrUser)(void)=NULLPTR;
/********************************************************************************************/

/************************************Call back functions*********************************************/
void SPI_voidSetCallBack(void(*Copy_FPtrUser)(void))
{
	SPI_FPtrUser=Copy_FPtrUser;
}
/*******************************************ISR*************************************************/
ISR(SPI_STC_vect)
{
	SPI_voidResieveNoBlocking();
	if(SPI_FPtrUser!=NULLPTR)
    {
		SPI_FPtrUser();
	}
}
/********************************************************************************************/

