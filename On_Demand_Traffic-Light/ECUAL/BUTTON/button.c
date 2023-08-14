/*
 * push.c
 *
 * Created: 4/5/2023 4:20:20 AM
 *  Author: Hassan
 */ 

#include "../../Utilities/type.h"
#include "../../MCAL/DIO Driver/dio.h"
#include "button.h"

void BUTTON_init(u8 copy_u8buttonPort,u8 copy_u8buttonPin)
{
	DIO_init(copy_u8buttonPort, copy_u8buttonPin, INPUT);
}

void BUTTON_read(u8 copy_u8buttonPort,u8 copy_u8buttonPin, u8 *ptrValue)
{
	 DIO_read(copy_u8buttonPort, copy_u8buttonPin, ptrValue);
}


