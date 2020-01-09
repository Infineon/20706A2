//  *****************************************************************************
//  Copyright (c), 2009-13 Cypress Semiconductor.
//
//          ALL RIGHTS RESERVED
//
//  *****************************************************************************
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
