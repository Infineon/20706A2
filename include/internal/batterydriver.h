/*
********************************************************************
* THIS INFORMATION IS PROPRIETARY TO
* Cypress Semiconductor.
*-------------------------------------------------------------------
*
*           Copyright (c) 2013 Cypress Semiconductor.
*                      ALL RIGHTS RESERVED
*
********************************************************************

********************************************************************
*    File Name: batterydriver.h
*
*    Abstract: This file defines the battery driver
*
********************************************************************
*/

#ifndef __BATTERY_DRIVER_H__
#define __BATTERY_DRIVER_H__

#include "types.h"
#include "adc.h"
#include "startupallocated.h"


/**  \addtogroup BatteryDriver
 *  \ingroup HardwareDrivers
*/
/*! @{ */
/**
* Defines a battery driver class. This class reads the battery
* voltage and calculates the battery charge level.
*/

class BatteryDriver : public StartupAllocated
{
public:
    BatteryDriver();
    virtual INT32 sampleVoltage(void);
    virtual BYTE calculateChargeLevel(INT32 measurementAverage);

protected:
    // Make the destructor protected to disallow creation of BatteryDriver instances
    // on the stack.
    virtual ~BatteryDriver();

/*******************************************************************************
* Protected data
*******************************************************************************/

};


/* @} */

#endif
