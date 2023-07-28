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
/* 0x3B is an an address of portA ,uint8_t is casting pointer to point to the address
volatile used with external hardware might been written on
and to alert the compiler to not optimize the input
* dereferencers pointer to write on the address */

/************************/
/*  STATUS REGISTERS   */
/**********************/

#define SREG  *((volatile uint8_t*)0x5F)

//PORT A Registers 
#define DDRA  *((volatile uint8_t*)0x3A)
#define PORTA *((volatile uint8_t*)0x3B)
#define PINA  *((volatile uint8_t*)0x39)

// PORT B Registers
#define DDRB  *((volatile uint8_t*)0x37)
#define PORTB *((volatile uint8_t*)0x38)
#define PINB  *((volatile uint8_t*)0x36)

// PORT C Registers
#define DDRC  *((volatile uint8_t*)0x34)
#define PORTC *((volatile uint8_t*)0x35)
#define PINC  *((volatile uint8_t*)0x33)

// PORT D Registers
#define DDRD  *((volatile uint8_t*)0x31)
#define PORTD *((volatile uint8_t*)0x32)
#define PIND  *((volatile uint8_t*)0x30)


/**************************/
/**   TIMER0 Register    **/
/************************/

// TIFR (TIMER INTERUPT FLAG REGISTER)
#define TIFR *((volatile uint8_t*)0x58)

// TCCR0 (TIMER/COUNTR CONTROL REGISTER)
#define TCCR0 *((volatile uint8_t*)0x53)

// TCNT0 (TIMER/COUNTER)
#define TCNT0 *((volatile uint8_t*)0x52)
 
/*************************/
/* Interrupt Registers  */
/***********************/
#define GICR   *((volatile uint8_t*)0x5B)
#define MCUCR  *((volatile uint8_t*)0x55)
#define GIFR   *((volatile uint8_t*)0x5A)
#define MCUCSR *((volatile uint8_t*)0x54)



#endif /* REGISTERS_H_ */