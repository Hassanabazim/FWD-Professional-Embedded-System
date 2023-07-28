/*
 * led.c
 *
 * Created: 4/5/2023 4:09:57 AM
 *  Author: Hassan
 */ 

#include "led.h"


void LED_init(uint8_t ledPort, uint8_t ledPin) 
{
	DIO_init(ledPort, ledPin, OUTPUT);
}
void LED_on(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, HIGH);
}
void LED_off(uint8_t ledPort, uint8_t ledPin)
{
	DIO_write(ledPort, ledPin, LOW);
}
void LED_toggle(uint8_t ledPort, uint8_t ledPin)
{
	DIO_toggle(ledPort, ledPin);
}

void LED_blink( uint8_t ledPort, uint8_t ledPin, uint8_t delay)
{
	uint8_t blink = 0;
	while (blink < delay)
	{
		LED_toggle(ledPort,ledPin);
		TIMER_1sec();
		blink ++ ;
	}
}

void TWO_LEDS_blink(uint8_t Port_1, uint8_t pin_1, uint8_t port_2, uint8_t pin_2,uint8_t delay)
{
	uint8_t blink = 0;
	while (blink < delay)
	{
		LED_toggle(Port_1,pin_1);
		LED_toggle(port_2,pin_2);
		TIMER_1sec();
		blink ++ ;
	}
}
