/*
 * SPI_communicateMCUs.c
 *
 * Created: 9/23/2021 1:29:20 PM
 *  Author: Farouk
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "UART _interface.h"

#define MAX_SIZE  255
uint8_t buffer[MAX_SIZE]; // startup code initializes all elements to be zeros

int main(void)
{
	SPI_Init();
	UART_Init(BR_9600,_1_stopbit,disabled,Asynchronous,_8_bits,polling);
    while(1)
    {
		SPI_ReceiveStr(buffer);
		UART_SendString(buffer);
		UART_SendChar('\r');
    }
}