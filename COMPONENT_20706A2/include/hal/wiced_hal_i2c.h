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

/** @file
*
* List of parameters and defined functions needed to access the
* Inter-Integrated Circuit (I2C, IIC) driver.
*
*/

#ifndef __WICED_I2C_DRIVER_H__
#define __WICED_I2C_DRIVER_H__

#include "wiced_result.h"

/**  \addtogroup I2CDriver I2C
* \ingroup HardwareDrivers
* @{
*
* Defines an I2C driver to facilitate communication with other devices on an
* I2C bus (such as a temperature sensor, etc). The driver is only capable of
* assuming a master role. Applications use this driver to obtain the status
* from and control the behavior of the I2C hardware. This driver only offers
* services for speed control and data transfer operations.
*
* Please note that even though this driver can access off-chip memory
* (if installed; EEPROM, etc), please use the drivers found in
* wiced_hal_ieeprom.h to access those modules, as those drivers include
* checks to ensure safe data handling operations. This driver is intended
* only to interface with other devices on the I2C bus, such as a motion
* sensor.
*
*/

/******************************************************************************
*** Parameters.
***
*** The following parameters are used to configure the driver or define
*** return status. They are not modifiable.
******************************************************************************/

/// Speed Options
enum
{
    /// I2C speed is 100 KHz
    I2CM_SPEED_100KHZ = 240,

    /// I2C speed is 400 KHz
    I2CM_SPEED_400KHZ = 60,

    /// I2C speed is 800 KHz
    I2CM_SPEED_800KHZ = 30,

    /// I2C speed is 1 MHz
    I2CM_SPEED_1000KHZ = 24,
};

/// Transaction Status Return Values
enum
{
    /// The transaction was sucessful
    I2CM_SUCCESS,

    /// The attempted operation failed, possibly because
    /// of no ack from slave.
    I2CM_OP_FAILED,

    /// The I2C HW block is busy with another transaction.
    I2CM_BUSY
};

enum
{
    /* Enable if configuring P35 and P37 for  I2C */
    WICED_I2C_SDA_P35_SCL_P37 = 0,

    /* Enable if configuring I2S_DOUT/PCM_OUT and I2S_DIN/PCM_IN for I2C */
    WICED_I2C_SDA_I2S_DOUT_PCM_OUT_SCL_I2S_DIN_PCM_IN = 1,

    /* Enable if configuring SFLASH_MOSI/SDA and SFLASH_MISO/SCL for I2C */
    WICED_I2C_SDA_SFLASH_MOSI_SCL_SFLASH_MISO = 2,
};

/******************************************************************************
*** Function prototypes.
******************************************************************************/
///////////////////////////////////////////////////////////////////////////////
/// Initializes the I2C driver and its private values. This initialization
/// sets the bus speed to 100KHz by default (I2CM_SPEED_100KHZ). To make
/// the bus run at another speed, call wiced_hal_i2c_setSpeed(<speed>)
/// right after this call.
///
/// (!) Note that it is the user's responsibility to configure the desired
/// GPIOs, since different HW platforms will have different configuration
/// parameters. Please see the Kit Guide for your device for more information.
///
/// \param configure_path : WICED_I2C_SDA_P35_SCL_P37 OR
///                         WICED_I2C_SDA_I2S_DOUT_PCM_OUT_SCL_I2S_DIN_PCM_IN  OR
///                         WICED_I2C_SDA_SFLASH_MOSI_SCL_SFLASH_MISO
///
/// \return wiced_result_t : On success WICED_SUCCESS otherwise WICED_ERROR
///////////////////////////////////////////////////////////////////////////////
wiced_result_t wiced_hal_i2c_init(UINT8 configure_path);

///////////////////////////////////////////////////////////////////////////////
/// Sets the I2C bus speed. Note that the default after initialization is
/// set to 100KHz by default (I2CM_SPEED_100KHZ). To make the bus run at
/// another speed, use one of the following parameters (also see Parameters
/// section):
///
///
///     // I2C speed is 100 KHz
///     I2CM_SPEED_100KHZ
///
///     // I2C speed is 400 KHz
///     I2CM_SPEED_400KHZ
///
///     // I2C speed is 800 KHz
///     I2CM_SPEED_800KHZ
///
///     // I2C speed is 1 MHz
///     I2CM_SPEED_1000KHZ
///
/// \param speed - The new speed to be used. This is the transport clock counter
/// that counts the number of reference clock cycles.
///
/// \return none
///////////////////////////////////////////////////////////////////////////////
void wiced_hal_i2c_set_speed(UINT8 speed);

///////////////////////////////////////////////////////////////////////////////
/// Gets the current I2C bus speed. Smaller numbers indicate higher speeds.
/// See the Parameters section for more information.
///
/// \param none
///
/// \return The SCL ref clock cycle counter value that corresponding to
/// the SCL speed.
///////////////////////////////////////////////////////////////////////////////
UINT8 wiced_hal_i2c_get_speed(void);

///////////////////////////////////////////////////////////////////////////////
/// Reads data into given buffer from the I2C HW addressing a particualr
/// slave address. The data bytes are transparent. Though any arbitrary
/// length of data may be read from the slave, atomic transactions greater
/// than HW's capability are not possible - they will be split into multiple
/// transactions. This is a blocking call. Interrupts will not affect timing
/// within a transaction.
/// Note: Please see the Kit Guide for your device for the actual limitation of
/// the part on your platform.
///
/// \param data   - Pointer to a buffer that will hold the incoming data.
/// \param length - The length of the data to read.
/// \param slave  - The source slave address.
///
/// \return The status of the transaction (success[0], failure[1], or busy[2]).
///////////////////////////////////////////////////////////////////////////////
UINT8 wiced_hal_i2c_read(UINT8* data, UINT16 length, UINT8 slave);

///////////////////////////////////////////////////////////////////////////////
/// Executes two transactions back-to-back with a repeated start condition between
/// the first and the second. firstTranBuf is written to the slave in the first transaction
/// while data is read back from the slave into secondTranBuf after the repeated start.
///
/// \param read_buff         - Pointer to the buffer where data is to be read after the repeated start
/// \param read_buff_length  - Number of bytes to read from slave_address - read_buff should be at least this big
/// \param write_buff        - Pointer to the buffer that is to be written to the slave ( eg : EEPROM read addr)
/// \param write_buff_length - Number of bytes to write to the slave starting from write_buff
/// \param slave_address     - The source slave address.
///
/// \return The status of the transaction (success[0], failure[1], or busy[2]).
///////////////////////////////////////////////////////////////////////////////
UINT8 wiced_hal_i2c_combo_read( UINT8* read_buff, UINT16 read_buff_length,
                                              UINT8* write_buff, UINT8 write_buff_length,
                                              UINT8 slave_address);

///////////////////////////////////////////////////////////////////////////////
/// Writes the given data to the I2C HW addressing a particualr slave address.
/// The data bytes are transparent. Though any arbitrary length of data may be
/// written to the slave, atomic transactions greater than HW's capability
/// are not possible - they will be split into multiple transactions. This is
/// a blocking call. Interrupts will not affect timing within a transaction.
/// Note: Please see the Kit Guide for your device for the actual limitation of
/// the part on your platform.
///
/// \param data   - Pointer to a buffer holding the data to write.
/// \param length - The length of the data to write.
/// \param slave  - The destination slave address.
///
/// \return The status of the transaction (success[0], failure[1], or busy[2]).
///////////////////////////////////////////////////////////////////////////////
UINT8 wiced_hal_i2c_write(UINT8* data, UINT16 length, UINT8 slave);

/* @} */

#endif // __WICED_I2C_DRIVER_H__
