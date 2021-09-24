/*
 * UART.h
 *
 * Created: 9/21/2021 11:10:50 AM
 *  Author: Farouk
 */ 


#ifndef UART_H_
#define UART_H_

typedef enum{
// first 2 bit for UCSRC the last 2 bits for UCSRB
	_5_bits=0x00,
	_6_bits=0x02,
	_7_bits=0x04,
	_8_bits=0x06
}EN_data_size;

typedef enum{
// in UCSRB reg
	polling=0x00,
	Receive_Complete_INT=0x80,
	Transmit_Complete_INT=0x40,
	Data_REG_Empty_INT=0x20
}EN_trig_source;

typedef enum{
	// in UCSRC reg 
	Asynchronous=0x00,
	Synchronous=0x40
}EN_sync_mode;

typedef enum{
	// in UCSRC reg
	disabled=0x00,
	even_parity=0x20,
	odd_parity=0x30
}EN_parity_mode;

typedef enum{
	// in UCSRC
	_2_stopbits=8,
	_1_stopbit=0
}EN_stopbit_count;


typedef enum{
	// in UBRR at 1M clk source (for other clk sources see p.165 tables)
	BR_2400  = 25, 
	BR_4800  = 12,
	BR_9600  = 6,
	BR_14_4K = 3,
	BR_19_2K = 2
}EN_baud_rate;




//-------- Function Declaration ------------------

void UART_Init(EN_baud_rate BR, EN_stopbit_count SB, EN_parity_mode pm, EN_sync_mode s_mode,
				EN_data_size size, EN_trig_source trig_mode);


void UART_SendString(uint8_t *data);

void UART_SendChar(uint8_t character);

void UART_SendInt(uint16_t number);


uint8_t UART_ReceiveCharSych(void);

void UART_ReceiveString(uint8_t *receive_buffer);


#endif