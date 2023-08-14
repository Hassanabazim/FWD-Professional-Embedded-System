/*
 * bit_math.h
 *
 * Created: 4/4/2023 9:53:14 AM
 *  Author: Hassan
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(REG,BIT)	REG |= (1<<BIT)
#define CLR_BIT(REG,BIT)   	REG &= ~(1<<BIT)
#define TOG_BIT(REG,BIT)   	REG ^= (1<<BIT)
#define GET_BIT(REG,BIT)   	(REG >> (BIT)) & 1

#endif /* BIT_MATH_H_ */
