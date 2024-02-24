/*
 * app.c
 *
 * Created: 4/9/2023 5:38:00 PM
 *  Author: Hassan
 */ 

#include "../Utilities/type.h"
#include "../MCAL/DIO Driver/dio.h"
#include "../MCAL/Ex-INTERRUPT/interrupt.h"
#include "../MCAL/TIMER Driver/timer.h"
#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"
#include "app.h"

static u8 LedState ;
static void LEDS_OFF(void);
static void Normal_mode(void);
static void Pedestrain_mode(void);

void APP_init(void)
{
	/* initialization of Car LEDS */
	LED_init(PORT_A,0);
	LED_init(PORT_A,1);
	LED_init(PORT_A,2);

	/* initialization of Pedestrian LEDS */
	LED_init(PORT_B,0);
	LED_init(PORT_B,1);
	LED_init(PORT_B,2);

	/* initialization of Pedestrian Button */
	BUTTON_init(PORT_D,2);

	/* initialization of Interrupt Service Routine */
	sei();
	INTERRUPT_init(INT_0);
	INTERRUPT_senseMode(INT_0, rising_edge);

	/* initialization of Timer0 */
	TIMER_init();
	TIMER_start();
}

void APP_start(void)
{
	while(1)
	{
		Normal_mode(); /* Execute only the Normal mode */
	}
}


ISR(EXT_INT_0)
{
	cli();
	Pedestrain_mode(); 	/* when Button Pressed execute the Ped-Mode */
	sei();
}


void Normal_mode(void)
{
	/* for loop that's implement forward and backward shifting bits 
		Green -> Yellow -> Red -> Yellow -> Green,
	 return state (within run-time) for controlling in ped Mode*/
	for ( LedState = 0; LedState < 3; LedState++)
	{
		LEDS_OFF();
		if (LedState == 0)
		{
			LED_on(PORT_A,LedState);
			TIMER_DelayMS(5000);
		}

		else if (LedState == 1)		/* 1st Yellow Blinking */
		{
			LED_blink(PORT_A,LedState);
		}

		else        /* when Red is HIGH create a backward loopRed -> 2nd Yellow Blinking */
		{
			LED_on(PORT_A,LedState);
			TIMER_DelayMS(5000);
			LEDS_OFF();
			LED_blink(PORT_A,LedState-1);
			LedState=-2;
		}
	}
}

void Pedestrain_mode(void)
{	
	if (LedState == 2)
	{
		/* when Car-RED is ON */
		LEDS_OFF();
		LED_on(PORT_A,2);	/* turn on Car-Red */
		LED_on(PORT_B,0);	/* turn on Ped-Green */
		TIMER_DelayMS(5000);
	}

	else if (LedState == 0 || LedState == 1)
	{
		/* when Car-Green or Car-Yellow is ON */
		LEDS_OFF();
		LED_on(PORT_B,2);	/* turn on Ped-Red */
		TWO_LEDS_blink(PORT_A,1,PORT_B,1); /* blink two Yellows */
		LEDS_OFF();
		LED_on(PORT_A,2);	/* turn on Car-Red */ 
		LED_on(PORT_B,0);	/* turn on Ped-Green */
		TIMER_DelayMS(5000);
	}

	LED_off(PORT_A,2);
	TWO_LEDS_blink(PORT_A,1,PORT_B,1); /* Two yellows blinks with delay 5sec divided into 5 blinks*/
	LEDS_OFF();
	LED_on(PORT_A,0); /* turn on the Car Green LED */
	LED_on(PORT_B,2); /* turn on the Pedestrian Red LED */
}




void TWO_LEDS_blink(u8 Port1, u8 pin1, u8 port2, u8 pin2)
{
	u8 blink = 0;
	while (blink < 10)
	{
		DIO_toggle(Port1,pin1);
		DIO_toggle(port2,pin2);
		TIMER_DelayMS(500);
		blink ++ ;
	}
}

void LED_blink(u8 port, u8 pin)
{
	u8 blink = 0;
	while (blink < 10)
	{
		DIO_toggle(port, pin);
		TIMER_DelayMS(500);
		blink++ ;
	}
}

//Function like a Buffer in the Run-time
void LEDS_OFF(void)
{
	LED_off(PORT_A,0);
	LED_off(PORT_A,1);
	LED_off(PORT_A,2);
	LED_off(PORT_B,0);
	LED_off(PORT_B,1);
	LED_off(PORT_B,2);
}
