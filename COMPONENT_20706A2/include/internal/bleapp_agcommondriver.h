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
*    File Name: agCommonDriver.h
*
*    Abstract: This file defines a driver for the common Agilent optical
*              motion sensor.
*
*    $History:$
*
********************************************************************
*/

#ifndef __BLEAPP_AG_COMMON_DRV_H__
#define __BLEAPP_AG_COMMON_DRV_H__

#include "bleapputils.h"
#include "spiffydriver.h"
#include "gpiodriver.h"

#pragma pack(1)
typedef PACKED struct
{
    UINT8       rwd;         // read or write or delay
    UINT8       regoffset;   // register offset or delay time, high byte
    UINT8       value;       // write value 	or delay time low byteus
}AgSensorRegSeq;

//////////////////////////////////
/// Optical Sensor Config for ag generic agdriver
//////////////////////////////////
typedef PACKED struct
    {
    /// port the agilent CS line is connected to
    /// Pin is specified as 0 (LSB) to 15 (MSB)
    BYTE csPort;
    /// pin the agilent CS line is connected to
    /// Pin is specified as 0 (LSB) to 15 (MSB)
    BYTE csPin;

    /// port the agilent motion line is connected to
    /// Pin is specified as 0 (LSB) to 15 (MSB)
    BYTE motionPort;
    /// pin the agilent motion line is connected to
    /// Pin is specified as 0 (LSB) to 15 (MSB)
    BYTE motionPin;

    /// motion pin pull configuration
    WORD motionPinPullConfig;

    /// Default 7050 configuration register value.
    BYTE configValue;

    /// SPI speed to use for the 7050.
    UINT32 spiSpeed;

    /// Delay in microseconds after write complete and before CS is deasserted
    UINT8 delayFromWriteToCSInactive;

    /// Delay in microseconds after 7050 reset
    UINT16 delayAfterReset;

    /// Default 7050 LASER CTRL0 register value.
    BYTE laserCtrl0Value;
    /// Default 7050 LSRPWR_CFG0 register value.
    BYTE lsrpwrCfg0Value;
    /// Default 7050 LSRPWR_CFG1 register value.
    BYTE lsrpwrCfg1Value;
    /// Default 7050 LASER CTRL1 register value.
    BYTE laserCtrl1Value;

    /// delay for spi-read in us
    BYTE delaySPIReadInUs;

    BYTE bustReadLength;

} AgDriverConfig;

/// Structure of the 7050 burst motion report
typedef struct
{
	///  indicates if any motion is detected
    UINT8    motion;
    ///  the accumulated X motion
    INT8    x;
	///  the accumulated Y motion
    INT8    y;

    /// reserved
    UINT8    reserved[4];
}BurstMotionReport;
#pragma pack()

enum
{
    // This bit must be set in the address byte of every write to
    WRITE_CMD_BIT  = 0x80,

    CS_ASSERT       = 0,    // low active
    CS_DEASSERT     = 1,
};

enum
{
    REG_PRODUCT_ID        = 0x00, /**< Product ID register */
    REG_REV_ID            = 0x01, /**< Revison ID register */
    REG_MOTION            = 0x02, /**< Motion register */
    REG_DELTA_X           = 0x03, /**< DELTA_X register */
    REG_DELTA_Y           = 0x04, /**< DELTA_Y register */
    REG_DELTA_XY_H        = 0x05, /**< DELTA_XY_H register */
    REG_SQUAL             = 0x06, /**< SQUAL register */
    REG_SHUTTER_HIGH      = 0x07, /**< SHUTTER_HIGH register */
    REG_SHUTTER_LOW       = 0x08, /**< SHUTTER_LOW register */
    REG_MAX_PIXEL         = 0x09, /**< MAX_PIXEL register */
    REG_PIXEL_SUM         = 0x0a, /**< PIXEL_SUM register */
    REG_MIN_PIXEL         = 0x0b, /**< MIN_PIXEL register */
    REG_CRC0              = 0x0c, /**< CRC0 register */
    REG_CRC1              = 0x0d, /**< CRC1 register */
    REG_CRC2              = 0x0e, /**< CRC2 register */
    REG_CRC3              = 0x0f, /**< CRC3 register */
    REG_SELF_TEST         = 0x10, /**< SELF_TEST register */

    REG_CONFIG2_BITS      = 0x12, /**< CONFIG_BITS register */
    REG_RUN_DOWNSHIFT     = 0x13,
    REG_RESET1_RATE       = 0x14,
    REG_RESET1_DOWNSHIFT  = 0x15,
    REG_RESET2_RATE       = 0x16,
    REG_RESET2_DOWNSHIFT  = 0x17,
    REG_RESET3_RATE       = 0x18,

    REG_LASER_CTRL0       = 0x1a, /**< LASER_CTRL0 register */
    REG_LSRPWR_CFG0       = 0x1c, /**< LASER_CTRL0 register */
    REG_LSRPWR_CFG1       = 0x1d, /**< LSRPWR_CFG1 register */
    REG_LASER_CTRL1       = 0x1f, /**< LASER_CTRL1 register */
    REG_POWER_UP          = 0x28, /**< This register is not defined in */
    /**< the register map of the spec, but */
    /**< mentioned in the POWER_UP procedure */
    REG_OBSERVATION       = 0x2e, /**< OBSERVATION register */
    REG_RESET             = 0x3a, /**< POWER_UP_RESET register */
    REG_SHUTDOWN          = 0x3b, /**< SHUTDOWN register */
    REG_INV_REV_ID        = 0x3e, /**< Inverse_Revision_ID register */
    REG_INV_PRODUCT_ID    = 0x3f, /**< Inverse_Product_ID register */
    REG_MOTION_BURST      = 0x42  /**< Motion_Burst register */
};


enum AGSENSOR_ACT_PROCEDURE_ID
{
    /// dely in ms, which indicate in AgSensorRegSeq.value
    /// max delay 255ms
    /// if longer deley is needed, please
    /// add one more action_item list
    ///
    AGSENSOR_DELAY_MS               =  1  ,

    /// dely in us, which indicate in AgSensorRegSeq.value
    /// max is 255
    /// if more delay needed, please add more delay items in the sequencelist
    AGSENSOR_DELAY_US               =  2  ,

    /// perform spi read and compare
    AGSENSOR_READCOMPARE            =  3  ,

    /// just read the sensor register via spi interferace, ignore the read result
    AGSENSOR_READONLY               =  4  ,

    /// write the sensor register
    AGSENSOR_WRITE                  =  5  ,

    /// compare with previoue read value,
    /// the regoffset will become mask
    AGSENSOR_COMPARE                  =  6  ,
};

void AgCommonDriver_init(const AgSensorRegSeq *agIDCheckSeq,
                       UINT8                agIDCheckSeqSize,
                       const AgSensorRegSeq *agResetSeq,
                       UINT8                agResetSeqSize,
                       const AgSensorRegSeq *agPowerUpSeq,
                       UINT8                agPowerUpSeqSize,
                       const AgSensorRegSeq *agPowerDownSeq,
                       UINT8                agPowerDownSeqSize
                       );

void AgCommonDriver_reset(void);
void AgCommonDriver_getMotion(INT16 *x, INT16 *y, BYTE maxReads);
void AgCommonDriver_turnOff(void);
void AgCommonDriver_turnOn(void);
void AgCommonDriver_registerForInterrupt(void (*userfn)(void*, UINT8), void* userdata);
void AgCommonDriver_burstRead(BYTE  *buf, BYTE bytesToRead);
BYTE AgCommonDriver_readReg(UINT8 regAddress);
void AgCommonDriver_writeReg(UINT8 regAddress, BYTE val);
BYTE AgCommonDriver_walkRegSequence(const AgSensorRegSeq *regSeqList, UINT16 regSeqNo);
void AgCommonDriver_init(const AgSensorRegSeq *agIDCheckSeqParam,
                               UINT8                agIDCheckSeqSizeParam,
                               const AgSensorRegSeq *agResetSeqParam,
                               UINT8                agResetSeqSizeParam,
                               const AgSensorRegSeq *agPowerUpSeqParam,
                               UINT8                agPowerUpSeqSizeParam,
                               const AgSensorRegSeq *agPowerDownSeqParam,
                               UINT8                agPowerDownSeqSizeParam
                              );
void AgCommonDriver_configureGpios(void);
BOOL AgCommonDriver_verifyProductId(void);
DWORD AgCommonDriver_selfTest(void);

extern AgDriverConfig      *agDriverCfg;
#endif
