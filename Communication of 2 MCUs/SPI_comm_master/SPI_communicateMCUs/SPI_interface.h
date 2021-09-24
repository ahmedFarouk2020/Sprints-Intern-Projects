/*
 * SPI_interface.h
 *
 * Created: 9/23/2021 1:30:50 PM
 *  Author: Farouk
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

void SPI_Init(void);
void SPI_sendChar(uint8_t character);
uint8_t SPI_ReceiveChar(void);
void SPI_SendStr(uint8_t* str);
void SPI_ReceiveStr(uint8_t* buffer);
void SPI_Disable(void);

#endif /* SPI_INTERFACE_H_ */