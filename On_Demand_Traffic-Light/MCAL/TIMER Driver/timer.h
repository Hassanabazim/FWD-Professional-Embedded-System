/*
 * timer.h
 *
 * Created: 4/9/2023 1:17:05 AM
 *  Author: Hassan
 */ 


#ifndef TIMER_H_
#define TIMER_H_
 
#define FCPU	8UL

#define TIMER0_PRESCALER_MASK		0xF8
#define TIMER0_NO_CLK 				0
#define TIMER0_PRESCALER_1			1
#define TIMER0_PRESCALER_8			2
#define TIMER0_PRESCALER_64			3
#define TIMER0_PRESCALER_256		4
#define TIMER0_PRESCALER_1024		5

#define TIMER0_PRESCALER	TIMER0_PRESCALER_1024

void TIMER_init(void) ;
void TIMER_start(void);
void TIMER_DelayMS(u32 copy_u16delay);
void TIMER_stop(void);

		
	
	





#endif /* TIMER_H_ */
