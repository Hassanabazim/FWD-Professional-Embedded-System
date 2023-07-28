/*
 * app.c
 *
 * Created: 4/9/2023 5:38:00 PM
 *  Author: Hassan
 */ 

#include "app.h"

// Global state variable
uint8_t state = 0;

void APP_init(void)
{
	// initialization of Car & Pedestrian LEDS 
	LED_init(PORT_A,0);   
	LED_init(PORT_A,1);
	LED_init(PORT_A,2);
	LED_init(PORT_B,0);
	LED_init(PORT_B,1);
	LED_init(PORT_B,2);
	
	// initialization of Interrupt Service Routine
	BUTTON_init(PORT_D,2);
	sei();
	INTERRUPT_init(INT_0);
	INTERRUPT_senseMode(INT_0,falling_edge);
	
	// initialization of Timer0
	TIMER_init();	
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

void END_state(void)
{
	LEDS_OFF();
	TWO_LEDS_blink(PORT_A,1,PORT_B,1,5); /* Two yellows blinks with delay 5sec divided into 5 blinks*/
	LEDS_OFF();
	LED_on(PORT_B,0); /* turn on the Pedestrian Green LED */ 
	TIMER_5sec();	  /* wait 5 sec */
	LEDS_OFF();
	LED_on(PORT_A,0); /* turn on the Car Green LED */
	LED_on(PORT_B,2); /* turn on the Pedestrian Red LED */
	TIMER_5sec();	  /* wait 5 sec */
	LED_off(PORT_B,2);/* turn off Pedestrian Red LED */ 
}


void Normal_mode(void)
{
	/* for loop that's implement forward and backward shifting bits 
	Green -> Yellow -> Red -> Yellow -> Green, return state (within run-time) for controlling in ped Mode*/
	for (uint8_t i = 0; i < 3; i++)
	{
		TIMER_start();
		if (i == 2)         /* when Red is HIGH create a backward loop */
		{
			LED_on(PORT_A,i);
			state = 1;
			TIMER_5sec();
			LED_off(PORT_A,i);
			for (uint8_t j = 1; j >= 1; j--) /* Red -> 2nd Yellow Blinking */
			{
				if (j == 1)
				{
					LED_blink(PORT_A,j,5);
					state = 2;
					LED_off(PORT_A,j);
				}
			}
		}
		
		else if (i == 1)		/* 1st Yellow Blinking */
		{
			LED_blink(PORT_A,i,5);
			state = 2;
			LED_off(PORT_A,i);			
		}
		
		else				/* Non-conditional state (Green) is HIGH */
		{
			LED_on(PORT_A,i);
			state = 2;
			TIMER_5sec();
			LED_off(PORT_A,i);
		
		}
		TIMER_stop();
	}
}
	
void Pedestrain_mode(void)
{	
	switch(state)
	 {
		 case 1:			/* when Car-Green is ON */
		 LEDS_OFF();
		 LED_on(PORT_A,2);	/* turn on Car-Red */
		 LED_on(PORT_B,0);	/* turn on Ped-Green */
		 TIMER_5sec();
		 END_state();		/* Execute END State */
		 break;
	 
	
		case 2:				/* when Car-Green or Car-Yellow is ON */
		LEDS_OFF();
		LED_on(PORT_B,2);	/* turn on Ped-Red */
		TWO_LEDS_blink(PORT_A,1,PORT_B,1,5); /* blink two Yellows */
		LEDS_OFF();
		LED_on(PORT_A,2);	/* turn on Car-Red */ 
		LED_on(PORT_B,0);	/* turn on Ped-Green */
		TIMER_5sec();
		END_state();        /* Execute END state */
		break;
	}
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
		Pedestrain_mode(); /* when Button Pressed execute the Ped-Mode */
}		