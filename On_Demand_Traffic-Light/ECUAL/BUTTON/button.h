/*
 * button.h
 *
 * Created: 4/5/2023 3:34:59 AM
 *  Author: Hassan
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#define PRESSED 1
#define NOT_PRESSED 0

void BUTTON_init(u8 copy_u8buttonPort,u8 copy_u8buttonPin);
void BUTTON_read(u8 copy_u8buttonPort,u8 copy_u8buttonPin, u8 *ptrValue);



#endif /* BUTTON_H_ */
