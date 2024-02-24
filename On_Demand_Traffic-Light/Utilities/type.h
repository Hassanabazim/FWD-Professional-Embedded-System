/*
 * type.h
 *
 * Created: 4/4/2023 9:53:14 AM
 *  Author: Hassan
 */ 


#ifndef TYPE_H_
#define TYPE_H_

#define NULL (void*) 0

typedef signed char          s8;            /*                     -128 - 12                          */
typedef unsigned char        u8;           	/*                      0 - 255                           */
typedef signed short         s16;          	/*                  -32,768 - 32,767                      */
typedef unsigned short       u16;          	/*                      0 - 65,535                        */
typedef signed long          s32;          	/*             -2,147,483,648 - 2,147,483,647             */
typedef unsigned long        u32;          	/*                   0 - 4,294,967,295                    */
typedef signed long long     s64;          	/* -9,223,372,036,854,775,808 - 9,223,372,036,854,775,807 */
typedef unsigned long long   u64;          	/*              0 - 18,446,744,073,709,551,615            */
typedef float                f32;          	/*                    3.4e-38 -> 4e+38                    */
typedef double               f64;         	/*                  1.7e-308 -> 1.7e+308                  */
typedef long double          f128;         	/*                  3.4e-4932 -> 1.1e+493                 */


#endif /* TYPE_H_ */
