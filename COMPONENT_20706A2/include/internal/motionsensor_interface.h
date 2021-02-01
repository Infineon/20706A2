/*
 * Copyright 2016-2021, Cypress Semiconductor Corporation (an Infineon company) or
 * an affiliate of Cypress Semiconductor Corporation.  All rights reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software") is owned by Cypress Semiconductor Corporation
 * or one of its affiliates ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products.  Any reproduction, modification, translation,
 * compilation, or representation of this Software except as specified
 * above is prohibited without the express written permission of Cypress.
 *
 * Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 * reserves the right to make changes to the Software without notice. Cypress
 * does not assume any liability arising out of the application or use of the
 * Software or any product or circuit described in the Software. Cypress does
 * not authorize its products for use in any products where a malfunction or
 * failure of the Cypress product may reasonably be expected to result in
 * significant property damage, injury or death ("High Risk Product"). By
 * including Cypress's product in a High Risk Product, the manufacturer
 * of such system or application assumes all risk of such use and in doing
 * so agrees to indemnify Cypress against all liability.
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
