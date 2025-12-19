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
