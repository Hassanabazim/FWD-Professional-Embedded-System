/*
 * timer.c
 *
 * Created: 4/9/2023 1:16:49 AM
 *  Author: Hassan
 */ 

#include "timer.h"

void TIMER_init(void)
{
	// choose time mode (Normal)
	TCCR0 = 0x00 ; 
	
	// set Timer initial value
	TCNT0 = 0x00 ;
}

void TIMER_start(void)
{
	// start timer -> setting the clock source (1024 prescaler)
	TCCR0 |= (1<<0) | (1<<2) ;
	TCCR0 &= ~(1<<1) ;
}

void TIMER_1sec(void)
{
	uint16_t overflows = 0;

	while (overflows < SEC_OF_OVERFLOW)
	{
		// stop after the no.of overflow is done and set
		// to exit the while loop ->  5 sec delay
		while ((TIFR & (1<<0)) == 0);
		
		// clear the overflow flag pin by writing 1
		TIFR |= (1<<0);
		
		overflows ++ ;
	}
}

void TIMER_5sec(void)
{
	uint16_t overflows = 0;

	while (overflows < NUMBER_OF_OVERFLOW)
	{
		// stop after the no.of overflow is done and set
		// to exit the while loop ->  5 sec delay
		while ((TIFR & (1<<0)) == 0);
		
		// clear the overflow flag pin by writing 1
		TIFR |= (1<<0);
		
		overflows ++ ;
	}
}

void TIMER_stop(void) 
{
	TCCR0 = 0x00;
}