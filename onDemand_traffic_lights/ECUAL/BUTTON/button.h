/*
 * button.h
 *
 * Created: 4/5/2023 3:34:59 AM
 *  Author: Hassan
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../MCAL/DIO Driver/dio.h"

#define PRESSED 1
#define NOT_PRESSED 0

void BUTTON_init(uint8_t buttonPort,uint8_t buttonPin);
void BUTTON_read(uint8_t buttonPort,uint8_t buttonPin, uint8_t *value);



#endif /* BUTTON_H_ */