/* common lib */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
/* DIO headers */
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

sint8_t DIO_setPinDirection(uint8_t GPIO, uint8_t pin_number, uint8_t direction)
{
	switch (GPIO)
	{
		case GPIOA:
			if (pin_number < 7) 
			{
				if (direction <= 1)
				{
					PORTA_DDR |= (direction<< pin_number);
					return NO_ERRORS; // no errors
				}
				return INVALID_PIN_DIRECTION;
			}
		return PIN_NUMBER_OUT_OF_RANGE; 
		
		case GPIOB:
			if (pin_number < 7)
			{
				if (direction <= 1)
				{
					PORTB_DDR |= (direction<< pin_number);
					return NO_ERRORS; // no errors
				}
				return INVALID_PIN_DIRECTION;
			}
			return PIN_NUMBER_OUT_OF_RANGE; // Error
		
		case GPIOC:
			if (pin_number < 7)
			{
				if (direction <= 1)
				{
					PORTC_DDR |= (direction<< pin_number);
					return NO_ERRORS; // no errors
				}
				return INVALID_PIN_DIRECTION;
			}
			return PIN_NUMBER_OUT_OF_RANGE; // Error
		
		case GPIOD:
		if (pin_number < 7)
		{
			if (direction <= 1)
			{
				PORTD_DDR |= (direction<< pin_number);
				return NO_ERRORS; // no errors
			}
			return INVALID_PIN_DIRECTION;
		}
		return PIN_NUMBER_OUT_OF_RANGE; // pin_number or direction are out of range
			

	default: return INVALID_PORT_ID; // GPIO Id isn't defined
	}
}



sint8_t DIO_setPinValue(uint8_t GPIO, uint8_t pin_number, uint8_t value)
{
	switch (GPIO)
	{
		case GPIOA:
		if (pin_number < 7)
		{
			if (GET_BIT(value, 0) == LOW)
			{
				CLR_BIT(PORTA_DATA, pin_number);
			}
			else
			{
				SET_BIT(PORTA_DATA, pin_number);
			}
			return NO_ERRORS; // no errors
		}
		return PIN_NUMBER_OUT_OF_RANGE; // Error


		case GPIOB:
		if (pin_number < 7)
		{
			if (GET_BIT(value, 0) == LOW)
			{
				CLR_BIT(PORTB_DATA, pin_number);
			}
			else
			{
				SET_BIT(PORTB_DATA, pin_number);
			}
			return NO_ERRORS; // no errors
		}
		return PIN_NUMBER_OUT_OF_RANGE; // Error

		
		case GPIOC:
		if (pin_number < 7)
		{
			if (GET_BIT(value, 0) == LOW)
			{
				CLR_BIT(PORTC_DATA, pin_number);
			}
			else
			{
				SET_BIT(PORTC_DATA, pin_number);
			}
			return NO_ERRORS; 
		}
		return PIN_NUMBER_OUT_OF_RANGE; // Error

		
		case GPIOD:
		if (pin_number < 7)
		{
			if (GET_BIT(value, 0) == LOW)
			{
				CLR_BIT(PORTD_DATA, pin_number);
			}
			else
			{
				SET_BIT(PORTD_DATA, pin_number);
			}
			return NO_ERRORS; // no errors
		}
		return PIN_NUMBER_OUT_OF_RANGE; // Error


		default: return INVALID_PORT_ID; // GPIO Id isn't defined
	}
}



uint8_t DIO_readPinValue(uint8_t GPIO, uint8_t pin_number)
{
	switch (GPIO)
	{
		case GPIOA:
			if (pin_number < 8) 
			{
				// return the value
				return GET_BIT(PORTA_PIN, pin_number); // no errors
			}
		return PIN_NUMBER_OUT_OF_RANGE; // Error

		case GPIOB:
			if (pin_number < 8) 
			{
				return GET_BIT(PORTB_PIN, pin_number); // no errors
			}
		return PIN_NUMBER_OUT_OF_RANGE; // Error
		
		case GPIOC:
			if (pin_number < 8) 
				{
					return GET_BIT(PORTC_PIN, pin_number); // no errors
				}
		return PIN_NUMBER_OUT_OF_RANGE; // Error
		
		case GPIOD:
		if (pin_number < 8) 
				{
					return GET_BIT(PORTD_PIN, pin_number); // no errors
				}
		return PIN_NUMBER_OUT_OF_RANGE; // Error

	default: return INVALID_PORT_ID; // GPIO Id isn't defined
	}
}

uint8_t DIO_GetPortValue (uint8_t PortNumber) {
	uint8_t value = 0 ;
	switch (PortNumber) {
		case GPIOA :
		value = PORTA_PIN ;
		break;
		
		case GPIOB :
		value = PORTB_PIN ;
		break;
		
		case GPIOC :
		value = PORTC_PIN ;
		break;

		case GPIOD :
		value = PORTD_PIN ;
		break;
	}
	return value ;
}

void DIO_SetPortValue (uint8_t PortNumber , uint8_t Value) {
	switch(PortNumber) {
		case GPIOA :
		PORTA_DATA = Value ;
		break;
		
		case GPIOB :
		PORTB_DATA = Value ;
		break;
		
		case GPIOC :
		PORTC_DATA = Value ;
		break;
		
		case GPIOD :
		PORTD_DATA = Value ;
		break;
	}
}

void DIO_SetPortDirection (uint8_t PortNumber , uint8_t Direction) {
	switch(PortNumber) {
		case GPIOA :
		if (Direction == OUTPUT) {
			PORTA_DDR = 0xff ;
		}
		else if (Direction == INPUT) {
			PORTA_DDR = 0x00 ;
		}
		break;
		
		case GPIOB :
		if (Direction == OUTPUT) {
			PORTB_DDR = 0xff ;
		}
		else if (Direction == INPUT) {
			PORTB_DDR = 0x00 ;
		}
		break;
		
		case GPIOC :
		if (Direction == OUTPUT) {
			PORTC_DDR = 0xff ;
		}
		else if (Direction == INPUT) {
			PORTC_DDR = 0x00 ;
		}
		break;
		
		case GPIOD :
		if (Direction == OUTPUT) {
			PORTD_DDR = 0xff ;
		}
		else if (Direction == INPUT) {
			PORTD_DDR = 0x00 ;
		}
		break;
	}
}