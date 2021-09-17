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
#include "timer_interface.h"
#include "LCD_interface.h"
#include "Button.h"
#include "Delay_interface.h"
#include "App.h"



void App_init(void)
{
	Button_init(GPIOD,PIN3);
	LCD_Init();
	
	global_int_enable();
	timer_enableInterrupt(OVERFLOW_FLAG);
	
	timer_init();
	timer_setInterval(256);
	timer_setCallback(App_SetExpireTime);
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
	timer_start(TIMER0);
	stage = USER_INPUT;
	uint8_t button_state = 0;
	uint8_t previous_state = 0;
	user_num = 0;
	while (stage == USER_INPUT)
	{
		// read button state
		button_state = Button_read(GPIOD,PIN3,PULLDOWN_RES);
		// falling edge?
		if (button_state && !previous_state)
		{
			user_num++;
			previous_state = button_state;
		}
		// not falling edge?
		else
		{
			previous_state = button_state;
		}
	}
}



void App_SetExpireTime(void)
{
	uint8_t num_of_timer_overflow = _40LOOPS;
	static uint8_t num_of_calls = 0;
	num_of_calls++;
	if (num_of_calls == num_of_timer_overflow)
	{
		num_of_calls = 0;
		stage = PROCESSING_DATA;
		timer_stop(TIMER0);
	}
}

void App_ValidateInput(void)
{
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
			timer_setInterval(256);
			App_TakeUserInput();
		}
		else if (user_num > 15)
		{
			LCD_SendCommand(CLEAR_SCREEN);
			LCD_DisplayString((uint8_t*)"The valid range: 1 to 15",1);
			// delay one second
			Delay_ms_independent(250); Delay_ms_independent(250); Delay_ms_independent(250);
			Delay_ms_independent(250);
			LCD_SendCommand(CLEAR_SCREEN);
			LCD_DisplayString((uint8_t*)"Please Guess the Number:",1);
			timer_setInterval(256);
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