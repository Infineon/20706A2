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
//  File Name: ami306.h
//
//  Abstract:  This file defines the interface of magnetic sensor driver (AMI306).
//
//  History:
//  *******************************************************************************


//  *******************************************************************************
//  Includes
// ******************************************************************************/
#ifndef __AMI306_DRIVER_H__
#define __AMI306_DRIVER_H__

#ifdef __cplusplus
#include "motionsensor_interface.h"
#include "hidd_mem.h"
#include "i2cm.h"


class I2cm;
/*******************************************************************************
* Types and Defines
*******************************************************************************/

class AMI306Driver : public MotionSensor_interface
{
public:
    // AMI306 magnetic sensor defines
    enum
    {
        WHO_AM_I    = 0x0F,

        OUT_X_L     = 0x10,
        OUT_X_H     = 0x11,
        OUT_Y_L     = 0x12,
        OUT_Y_H     = 0x13,
        OUT_Z_L     = 0x14,
        OUT_Z_H     = 0x15,

        STATUS_REG  = 0x18,

        CTRL_REG1   = 0x1B,
        CTRL_REG2   = 0x1C,
        CTRL_REG3   = 0x1D,
        CTRL_REG4_L = 0x5C,
        CTRL_REG4_H = 0x5D,

        SENSX_L     = 0x96,
        SENSX_H     = 0x97,
        SENSY_L     = 0x98,
        SENSY_H     = 0x99,
        SENSZ_L     = 0x9A,
        SENSZ_H     = 0x9B,

        VER_L       = 0xE8,
        VER_H       = 0xE9,

        SN_L        = 0xEA,
        SN_H        = 0xEB,
    };

protected:

    UINT16 mag_x;
    UINT16 mag_y;
    UINT16 mag_z;

    //************************************
    // AMI306 I2C slave Address
    enum
    {
        MAG_SENSOR_I2C_ADDR  = 0x1C, //b 0001 110 (AMI306)
    };

public:
    AMI306Driver();

    // functions called from the App.
    virtual void init(void);
    virtual void startSensorHw(void);
    virtual void stopSensorHw(void);
    virtual BOOL8 isActive(void);
    virtual void  enableInterrupt(BOOL8 enable);
    virtual void pollMotionData(HidEventMotion* evntPtr);
    virtual void  registerForInterrupt(void (*userfn)(void*, UINT8), void* userdata);


protected:
    virtual UINT8 readByte(UINT8 address);
    virtual void readBlock(BYTE sub_address, UINT16 length, BYTE *data);
    virtual void  writeByte(UINT8 address, UINT8 data);

    ~AMI306Driver();
};

#endif
#endif // #define __AMI306_DRIVER_H__
