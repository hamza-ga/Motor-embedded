/*
 * TIMER1_prog.c
 *
 *  Created on: Sep 11, 2021
 *      Author: hp
 */

#include "STD.h"
#include "Macros.h"
#include "DIO_interface.h"
#include "TIMER1_interface.h"
#include <avr/io.h>

void TIMER1_vidInit(u8 u8WGMCpy,u8 u8COM1ACpy,u8 u8COM1BCpy,u8 u8ClkCpy)
{
	if (u8COM1ACpy == TIMER1_COM1A_NORMAL)
	{
		CLEAR_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
	}
	else if (u8COM1ACpy == TIMER1_COM1A_TOGGLE)
	{
		CLEAR_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
	}
	else if (u8COM1ACpy == TIMER1_COM1A_CLEAR)
	{
		SET_BIT(TCCR1A,7);
		CLEAR_BIT(TCCR1A,6);
	}
	else if (u8COM1ACpy == TIMER1_COM1A_SET)
	{
		SET_BIT(TCCR1A,7);
		SET_BIT(TCCR1A,6);
	}
	if (u8COM1BCpy == TIMER1_COM1B_NORMAL)
	{
		CLEAR_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
	}
	else if (u8COM1BCpy == TIMER1_COM1B_TOGGLE)
	{
		CLEAR_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
	}
	else if (u8COM1BCpy == TIMER1_COM1B_CLEAR)
	{
		SET_BIT(TCCR1A,5);
		CLEAR_BIT(TCCR1A,4);
	}
	else if (u8COM1BCpy == TIMER1_COM1B_SET)
	{
		SET_BIT(TCCR1A,5);
		SET_BIT(TCCR1A,4);
	}
	//Configuring the mode
	if (u8WGMCpy == TIMER1_WGM_NORMAL)
	{
		CLEAR_BIT(TCCR1A,0); //WGM10
		CLEAR_BIT(TCCR1A,1); //WGM11
		CLEAR_BIT(TCCR1B,3); //WGM12
		CLEAR_BIT(TCCR1B,4); //WGM13
	}
	else if (u8WGMCpy == TIMER1_WGM_CTC)
	{
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_PWM_8)
	{
		SET_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_PWM_9)
	{
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_PWM_10)
	{
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_CTC)
	{
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_FPWM_8)
	{
		SET_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_FPWM_9)
	{
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_FPWM_10)
	{
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		CLEAR_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_PWM_PF_ICR)
	{
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_PWM_PF_OCR)
	{
		SET_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_PWM_P_ICR)
	{
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_PWM_P_OCR)
	{
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		CLEAR_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_CTC_ICR)
	{
		CLEAR_BIT(TCCR1A,0);
		CLEAR_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_FPWM_ICR)
	{
		CLEAR_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1B,3);
		SET_BIT(TCCR1B,4);
	}
	else if (u8WGMCpy == TIMER1_WGM_FPWM_OCR)
	{
		SET_BIT(TCCR1A,0);
		SET_BIT(TCCR1A,1);
		SET_BIT(TCCR1A,3);
		SET_BIT(TCCR1A,4);
	}
	if (u8ClkCpy == TIMER1_CLK_NOCLK)
	{
		CLEAR_BIT(TCCR1B,0);
		CLEAR_BIT(TCCR1B,1);
		CLEAR_BIT(TCCR1B,2);
	}
	else if (u8ClkCpy == TIMER1_CLK_1)
	{
		SET_BIT(TCCR1B,0);
		CLEAR_BIT(TCCR1B,1);
		CLEAR_BIT(TCCR1B,2);
	}
	else if (u8ClkCpy == TIMER1_CLK_8)
	{
		CLEAR_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		CLEAR_BIT(TCCR1B,2);
	}
	else if (u8ClkCpy == TIMER1_CLK_64)
	{
		SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		CLEAR_BIT(TCCR1B,2);
	}
	else if (u8ClkCpy == TIMER1_CLK_256)
	{
		CLEAR_BIT(TCCR1B,0);
		CLEAR_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
	else if (u8ClkCpy == TIMER1_CLK_1024)
	{
		SET_BIT(TCCR1B,0);
		CLEAR_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
	else if (u8ClkCpy == TIMER1_CLK_EXT_FALLING)
	{
		CLEAR_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
	else if (u8ClkCpy == TIMER1_CLK_EXT_RISING)
	{
		SET_BIT(TCCR1B,0);
		SET_BIT(TCCR1B,1);
		SET_BIT(TCCR1B,2);
	}
}

void TIMER1_vidSetOCRB(u16 u16OCRBCpy)
{
	OCR1B = u16OCRBCpy;
}

void TIMER1_vidSetOCRA(u16 u16OCRACpy)
{
	OCR1A = u16OCRACpy;
}
