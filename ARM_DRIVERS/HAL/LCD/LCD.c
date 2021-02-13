/*
 * LCD.c
 *
 *  Created on: Feb 6, 2021
 *      Author: ahmedalyeldin
 */

#include "LCD.h"


int strlength(u8* str)
{
	int i;
	for( i =0 ; str[i] ; i++);

	return i;
}
void LCD_WriteData(u8 data)
{
	DIO_voidSetPinValue(LCD_PORT_CONT,RS,DIO_U8_HIGH);
	DIO_voidSetPinValue(LCD_PORT_DATA, D7,GET_BIT(data,7));
	DIO_voidSetPinValue(LCD_PORT_DATA,D6,GET_BIT(data,6));
	DIO_voidSetPinValue(LCD_PORT_DATA,D5,GET_BIT(data,5));
	DIO_voidSetPinValue(LCD_PORT_DATA,D4,GET_BIT(data,4));
	DIO_voidSetPinValue(LCD_PORT_CONT,EN,DIO_U8_HIGH);
	_delay_us(1000);
	DIO_voidSetPinValue(LCD_PORT_CONT,EN,DIO_U8_LOW);
	_delay_us(1000);
	DIO_voidSetPinValue(LCD_PORT_DATA,D7,GET_BIT(data,3));
	DIO_voidSetPinValue(LCD_PORT_DATA,D6,GET_BIT(data,2));
	DIO_voidSetPinValue(LCD_PORT_DATA,D5,GET_BIT(data,1));
	DIO_voidSetPinValue(LCD_PORT_DATA,D4,GET_BIT(data,0));
	DIO_voidSetPinValue(LCD_PORT_CONT,EN,DIO_U8_HIGH);
	_delay_us(1000);
	DIO_voidSetPinValue(LCD_PORT_CONT,EN,DIO_U8_LOW);
	_delay_us(1000);
}
void LCD_WriteCommand(u8 data)
{
		DIO_voidSetPinValue(LCD_PORT_CONT,RS,DIO_U8_LOW);
		DIO_voidSetPinValue(LCD_PORT_DATA, D7,GET_BIT(data,7));
		DIO_voidSetPinValue(LCD_PORT_DATA,D6,GET_BIT(data,6));
		DIO_voidSetPinValue(LCD_PORT_DATA,D5,GET_BIT(data,5));
		DIO_voidSetPinValue(LCD_PORT_DATA,D4,GET_BIT(data,4));
		DIO_voidSetPinValue(LCD_PORT_CONT,EN,DIO_U8_HIGH);
		_delay_us(1000);
		DIO_voidSetPinValue(LCD_PORT_CONT,EN,DIO_U8_LOW);
		_delay_us(1000);
		DIO_voidSetPinValue(LCD_PORT_DATA,D7,GET_BIT(data,3));
		DIO_voidSetPinValue(LCD_PORT_DATA,D6,GET_BIT(data,2));
		DIO_voidSetPinValue(LCD_PORT_DATA,D5,GET_BIT(data,1));
		DIO_voidSetPinValue(LCD_PORT_DATA,D4,GET_BIT(data,0));
		DIO_voidSetPinValue(LCD_PORT_CONT,EN,DIO_U8_HIGH);
		_delay_us(1000);
		DIO_voidSetPinValue(LCD_PORT_CONT,EN,DIO_U8_LOW);
		_delay_us(1000);
}
void LCD_Init(void)
{
	_delay_us(50000);
	LCD_WriteCommand(0x02);     // return home
	_delay_us(1000);
	LCD_WriteCommand(0x28);     // 4-Bit mode , 2 line mode , 5*8 mode
	_delay_us(1000);
	LCD_WriteCommand(0x0c);     // display ON
	_delay_us(1000);
	LCD_WriteCommand(0x01);     // clear display
	_delay_us(2000);
	LCD_WriteCommand(0x06);    // cursor moving to the right
	_delay_us(1000);


}
void LCD_WriteChar(u8 ch)
{
	LCD_WriteData(ch);
}
void LCD_WriteNumber(s64 num)
{
	s64 number[16];
	u8 i = 0;
	s8 j;
	if(num == 0)
	{
		LCD_WriteData('0');
	}


	else if(num > 0)
	{
		while(!(num == 0))
		{
			number[i] = num%10 + '0';
			num /=10;
			i++;
		}
		for(j=i-1 ; j>=0; j--)
		{
			LCD_WriteData(number[j]);
		}
	}


	else if(num < 0)
	{
		LCD_WriteData('-');
		num = num*(-1);
		while(!(num == 0))
		{
			number[i] = num%10 + '0';
			num /=10;
			i++;
		}
		for(j=i-1 ; j>=0; j--)
		{
			LCD_WriteData(number[j]);
		}
	}
}
void LCD_WriteNumber4digits(u16 num)
{
	u16 num4 = num%10 + '0';
	num /=10;
	u16 num3 = num%10 + '0';
	num /=10;
	u16 num2 = num%10 + '0';
	num /=10;
	u16 num1 = num%10 + '0';
	LCD_WriteChar(num1);
	LCD_WriteChar(num2);
	LCD_WriteChar(num3);
	LCD_WriteChar(num4);
}
void LCD_WriteBinary(u16 num)
{
	u8 i;
	for(i=0 ; i<16 ; i++)
	{
		if((((num>>(15-i))&1) == 1))
		{
			LCD_WriteChar('1');
		}
		else
		{
			LCD_WriteChar('0');
		}
	}
}
void LCD_WriteHex(u16 num)
{
	u8 i;
	u8 num1 = 0;
	u8 num2 = 0;
	u8 num3 = 0;
	u8 num4 = 0;
	for(i=1 ; i<=4 ; i++)
	{
		if((((num>>(i-1))&1) == 1))
		{
			if(i == 1)
			{
				num1 = 1;
			}
			else
			{
				num1 = num1+(POWER(2,(i-1)));
			}
		}

	}
	if(num1 == 10)
	{
		num1 = 'A';
	}
	else if(num1 == 11)
	{
		num1 = 'B';
	}
	else if(num1 == 12)
	{
		num1 = 'C';
	}
	else if(num1 == 13)
	{
		num1 = 'D';
	}
	else if(num1 == 14)
	{
		num1 = 'E';
	}
	else if(num1 == 15)
	{
		num1 = 'F';
	}
	for(i=1 ; i<=4 ; i++)
	{
		if((((num>>(i+4-1))&1) == 1))
		{
			if(i == 1)
			{
				num2 = 1;
			}
			else
			{
				num2 = num2+(POWER(2,(i-1)));
			}
		}

	}
	if(num2 == 10)
	{
		num2 = 'A';
	}
	else if(num2 == 11)
	{
		num2 = 'B';
	}
	else if(num2 == 12)
	{
		num2 = 'C';
	}
	else if(num2 == 13)
	{
		num2 = 'D';
	}
	else if(num2 == 14)
	{
		num2 = 'E';
	}
	else if(num2 == 15)
	{
		num2 = 'F';
	}

	for(i=1 ; i<=4 ; i++)
	{
		if((((num>>(i+8-1))&1) == 1))
		{
			if(i == 1)
			{
				num3 = 1;
			}
			else
			{
				num3 = num3+(POWER(2,(i-1)));
			}
		}

	}

	if(num3 == 10)
	{
		num3 = 'A';
	}
	else if(num3 == 11)
	{
		num3 = 'B';
	}
	else if(num3 == 12)
	{
		num3 = 'C';
	}
	else if(num3 == 13)
	{
		num3 = 'D';
	}
	else if(num3 == 14)
	{
		num3 = 'E';
	}
	else if(num3 == 15)
	{
		num3 = 'F';
	}
	for(i=1 ; i<=4 ; i++)
	{
		if((((num>>(i+12-1))&1) == 1))
		{
			if(i == 1)
			{
				num4 = 1;
			}
			else
			{
				num4 = num4+(POWER(2,(i-1)));
			}
		}
		if(num4 == 10)
		{
			num4 = 'A';
		}
		else if(num4 == 11)
		{
			num4 = 'B';
		}
		else if(num4 == 12)
		{
			num4 = 'C';
		}
		else if(num4 == 13)
		{
			num4 = 'D';
		}
		else if(num4 == 14)
		{
			num4 = 'E';
		}
		else if(num4 == 15)
		{
			num4 = 'F';
		}
	}
	if(num4>=0 && num4<=9)
	{
		LCD_WriteNumber(num4);
	}
	else
	{
		LCD_WriteChar(num4);
	}
	if(num3>=0 && num3<=9)
	{
		LCD_WriteNumber(num3);
	}
	else
	{
		LCD_WriteChar(num3);
	}
	if(num2>=0 && num2<=9)
	{
		LCD_WriteNumber(num2);
	}
	else
	{
		LCD_WriteChar(num2);
	}
	if(num1>=0 && num1<=9)
	{
		LCD_WriteNumber(num1);
	}
	else
	{
		LCD_WriteChar(num1);
	}

}
void LCD_SetCursor(u8 line,u8 coloumn)
{
	if(line == 0)
	{
		LCD_WriteCommand(0x80 + coloumn);
	}
	else if(line == 1)
	{
		LCD_WriteCommand(0x80 + 0x40 + coloumn);
	}
}
void LCD_Clr(void)
{
	LCD_WriteCommand(0x01);
}
void LCD_WriteString(u8*str)
{
	u8 i=0;
	while(str[i]!=0)
	{
		LCD_WriteChar(str[i]);
		i++;
	}

}
void LCD_StringAnimation(u8*str)
{
	for(u8 i =0 ; i<16 ; i++)
	{
		LCD_Clr();
		LCD_SetCursor(0,i);
		if(i<strlength(str))
		{
			LCD_WriteString(str+(strlength(str)-i));
		}
		else if(i>strlength(str))
		{
			LCD_WriteString(str);
		}
		_delay_us(1000000);
	}
	for(u8 j =0 ; j<16 ; j++)
	{
		LCD_Clr();
		LCD_SetCursor(1,j-strlength(str));
		LCD_WriteString(str);
		_delay_us(1000000);
	}

}
void LCD_AsciCount(void)
{
	for(u8 i = 100 ; i>0 ; i--)
	{
		LCD_SetCursor(0,0);
		LCD_WriteString("Char: ");
		LCD_WriteChar(i);
		LCD_SetCursor(1,8);
		LCD_WriteChar(' ');
		LCD_SetCursor(1,0);
		LCD_WriteString("Asci: ");
		LCD_WriteNumber(i);
		_delay_us(100000);
	}
}
void LCD_Create_Character(u8* pattern,u8 location)
{
	u8 i =0;
	LCD_WriteCommand(0x40+(location*8));
	for(i = 0 ; i<8 ; i++)
	{
		LCD_WriteData(pattern[i]);

	}
	LCD_WriteCommand(0x80);
}
