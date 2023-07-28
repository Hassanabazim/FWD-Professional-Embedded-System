/*
 * interrupt.h
 *
 * Created: 4/8/2023 7:22:06 AM
 *  Author: Hassan
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#include "../../Utilities/registers.h"
#include "../../Utilities/type.h"

// External Interrupts Vectors

#define  EXT_INT_0 __vector_1
#define  EXT_INT_1 __vector_2
#define  EXT_INT_2 __vector_3


void sei(void);
void cli(void);
void INTERRUPT_init(INTERRUPT num);
void INTERRUPT_senseMode(INTERRUPT num, INTERRUPT mode);
void INTERRUPT_stop(INTERRUPT num);


//ISR definition 
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

 
 #endif /* INTERRUPT_H_ */