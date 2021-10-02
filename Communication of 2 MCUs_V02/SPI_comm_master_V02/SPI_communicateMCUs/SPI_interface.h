/*
 * SPI_interface.h
 *
 * Created: 9/23/2021 1:30:50 PM
 *  Author: Farouk
 */ 


#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_


/*****
 * Description: Init SPI module via config file -> see SPI_config.h
 * args: none
 * Return: none
 * Ex: SPI_Init();
 */
void SPI_Init(void);


/*****
 * Description: send a frame
 * args: frame_data -> uint8_t
 * Return: none
 * Ex: SPI_sendChar(frame_data);
 */
void SPI_sendChar(uint8_t character);


/*****
 * Description: receive a frame
 * args: none
 * Return: received_frame -> uint8_t
 * Ex: received_frame = SPI_ReceiveChar();
 */
uint8_t SPI_ReceiveChar(void);


/*****
 * Description: send string (multiple frames)
 * args: string_to_be_sent -> uint8_t*
 * Return: none
 * Ex: SPI_SendStr(str);
 */
void SPI_SendStr(uint8_t* str);


/*****
 * Description: receive string (multiple frames)
 * args: buffer_to_store_data_inside  -> uint8_t*
 * Return: none
 * Ex: SPI_ReceiveStr(buffer);
 */
void SPI_ReceiveStr(uint8_t* buffer);


/*****
 * Description: Disable SPI
 * args: none
 * Return: none
 * Ex: SPI_Disable();
 */
void SPI_Disable(void);

#endif /* SPI_INTERFACE_H_ */