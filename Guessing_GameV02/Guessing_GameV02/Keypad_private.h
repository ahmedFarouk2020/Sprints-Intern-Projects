/*
 * Keypad_private.h
 *
 * Created: 9/13/2021 9:28:11 PM
 *  Author: farouk
 */ 


#ifndef KEYPAD_PRIVATE_H_
#define KEYPAD_PRIVATE_H_






// Private functions Definitions

/*****
 * Description: take index of pressed button and return button char(as written on the button) 
 * Parameters: uint8_t row index, uint8_t colums index in the array
 * Return: the value of pressed button as showed on it (char)
 * EX: Keypad_GetPressedButton(0,1) -> '1'
 * NOTE: This Function can't be called by other module
 */
static sint8_t Keypad_GetPressedButton(uint8_t row, uint8_t col);

static sint8_t Keypad_ReadColPin(uint8_t colID);

static void Keypad_AssignRowValue(uint8_t rowID);


#endif 