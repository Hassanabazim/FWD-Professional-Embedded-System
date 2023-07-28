/*
 * dio.c
 *
 * Created: 4/4/2023 9:57:14 AM
 *  Author: Hassan
 */ 

#include "dio.h"


void DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t direction)
{
	switch (portNum)
	{
		case PORT_A :
		if (direction == INPUT)
		{
			DDRA &= ~(1<<pinNum);
		}
		else if(direction == OUTPUT)
		{
			DDRA |= (1<<pinNum);
		}
		
		break ;
	
		case PORT_B :
		if (direction == INPUT)
		{
			DDRB &= ~(1<<pinNum);
		}
		else if(direction == OUTPUT)
		{
			DDRB |= (1<<pinNum);
		}
		
		break ;
	
		case PORT_C :
		if (direction == INPUT)
		{
			DDRC &= ~(1<<pinNum);
		}
		else if(direction == OUTPUT)
		{
			DDRC |= (1<<pinNum);
		}
		
		break ;
	
		case PORT_D :
		if (direction == INPUT)
		{
			DDRD &= ~(1<<pinNum);
		}
		else if(direction == OUTPUT)
		{
			DDRD |= (1<<pinNum);
		}
		
		break ;
	}
}

void DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value)
{
	switch (portNum)
	{
		case PORT_A :
		if (value == HIGH)
		{
			PORTA |= (1<<pinNum);
		} 
		else if (value == LOW)
		{
			PORTA &= ~(1<<pinNum);
		}
		
		break;
		
		case PORT_B :
		if (value == HIGH)
		{
			PORTB |= (1<<pinNum);
		}
		else if (value == LOW)
		{
			PORTB &= ~(1<<pinNum);
		}
		
		break;
	
		case PORT_C :
		if (value == HIGH)
		{
			PORTC |= (1<<pinNum);
		}
		else if (value == LOW)
		{
			PORTC &= ~(1<<pinNum);
		}
		
		
		case PORT_D :
		if (value == HIGH)
		{
			PORTD |= (1<<pinNum);
		}
		else if (value == LOW)
		{
			PORTD &= ~(1<<pinNum);
		}
		
		break;
	} 
}

void DIO_toggle(uint8_t portNum, uint8_t pinNum)
{
	switch (portNum)
	{
		case PORT_A:
		PORTA ^= (1<<pinNum);
		break;
		
		case PORT_B:
		PORTB ^= (1<<pinNum);
		break;
		
		case PORT_C:
		PORTC ^= (1<<pinNum);
		break;
		
		case PORT_D:
		PORTD ^= (1<<pinNum);
		break;
	}
}


void DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t *value)
{
	switch(portNum)
	{
		case PORT_A:
		*value = ((PINA & (1<<pinNum)) >>pinNum) ; 
		break;
		
		case PORT_B:
		*value = ((PINB & (1<<pinNum)) >>pinNum);
		break;
		
		case PORT_C:
		*value = ((PINC & (1<<pinNum)) >>pinNum) ;
		break;
		
		case PORT_D:
		*value = ((PIND & (1<<pinNum)) >>pinNum) ;
		break;	
	}
}
