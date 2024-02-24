/*
 * registers.h
 * All Micro-controllers Registers 
 * Created: 4/4/2023 9:48:54 AM
 *  Author: Hassan Abdelazim
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_
#include "type.h"


/******************************/
/*		DIO REGISTERS        */
/****************************/
/* 0x3B is an an address of portA ,u8 is casting pointer to point to the address
volatile used with external hardware might been written on
and to alert the compiler to not optimize the input
* dereferencers pointer to write on the address */

/************************/
/*  STATUS REGISTERS   */
/**********************/

#define SREG  *((volatile u8*)0x5F)

//PORT A Registers 
#define DDRA  *((volatile u8*)0x3A)
#define PORTA *((volatile u8*)0x3B)
#define PINA  *((volatile u8*)0x39)

// PORT B Registers
#define DDRB  *((volatile u8*)0x37)
#define PORTB *((volatile u8*)0x38)
#define PINB  *((volatile u8*)0x36)

// PORT C Registers
#define DDRC  *((volatile u8*)0x34)
#define PORTC *((volatile u8*)0x35)
#define PINC  *((volatile u8*)0x33)

// PORT D Registers
#define DDRD  *((volatile u8*)0x31)
#define PORTD *((volatile u8*)0x32)
#define PIND  *((volatile u8*)0x30)


/**************************/
/**   TIMER0 Register    **/
/************************/

// TIFR (TIMER INTERUPT FLAG REGISTER)
#define TIFR *((volatile u8*)0x58)

// TCCR0 (TIMER/COUNTR CONTROL REGISTER)
#define TCCR0 *((volatile u8*)0x53)

// TCNT0 (TIMER/COUNTER)
#define TCNT0 *((volatile u8*)0x52)
 
/*************************/
/* Interrupt Registers  */
/***********************/
#define GICR   *((volatile u8*)0x5B)
#define MCUCR  *((volatile u8*)0x55)
#define GIFR   *((volatile u8*)0x5A)
#define MCUCSR *((volatile u8*)0x54)



#endif /* REGISTERS_H_ */
