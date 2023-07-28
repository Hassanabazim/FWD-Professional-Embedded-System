/*
 * led.h
 *
 * Created: 4/5/2023 4:10:16 AM
 *  Author: Hassan
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO Driver/dio.h"

void LED_init(uint8_t ledPort, uint8_t ledPin);
void LED_on(uint8_t ledPort, uint8_t ledPin);
void LED_off(uint8_t ledPort, uint8_t ledPin);
void LED_toggle(uint8_t ledPort, uint8_t ledPin);
void LED_blink( uint8_t ledPort, uint8_t ledPin, uint8_t delay);
void TWO_LEDS_blink(uint8_t Port_1, uint8_t pin_1, uint8_t port_2, uint8_t pin_2,uint8_t delay);




#endif /* LED_H_ */