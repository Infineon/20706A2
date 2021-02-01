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

/** @addtogroup Transport     WICED Transport
 *  @ingroup HardwareDrivers
 *
 * This section describes the API's to configure and use the SPI as WICED transport.
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
 * resumes  on waking from sleep. Application can also configure the BT DEV WAKE GPIO and the active mode
 * of the BT DEV WAKE GPIO using this function.
 * BT DEV WAKE GPIO -Host can wake the device from sleep by setting the BT device wake pin active, if the device is in sleep mode
 *
 * @param[in]      bt_dev_wake_gpio  : BT Device Wake pin, Use arm gpio as the BT_DEV_WAKE pin
 * @param[in]      bt_dev_wake_mode  : Active Mode of the BT_DEV_WAKE pin
 *
 * @return           WICED_SUCCESS, if sleep is configured successfully
 *                   WICED_ERROR, if BT_DEV_WAKE is not an arm gpio
 *
 */
wiced_result_t wiced_trans_spi_sleep_config(  wiced_bt_gpio_numbers_t bt_dev_wake_gpio, wiced_wake_gpio_mode_t bt_dev_wake_mode );

/* @} */
