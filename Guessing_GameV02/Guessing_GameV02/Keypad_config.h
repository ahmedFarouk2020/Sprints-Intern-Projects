/*
 * Keypad_config.h
 *
 * Created: 9/13/2021 9:28:11 PM
 *  Author: farouk
 */ 


#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

#define NUM_OF_ROW   4
#define NUM_OF_COL   4


/* Pin Definition */
#define ROW0  GPIOC, 0
#define ROW1  GPIOC, 1
#define ROW2  GPIOC, 2
#define ROW3  GPIOC, 3

#define COL0  GPIOC, 4
#define COL1  GPIOC, 5
#define COL2  GPIOC, 6
#define COL3  GPIOC, 7


sint8_t buttons[NUM_OF_ROW][NUM_OF_COL] = {
	{'7', '8', '9','/'},
	{'4', '5', '6','*'},
	{'1', '2', '3','-'},
	{'C', '0', '=','+'}
};


// ERRORS
#define INVALID_INDEX      0
#define NO_PRESSED_BUTTON  0

#endif