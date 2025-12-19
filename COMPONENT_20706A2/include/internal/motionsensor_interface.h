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

// ******************************************************************************
//  File Name: motionsensor_interface.cpp
//
//  Abstract:  This file defines the Motion Sensor Interface.
//
//  History:
//  *******************************************************************************


//  *******************************************************************************
//  Includes
// ******************************************************************************/
#ifndef __MOTION_SENSOR_INTERFACE_H__
#define __MOTION_SENSOR_INTERFACE_H__

#include "types.h"
#include "startupallocated.h"
#include "remoterpt.h"

/**  \addtogroup interfaces
*/
/*! @{ */
/**
* Defines a motion sensor interface. Applications that use this interface
* can plug in different motion sensor drivers with no impact. motion sensor drivers that comply with this interface
* can be used by different applications. The BCM remote application uses this
* interface to control motion sensor activities.
* The BCM standard motion sensor driver also complies with this interface.
*/

class MotionSensor_interface : public StartupAllocated
{
public:
    // functions called from the App.
    virtual void init(void) = 0;
    virtual void startSensorHw(void) = 0;
    virtual void stopSensorHw(void) = 0;
    virtual BOOL8 isActive(void) = 0;
    virtual void  enableInterrupt(BOOL8 enable) = 0;
    virtual void pollMotionData(HidEventMotion* evntPtr) = 0;
    virtual void  registerForInterrupt(void (*userfn)(void*, UINT8), void* userdata) = 0;

};

/* @} */

#endif
