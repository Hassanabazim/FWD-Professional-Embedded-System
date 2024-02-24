/*
 * dio.h
 *
 * Created: 4/4/2023 9:56:50 AM
 *  Author: Hassan
 */ 

#include "../../Utilities/type.h"

#ifndef DIO_H_
#define DIO_H_

// all internal driver typedefs

// all driver macros
// Values 
#define HIGH 1 
#define LOW 0

// direction 
#define INPUT 0
#define OUTPUT 1

// PORTS 
#define PORT_A  'A'
#define PORT_B  'B'
#define PORT_C  'C'
#define PORT_D  'D'


// all driver function prototypes

void DIO_init(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8direction);

void DIO_write(u8 copy_u8port, u8 copy_u8pin, u8 copy_u8Value);

void DIO_toggle(u8 copy_u8port, u8 copy_u8pin);

void DIO_read(u8 copy_u8port, u8 copy_u8pin, u8 *ptrValue);

#endif /* DIO_H_ */
