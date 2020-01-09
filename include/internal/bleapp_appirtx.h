/*
********************************************************************
* THIS INFORMATION IS PROPRIETARY TO
* Cypress Semiconductor.
*-------------------------------------------------------------------
*
*           Copyright (c) 2010 Cypress Semiconductor.
*                      ALL RIGHTS RESERVED
*
********************************************************************

********************************************************************
*    File Name: ble_appirtx.h
*
*    Abstract: This file defines a driver for the appirtxt
*
*    $History:$
*
********************************************************************
*/

#ifndef __BLEAPP_APPIRTX_H__
#define __BLEAPP_APPIRTX_H__

typedef struct
{
    void (*SendIR)(BYTE code, BOOL8 repeat, BYTE repeatcount);
    BOOL8 (*isActive)(void);
    void (*stopRepeat)(void);
}tIrTxDriverVtbl;

tIrTxDriverVtbl* appIRtx_appIRtx(UINT8 port, UINT8 pin);

#endif
