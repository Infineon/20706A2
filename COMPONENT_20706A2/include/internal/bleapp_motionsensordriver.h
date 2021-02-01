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
//  File Name: motionsensordriver.cpp
//
//  Abstract:  This file implements the Motion Sensor driver (IMU-3000).
//
//  History:
//  *******************************************************************************


//  *******************************************************************************
//  Includes
// ******************************************************************************/
#ifndef __BLEAPP_MOTION_SENSOR_DRIVER_H__
#define __BLEAPP_MOTION_SENSOR_DRIVER_H__
#include "blehidevent.h"


/*******************************************************************************
* Types and Defines
*******************************************************************************/
#define MOTION_FIFO_CNT   46

/// Maximum number of motion data in a motion report.
/// Here is the motion data for BRCM referenced remote
///INT16   gyro_x;  //gyro_x_output
///INT16   gyro_y;  //gyro_y_output
///INT16   gyro_z;  //gyro_z_output
///INT16   accl_x;  //accl_x_output
///INT16   accl_y;  //accl_y_output
///INT16   accl_z;  //accl_z_output
///INT16   mag_x;   //mag_x_output
///INT16   mag_y;   //mag_y_output
///INT16   mag_z;   //mag_z_output
#define MOTIONRPT_MAX_DATA 9

#pragma pack(1)
/// motion report structure
typedef struct
{
    /// Set to the value specified in the config record.
    BYTE    reportID;
    BYTE    reserve;
    INT16   m_data[MOTIONRPT_MAX_DATA];
} MotionReport;

typedef PACKED struct
{
    /// Base event info
    HidEvent eventInfo;

    /// The event
    MotionReport* data;
} HidEventMotion;

#pragma pack()

typedef struct
{
    // functions called from the App.
    void    (*init)(void);
    void    (*startSensorHw)(void);
    void    (*stopSensorHw)(void);
    BOOLEAN (*isActive)(void);
    void    (*enableInterrupt)(BOOL8 enable);
    void    (*pollMotionData)(void* evntPtr);
    void    (*registerForInterrupt)(void (*userfn)(void*, UINT8), void* userdata);
}tMotionSensorDriverVtbl;

tMotionSensorDriverVtbl * MotionSensorDriver_Constructor(void);

#endif
