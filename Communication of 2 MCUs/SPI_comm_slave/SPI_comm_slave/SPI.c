/*
 * SPI.c
 *
 * Created: 9/23/2021 1:30:36 PM
 *  Author: Farouk
 */ 

/* common lib */
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void SPI_Init(void)
{
	/* Configure SPI Pins first (MUST) */
		#if  SPI_MODE == MasterMode 
			DIO_setPinDirection(MOSI,OUTPUT);
			DIO_setPinDirection(SS,OUTPUT);
			DIO_setPinDirection(CLK,OUTPUT);
			DIO_setPinDirection(MISO,INPUT);
			SS_ENABLE();
		#elif  SPI_MODE == SLaveMode
			DIO_setPinDirection(MOSI,INPUT);
			DIO_setPinDirection(SS,INPUT);
			DIO_setPinDirection(CLK,INPUT);
			DIO_setPinDirection(MISO,OUTPUT);
		#endif
		/* setup SPI communication options */
		SPSR = DOUBLE_SPEED;
		SPCR = SPI_CLK | SPI_MODE | BIT_ORDER | INTERRUPT_STATE | SCK_MODE | SPI_ENABLE;
}
void SPI_sendChar(uint8_t character)
{
	SPDR = character;
	while(GET_BIT(SPSR,7) == 0);
}
uint8_t SPI_ReceiveChar(void)
{
	while(GET_BIT(SPSR,7) == 0);
	return SPDR;
}
//void SPI_SendStr(uint8_t* str);
//void SPI_ReceiveChar(uint8_t* buffer);
//void SPI_Disable(void);