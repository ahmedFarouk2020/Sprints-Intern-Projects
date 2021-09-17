/*
 * LCD.h
 *
 * Created: 6/30/2020 10:49:36 AM
 *  Author: Farouk
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

//------ LCD Control Pins Definitions
#define RS 							GPIOA, PIN0
#define RW  						GPIOA, PIN1
#define E   						GPIOA, PIN2

//------ LCD DATA Pin Definition 
#define LCD_D0 	GPIOB, PIN0
#define LCD_D1 	GPIOB, PIN1
#define LCD_D2 	GPIOB, PIN2
#define LCD_D3 	GPIOB, PIN3
#define LCD_D4 	GPIOB, PIN4
#define LCD_D5 	GPIOB, PIN5
#define LCD_D6  GPIOB, PIN6
#define LCD_D7  GPIOB, PIN7

#define LCD_DATA_BUFFER		GPIOB

//---------- Transmition Mode
#define SEND_COMMAND	   0
#define SEND_DATA		   1
#define RECEIVE_COMMAND	   2
#define RECEIVE_DATA	   3

//------- Commands
#define DISPLAY_OFF_CURSOR_OFF 		0x08
#define DISPLAY_ON_CURSOR_ON   		0x0E
#define DISPLAY_ON_CURSOR_OFF   	0x0C
#define DISPLAY_ON_CURSOR_BLINKING  0x0F
#define SHIFT_LEFT					0x18
#define SHIFT_RIGHT					0x1C
#define TWO_LINE_8_BITS 			0x38
#define CURSOR_OFF      			0x0c
#define CLEAR_SCREEN    			0x01
#define ENABLE_LINE1                0x80
#define CURSOR_AT_LINE2             0xC0
#define RETURN_HOME					0x02
#define _2LINES_58FORMAT_4BITMODE 	0x28
#define CURSOR_RIGHT				0x06
#define ACTIVATE_SECOND_LINE		0xC0


//------- function prototypes
void LCD_Init(void);
void LCD_SendCommand(uint8_t command);
void LCD_DisplayCharacter(uint8_t character);
void LCD_DisplayString(uint8_t * str, uint8_t writing_speed_ms);

//------ Not implemented (included in the Next Version ISA)
void LCD_DisplayInt(uint8_t a_number);
uint8_t LCD_ReceiveBF_AC(void);
void LCD_DisplayOnColRow(uint8_t row , uint8_t col , const uint8_t * str);
void LCD_GoToRowCol(uint8_t row , uint8_t col);




#endif /* LCD_H_ */