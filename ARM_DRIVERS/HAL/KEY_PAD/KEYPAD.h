/*
 * KEYPAD.h
 *
 *  Created on: Feb 6, 2021
 *      Author: ahmedalyeldin
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "STD_TYPES.h"

#define FIRST_INPUT        DIO_U8_PIN4
#define FIRST_INPUT_PORT   DIO_U8_PORTB
#define FIRST_OUTPUT       DIO_U8_PIN8
#define FIRST_OUTPUT_PORT  DIO_U8_PORTB
#define NO_KEY '.'

u8 KEYPAD_Getkey(void);


#endif /* KEYPAD_H_ */
