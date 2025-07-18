/*
 * Copyright 2016-2025, Cypress Semiconductor Corporation (an Infineon company) or
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
//  File Name: lis331dlh_driver.h
//
//  Abstract:  This file defines the interface of the accelerometer driver (LIS331DLH).
//
//  History:
//  *******************************************************************************


//  *******************************************************************************
//  Includes
// ******************************************************************************/
#ifndef __LIS331DLH_DRIVER_H__
#define __LIS331DLH_DRIVER_H__

#ifdef __cplusplus
#include "motionsensor_interface.h"
#include "gpiodriver.h"
#include "hidd_mem.h"
#include "hidevent.h"
#include "remoterpt.h"
#include "i2cm.h"
#include "gpiodriver.h"


class I2cm;
/*******************************************************************************
* Types and Defines
*******************************************************************************/

class LIS331DLHDriver : public MotionSensor_interface
{
public:
    // Enums
    // LIS331DLH accelerometer defines
    enum
    {
        WHO_AM_I    =   0x0F,
        CTRL_REG1   =   0x20,
        CTRL_REG2   =   0x21,
        CTRL_REG3   =   0x22,
        CTRL_REG4   =   0x23,
        CTRL_REG5   =   0x24,
        HP_FILTER_RESET =   0x25,
        STATUS_REG  =   0x27,
        OUT_X_L     =   0x28,
        OUT_X_H     =   0x29,
        OUT_Y_L     =   0x2A,
        OUT_Y_H     =   0x2B,
        OUT_Z_L     =   0x2C,
        OUT_Z_H     =   0x2D,
        INT1_CFG    =   0x30,
        INT1_SRC    =   0x31,
        INT1_THS    =   0x32,
        INT1_DURATION   =   0x33
    };

    // LIS331DLHDriver INT Port And Pin
    static BYTE interrupt_Port;
    static BYTE interrupt_Pin;

protected:

    UINT16 accl_x;
    UINT16 accl_y;
    UINT16 accl_z;


    //************************************
    // LIS331DLHDriver I2C slave Address
    enum
    {
        MOTION_SENSOR_I2C_ADDR     = 0x32, //b00110010 (LIS331DLH)

    };

public:
    LIS331DLHDriver();
    // functions called from the App.
    virtual void init(void);
    virtual void startSensorHw(void);
    virtual void stopSensorHw(void);
    virtual BOOL8 isActive(void);
    virtual void  enableInterrupt(BOOL8 enable);
    virtual void pollMotionData(HidEventMotion* evntPtr);
    virtual void  registerForInterrupt(void (*userfn)(void*, UINT8), void* userdata);

protected:
    ~LIS331DLHDriver();

    virtual UINT8 readByte(UINT8 address);
    virtual void readBlock(BYTE sub_address, UINT16 length, BYTE *data);
    virtual void  writeByte(UINT8 address, UINT8 data);

};

#endif
#endif
