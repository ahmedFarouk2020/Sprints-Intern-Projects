///*
 //* test_timer.c
 //*
 //* Created: 9/4/2021 10:27:29 PM
 //*  Author: Farouk
 //*/ 
//// COMMON LIB
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//
//#include "DIO_interface.h"
//#include "timer_interface.h"
//
//
//int main(void)
//{
	//// led definition
	//DIO_setPinDirection(GPIOB, PIN0, OUTPUT);
	//DIO_setPinValue(GPIOB, PIN0, LOW);
	//
	//// timer configurations
	//timer_init(); // timer mode is nomal
	//timer_setInterval(256);
	//timer_start(TIMER0); // timer clk = tclk/1024 (timer tick time = 1.04 ms)
    //while(1)
    //{
		//// LOW region
        //timer_waitFlag(OVERFLOW_FLAG);// 262.144 ms
		//timer_setInterval(230);
		//timer_waitFlag(OVERFLOW_FLAG); // 244.4 ms
		//DIO_setPinValue(GPIOB, PIN0, HIGH);
		//
		//// HIGH region
		//timer_setInterval(256); // reset
		//timer_waitFlag(OVERFLOW_FLAG); // 262.144 ms
		//timer_setInterval(36);
		//timer_waitFlag(OVERFLOW_FLAG); // 36.4 ms
		//DIO_setPinValue(GPIOB, PIN0, LOW);
    //}
//}