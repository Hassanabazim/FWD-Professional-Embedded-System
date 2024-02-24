/*
 * dio.c
 *
 * Created: 4/4/2023 9:57:14 AM
 *  Author: Hassan
 */ 

#include "../../Utilities/type.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_math.h"
#include "dio.h"


void DIO_init(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8direction)
{
	switch (copy_u8port)
	{
	case PORT_A :
		if (copy_u8direction == INPUT)
		{
			CLR_BIT(DDRA,copy_u8pin);
		}
		else if(copy_u8direction == OUTPUT)
		{
			SET_BIT(DDRA,copy_u8pin);
		}

		break ;

	case PORT_B :
		if (copy_u8direction == INPUT)
		{
			CLR_BIT(DDRB,copy_u8pin);
		}
		else if(copy_u8direction == OUTPUT)
		{
			SET_BIT(DDRB,copy_u8pin);
		}

		break ;

	case PORT_C :
		if (copy_u8direction == INPUT)
		{
			CLR_BIT(DDRC,copy_u8pin);
		}
		else if(copy_u8direction == OUTPUT)
		{
			SET_BIT(DDRC,copy_u8pin);
		}

		break ;

	case PORT_D :
		if (copy_u8direction == INPUT)
		{
			CLR_BIT(DDRD,copy_u8pin);
		}
		else if(copy_u8direction == OUTPUT)
		{
			SET_BIT(DDRD,copy_u8pin);
		}

		break ;
	}
}

void DIO_write(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8Value)
{
	switch (copy_u8port)
	{
	case PORT_A :
		if (copy_u8Value == HIGH)
		{
			SET_BIT(PORTA,copy_u8pin);
		} 
		else if (copy_u8Value == LOW)
		{
			CLR_BIT(PORTA,copy_u8pin);
		}
		break;

	case PORT_B :
		if (copy_u8Value == HIGH)
		{
			SET_BIT(PORTB,copy_u8pin);
		}
		else if (copy_u8Value == LOW)
		{
			CLR_BIT(PORTB,copy_u8pin);
		}

		break;

	case PORT_C :
		if (copy_u8Value == HIGH)
		{
			SET_BIT(PORTC,copy_u8pin);
		}
		else if (copy_u8Value == LOW)
		{
			CLR_BIT(PORTC,copy_u8pin);
		}
		break;


	case PORT_D :
		if (copy_u8Value == HIGH)
		{
			SET_BIT(PORTD,copy_u8pin);

		}
		else if (copy_u8Value == LOW)
		{
			CLR_BIT(PORTD,copy_u8pin);
		}

		break;
	} 
}

void DIO_toggle(u8 copy_u8port, u8 copy_u8pin)
{
	switch (copy_u8port)
	{
	case PORT_A:
		TOG_BIT(PORTA,copy_u8pin);
		break;

	case PORT_B:
		TOG_BIT(PORTB,copy_u8pin);
		break;

	case PORT_C:
		TOG_BIT(PORTC,copy_u8pin);
		break;

	case PORT_D:
		TOG_BIT(PORTD,copy_u8pin);
		break;
	}
}


void DIO_read(u8 copy_u8port, u8 copy_u8pin, u8 *ptrValue)
{
	switch(copy_u8port)
	{
	case PORT_A:
		*ptrValue = GET_BIT(PINA,copy_u8pin) ;
		break;

	case PORT_B:
		*ptrValue = GET_BIT(PINB,copy_u8pin) ;
		break;

	case PORT_C:
		*ptrValue = GET_BIT(PINC,copy_u8pin) ;
		break;

	case PORT_D:
		*ptrValue = GET_BIT(PIND,copy_u8pin) ;
		break;	
	}
}
