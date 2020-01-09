//  *****************************************************************************
//  Copyright (c), 2009-13 Cypress Semiconductor.
//
//          ALL RIGHTS RESERVED
//
//  *****************************************************************************
// ******************************************************************************
//  File Name: ami306.h
//
//  Abstract:  This file defines the interface of magnetic sensor driver (AMI306).
//
//  History:
//  *******************************************************************************


//  *******************************************************************************
//  Includes
// ******************************************************************************/
#ifndef __BLEAPP_AMI306_DRIVER_H__
#define __BLEAPP_AMI306_DRIVER_H__
#include "types.h"

void AMI306Driver_init(void);
BOOLEAN AMI306Driver_isActive(void);
UINT8 AMI306Driver_readByte(UINT8 address);
void AMI306Driver_readBlock(BYTE sub_address, UINT16 length, BYTE *data);
void AMI306Driver_writeByte(UINT8 address, UINT8 data);
void AMI306Driver_startSensorHw(void);
void AMI306Driver_stopSensorHw(void);
void AMI306Driver_pollMotionData(void* evntPtr);
#endif // #define __BLEAPP_AMI306_DRIVER_H__
