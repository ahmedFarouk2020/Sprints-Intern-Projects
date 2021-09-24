#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/* Register Definition */
#define PORTA_DATA	*((volatile uint8_t*)0x3B)
#define PORTB_DATA  *((volatile uint8_t*)0x38)
#define PORTC_DATA  *((volatile uint8_t*)0x35)
#define PORTD_DATA  *((volatile uint8_t*)0x32)

#define PORTA_DDR   *((volatile uint8_t*)0x3A)
#define PORTB_DDR   *((volatile uint8_t*)0x37)
#define PORTC_DDR   *((volatile uint8_t*)0x34)
#define PORTD_DDR   *((volatile uint8_t*)0x31)

#define PORTA_PIN   *((volatile uint8_t*)0x39)
#define PORTB_PIN   *((volatile uint8_t*)0x36)
#define PORTC_PIN   *((volatile uint8_t*)0x33)
#define PORTD_PIN   *((volatile uint8_t*)0x30)


#endif