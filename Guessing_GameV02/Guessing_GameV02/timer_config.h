/*********************************************************/
/*  author   :  farouk                                   */
/*  date     :  2 SEPT 2021                              */
/*  version  :  V01                                      */
/*********************************************************/

// OCF0 cleared by SW by writing 1

#ifndef TIMER_CONFIG_H_
#define TIMER_CONFIG_H_


/* Timer Mode */
#define TIMER_MODE	NORMAL
/* Options */
#define NORMAL  	0
#define PC_PWM  	1
#define CTC			2
#define FAST_PWM  	3


/* Prescaler (clk source) */
#define CLK_SOURCE	 CLK_DIV_1024
/* options */
/* STOPPED	CLK_DIV_1  CLK_DIV_8  CLK_DIV_64  CLK_DIV_256  CLK_DIV_1024 
 EXT_CLK_FALLING_EDGE  EXT_CLK_RISING_EDGE */

/* Flag ID*/
#define OVERFLOW_FLAG 		0
#define COMPARE_FLAG 		1

/* TimerID */
#define TIMER_ID  TIMER0
/* option */
// TIMER0  TIMER1  TIMER2  ALL_IDs

/* Key (decide if the function will be included in your code or not) */
#define KEY  UNLOCKED
/* options */
#define LOCKED  0
#define UNLOCKED  1


#endif