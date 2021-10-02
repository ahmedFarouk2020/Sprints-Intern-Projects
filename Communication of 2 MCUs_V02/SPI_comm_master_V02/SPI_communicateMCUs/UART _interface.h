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
	ENABLE=1,
	DISABLE=0
}EN_Double_Speed;



//-------- Function Declaration ------------------

/*****
 * Description: Initialization of UART module
 * Args: (stopbit_number, parity_type, synchronous_or_not, data_size, polling_or_interrupt) -> uint8_t
 * Return: None
 * Example: UART_Init(_1_stopbit,even_parity,Asynchronous,_8_bits,polling);
 */
void UART_Init(EN_stopbit_count SB, EN_parity_mode pm, EN_sync_mode s_mode,
				EN_data_size size, EN_trig_source trig_mode, EN_Double_Speed double_speed);


/*****
 * Description: Send string (number of frames) successively
 * Args: data -> str
 * Return: None
 * Example: UART_SendString((uint8_t*)"any string text");
 */
void UART_SendString(uint8_t *data);


/*****
 * Description: Send a frame
 * Args: character -> uint8_t
 * Return: None
 * Example: UART_SendChar(frame);
 */
void UART_SendChar(uint8_t character);



/*****
 * Description: Send a number
 * Args: number -> uint8_t
 * Return: None
 * Example: UART_SendInt(number);
 */
void UART_SendInt(uint16_t number);


/*****
 * Description: receive a frame
 * Args: None
 * Return: frame -> uint8_t
 * Example: frame = UART_ReceiveCharSych();
 */
uint8_t UART_ReceiveCharSych(void);


/*****
 * Description: receive a string from terminal (series of frames)
 * Args: buffer(to receive date into it) -> uint8_t*
 * Return: None
 * Example: UART_ReceiveString(frame);
 * Note: The frame received by this function must end with '\r' otherwise program will stuck inside it (infinte loop)
 */
void UART_ReceiveString(uint8_t *receive_buffer);


#endif