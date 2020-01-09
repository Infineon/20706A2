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
*    File Name: ag7050.h
*
*    Abstract: This file defines a driver for the Agilent 7050 optical
*              motion sensor.
*
*    $History:$
*
********************************************************************
*/

#ifndef __BLEAPP_AG_7530_DRV_H__
#define __BLEAPP_AG_7530_DRV_H__

#include "bleapp_agcommondriver.h"


/**  \addtogroup AG7530
 *  \ingroup AglientOpticalSensorDriver
*/
void Ag7530Driver_init(void);
void Ag7530Driver_getMotion(INT16 *x, INT16 *y, BYTE maxReads);

#endif
/* @}  */
