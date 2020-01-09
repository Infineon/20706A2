//  *****************************************************************************
//  Copyright (c), 2009-12 Cypress Semiconductor.
//
//          ALL RIGHTS RESERVED
//
//  *****************************************************************************
// ******************************************************************************
//  File Name: lis331dlh_driver.h
//
//  Abstract:  This file defines the interface of the accelerometer driver (LIS331DLH).
//
//  History:
//  *******************************************************************************


//  *******************************************************************************
//  Includes
// ******************************************************************************/
#ifndef __BLEAPP_LIS331DLH_DRIVER_H__
#define __BLEAPP_LIS331DLH_DRIVER_H__
#include "types.h"

extern BYTE LIS331DLHDriver_interrupt_Port;
extern BYTE LIS331DLHDriver_interrupt_Pin;

void LIS331DLHDriver_init(void);
void LIS331DLHDriver_enableInterrupt(BOOLEAN enable);
UINT8 LIS331DLHDriver_readByte(UINT8 address);
void LIS331DLHDriver_writeByte(UINT8 address, UINT8 data);
void LIS331DLHDriver_startSensorHw(void);
void LIS331DLHDriver_stopSensorHw(void);
void LIS331DLHDriver_pollMotionData(void* evntPtr);
#endif
