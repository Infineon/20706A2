/*
 * (c) 2016-2025, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 * This software, associated documentation and materials ("Software") is
 * owned by Infineon Technologies AG or one of its affiliates ("Infineon")
 * and is protected by and subject to worldwide patent protection, worldwide
 * copyright laws, and international treaty provisions. Therefore, you may use
 * this Software only as provided in the license agreement accompanying the
 * software package from which you obtained this Software. If no license
 * agreement applies, then any use, reproduction, modification, translation, or
 * compilation of this Software is prohibited without the express written
 * permission of Infineon.
 *
 * Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
 * IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
 * THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
 * SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
 * Infineon reserves the right to make changes to the Software without notice.
 * You are responsible for properly designing, programming, and testing the
 * functionality and safety of your intended application of the Software, as
 * well as complying with any legal requirements related to its use. Infineon
 * does not guarantee that the Software will be free from intrusion, data theft
 * or loss, or other breaches ("Security Breaches"), and Infineon shall have
 * no liability arising out of any Security Breaches. Unless otherwise
 * explicitly approved by Infineon, the Software may not be used in any
 * application where a failure of the Product or any consequences of the use
 * thereof can reasonably be expected to result in personal injury.
 */
/*
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
