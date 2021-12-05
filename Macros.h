/*
 * Macros.h
 *
 *  Created on: Sep 11, 2021
 *      Author: hp
 */

#ifndef MACROS_H_
#define MACROS_H_

#define SET_BIT(reg,bit) reg |= (1<<bit)
#define CLEAR_BIT(reg,bit) reg &= ~(1<<bit)
#define GET_BIT(reg,bit) ((reg>>bit)&1)
#define TOGGLE_BIT(reg,bit) reg ^= (1<<bit)

#endif /* MACROS_H_ */
