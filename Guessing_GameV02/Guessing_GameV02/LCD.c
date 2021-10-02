/*
 * LCD.c
 *
 * Created: 6/30/2020 11:04:39 AM
 *  Author: Farouk
 */ 

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "LCD_interface.h"
#include "LCD_private.h"
#include "LCD_config.h"
#include "DIO_interface.h"

#include "Delay_interface.h"


static uint8_t LCD_SetOperationMode(uint8_t mode)
{
	switch(mode)
	{
		case SEND_COMMAND:
				// send command config rs=0   rw=0
				DIO_setPinValue(RS,0);
				DIO_setPinValue(RW,0);
				break;
		case SEND_DATA:
				// send data config  rs=1   rw=0
				DIO_setPinValue(RS,1);
				DIO_setPinValue(RW,0);
				break;
		case RECEIVE_COMMAND:
				// receive command config rs=0   rw=1 (read BF)
				DIO_setPinValue(RS,0);
				DIO_setPinValue(RW,1);
				break;
		case RECEIVE_DATA:
				// receive data config rs=1   rw=0
				DIO_setPinValue(RS,1);
				DIO_setPinValue(RW,1);
				break;
		default: return INVALID_OPERATION_MODE;
	}
	Delay_ms_independent(1);
	DIO_setPinValue(E,1); // stop operation
	Delay_ms_independent(1);
	return 1;
}

void LCD_Init(void)
{
	Delay_ms_independent(10);
	//- set Lcd pins as output
	//---- Control pins
	DIO_setPinDirection(E,OUTPUT);
	Delay_ms_independent(1);
	DIO_setPinDirection(RW,OUTPUT);
	DIO_setPinDirection(RS,OUTPUT);
	Delay_ms_independent(1);
	//----- Data pins
	DIO_setPinDirection(LCD_D7,OUTPUT);
	DIO_setPinDirection(LCD_D6,OUTPUT);
	DIO_setPinDirection(LCD_D5,OUTPUT);
	DIO_setPinDirection(LCD_D4,OUTPUT);
	
	
	//-  follow init sequence
	LCD_SendCommand(TO_4_BIT_MODE);// 4-bit mode
	//LCD_IsBusy();
	Delay_ms_independent(1);
	LCD_SendCommand(_2LINES_58FORMAT_4BITMODE);
	//LCD_IsBusy();
	Delay_ms_independent(1);
	LCD_SendCommand(DISPLAY_ON_CURSOR_BLINKING);
	Delay_ms_independent(1);
	LCD_SendCommand(CURSOR_RIGHT);
	Delay_ms_independent(1);
	//LCD_IsBusy();
	LCD_SendCommand(CLEAR_SCREEN);
}


void LCD_SendCommand(uint8_t command)
{
	LCD_SetOperationMode(SEND_COMMAND);
	//DIO_SetPortValue(LCD_DATA_BUFFER,command);----------------------
	// clear the higher 4-bits 
	LCD_DATA_BUFFER &= 0x0f; 
	// store cmd into buffer
	LCD_DATA_BUFFER |= command & (0xf0); // high first
	Delay_ms_independent(1);
	LCD_StartOperation(); // start operation
	Delay_ms_independent(1);
	LCD_StopOperation();
	// shift
	command = (command<<4);
	// clear the higher 4-bits 
	LCD_DATA_BUFFER &= 0x0f; 
	// store cmd into buffer
	LCD_DATA_BUFFER |= command & (0xf0);
	//DIO_SetPortValue(LCD_DATA_BUFFER,command);-------------------------
	Delay_ms_independent(1);
	LCD_StartOperation();
	Delay_ms_independent(1);
}


void LCD_DisplayCharacter(uint8_t character)
{
	LCD_SetOperationMode(SEND_DATA);
	// clear the higher 4-bits 
	LCD_DATA_BUFFER &= 0x0f; 
	// store cmd into buffer
	LCD_DATA_BUFFER |= character & (0xf0);
	
	//DIO_SetPortValue(LCD_DATA_BUFFER,character);
	Delay_ms_independent(1);
	LCD_StartOperation();
	Delay_ms_independent(1);
	LCD_StopOperation();
	Delay_ms_independent(1);
	
	// clear the higher 4-bits 
	LCD_DATA_BUFFER &= 0x0f; 
	// store cmd into buffer
	LCD_DATA_BUFFER |= (character<<4) & (0xf0);
	//DIO_SetPortValue(LCD_DATA_BUFFER,(character<<4));
	Delay_ms_independent(1);
	LCD_StartOperation();
	Delay_ms_independent(1);
}

void LCD_DisplayString(uint8_t * str, uint8_t writing_speed_ms)
{
	LCD_Cursor_Pos = 0;
	
	while(str[LCD_Cursor_Pos] != 0)
	{
		LCD_DisplayCharacter(str[LCD_Cursor_Pos]);
		Delay_ms_independent(writing_speed_ms);
		LCD_Cursor_Pos++;
		
		/* Check Cursor Position */
		if (LCD_Cursor_Pos == END_OF_LINE1) // the space of 1st line has been ended
		{
			LCD_SendCommand(CURSOR_AT_LINE2);
		}
		
		else if(LCD_Cursor_Pos == END_OF_LINE2)
		{
			LCD_SendCommand(CLEAR_SCREEN); // return to position 0 
			LCD_Cursor_Pos = 0;
		}
	}
}

static void LCD_StartOperation(void)
{
	// clear E pin
	DIO_setPinValue(E,0);	
}


static void LCD_StopOperation(void)
{
	// set E pin
	DIO_setPinValue(E,1);
}