/*
 * UART.h
 *
 * Created: 9/21/2021 11:10:50 AM
 *  Author: Farouk
 */ 


#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_

#define USART_BAUDRATE		9600
#define F_CPU				1000000UL

#define BAUD_PRESCALE (((F_CPU / (USART_BAUDRATE * 8UL))) - 1)


#endif 