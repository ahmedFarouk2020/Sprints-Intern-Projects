/*
 * Delay_interface.h
 *
 * Created: 9/15/2021 1:21:53 PM
 *  Author: Farouk
 */ 


#ifndef DELAY_INTERFACE_H_
#define DELAY_INTERFACE_H_

//---- Function Prototypes
void Delay_Init(void);

void Delay_ms(uint16_t ticks_num);


void Delay_us(uint16_t ticks_num);

void Delay_us_independent(uint16_t time_us);
void Delay_ms_independent(uint8_t time_ms);

//----- Calibration
#define OVERLOAD_TIME_MS	3
#define OVERLOAD_TIME_US	40

#endif /* DELAY_INTERFACE_H_ */