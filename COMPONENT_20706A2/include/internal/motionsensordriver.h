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
#ifndef __MOTION_SENSOR_DRIVER_H__
#define __MOTION_SENSOR_DRIVER_H__

#ifdef __cplusplus
#include "motionsensor_interface.h"
#include "gpiodriver.h"
#include "hidd_mem.h"
#include "i2cm.h"
#include "lis331dlh_driver.h"
#include "ami306_driver.h"

/*******************************************************************************
* Types and Defines
*******************************************************************************/
#define MOTION_FIFO_CNT   46

class MotionSensorDriver : public MotionSensor_interface
{
public:
    // Enums
    // IMU-3000 Motion Sensor defines
    enum
    {
        WHO_AM_I    =   0x0,
        SMPLRT_DIV  =   0x15,
        DLPF_FS     =   0x16,
        INT_CFG     =   0x17,
        INT_STATUS  =   0x1A,
        GYRO_XOUT_H =   0x1D,
        GYRO_XOUT_L =   0x1E,
        GYRO_YOUT_H =   0x1F,
        GYRO_YOUT_L =   0x20,
        GYRO_ZOUT_H =   0x21,
        GYRO_ZOUT_L =   0x22,
        USER_CTRL   =   0x3D,
        PWR_MGM     =   0x3E
    };

    // MotionSensorDriver INT Port And Pin
    static BYTE interrupt_Port;
    static BYTE interrupt_Pin;

protected:

    LIS331DLHDriver* accl;
    AMI306Driver* mag;

    static WORD motionSensorDetectMask[GPIO_NUM_PORTS];

    //motion data FIFO
    MotionReport motionData[MOTION_FIFO_CNT];
    BYTE fifoIndex;
    BOOL8 sensor_active;

    //************************************
    // MotionSensorDriver I2C slave Address
    enum
    {
        MOTION_SENSOR_I2C_ADDR     = 0xd0, //b1101000 (IMU-3000)
    };

public:
    MotionSensorDriver();
    // functions called from the App.
    virtual void init(void);
    virtual void startSensorHw(void);
    virtual void stopSensorHw(void);
    virtual BOOL8 isActive(void);
    virtual void  enableInterrupt(BOOL8 enable);
    virtual void pollMotionData(HidEventMotion* evntPtr);
    virtual void  registerForInterrupt(void (*userfn)(void*, UINT8), void* userdata);


protected:
    ~MotionSensorDriver();

    virtual void readBlock(BYTE sub_address, UINT16 length, BYTE *data);
    virtual void  writeByte(UINT8 address, UINT8 data);

};

#endif
#endif
