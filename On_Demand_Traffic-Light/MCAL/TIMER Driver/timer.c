/*
 * timer.c
 *
 * Created: 4/9/2023 1:16:49 AM
 *  Author: Hassan
 */ 

#include "../../Utilities/type.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_math.h"
#include "timer.h"

void TIMER_init(void)
{
	// choose time mode (Normal)
	CLR_BIT(TCCR0, 3);
	CLR_BIT(TCCR0, 6);
}

void TIMER_start(void)
{
	// start timer -> setting the clock source

	TCCR0 &= TIMER0_PRESCALER_MASK;
	TCCR0 |= TIMER0_PRESCALER;
}



void TIMER_DelayMS(u32 copy_u16delay)
{
	u8 prescaler[5] = {1,8,64,256,1024};
	f32 tickTime = prescaler[TIMER0_PRESCALER - 1] / FCPU ;
	f32 OVFtime = tickTime * 256;
	u16 OVFnum = ((copy_u16delay * 1000 )  / OVFtime);
	u16 preload = 256 - (OVFnum / 2) ;
	TCNT0 =  preload;

	u16 OvfCounter = 0;
	while (OvfCounter < OVFnum )
	{
		// stop after the no.of overflow is done and set
		while ((TIFR & (1<<0)) == 0);

		// clear the overflow flag pin by writing 1
		SET_BIT(TIFR,0);
		OvfCounter ++ ;
	}
}

void TIMER_stop(void) 
{
	TCCR0 = 0x00;
}
