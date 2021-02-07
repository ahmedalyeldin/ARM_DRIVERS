/*
 * 7SEGMANT.c
 *
 *  Created on: Feb 6, 2021
 *      Author: ahmedalyeldin
 */

#define F_CPU 8000000
#include <SEVEN_SEGMANT.h>
#include "GPIO_interface.h"




void _delay_ms(u32 Copy_u32Time)
{
	for(u32 i = 0 ; i < Copy_u32Time ; i++)
	{
		for(u16 j = 0 ; j < 565 ; j++)
		{
			asm("NOP");
		}
	}

}


void SEVENSEGMENT_print(int number)
{
	#if SEGMENT_TYPE

	#if SEGMANT_COMMON
	u8 arr_cathod[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
	int x1,x2;
	x1 = number%10;
	x2 = number/10;
	DIO_voidSetPinValue(ENABLE_PORT1, ENABLE_PIN1, HIGH);
	DIO_voidSetPortValue(SEGMENT_PORT,(arr_cathod[number%10]));
	DIO_voidSetPinValue(ENABLE_PORT1, ENABLE_PIN2, LOW);
	_delay_ms(1);
	DIO_voidSetPinValue(ENABLE_PORT1, ENABLE_PIN2, HIGH);
	DIO_voidSetPortValue(SEGMENT_PORT,(arr_cathod[number/10]));
	DIO_voidSetPinValue(ENABLE_PORT1, ENABLE_PIN1, LOW);
	_delay_ms(1);

	#else

	u8 arr_anode [10]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};
	int x1,x2;
	x1 = number%10;
	x2 = number/10;
	DIO_voidSetPinValue(ENABLE_PORT1, ENABLE_PIN1, HIGH);
	DIO_voidSetPortValue(SEGMENT_PORT,(arr_anode[number%10]));
	DIO_voidSetPinValue(ENABLE_PORT1, ENABLE_PIN2, LOW);
	_delay_ms(1);
	DIO_voidSetPinValue(ENABLE_PORT1, ENABLE_PIN2, HIGH);
	DIO_voidSetPortValue(SEGMENT_PORT,(arr_anode[number/10]));
	DIO_voidSetPinValue(ENABLE_PORT1, ENABLE_PIN1, LOW);
	_delay_ms(1);
	#endif

	#else

	#if SEGMANT_COMMON
	u16 arr_cathod[10]={0x00C0,0x00F9,0x00A4,0x00B0,0x0099,0x0092,0x0082,0x00F8,0x0080,0x0090};
	DIO_voidSetPortValue(SEGMENT_PORT,(arr_cathod[number]));

	#else

	u16 arr_anode[10]={0x003F,0x0006,0x005B,0x004F,0x0066,0x006D,0x007D,0x0007,0x007F,0x006F};
	DIO_voidSetPortValue(SEGMENT_PORT,(arr_anode[number]));

	#endif
    #endif

}

