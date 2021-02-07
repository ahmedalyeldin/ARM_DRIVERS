/*
 * GPIO_interface.h
 *
 *  Created on: Feb 3, 2021
 *      Author: ahmed
 */

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#include"STD_TYPES.h"


typedef enum{
DIO_U8_PORTA = 0,
DIO_U8_PORTB,
DIO_U8_PORTC
}  DIO_PORTS;

typedef enum{
DIO_U8_PIN0	= 0,
DIO_U8_PIN1,
DIO_U8_PIN2,
DIO_U8_PIN3,
DIO_U8_PIN4,
DIO_U8_PIN5,
DIO_U8_PIN6,
DIO_U8_PIN7,
DIO_U8_PIN8,
DIO_U8_PIN9,
DIO_U8_PIN10,
DIO_U8_PIN11,
DIO_U8_PIN12,
DIO_U8_PIN13,
DIO_U8_PIN14,
DIO_U8_PIN15
}  DIO_PINS;


typedef enum{
DIO_U8_LOW = 0,
DIO_U8_HIGH
} DIO_STATE;


typedef enum{
/*                INPUT Options                    */
DIO_INPUT_ANALOG	=   	0b0000,
DIO_INPUT_FLOATING	=	    0b0100,
DIO_INPUT_PULL_UP_DOWN =	0b1000,

/*				OUTPUT 2 MHz Options			*/
DIO_OUTPUT_2MHZ_PP	=   	0b0010,
DIO_OUTPUT_2MHZ_OD	=   	0b0110,
DIO_OUTPUT_2MHZ_AF_PP =  	0b1010,
DIO_OUTPUT_2MHZ_AF_OD = 	0b1110,

/*				OUTPUT 10 MHz Options			*/
DIO_OUTPUT_10MHZ_PP	=   	0b0001,
DIO_OUTPUT_10MHZ_OD	=   	0b0101,
DIO_OUTPUT_10MHZ_AF_PP =    0b1001,
DIO_OUTPUT_10MHZ_AF_OD =    0b1101,

/*				OUTPUT 50 MHz Options			*/
DIO_OUTPUT_50MHZ_PP	=	0b0011,
DIO_OUTPUT_50MHZ_OD	=	0b0111,
DIO_OUTPUT_50MHZ_AF_PP =0b1011,
DIO_OUTPUT_50MHZ_AF_OD= 0b1111
} DIO_MODES;



void	DIO_voidSetPinDirection(DIO_PORTS Copy_u8PortID,DIO_PINS Copy_u8PinID,DIO_MODES Copy_u8Mode);
void    DIO_voidSetPortDirection(DIO_PORTS Copy_u8PortID,DIO_MODES Copy_u8Mode);

void    DIO_voidSetPortValue(DIO_PORTS Copy_u8PortID,u16 Copy_u8Value);
void	DIO_voidSetPinValue(DIO_PORTS Copy_u8PortID,DIO_PINS Copy_u8PinID,DIO_STATE Copy_u8Value);


u8      DIO_u8GetPinValue(DIO_PORTS Copy_u8PortID,DIO_PINS Copy_u8PinID);
u8		DIO_u8GetPortValue(DIO_PORTS Copy_u8PortID);

#endif /* GPIO_INTERFACE_H_ */
