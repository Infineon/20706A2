
/*
 * Copyright 2025, Cypress Semiconductor Corporation (an Infineon company) or
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
* wrappers for correctly timed i2c operation
*
*/

#ifdef __WICED_I2C_LIB_DRIVER_H__
#define __WICED_I2C_LIB_DRIVER_H__

/**  \addtogroup I2CDriver I2C
* \ingroup I2CDriver
* @{
* This patch library provides wrappers to the I2CDriver module,
* correcting speed and slave address bit shift to match the i2c
* operation on other devices.
*/

/// Wrapper for wiced_hal_i2c_init() that provides some extra hardware setup
wiced_result_t wiced_hal_i2c_lib_init(UINT8 configure_path);

/// Wrapper for wiced_hal_i2c_lib_set_speed() that modifies the speed value for correct clocking
void wiced_hal_i2c_lib_set_speed(UINT8 speed);

/// wrapper for wiced_hal_i2c_get_speed() that returns the current speed value
UINT8 wiced_hal_i2c_lib_get_speed(void);

/// Wrapper for wiced_hal_i2c_read() that shifts the slave address ( << 1 ) for
/// API consistency with other devices.
UINT8 wiced_hal_i2c_lib_read(UINT8* data, UINT16 length, UINT8 slave);

/// Wrapper for wiced_hal_i2c_combo_read() that shifts the slave address ( << 1 ) for
/// API consistency with other devices.
UINT8 wiced_hal_i2c_lib_combo_read( UINT8* read_buff, UINT16 read_buff_length,
                                              UINT8* write_buff, UINT8 write_buff_length,
                                              UINT8 slave_address);

/// Wrapper for wiced_hal_i2c_write() that shifts the slave address ( << 1 ) for
/// API consistency with other devices.
UINT8 wiced_hal_i2c_lib_write(UINT8* data, UINT16 length, UINT8 slave);

/* @} */

#endif // __WICED_I2C_LIB_DRIVER_H__
