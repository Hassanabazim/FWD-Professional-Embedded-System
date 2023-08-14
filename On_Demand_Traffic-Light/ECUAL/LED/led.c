/*
 * led.c
 *
 * Created: 4/5/2023 4:09:57 AM
 *  Author: Hassan
 */ 

#include "../../Utilities/type.h"
#include "../../MCAL/DIO Driver/dio.h"
#include "led.h"


void LED_init(u8 copy_u8ledPort, u8 copy_u8ledPin)
{
	DIO_init(copy_u8ledPort, copy_u8ledPin, OUTPUT);
}
void LED_on(u8 copy_u8ledPort, u8 copy_u8ledPin)
{
	DIO_write(copy_u8ledPort, copy_u8ledPin, HIGH);
}
void LED_off(u8 copy_u8ledPort, u8 copy_u8ledPin)
{
	DIO_write(copy_u8ledPort, copy_u8ledPin, LOW);
}
void LED_toggle(u8 copy_u8ledPort, u8 copy_u8ledPin)
{
	DIO_toggle(copy_u8ledPort, copy_u8ledPin);
}


