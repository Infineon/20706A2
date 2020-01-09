//  *****************************************************************************
//  Copyright (c), 2009-12 Cypress Semiconductor.
//
//          ALL RIGHTS RESERVED
//
//  *****************************************************************************
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
