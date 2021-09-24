/*
 * LCD.h
 *
 * Created: 6/30/2020 10:49:36 AM
 *  Author: Farouk
 */ 


#ifndef LCD_PRIVATE_H_
#define LCD_PRIVATE_H_



//------- Private Functions
/* return Busy flat state */
static void LCD_IsBusy(void);
/* make E=1 adjust operation mode */
static uint8_t LCD_SetOperationMode(uint8_t mode);
static void LCD_StartOperation(void);
static void LCD_StopOperation(void);

#endif /* LCD_H_ */