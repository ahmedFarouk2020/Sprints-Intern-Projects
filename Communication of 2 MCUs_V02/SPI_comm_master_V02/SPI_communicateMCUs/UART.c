/*
 * UART.h
 *
 * Created: 9/21/2021 11:10:50 AM
 *  Author: Farouk
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "UART _interface.h"
#include "UART _private.h"
#include "UART_config.h"




void UART_Init(EN_stopbit_count SB, EN_parity_mode pm, EN_sync_mode s_mode,
				EN_data_size size, EN_trig_source trig_mode, EN_Double_Speed double_speed)
{
	#if double_speed == ENABLE
		//UCSRA = (1<<1); // when disable this mode, data corruption ocurrs
		SET_BIT(UCSRA,1);
	#endif
	
	UCSRB = trig_mode ;
	ENABLE_TRANSMITTER();
	ENABLE_RECEIVER();
	
	SWITCH_TO_UCSRC();
	UCSRC |= ( SB | pm | s_mode | size );
	
	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = BAUD_PRESCALE>>8;
	UBRRL = BAUD_PRESCALE;
	
}



void UART_SendChar(uint8_t character)
{
	// wait until UDRE flag is enabled (ready to transmit data)
	while(!GET_BIT(UCSRA,5));
	UDR = character;
}


void UART_SendString(uint8_t *data)
{
	uint16_t index = 0;
	while(data[index] != '\0')
	{
		UART_SendChar(data[index]);
		index++;
	}
}


void UART_ReceiveString(uint8_t *receive_buffer)
{
	uint8_t index = 0;
	do 
	{
		receive_buffer[index] = UART_ReceiveCharSych();
		index++;
	} while (receive_buffer[index-1] != '\r');
	receive_buffer[index-1] = '\0';
}



void UART_SendInt(uint16_t number)
{
	sint8_t* str = {'\0'};
	itostr(number, str);
	UART_SendString(str);
}


static void itostr(uint16_t number, sint8_t *buffer)
{
	uint8_t remainder;
	sint8_t counter = 0;

	if(number == 0)
	{
		buffer[0] = 48;
		counter = 0 ;
	}
	while(number)
	{
		remainder = (uint8_t)(number%10);
		buffer[counter++] = remainder + 48;
		number = number/10;
	}

}


static void UART_ReceiveChar(uint8_t *receive_buffer)
{
	uint16_t timeout = 0;
	while(!GET_BIT(UCSRA,7)){
		timeout++;
		if(timeout == 0xffff)
		{
			*receive_buffer = 255;
			return;
		}
	}
	*receive_buffer = UDR;
}

uint8_t UART_ReceiveCharSych(void)
{
	while(!GET_BIT(UCSRA,7));
	return UDR;
}

