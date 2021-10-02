/*
 * LCD.h
 *
 * Created: 6/30/2020 10:49:36 AM
 *  Author: Farouk
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_

//---- Global Variable --------
uint8_t LCD_Cursor_Pos;

//----- Macros ------------
#define END_OF_LINE1	16
#define END_OF_LINE2	32


//---- Private Functions ------------
//--- make E=1 adjust operation mode -----

/****
 * Description: set operation mode for the following operation (SEND_COMMAND, SEND_DATA, ..)
 * args: mode  ->  uint8_t
 * Return: None
 * EX: LCD_SetOperationMode(SEND_COMMAND);
 */
static uint8_t LCD_SetOperationMode(uint8_t mode);


/****
 * Description: clear E pin to start operation
 * args: None
 * Return: None
 * EX: LCD_StartOperation();
 */
static void LCD_StartOperation(void);


/****
 * Description: set E pin to stop operation
 * args: None
 * Return: None
 * EX: LCD_StopOperation();
 */
static void LCD_StopOperation(void);

#endif /* LCD_H_ */