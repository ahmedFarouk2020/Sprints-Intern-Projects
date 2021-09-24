#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/* Ligical levels */
#define HIGH    1
#define LOW     0

/* GPIO IDs */
#define GPIOA   0
#define GPIOB   1
#define GPIOC   2
#define GPIOD   3

/* Pin IDs */
#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7

/* Data Direction */
#define INPUT    0
#define OUTPUT   1


// Function Declarations

/********
	Function Description: 
			set pin direction (input or output)
	Parameters: 
			GPIO register, pin number, pin direction
	Return: 
		1: No ERROR, 0: ERROR OCCURS
*/
sint8_t DIO_setPinDirection(uint8_t GPIO, uint8_t pin_number, uint8_t direction);


/********
	Function Description: set pin value(HIGH or LOW)
	Parameters: GPIO register, pin number, pin value
	Return: 
	1: No ERRORS		0: ERROR OCCURS
*/
sint8_t DIO_setPinValue(uint8_t GPIO, uint8_t pin_number, uint8_t value);


/********
	Function Description: read value of pin (0 or 1)
	Parameters: GPIO register, pin number
	Return: the value of pin (0 or 1)
*/
uint8_t DIO_readPinValue(uint8_t GPIO, uint8_t pin_number);


uint8_t DIO_GetPortValue (uint8_t PortNumber);

void DIO_SetPortValue (uint8_t PortNumber , uint8_t Value);

void DIO_SetPortDirection (uint8_t PortNumber , uint8_t Direction);

#endif