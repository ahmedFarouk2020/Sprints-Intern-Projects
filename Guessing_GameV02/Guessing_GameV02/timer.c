/********************************************************/
/*  author     :  Farouk                                */
/*  date       :  2 SEPT 2021                           */
/*  version    :  V01      								*/
/*  Description:  normal-mode timer0 driver 
				  (can be updated with the others) 	    */
/********************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "timer_interface.h"
#include "timer_private.h"
#include "timer_config.h"


/* Callback functions */
void (* volatile overflow_callback)(void) = 0;
void (* volatile CTC_callback)(void) = 0;



void global_int_enable(void)
{
	#define SREG  *((volatile uint8_t*)(0x5F))
	SET_BIT(SREG, 7);
}


void timer_setCallback(void(*ptr_to_func)(void))
{
	overflow_callback = ptr_to_func;
}

sint8_t timer_init(void)
{
	// set mode
	#if TIMER_MODE == NORMAL
	TCCR0 |= 0x00;
	#endif
	return 1;
}

#if KEY == UNLOCKED // ********************************
sint8_t timer_enableInterrupt(uint8_t flag)
{
	#if TIMER_ID == TIMER0
	if (flag == OVERFLOW_FLAG || flag == COMPARE_FLAG )
	{
		TIMSK |= (1<<flag);
		return 1;
	}
	return -1; // Invalid input
	#endif
}
#endif // ***********************************


sint8_t timer_start(uint8_t timerID)
{
	// set clk source and start timer operation
	TCCR0 &= ~(0x07); // clear prescaler bits 
	TCCR0 |= CLK_SOURCE; // set the value to register
	return 1;
}


sint8_t timer_setClk_start(uint8_t timerID, uint8_t clk)
{
	// set clk source and start timer operation
	TCCR0 &= ~(0x07); // clear prescaler bits
	TCCR0 |= clk; // set the value to register
	return 1;
}


sint8_t timer_setInterval(uint16_t num_of_counts)
{
	TCNT0 = 256-num_of_counts;
	return 1;
}


sint8_t timer_read(uint8_t *value)
{
	*value = TCNT0;
	return 1;
}


#if KEY == LOCKED // ********************************
sint8_t timer_setConfigrations(uint8_t timerID, uint8_t Tmode)
{
	return 1;
}
#endif // ********************************************


sint8_t timer_stop(uint8_t timerID)
{
	// set clk source as no clk
	TCCR0 &= ~(0x07); // clear prescaler bits 
	TCCR0 |= STOPPED; // set the value to register
	return 1;
}

sint8_t timer_waitFlag(uint8_t flagID)
{
	switch (flagID)
	{
		case OVERFLOW_FLAG:
			// wait until flag is set
			while(!GET_BIT(TIFR, 0));
			// clear flag
			SET_BIT(TIFR, 0);
			break;
		case COMPARE_FLAG:
			// wait until flag is set
			while(!GET_BIT(TIFR, 1));
			// clear flag
			SET_BIT(TIFR, 1);
			break;
		default:	return -1; // data not valid
	}
	return 1; // No Errors
}




void __vector_11(void) 
{
	if (overflow_callback != 0)
	{
		//TCNT0 = 256-145; // set the value again
		overflow_callback();
	}
}


//ISR( _VECTOR(10))
//{
	//if ( CTC_Isr != 0)
	//{
		//CTC_Isr();
	//}
//}
