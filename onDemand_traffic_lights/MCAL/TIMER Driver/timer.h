/*
 * timer.h
 *
 * Created: 4/9/2023 1:17:05 AM
 *  Author: Hassan
 */ 


#ifndef TIMER_H_
#define TIMER_H_
 
#include "../../Utilities/registers.h" 
#include "../../Utilities/type.h"


#define NUMBER_OF_OVERFLOW 19
#define SEC_OF_OVERFLOW 4
#define LONG_PRESS_OVERFLOW 6


void TIMER_init(void) ;
void TIMER_start(void);
void TIMER_1sec(void);
void TIMER_5sec(void);
void TIMER_stop(void);

		
	
	





#endif /* TIMER_H_ */