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
