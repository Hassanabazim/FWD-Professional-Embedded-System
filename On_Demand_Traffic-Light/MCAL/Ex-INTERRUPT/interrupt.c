/*
 * INTERRUPT_t.c
 *
 * Created: 4/11/2023 11:09:56 PM
 *  Author: Hassan
 */ 

#include "../../Utilities/type.h"
#include "../../Utilities/registers.h"
#include "../../Utilities/bit_math.h"
#include "INTERRUPT.h"

void sei(void)
{
	SET_BIT(SREG,7);
}

void cli(void)
{
	CLR_BIT(SREG,7);
}

void INTERRUPT_init(INTERRUPT_t copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case INT_0:
		SET_BIT(GICR,6);
		break;

	case INT_1:
		SET_BIT(GICR,7);
		break;

	case INT_2:
		SET_BIT(GICR,5);
		break;

	default:
		break;
	}	
}

void INTERRUPT_senseMode(INTERRUPT_t copy_u8IntID, INTERRUPT_t copy_u8IntMode)
{
	if (copy_u8IntID == INT_0)
	{
		switch(copy_u8IntMode)
		{
		case low_level:
			CLR_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;

		case logical_change:
			SET_BIT(MCUCR,0);
			CLR_BIT(MCUCR,1);
			break;

		case falling_edge:
			SET_BIT(MCUCR,1);
			CLR_BIT(MCUCR,0);
			break;

		case rising_edge:
			SET_BIT(MCUCR,0);
			SET_BIT(MCUCR,1);
			break;

		default:
			break;
		}
	}

	else if (copy_u8IntID == INT_1)
	{	
		switch(copy_u8IntMode)
		{
		case low_level:
			CLR_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;

		case logical_change:
			SET_BIT(MCUCR,2);
			CLR_BIT(MCUCR,3);
			break;

		case falling_edge:
			SET_BIT(MCUCR,3);
			CLR_BIT(MCUCR,2);
			break;

		case rising_edge:
			SET_BIT(MCUCR,2);
			SET_BIT(MCUCR,3);
			break;

		default:
			break;
		}
	}
	else if (copy_u8IntID == INT_2)
	{
		switch(copy_u8IntMode)
		{	
		case falling_edge:
			CLR_BIT(MCUCR,6);
			break;

		case rising_edge:
			SET_BIT(MCUCR,6);
			break;

		default:
			break;
		}
	}
}

void INTERRUPT_stop(INTERRUPT_t copy_u8IntID)
{
	switch(copy_u8IntID)
	{
	case INT_0:
		CLR_BIT(GICR,6);
		break;

	case INT_1:
		CLR_BIT(GICR,7);
		break;

	case INT_2:
		CLR_BIT(GICR,5);
		break;

	default:
		break;
	}
}
