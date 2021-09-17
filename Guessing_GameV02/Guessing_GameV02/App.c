/*
 * App.c
 *
 * Created: 9/16/2021 1:40:10 PM
 *  Author: Farouk
 */


#include <stdlib.h>
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "LCD_interface.h"

#include "Delay_interface.h"
#include "App.h"



void App_init(void)
{
	LCD_Init();
	Keypad_Init();
}

void App_CreateRandNum(void)
{
	random_var = rand();
	random_var = random_var%15;
	if (random_var == 0)
	{
		random_var = 1;
	}
}

void App_TakeUserInput(void)
{
	uint8_t button_state = 0; // not pressed
	uint8_t previous_state = 0; // not pressed
	// init
	user_input[0] = 0;
	user_input[1] = 0;
	user_input[2] = 0;
	int index = 0;
	while (1)
	{
		 button_state = Keypad_ReadPressedButton();
		 if(button_state == previous_state){
			 continue;
		 }
		 else if (button_state != 0)
		 {
			 // end of input
			 if (button_state == '=')
			 {
				 App_ValidateInput();
				 return;
			 }
			 user_input[index] = button_state;
			 previous_state = button_state;
			 index++;
		 }
		 else
		 {
			 previous_state = button_state;
		 }
	}
}





void App_ValidateInput(void)
{
	user_num = atoi(user_input);
	// loop until insert valid data
	while(1) {
		if (user_num < 1)
		{
			LCD_SendCommand(CLEAR_SCREEN);
			LCD_DisplayString((uint8_t*)"You Didn't choose a number",1);
			// delay one second
			Delay_ms_independent(250);
			LCD_SendCommand(CLEAR_SCREEN);
			LCD_DisplayString((uint8_t*)"Please Guess the Number:",1);
			App_TakeUserInput();
		}
		else if (user_num > 15)
		{
			LCD_SendCommand(CLEAR_SCREEN);
			LCD_DisplayString((uint8_t*)"The valid range is 1 to 15",1);
			// delay one second
			Delay_ms_independent(250); Delay_ms_independent(250); Delay_ms_independent(250);
			Delay_ms_independent(250);
			LCD_SendCommand(CLEAR_SCREEN);
			LCD_DisplayString((uint8_t*)"Please Guess the Number:",1);
			App_TakeUserInput();
		}
		else
		{
			break;
		}
	}
}

void App_PrintResult(void)
{
	if (random_var == user_num)
	{
		LCD_SendCommand(CLEAR_SCREEN);
		LCD_DisplayString((uint8_t*)"You Won",1);
	}
	else
	{
		LCD_SendCommand(CLEAR_SCREEN);
		LCD_DisplayString((uint8_t*)"You Lost",1);
	}
	Delay_ms_independent(250);
	Delay_ms_independent(250);
	Delay_ms_independent(250);
	Delay_ms_independent(250);
}

void App_promptUser(uint8_t *str)
{
	LCD_SendCommand(CLEAR_SCREEN);
	LCD_DisplayString(str,1);
}