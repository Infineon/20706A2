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

/** @addtogroup Transport     AIROC Transport
 *  @ingroup HardwareDrivers
 *
 * This section describes the API's to configure and use the SPI as AIROC transport.
 *
 *   @{
 *
 */

#pragma once

#include "spiffydriver.h"
#include "wiced_hal_gpio.h"
#include "wiced_power_save.h"

/**
 * Application can invoke this function to confgure and enable low power mode of operation. Application
 * resumes on waking from sleep. Application can also configure the BT_DEV_WAKE GPIO and the active mode
 * of the BT_DEV_WAKE GPIO using this function.
 * BT_DEV_WAKE GPIO - Host can wake the device from sleep by setting the Bluetooth device wake pin active,
 * if the device is in sleep mode
 *
 * @param[in]      bt_dev_wake_gpio  : Bluetooth Device Wake pin, Use arm gpio as the BT_DEV_WAKE pin
 * @param[in]      bt_dev_wake_mode  : Active Mode of the BT_DEV_WAKE pin
 *
 * @return           WICED_SUCCESS, if sleep is configured successfully
 *                   WICED_ERROR, if BT_DEV_WAKE is not an arm gpio
 *
 */
wiced_result_t wiced_trans_spi_sleep_config(  wiced_bt_gpio_numbers_t bt_dev_wake_gpio, wiced_wake_gpio_mode_t bt_dev_wake_mode );

/* @} */
