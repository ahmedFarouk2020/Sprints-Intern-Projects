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

static void LCD_IsBusy(void)
{
	LCD_SetOperationMode(RECEIVE_COMMAND);
	uint8_t BF_state = 0;
	//Delay_us_independent(30);
	// get BF and AC
	LCD_StartOperation();
	while(1) {
		//delay
		Delay_us_independent(30);
		// check the the last pin 
		BF_state = DIO_readPinValue(LCD_D7);
		// if true -> ready to receive data & commands (end the function)
		if(BF_state == 0) {
			break;
		}
	}
}

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
	
	////-  follow init sequence
	//LCD_SendCommand(0x02);
	////LCD_IsBusy();
	//Delay_ms_independent(1);
	//LCD_SendCommand(_2LINES_58FORMAT_4BITMODE);
	////LCD_IsBusy();
	//Delay_ms_independent(1);
	//LCD_SendCommand(DISPLAY_ON_CURSOR_ON);
	//Delay_ms_independent(1);
	////LCD_IsBusy();
	//LCD_SendCommand(CLEAR_SCREEN);
	
	//-  follow init sequence
	LCD_SendCommand(0x02);// 4-bit mode
	//LCD_IsBusy();
	Delay_ms_independent(1);
	LCD_SendCommand(_2LINES_58FORMAT_4BITMODE);
	//LCD_IsBusy();
	Delay_ms_independent(1);
	LCD_SendCommand(DISPLAY_ON_CURSOR_OFF);
	Delay_ms_independent(1);
	LCD_SendCommand(CURSOR_RIGHT);
	Delay_ms_independent(1);
	//LCD_IsBusy();
	LCD_SendCommand(CLEAR_SCREEN);
}


//void LCD_init(void)
//{
	//LCD_DATA_DIR = 0XFF;
	//LCD_CTRL_DIR = 0X07;
	//_delay_ms(15);
	//LCD_sendCommand(TWO_LINE_8_BITS);
	//LCD_sendCommand(DISPLAY_ON_CURSOR_ON);
	//LCD_sendCommand(CLEAR_SCREEN);
	//_delay_ms(2);
//}

void LCD_SendCommand(uint8_t command)
{
	LCD_SetOperationMode(SEND_COMMAND);
	DIO_SetPortValue(LCD_DATA_BUFFER,command);
	Delay_ms_independent(1);
	LCD_StartOperation(); // start operation
	Delay_ms_independent(1);
	LCD_StopOperation();
	// shift
	command = (command<<4);
	DIO_SetPortValue(LCD_DATA_BUFFER,command);
	Delay_ms_independent(1);
	LCD_StartOperation();
	Delay_ms_independent(1);
}


void LCD_DisplayCharacter(uint8_t character)
{
	LCD_SetOperationMode(SEND_DATA);
	DIO_SetPortValue(LCD_DATA_BUFFER,character);
	Delay_ms_independent(1);
	LCD_StartOperation();
	Delay_ms_independent(1);
	LCD_StopOperation();
	Delay_ms_independent(1);
	DIO_SetPortValue(LCD_DATA_BUFFER,(character<<4));
	Delay_ms_independent(1);
	LCD_StartOperation();
	Delay_ms_independent(1);
}

void LCD_DisplayString(uint8_t * str, uint8_t writing_speed_ms)
{
	uint8_t i=0;
	while(str[i] != 0)
	{
		LCD_DisplayCharacter(str[i]);
		Delay_ms_independent(writing_speed_ms);
		i++;
		if (i == 16) // the space of 1st line has been ended
		{
			LCD_SendCommand(CURSOR_AT_LINE2);
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