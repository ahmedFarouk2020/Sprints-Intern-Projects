/*
 * UART.h
 *
 * Created: 9/21/2021 11:10:50 AM
 *  Author: Farouk
 */ 


#ifndef UART_PRIVATE_H_
#define UART_PRIVATE_H_

/* Resgister Defination */

#define UDR		*((volatile uint8_t*)0x2C)
#define UCSRA	*((volatile uint8_t*)0x2B)
#define UCSRB	*((volatile uint8_t*)0x2A)
#define UCSRC	*((volatile uint8_t*)0x40)
#define UBRRL	*((volatile uint8_t*)0x29)
#define UBRRH	*((volatile uint8_t*)0x40)


//------ Helping Macros
#define ENABLE_TRANSMITTER()  SET_BIT(UCSRB,3)
#define ENABLE_RECEIVER()	  SET_BIT(UCSRB,4)
#define SWITCH_TO_UCSRC()     SET_BIT(UBRRH,7)
#define SWITCH_TO_UBRRH()     CLR_BIT(UBRRH,7)

//------ Helping Function

static void UART_ReceiveChar(uint8_t *receive_buffer);


#endif 