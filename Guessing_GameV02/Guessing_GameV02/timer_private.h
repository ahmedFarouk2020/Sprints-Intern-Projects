/*********************************************************/
/*  author   :  farouk                                   */
/*  date     :  2 SEPT 2021                              */
/*  version  :  V01                                      */
/*********************************************************/

#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_


/* Register Definition */

#define TCCR0	*((volatile uint8_t *)(0x53))
#define TCNT0	*((volatile uint8_t *)(0x52))
#define OCR0	*((volatile uint8_t *)(0x5C))
#define TIMSK	*((volatile uint8_t *)(0x59))
#define TIFR	*((volatile uint8_t *)(0x58))




#endif