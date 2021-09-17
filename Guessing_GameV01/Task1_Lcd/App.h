/*
 * App.h
 *
 * Created: 9/16/2021 1:40:21 PM
 *  Author: Farouk
 */ 


#ifndef APP_H_
#define APP_H_


#define USER_INPUT   1
#define PROCESSING_DATA   0

//------ Global Variables
uint8_t random_var;
uint8_t user_num;
volatile uint8_t stage ;

typedef enum{
	_40LOOPS = 40,
	_60LOOPS = 60,
	_80LOOPS = 80
}Num_of_timeroverflow;

void App_init(void);

void App_CreateRandNum(void);

void App_TakeUserInput(void);

void App_SetExpireTime(void);

void App_ValidateInput(void);

void App_PrintResult(void);
void App_promptUser(uint8_t *str);

#endif /* APP_H_ */