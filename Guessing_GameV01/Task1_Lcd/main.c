/*
 * main.c
 *
 * Created: 9/16/2021 2:45:22 PM
 *  Author: Farouk
 */ 


/*
 * Task1_Lcd.c
 *
 * Created: 9/15/2021 10:54:46 AM
 *  Author: Farouk
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "App.h"


int main(void)
{
	App_init();
    while(1)
    {
		App_promptUser("Please Guess the Number:");
		App_CreateRandNum();
		App_TakeUserInput();
		App_ValidateInput();
		App_PrintResult();
    }
}