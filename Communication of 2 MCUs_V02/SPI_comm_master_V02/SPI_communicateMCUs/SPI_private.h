/*
 * SPI_private.h
 *
 * Created: 9/23/2021 1:31:05 PM
 *  Author: Farouk
 */ 


#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_

/* Register Definition */

#define SPSR	*((volatile uint8_t *)0x2E)
#define SPDR	*((volatile uint8_t *)0x2F)
#define	SPCR	*((volatile uint8_t *)0x2D)

//------- MACROS ------------
#define SS_ENABLE()		DIO_setPinValue(SS,LOW)
#define SS_DISABLE()    DIO_setPinValue(SS,HIGH)

//------- Config Options ----------
typedef enum
{
	SPI_InterruptDisable=0x00,
	SPI_InterruptEnable=0x80,
}SPI_Interrupt;

typedef enum
{
	SPI_DIS=0x00,
	SPI_ENABLE=0x40,
}SPI_Control;

typedef enum
{
	MSBFirst=0x00,
	LSBFirst=0x20,
}SPI_DataOrder;

typedef enum
{
	SLaveMode=0x00,
	MasterMode=0x10,
}SPI_MSTR;

typedef enum
{
	CLK_DIV4=0x00,
	CLK_DIV16=0x01,
	CLK_DIV64=0x02,
	CLK_DIV128=0x03
}SPI_CLOCK;

typedef enum
{
	DoubleSpeedDisable=0x00,
	DoubleSpeedEnable=0x01,
}SPI_DoubleSpeed;


typedef enum
{
	SPI_Mode0=0x00,
	SPI_Mode1=0x04,
	SPI_Mode2=0x08,
	SPI_Mode3=0x0C,
}SPI_Modes;



#endif /* SPI_PRIVATE_H_ */