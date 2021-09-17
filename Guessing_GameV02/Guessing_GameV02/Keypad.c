/*
 * Keypad.c
 *
 * Created: 9/13/2021 9:28:11 PM
 *  Author: farouk
 */ 
 
 /* Common Lib */
 #include "STD_TYPES.h"
 #include "BIT_MATH.h"
 
 #include "DIO_interface.h"
 
 #include "Keypad_interface.h"
 #include "Keypad_private.h"
 #include "Keypad_config.h"
 
 /*****
 * Description: Initialization Gpio pin directions and values
 * Parameters: none (configurations of pins in the config.h file)
 * Return: none
 * EX: Keypad_Init();
 */
void Keypad_Init(void)
{
	// set direction of row pins (output)
	DIO_setPinDirection(ROW0, 1);
	DIO_setPinDirection(ROW1, 1);
	DIO_setPinDirection(ROW2, 1);
	DIO_setPinDirection(ROW3, 1);
	// set direction of col pins (input with pullup enabled)
	DIO_setPinDirection(COL0, 0);
	DIO_setPinDirection(COL1, 0);
	DIO_setPinDirection(COL2, 0);
	DIO_setPinDirection(COL3, 0);
	// set value to col pins (High)
	DIO_setPinValue(COL0,1);
	DIO_setPinValue(COL1,1);
	DIO_setPinValue(COL2,1);
	DIO_setPinValue(COL3,1);
	
	// set value to row pins (Low)
	DIO_setPinValue(ROW0,0);
	DIO_setPinValue(ROW1,0);
	DIO_setPinValue(ROW2,0);
	DIO_setPinValue(ROW3,0);
	
}

/*****
 * Description: detect the pressed button and return its character ex: '1', '2', ...
 * Parameters: none
 * Return: The pressed button (char) 
 * EX: Keypad_ReadPressedButton();  -> '2'
 */
sint8_t Keypad_ReadPressedButton(void)
{
	// pressed button indecies  row, col
	sint8_t button_rowID = -1;
	sint8_t button_colID = -1;
	/* loop on raw and each time put on zero to a row */
	for(uint8_t count_rawId=0; count_rawId<NUM_OF_ROW; count_rawId++)
	{
		// put value on raw pins
		Keypad_AssignRowValue(count_rawId);
		/* loop on cols to catch the zero value of them (i.e. where is the pressed button) */
		for(uint8_t count_colId=0; count_colId<NUM_OF_COL; count_colId++)
		{
			// get the col state (High , low)
			uint8_t col_state = Keypad_ReadColPin(count_colId);
			// if low?
			if (col_state == 0)
			{
				// button is detected
				button_rowID = count_rawId;
				button_colID = count_colId;
				sint8_t result = Keypad_GetPressedButton(button_rowID, button_colID);
				return result;
			}
		}
	}
	return NO_PRESSED_BUTTON; 
}


/*****
 * Description: take index of pressed button and return button char(as written on the button) 
 * Parameters: uint8 row index, uint8 colums index in the array
 * Return: the value of pressed button as showed on it (char)
 * EX: Keypad_GetPressedButton(0,1) -> '1'
 * NOTE: This Function can't be called by other module
 */
static sint8_t Keypad_GetPressedButton(uint8_t row, uint8_t col)
{
	if(row<4 && col<3)
	{
		return buttons[row][col];
	}
	return INVALID_INDEX; // ERROR
}


/*****
 * Description: take row index and assign zero to this index and one to the others 
 * Parameters: uint8 row index
 * Return: none
 * EX: Keypad_AssignRowValue(3)
 * NOTE: This Function can't be called by the other modules
 */
static void Keypad_AssignRowValue(uint8_t rowID)
{
	switch (rowID)
	{
		case 0:
		// write the value 1110 to the rows
			DIO_setPinValue(ROW0,0);
			DIO_setPinValue(ROW1,1);
			DIO_setPinValue(ROW2,1);
			DIO_setPinValue(ROW3,1);
			break;
		case 1:
			// write the value 1101 to the rows
			DIO_setPinValue(ROW0,1);
			DIO_setPinValue(ROW1,0);
			DIO_setPinValue(ROW2,1);
			DIO_setPinValue(ROW3,1);
			break;
		case 2:
			// write the value 1011 to the rows
			DIO_setPinValue(ROW0,1);
			DIO_setPinValue(ROW1,1);
			DIO_setPinValue(ROW2,0);
			DIO_setPinValue(ROW3,1);
			break;
		case 3:
			// write the value 0111 to the rows
			DIO_setPinValue(ROW0,1);
			DIO_setPinValue(ROW1,1);
			DIO_setPinValue(ROW2,1);
			DIO_setPinValue(ROW3,0);
			break;
	}
}



/*****
 * Description: take column index (0,1,2) and return column state(High, Low) 
 * Parameters: uint8 colums index
 * Return: uint8 column state(High, Low) 
 * EX: Keypad_ReadColPin(0) -> 1
 * NOTE: This Function can't be called by the other modules
 */
static sint8_t Keypad_ReadColPin(uint8_t colID)
{
	uint8_t result = 0;
	switch (colID)
	{
		case 0:
			result = DIO_readPinValue(COL0);
			break;
		case 1:
			result = DIO_readPinValue(COL1);
			break;
		case 2:
			result = DIO_readPinValue(COL2);
			break;
		case 3:
			result = DIO_readPinValue(COL2);
			break;
	}
	return result;
}