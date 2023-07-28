/*
 * interrupt.c
 *
 * Created: 4/11/2023 11:09:56 PM
 *  Author: Hassan
 */ 

#include "interrupt.h"

void sei(void)
{
	SREG |= (1<<7);
}

void cli(void)
{
	SREG &= ~(1<<7);
}

void INTERRUPT_init(INTERRUPT num)
{
	switch(num)
	{
		case INT_0:
		GICR |= (1<<6);
		break;
		
		case INT_1:
		GICR |= (1<<7);
		break;
		
		case INT_2: 
		GICR |= (1<<5);
		break;
		
		default:
		break;
	}	
}

void INTERRUPT_senseMode(INTERRUPT num, INTERRUPT mode)
{
	if (num == INT_0)
	{
		switch(mode)
		{
			case low_level:
			MCUCR &= ~((1<<1)|(1<<0));
			break;
			
			case logical_change:
			MCUCR |= (1<<0);
			MCUCR &= ~(1<<1);
			break;
			
			case falling_edge:
			MCUCR |= (1<<1);
			MCUCR &= ~(1<<0);
			break;
			
			case rising_edge:
			MCUCR |= (1<<1) | (1<<0);
			break;
			
			default:
			break;
		}
	}

	else if (num == INT_1)		
	{	
		switch(mode)
		{
			case low_level:
			MCUCR &= ~((1<<2)|(1<<3));
			break;
			
			case logical_change:
			MCUCR |= (1<<2);
			MCUCR &= ~(1<<3);
			break;
			
			case falling_edge:
			MCUCR |= (1<<3);
			MCUCR &= ~(1<<2);
			break;
			
			case rising_edge:
			MCUCR |= (1<<2) | (1<<3);
			break;
			
			default:
			break;
		}
	}
	else if (num == INT_2)
	{
		switch(mode)
		{	
			case falling_edge:
			MCUCR &= ~(1<<6);
			break;
		
			case rising_edge:
			MCUCR |= (1<<6) ;
			break;
			
			default:
			break;
		}
	}
}

void INTERRUPT_stop(INTERRUPT num)
{
	switch(num)
	{
		case INT_0:
		GICR &= ~(1<<6);
		break;
	
		case INT_1:
		GICR &= ~(1<<7);
		break;
	
		case INT_2:
		GICR &= ~(1<<5);
		break;
	
		default:
		break;
	}
}
