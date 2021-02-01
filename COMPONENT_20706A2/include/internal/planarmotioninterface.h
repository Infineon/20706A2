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
/*
********************************************************************
*    File Name: planarmotioninterface.h
*
*    Abstract: Planar motion interface definition. Intended for
*      mice XY but may be used for other things like a touchpad
*
*    $History:$
*
********************************************************************
*/

#ifndef __PLANAR_MOTION_INTERFACE_H__
#define __PLANAR_MOTION_INTERFACE_H__

#include "bt_types.h"
#include "hidd_mem.h"
#include "startupallocated.h"

/**  \addtogroup interfaces
*/
/*! @{ */
/**
* Defines a planar motion interface. Planar motion captures motion in two dimensions,
* e.g. a mouse optical sensor, a touchpad, or a trackball. The two axis in planar
* motion are referred to as X and Y in the interface.
*/
class PlanarMotionInterface : public StartupAllocated
{
public:
    /// This function should check for motion and add any detected motion to the
    /// x/y variables passed in. Note that the function must add new motion to the x/y
    /// variables; it should not replace what is in there or motion may be lost.
    /// Some sensors have the ability to accumulate more motion than they can report in a single
    /// poll and require multiple polls to get all the accumulated motion. In such cases
    /// the driver is allowed to poll the sensor multiple times, up to a maximum of
    /// maxSensorReads. An example of such a sensor is the AG3040, which can accumulate more
    /// than a bytes worth of motion but reports it only a byte at a time (-128 to 127).
    /// By limiting the number of polls an application can bound the time it takes
    /// to generate a report.
    /// \param *x pointer to variable to which detected x motion should be added.
    /// \param *y pointer to variable to which detected y motion should be added.
    /// \param maxSensorReads maximum number of times the motion sensor HW can be polled.
    ///     Must be >= 1 or the result is undefined.
    virtual void getMotion(INT16 *x, INT16 *y, BYTE maxSensorReads) = 0;

    /// This function should turn off the planar sensor. This is used when entering
    /// power-off mode (software or low battery)
    virtual void turnOff(void) = 0;

    /// This function should turn on the planar sensor. This is used when exiting
    /// power-off mode (software or low battery)
    virtual void turnOn(void) = 0;

    /// Register for notification of changes.
    virtual void registerForInterrupt(void (*userfn)(void*, UINT8),void* userdata) = 0;

};

/* @}  */
#endif
