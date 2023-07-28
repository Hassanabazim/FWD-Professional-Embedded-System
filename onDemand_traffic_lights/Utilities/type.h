/*
 * type.h
 *
 * Created: 4/4/2023 9:53:14 AM
 *  Author: Hassan
 */ 


#ifndef TYPE_H_
#define TYPE_H_


typedef unsigned char uint8_t;  
typedef unsigned int uint16_t;

typedef enum
	{	INT_0,
		INT_1, 
		INT_2,
		low_level,
		logical_change, 
		falling_edge,
		rising_edge
	}INTERRUPT;




#endif /* TYPE_H_ */