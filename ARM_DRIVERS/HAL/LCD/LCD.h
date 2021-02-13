/*
 * LCD.h
 *
 *  Created on: Feb 6, 2021
 *      Author: ahmedalyeldin
 */

#ifndef LCD_H_
#define LCD_H_


#define _4_BIT 1
#define _8_bit 0

/*********************************8_BIT******************************/
//#define LCD_PORT PA
/*********************************4_BIT******************************/
#define D4 			 DIO_U8_PIN4
#define D5 			 DIO_U8_PIN3
#define D6			 DIO_U8_PIN2
#define D7			 DIO_U8_PIN1
#define RS			 DIO_U8_PIN11
#define EN			 DIO_U8_PIN10
#define LCD_PORT_DATA     DIO_U8_PORTA
#define LCD_PORT_CONT     DIO_U8_PORTB



#include "GPIO_interface.h"
#include "BIT_MATH.h"
#include "STK_interface.h"

void LCD_Init(void);
void LCD_WriteData(u8 data);
void LCD_WriteCommand(u8 command);
void LCD_WriteChar(u8 ch);
void LCD_WriteNumber(s64 num);
void LCD_WriteNumber4digits(u16 num);
void LCD_WriteBinary(u16 num);
void LCD_SetCursor(u8 line,u8 coloumn);
void LCD_Clr(void);
void LCD_AsciCount(void);
void LCD_StringAnimation(u8*str);
void LCD_WriteString(u8*str);
void LCD_Create_Character(u8* pattern,u8 location);
void LCD_WriteHex(u16 num);



#endif /* LCD_H_ */
