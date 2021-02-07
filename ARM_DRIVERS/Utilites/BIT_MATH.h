/*
 * BIT_MATH.h
 *
 *  Created on: Feb 3, 2021
 *      Author: ahmed
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define GET_BIT(reg,bit)  ((reg>>bit)&1)
#define SET_BIT(reg,bit)  (reg=((1<<bit)|reg))
#define CLR_BIT(reg,bit)  (reg=((~(1<<bit))&reg))
#define TGL_BIT(reg,bit)  (reg=((1<<bit)^reg))

#endif /* BIT_MATH_H_ */
