/*
 * dio.h
 *
 * Created: 4/4/2023 9:56:50 AM
 *  Author: Hassan
 */ 


#ifndef DIO_H_
#define DIO_H_

// all internal driver typedefs
#include "../../Utilities/registers.h"

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

void DIO_init(uint8_t portNum, uint8_t pinNum, uint8_t direction); //initialize DIO direction 

void DIO_write(uint8_t portNum, uint8_t pinNum, uint8_t value); // write data to dio

void DIO_toggle(uint8_t portNum, uint8_t pinNum); // toggle dio

void DIO_read(uint8_t portNum, uint8_t pinNum, uint8_t *value); // read dio
/* use pointer to value to avoid return value within function 
and it's better to return as argument for readability*/

#endif /* DIO_H_ */