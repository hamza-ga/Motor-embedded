/*
 * LCD_prog.c
 *
 *  Created on: Sep 11, 2021
 *      Author: hp
 */

#include "STD.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <util/delay.h>


void LCD_vidInit(void)
{
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D0,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D1,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D2,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D3,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D4,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D5,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D6,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_DATA_PORT,LCD_D7,DIO_OUTPUT);


	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_E,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RS,DIO_OUTPUT);
	DIO_vidSetPinDirection(LCD_CTRL_PORT,LCD_RW,DIO_OUTPUT);

	_delay_ms(50) ;
	/*
	   LCD_vidSendCommand(LCD_8MODE_2L);
	   _delay_ms(2);
	   LCD_vidSendCommand(LCD_ON_NOCURSOR);
	   _delay_ms(2);
	   LCD_vidSendCommand(LCD_CLEAR_SCREEN);
	   */
	LCD_vidSendCommand(LCD_CLEAR_SCREEN); /*Clear screen*/
	_delay_ms(1) ;
	LCD_vidSendCommand(LCD_RETURN_HOME); /*Move to home*/
	_delay_ms(1) ;
	LCD_vidSendCommand(0b00000110); /*Set entry mode*/
	_delay_ms(1) ;
	LCD_vidSendCommand(0b00001100); /*Display On/Off control*/
	_delay_ms(1) ;
	LCD_vidSendCommand(0b00111000); /*Function Set*/
	_delay_ms(1) ;

}

void LCD_vidSendCommand(u8 commandCpy)
{
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RS,STD_LOW);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RW,STD_LOW);
	_delay_ms(1) ;

	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D0,GET_BIT(commandCpy,0));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D1,GET_BIT(commandCpy,1));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D2,GET_BIT(commandCpy,2));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D3,GET_BIT(commandCpy,3));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(commandCpy,4));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(commandCpy,5));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(commandCpy,6));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(commandCpy,7));
	_delay_ms(1) ;

	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_ms(2);
}

void LCD_vidWriteCharacter(u8 charCpy)
{
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RS,STD_HIGH);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_RW,STD_LOW);
	_delay_ms(1) ;

	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D0,GET_BIT(charCpy,0));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D1,GET_BIT(charCpy,1));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D2,GET_BIT(charCpy,2));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D3,GET_BIT(charCpy,3));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D4,GET_BIT(charCpy,4));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D5,GET_BIT(charCpy,5));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D6,GET_BIT(charCpy,6));
	DIO_vidSetPinValue(LCD_DATA_PORT,LCD_D7,GET_BIT(charCpy,7));
	_delay_ms(1) ;

	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_LOW);
	_delay_ms(2);
	DIO_vidSetPinValue(LCD_CTRL_PORT,LCD_E,STD_HIGH);
}

void LCD_vidWriteString(s8 * s8String)
{
	while(*s8String != '\0')
	{
		LCD_vidWriteCharacter(*s8String);
		s8String++;
	}
}

void LCD_vidWriteSizedString(s8 * s8String,u8 u8sizeCpy) {
	u8 i = 0;
	do {
		LCD_vidWriteCharacter(*s8String);
		s8String++;
		i++;
	}
	while(u8sizeCpy > i);
}

void LCD_vidBlinkString(s8 * s8stringCpy,u8 u8timesCpy)
{
	u8 i = 0;
	s8 * s8string;
	s8string = s8stringCpy;
	do
	{
		_delay_ms(500);

		while(*s8string != '\0')
		{
			LCD_vidWriteCharacter(*s8string);
			s8string++;
		}
		_delay_ms(500);
		i++;
		LCD_vidSendCommand(LCD_CLEAR_SCREEN);
		s8string = s8stringCpy;
	}
	while (u8timesCpy > i);
}

void LCD_vidWriteNumber(u16 u16NumberCpy)
{
	if(u16NumberCpy < 10)
	{
		LCD_vidWriteCharacter(u16NumberCpy+'0');
	}
	else
	{
		if (u16NumberCpy < 100)
		{
			LCD_vidWriteCharacter(u16NumberCpy/10+'0');
			LCD_vidWriteCharacter(u16NumberCpy%10+'0');
		}

		if  (u16NumberCpy < 1000)
		{
			LCD_vidWriteCharacter(u16NumberCpy/100+'0');
			LCD_vidWriteCharacter((u16NumberCpy%100)/10+'0');
			LCD_vidWriteCharacter((u16NumberCpy%100)%10+'0');
		}
	}
}

void LCD_vidGoToXY(s8 s8xCpy, s8 s8yCpy)
{
	if (s8yCpy == 0)
	{
			LCD_vidSendCommand(0x80+s8xCpy);
	}
	else
	{
			LCD_vidSendCommand(0xC0+s8xCpy);
	}
}

void LCD_vidCreateCustomChar(u8 * u8CharPtrCpy, u8 u8LocationCpy)
{
	u8 i = 0;
	LCD_vidSendCommand(0x40+(u8LocationCpy*8)); /*Setting to CGRAM address8*/
	while (i != 8)
	{
		LCD_vidWriteCharacter(*u8CharPtrCpy++);
		i++;
	}
	LCD_vidWriteCharacter(0x00+u8LocationCpy);
}

void LCD_vidWriteCustomChar(u8 u8LocationCpy)
{
	LCD_vidWriteCharacter(0x00+u8LocationCpy);
}

void LCD_vidWriteInPlace(u8 u8xCpy, u8 u8CharCpy)
{
	LCD_vidSendCommand(LCD_RETURN_HOME);
	LCD_vidSendCommand(0x80+u8xCpy);
	LCD_vidWriteCharacter(u8CharCpy);
}
