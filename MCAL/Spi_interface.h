
/*
 * Spi_interface.h
 *
 * Created: 3/5/2024 9:24:03 AM
 *  Author: lenovo
 */ 

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_
#include "Utils.h"
#include "StdType.h"
typedef enum{
	MASTER,
	SLAVE
}SPI_Mode_t;

void SPI_vInit(SPI_Mode_t Copy_enumMode);

void SPI_vTransieve(u8 Copy_u8TxData,u8* Copy_pu8RxData);


#endif