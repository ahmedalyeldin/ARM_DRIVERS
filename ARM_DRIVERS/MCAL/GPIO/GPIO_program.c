/*
 * GPIO_program.c
 *
 *  Created on: Feb 3, 2021
 *      Author: ahmed
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void	DIO_voidSetPortDirection(DIO_PORTS Copy_u8PortID,DIO_MODES Copy_u8Mode)
{
	/*		Range Check							*/
	if( (Copy_u8PortID<3) )
	{
		switch(Copy_u8PortID)
		{
			case DIO_U8_PORTA:
					GPIOA_CRL &= 0;//~((u32)(0xFFFFFFFF));
					GPIOA_CRH &= 0;// ~((u32)(0x11111111));
                    for(u8 i = 0 ; i<=7 ; i++)
                    {
					GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(i * 4));
					GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(i * 4));
                    }

				break;
			case DIO_U8_PORTB:
                    GPIOB_CRL &= 0;//~((u32)(0x11111111));
                    GPIOB_CRH &= 0;//~((u32)(0x11111111));
                    for(u8 i = 0 ; i<=7 ; i++)
                    {
                    GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(i * 4));
                    GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(i * 4));
                    }
				break;
			case DIO_U8_PORTC:
                    GPIOC_CRL &= 0;// ~((u32)(0x11111111));
                    GPIOC_CRH &= 0;//~((u32)(0x11111111));
                    for(u8 i = 0 ; i<=7 ; i++)
                    {
                    GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(i * 4));
                    GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(i * 4));
                    }
				break;
		}
	}else{/*	Return ERROR	*/}

}

void	DIO_voidSetPinDirection(DIO_PORTS Copy_u8PortID,DIO_PINS Copy_u8PinID,DIO_MODES Copy_u8Mode)
{
	/*		Range Check							*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch(Copy_u8PortID)
		{
			case DIO_U8_PORTA:
				/*		LOW PORT				*/
				if( Copy_u8PinID < 8 )
				{
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOA_CRL &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOA_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				/*		HIGH PORT				*/
				else
				{
					Copy_u8PinID -= 8 ;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOA_CRH &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOA_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				break;
			case DIO_U8_PORTB:
				if( Copy_u8PinID < 8 )
				{
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOB_CRL &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOB_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				/*		HIGH PORT				*/
				else
				{
					Copy_u8PinID -= 8 ;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOB_CRH &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOB_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				break;
			case DIO_U8_PORTC:
				if( Copy_u8PinID < 8 )
				{
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOC_CRL &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOC_CRL |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				/*		HIGH PORT				*/
				else
				{
					Copy_u8PinID -= 8 ;
				/*	To deal with Bit Masking 1- Clear a specific Bits 2- Assign a specific Bits	*/
					GPIOC_CRH &= ~((u32)(0b1111)<<(Copy_u8PinID * 4));
					GPIOC_CRH |=  ((u32)(Copy_u8Mode)<<(Copy_u8PinID * 4));
				}
				break;
		}
	}else{/*	Return ERROR	*/}

}



void	DIO_voidSetPortValue(DIO_PORTS Copy_u8PortID,u16 Copy_u8Value)
{
	/*		Range Check							*/
	if( (Copy_u8PortID<3)  )
	{
		switch(Copy_u8PortID)
		{
			case DIO_U8_PORTA:
					GPIOA_ODR = Copy_u8Value;
				break;
			case DIO_U8_PORTB:
					GPIOB_ODR = Copy_u8Value;
				break;
			case DIO_U8_PORTC:
					GPIOC_ODR = Copy_u8Value;
				break;
	}
	}else{/*	Return ERROR	*/}
}

void	DIO_voidSetPinValue(DIO_PORTS Copy_u8PortID,DIO_PINS Copy_u8PinID,DIO_STATE Copy_u8Value)
{
	/*		Range Check							*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{
		switch(Copy_u8PortID)
		{
			case DIO_U8_PORTA:
				switch(Copy_u8Value)
				{
					case DIO_U8_HIGH:	SET_BIT(GPIOA_ODR , Copy_u8PinID);	break;
					case DIO_U8_LOW	:	CLR_BIT(GPIOA_ODR , Copy_u8PinID);	break;
					default:;	/*		Return ERROR		*/
				}
				break;
			case DIO_U8_PORTB:
				switch(Copy_u8Value)
				{
					case DIO_U8_HIGH:	SET_BIT(GPIOB_ODR , Copy_u8PinID);	break;
					case DIO_U8_LOW	:	CLR_BIT(GPIOB_ODR , Copy_u8PinID);	break;
					default:;	/*		Return ERROR		*/
				}
				break;
			case DIO_U8_PORTC:
				switch(Copy_u8Value)
				{
					case DIO_U8_HIGH:	SET_BIT(GPIOC_ODR , Copy_u8PinID);	break;
					case DIO_U8_LOW	:	CLR_BIT(GPIOC_ODR , Copy_u8PinID);	break;
					default:;	/*		Return ERROR		*/
				}
				break;
	}
	}else{/*	Return ERROR	*/}
}



u8		DIO_u8GetPortValue(DIO_PORTS Copy_u8PortID)
{
	u32 Local_u32Value = 0XFFFF;
	/*		Range Check							*/
	if( (Copy_u8PortID<3)  )
	{

		switch(Copy_u8PortID)
		{
			case DIO_U8_PORTA:	Local_u32Value = GPIOA_IDR;	break;
			case DIO_U8_PORTB:	Local_u32Value = GPIOB_IDR;	break;
			case DIO_U8_PORTC:	Local_u32Value = GPIOC_IDR;	break;

		}
	}else{/*	Return ERROR	*/}

	return Local_u32Value;
}

u8		DIO_u8GetPinValue(DIO_PORTS Copy_u8PortID,DIO_PINS Copy_u8PinID)
{
	u8 Local_u8Value = 0;
	/*		Range Check							*/
	if( (Copy_u8PortID<3) && (Copy_u8PinID<16) )
	{

		switch(Copy_u8PortID)
		{
			case DIO_U8_PORTA:	Local_u8Value = GET_BIT(GPIOA_IDR , Copy_u8PinID);	break;
			case DIO_U8_PORTB:	Local_u8Value = GET_BIT(GPIOB_IDR , Copy_u8PinID);	break;
			case DIO_U8_PORTC:	Local_u8Value = GET_BIT(GPIOC_IDR , Copy_u8PinID);	break;

		}
	}else{/*	Return ERROR	*/}

	return Local_u8Value;
}
