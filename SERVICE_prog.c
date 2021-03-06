/*
 * SERVICE_prog.c
 *
 *  Created on: Sep 11, 2021
 *      Author: hp
 */
#include "STD.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include "KEYPAD_interface.h"
#include "SERVICES_interface.h"
#include <util/delay.h>

void SERVICES_vidWriteCharacter(u8 u8ClearScreen)
{
	u8keyPressed = 0xFF;
	do
	{
		u8keyPressed = KEYPAD_u8GetKey();
		_delay_ms(300);
		u8keyPressed = KEYPAD_u8GetKey();
	}
	while(u8keyPressed == 0xFF);
	if (u8keyPressed == '#')
	{
		_delay_ms(10);
	}
	else
	{
		if((u8keyPressed >= 0) && (u8keyPressed <= 9))
		{
			u8keyPressed += 0x30;
		}
		if (u8ClearScreen == 0)
		{
			LCD_vidWriteCharacter(u8keyPressed);
		}
		else
		{
			LCD_vidSendCommand(LCD_CLEAR_SCREEN);
			LCD_vidSendCommand(LCD_RETURN_HOME);
			LCD_vidWriteCharacter(u8keyPressed);
		}
	}
}

