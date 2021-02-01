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
*    File Name: ag7050.h
*
*    Abstract: This file defines a driver for the Agilent 7050 optical
*              motion sensor.
*
*    $History:$
*
********************************************************************
*/

#ifndef __AG_7530_DRV_H__
#define __AG_7530_DRV_H__

#include "spi.h"
#include "planarmotioninterface.h"
#include "agcommondriver.h"


/**  \addtogroup AG7530
 *  \ingroup AglientOpticalSensorDriver
*/

/*! @{ */
/**
*  AG7530 sensor driver class
*/
class Ag7530Driver : public AgCommonDriver //PlanarMotionInterface
{

public:

    // constructor
    Ag7530Driver(SpiInterface *spi);

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


    // 7050 settings
    enum
    {
        // Reset command
        RESET_CMD                  = 0x5a,
        POWER_UP_CMD               = 0xfe,
        // Shutdown command
        SHUTDOWN_CMD               = 0xe7,
        // Power adjustment value
        LASER_CTRL0_VAL            = 0x0a,
        LASER_CTRL1_VAL            = 0xa0,
        LSRPWR_CFG0_VAL            = 0xff,
        LSRPWR_CFG1_VAL            = 0x00,
        // 7050 resolution (in the config register)
        RESOLUTION_BIT_MASK        = 0x80,
        // 400dpi
        RESOLUTION_400             = 0x00,
        //800dpi
        RESOLUTION_800             = 0x20,
        RESOLUTION_1200            = 0x40,
        RESOLUTION_1600            = 0x60,

        // 7050 operation mode (normal or rest 3)
        OP_MODE_BIT_MASK           = 0x30,
        // Normal
        OP_MODE_NORMAL             = 0x00,
        //Rest 3
        OP_MODE_REST3              = 0x30,
        // Maximum number of bytes retrieved from the 7050 during a burst read
        MAX_BURST_LEN              = 7,
        // Minimum number of bytes read from the 7050 that include complete motion
        // information. This is also the minimum number required by the 7050 spec.
        MIN_BURST_LEN              = 3,
        // Command to enter self test
        ENTER_SELF_TEST            = 0x01,
        // Bit definition for the motion register
        // Motion since last report
        MOTION_REG_MOT_BIT         = 0x80,
        // Pixel Dump data byte is available in Pixel_Dump register
        MOTION_REG_PIXRDY_BIT      = 0x40,
        // This bit is set when the Pixel_Grab register is written to or
        // when a complete pixel array has been read, initiating an increment to pixel 0,0.
        MOTION_REG_PIXFIRST_BIT    = 0x20,
        // Motion overflow, .Y and/or .X buffer has overflowed since last report
        MOTION_REG_OVF_BIT         = 0x10,
        // Active state of various pins
        CS_INACTIVE                = 1,
        CS_ACTIVE                  = 0,
        MOTION_INACTIVE            = 1,
        MOTION_ACTIVE              = 0
    };
    ~Ag7530Driver();

protected:
    virtual DWORD selfTest(void);
    virtual void getMotion(INT16 *x, INT16 *y, BYTE maxReads);

};

#endif
/* @}  */
