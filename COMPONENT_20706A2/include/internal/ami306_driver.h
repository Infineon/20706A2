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
