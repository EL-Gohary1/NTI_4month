
/*
 * Spi_private.h
 *
 * Created: 3/5/2024 9:26:59 AM
 *  Author: lenovo
 */ 

#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

typedef struct{
	volatile u8 SPCR;
	volatile u8	SPSR;
	volatile u8	SPDR;
	
}SPI_t;

#define SPI_REGS  ((volatile SPI_t *)0x2d)

#define SPIE  7 
#define SPE   6
#define DORD  5 
#define MSTR  4
#define CPOL  3
#define CPHA  2
#define SPR1  1
#define SPR0  0


#define SPIF   7
#define WCOL   6
#define SPI2X  0


#endif