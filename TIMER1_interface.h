/*
 * TIMER1_interface.h
 *
 *  Created on: Sep 11, 2021
 *      Author: hp
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void TIMER1_vidInit(u8 u8WGMCpy,u8 u8COM1ACpy,u8 u8COM1BCpy,u8 u8ClkCpy);
void TIMER1_vidSetOCRA(u16 u16OCRACpy);
void TIMER1_vidSetOCRB(u16 u16OCRBCpy);
//void TIMER1_vidSetTCNT(u16);

#define TIMER1_COM1A_NORMAL 0
#define TIMER1_COM1A_TOGGLE 1
#define TIMER1_COM1A_CLEAR 2
#define TIMER1_COM1A_SET 3

#define TIMER1_COM1B_NORMAL 0
#define TIMER1_COM1B_TOGGLE 1
#define TIMER1_COM1B_CLEAR 2
#define TIMER1_COM1B_SET 3

#define TIMER1_WGM_NORMAL 0
#define TIMER1_WGM_PWM_8 1
#define TIMER1_WGM_PWM_9 2
#define TIMER1_WGM_PWM_10 3
#define TIMER1_WGM_CTC 4
#define TIMER1_WGM_FPWM_8 5
#define TIMER1_WGM_FPWM_9 6
#define TIMER1_WGM_FPWM_10 7
#define TIMER1_WGM_PWM_PF_ICR 8
#define TIMER1_WGM_PWM_PF_OCR 9
#define TIMER1_WGM_PWM_P_ICR 10
#define TIMER1_WGM_PWM_P_OCR 11
#define TIMER1_WGM_CTC_ICR 12
#define TIMER1_WGM_FPWM_ICR 14
#define TIMER1_WGM_FPWM_OCR 15

#define TIMER1_CLK_NOCLK 0
#define TIMER1_CLK_1 1
#define TIMER1_CLK_8 2
#define TIMER1_CLK_64 3
#define TIMER1_CLK_256 4
#define TIMER1_CLK_1024 5
#define TIMER1_CLK_EXT_FALLING 6
#define TIMER1_CLK_EXT_RISING 7

#endif /* TIMER1_INTERFACE_H_ */
