/*********************************************************/
/*  author   :  farouk                                   */
/*  date     :  2 SEPT 2021                               */
/*  version  :  V01                                      */
/*********************************************************/

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_

/* Timer ID */
#define TIMER0   0
#define TIMER1   1
#define TIMER2   2

/* Flag ID*/
#define OVERFLOW_FLAG 		0
#define COMPARE_FLAG 		1

/* Prescaler (clk source) */
#define STOPPED			0
#define CLK_DIV_1 		1
#define CLK_DIV_8 		2
#define CLK_DIV_64 		3
#define CLK_DIV_256 	4
#define CLK_DIV_1024 	5
#define EXT_CLK_FALLING_EDGE 		6
#define EXT_CLK_RISING_EDGE 		7

// Function Description 

/*****
	Function Description: set timer mode from config.h file (normal, pwm, ...)
	Parameters: none
	Return: 1: No Errors	negative value: Error
*/
sint8_t timer_init(void);

/******
	Function Description: set configurations of a timer (prescaler, clk source, timer mode)
	Parameters: timerID, Timer mode, clk source (prescaler) 
	Return: 1: No Errors	negative value: Error
*/
sint8_t timer_setConfigrations(uint8_t timerID, uint8_t Tmode);


/*****
	Function Description: set interval (i.e. number of counts)
	Parameters: the initial value 
	Return: 1: No Errors	negative value: Error
*/
sint8_t timer_setInterval(uint16_t num_of_counts);

sint8_t timer_setClk_start(uint8_t timerID, uint8_t clk);


/******
	Function Description: read timer value in register
	Parameters: pointer to buffer to store the value inside
	Return: 1: No Errors	negative value: Error
*/
sint8_t timer_read(uint8_t *value);


/*****
	Function Description: stop the timer
	Parameters: timerID
	Return: 1: No Errors	negative value: Error
*/
sint8_t timer_stop(uint8_t timerID);


/******
	Function Description: start timer functionality
	Parameters: timerID
	Return: 1: No Errors	negative value: Error

*/
sint8_t timer_start(uint8_t timerID);

/*****
	Function Description: stuck in this function until flag is set
	Parameters: flag ID
	Return: 1: No Errors	negative value: Error
*/
sint8_t timer_waitFlag(uint8_t flagID);

void timer_setCallback(void(*ptr_to_func)(void));

sint8_t timer_enableInterrupt(uint8_t flag);

void global_int_enable(void);
void __vector_11(void) __attribute((signal,used));


#endif