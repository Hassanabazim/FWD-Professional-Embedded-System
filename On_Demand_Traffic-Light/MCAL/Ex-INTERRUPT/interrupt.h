/*
 * INTERRUPT.h
 *
 * Created: 4/8/2023 7:22:06 AM
 *  Author: Hassan
 */ 

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

// External INTERRUPT_ts Vectors

#define  EXT_INT_0 __vector_1
#define  EXT_INT_1 __vector_2
#define  EXT_INT_2 __vector_3

typedef enum
{	INT_0,
	INT_1,
	INT_2,
	low_level,
	logical_change,
	falling_edge,
	rising_edge
}INTERRUPT_t;

void sei(void);
void cli(void);
void INTERRUPT_init(INTERRUPT_t copy_u8IntID);
void INTERRUPT_senseMode(INTERRUPT_t copy_u8IntID, INTERRUPT_t copy_u8IntMode);
void INTERRUPT_stop(INTERRUPT_t copy_u8IntID);


//ISR definition 
#define ISR(INT_VECT)void INT_VECT(void) __attribute__ ((signal,used));\
void INT_VECT(void)

 
 #endif /* INTERRUPT_H_ */
