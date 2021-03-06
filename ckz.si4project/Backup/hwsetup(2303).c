/***********************************************************************/
/*                                                                     */
/*  FILE        :hwsetup.c                                             */
/*  DATE        :Mon, Sep 19, 2011                                     */
/*  DESCRIPTION :Hardware Setup file                                   */
/*  CPU TYPE    :RX62N                                                 */
/*                                                                     */
/*  This file is generated by Renesas Project Generator (Ver.4.52).    */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/
/************************************************************************
*
* Device     : RX/RX600/RX62N
*
* File Name  : hwsetup.c
*
* Abstract   : Hardware Setup file.
*
* History    : 1.00  (2010-03-05)  [Hardware Manual Revision : 0.50]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2009 Renesas Electronics Corporation.
* and Renesas Solutions Corporation. All rights reserved.
*
************************************************************************/

#include "Global.h"

extern void SetupTimer0Interrupt( void );

void HardwareSetup(void)
{
   /*
   Clock Description              Frequency
   ----------------------------------------
   Input Clock Frequency..............11.0592MHz
   Internal Clock Frequency..........ICLK * 8 MHz
   Peripheral Clock Frequency.........ICLK * 4 MHz
   External Bus Clock Frequency.......ICLK * 4 MHz
    */

  /* Configure SCKCR based on header request */
  {
    uint32_t sckcr = 0;
    sckcr += (ICLK_MUL==8) ? (0ul << 24) : (ICLK_MUL==4) ? (1ul << 24) : (ICLK_MUL==2)? (2ul << 24) : (1ul << 24);
    sckcr += (BCLK_MUL==8) ? (0ul << 16) : (BCLK_MUL==4) ? (1ul << 16) : (BCLK_MUL==2)? (2ul << 16) : (1ul << 16);
    sckcr += (PCLK_MUL==8) ? (0ul <<  8) : (PCLK_MUL==4) ? (1ul <<  8) : (PCLK_MUL==2)? (2ul <<  8) : (1ul <<  8);
    SYSTEM.SCKCR.LONG = sckcr;
  }


    GpioInit();
	//初始化定时器0比较中断
	SetupTimer0Interrupt();
	UartInit(BAUD_FREQ);
       //ResetServoDrv();
	//ʹ��IRQ9���ⲿ�жϣ�����P41
	//	IOPORT.PF8IRQ.BYTE = 0x02;
}


