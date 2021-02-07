/*
 * KEYPAD.c
 *
 *  Created on: Feb 6, 2021
 *      Author: ahmedalyeldin
 */


#include "KEYPAD.h"
#include "GPIO_interface.h"
#include "SEVEN_SEGMANT.h"

static const u8 key[4][4] = {   {'7','8','9','/'},
	                            {'4','5','6','*'},
	                            {'1','2','3','-'},
				                {'c','0','=','+'}
                                                    };

u8 KEYPAD_Getkey(void)
{
	u8 r,c,key1= NO_KEY;
	DIO_voidSetPinValue(FIRST_OUTPUT_PORT,FIRST_OUTPUT+0,DIO_U8_HIGH);
	DIO_voidSetPinValue(FIRST_OUTPUT_PORT,FIRST_OUTPUT+1,DIO_U8_HIGH);
	DIO_voidSetPinValue(FIRST_OUTPUT_PORT,FIRST_OUTPUT+2,DIO_U8_HIGH);
	DIO_voidSetPinValue(FIRST_OUTPUT_PORT,FIRST_OUTPUT+3,DIO_U8_HIGH);
	for(r=0 ; r<4 ; r++)
	{
		DIO_voidSetPinValue(FIRST_OUTPUT_PORT,FIRST_OUTPUT+r,DIO_U8_LOW);
		for(c=0 ; c<4 ; c++)
		{
			if(!DIO_u8GetPinValue(FIRST_INPUT_PORT,FIRST_INPUT+c))
			{
				//SEVENSEGMENT_print(0);
			//	_delay_ms(1000);
				key1 = key[r][c];
				while(!DIO_u8GetPinValue(FIRST_INPUT_PORT,FIRST_INPUT+c));
			//	SEVENSEGMENT_print(9);
			}
		}
		DIO_voidSetPinValue(FIRST_OUTPUT_PORT,FIRST_OUTPUT+r,DIO_U8_HIGH);
	}
	return key1;
}
