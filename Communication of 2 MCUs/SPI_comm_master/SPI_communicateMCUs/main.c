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

uint8_t data[11] = "Hello SPI!";

int main(void)
{
	SPI_Init();
	LCD_Init();
	
    while(1)
    {
        	for (uint8_t counter=0;data[counter] != '\0';counter++)
        	{
				SPI_sendChar(data[counter]);
				LCD_DisplayCharacter(data[counter]);
				Delay_ms_independent(250);Delay_ms_independent(250);Delay_ms_independent(250);
				Delay_ms_independent(250);		
        	}
			LCD_SendCommand(CLEAR_SCREEN);
    }
}