/*
 * SPI_communicateMCUs.c
 *
 * Created: 9/23/2021 1:29:20 PM
 *  Author: Farouk
 */ 

#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "DIO_interface.h"
#include "SPI_interface.h"
#include "Delay_interface.h"
#include "LCD_interface.h"


int main(void)
{
	DIO_SetPortDirection(GPIOC,OUTPUT);
	LCD_Init();
	SPI_Init();
	
    while(1)
    {
		uint8_t data = SPI_ReceiveChar();
		DIO_SetPortValue(GPIOC,data);
		LCD_DisplayCharacter(data);
		if (data == '!')
		{
			LCD_SendCommand(CLEAR_SCREEN);
		}
    }
}