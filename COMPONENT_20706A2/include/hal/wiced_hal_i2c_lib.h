
/*

 * (c) 2025, Infineon Technologies AG, or an affiliate of Infineon

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
