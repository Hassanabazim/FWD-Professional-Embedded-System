/*
 * push.c
 *
 * Created: 4/5/2023 4:20:20 AM
 *  Author: Hassan
 */ 
#include "button.h"

void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin)
{
	DIO_init(buttonPort, buttonPin, INPUT);	
}
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin, uint8_t *value)
{
	 DIO_read(buttonPort, buttonPin, value);
}


