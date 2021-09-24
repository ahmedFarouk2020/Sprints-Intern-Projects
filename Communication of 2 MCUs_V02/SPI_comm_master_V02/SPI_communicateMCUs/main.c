/*
 * SPI_communicateMCUs.c
 *
 * Created: 9/23/2021 1:29:20 PM
 *  Author: Farouk
 */ 

#include <string.h>

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "UART _interface.h"

#define MAX_SIZE  255
uint8_t buffer[MAX_SIZE] ;

int main(void)
{
	SPI_Init();
	UART_Init(BR_9600,_1_stopbit,disabled,Asynchronous,_8_bits,polling);
	/* init buffer */
	for (uint16_t counter=0; counter<=MAX_SIZE; counter++)
	{
		buffer[counter] = '\0';
	}
    while(1)
    {
        UART_ReceiveString(buffer);
		SPI_SendStr(buffer);
		SPI_sendChar('\0'); // indicator for the end of str
		UART_SendString((uint8_t*)"\rSent Successfully\r");
    }
}