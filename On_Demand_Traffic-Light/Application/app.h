/*
 * app.h
 *
 * Created: 4/5/2023 3:48:14 AM
 *  Author: Hassan
 */ 


#ifndef APP_H_
#define APP_H_

#include "../Utilities/type.h"


void LED_blink(u8 port, u8 pin);
void TWO_LEDS_blink(u8 Port1, u8 pin1, u8 port2, u8 pin2);

void APP_init(void);
void APP_start(void);



#endif /* APP_H_ */
