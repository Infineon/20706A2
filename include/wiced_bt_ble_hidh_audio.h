/*
 *  Copyright 2016-2020, Cypress Semiconductor Corporation or a subsidiary of
 *  Cypress Semiconductor Corporation. All Rights Reserved.
 * 
 *  This software, including source code, documentation and related
 *  materials ("Software"), is owned by Cypress Semiconductor Corporation
 *  or one of its subsidiaries ("Cypress") and is protected by and subject to
 *  worldwide patent protection (United States and foreign),
 *  United States copyright laws and international treaty provisions.
 *  Therefore, you may use this Software only as provided in the license
 *  agreement accompanying the software package from which you
 *  obtained this Software ("EULA").
 *  If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 *  non-transferable license to copy, modify, and compile the Software
 *  source code solely for use in connection with Cypress's
 *  integrated circuit products. Any reproduction, modification, translation,
 *  compilation, or representation of this Software except as specified
 *  above is prohibited without the express written permission of Cypress.
 * 
 *  Disclaimer: THIS SOFTWARE IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND,
 *  EXPRESS OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, NONINFRINGEMENT, IMPLIED
 *  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. Cypress
 *  reserves the right to make changes to the Software without notice. Cypress
 *  does not assume any liability arising out of the application or use of the
 *  Software or any product or circuit described in the Software. Cypress does
 *  not authorize its products for use in any products where a malfunction or
 *  failure of the Cypress product may reasonably be expected to result in
 *  significant property damage, injury or death ("High Risk Product"). By
 *  including Cypress's product in a High Risk Product, the manufacturer
 *  of such system or application assumes all risk of such use and in doing
 *  so agrees to indemnify Cypress against all liability.
 */

#pragma once

#include "wiced_bt_ble_hidh.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup  wiced_bt_ble_hidh_audio_api_functions   HID Host over BLE Audio
 * @ingroup     wiced_bt_hid
 *
 * The Human Interface Device Host Audio library of the WICED SDK provide a simple method
 * for an application to integrate HIDH Audio functionality.
 * This library is typically used to decode Audio received from Remote Control.
 *
 * @{
*/

/**
 * @brief HIDH Audio Events.
 *
 * BLE HID Host Audio event received by the BLE HID Host Audio callback (see
 * wiced_bt_ble_hidh_audio_cback_t)
 */
typedef enum
{
    WICED_BT_BLE_HIDH_AUDIO_START_EVT,      /**< Audio Start. */
    WICED_BT_BLE_HIDH_AUDIO_STOP_EVT,       /**< Audio Stop. */
    WICED_BT_BLE_HIDH_AUDIO_RX_DATA_EVT,    /**< Audio Data Received. */
} wiced_bt_ble_hidh_audio_event_t;


typedef enum
{
    WICED_BT_BLE_HIDH_AUDIO_FORMAT_PCM_16,  /**< 16 Bit Per Sample, Little Endian */
} wiced_bt_ble_hidh_audio_format_t;

typedef struct
{
    uint16_t                            handle;     /**< HIDH Connection Handle. */
    wiced_bt_ble_hidh_audio_format_t    format;     /**< Data Format */
    uint8_t                             channel_nb; /**< Channel Number (1:Mono; 2:Stereo) */
    uint16_t                            frequency;  /**< Sampling Frequency (in Hertz) */
} wiced_bt_ble_hidh_audio_start_t;

typedef struct
{
    uint16_t                            handle;     /**< HIDH Connection Handle. */
} wiced_bt_ble_hidh_audio_stop_t;

typedef struct
{
    uint16_t                    handle;     /**< HIDH Connection Handle. */
    uint16_t                    length;     /**< Data Length (in byte) */
    uint8_t                     *p_data;    /**< PCM Data. */
} wiced_bt_ble_hidh_audio_rx_data_t;

typedef union
{
    wiced_bt_ble_hidh_audio_start_t     start;      /**< WICED_BT_BLE_HIDH_AUDIO_START_EVT */
    wiced_bt_ble_hidh_audio_stop_t      stop;       /**< WICED_BT_BLE_HIDH_AUDIO_STOP_EVT */
    wiced_bt_ble_hidh_audio_rx_data_t   rx_data;    /**< WICED_BT_BLE_HIDH_AUDIO_RX_DATA_EVT */
} wiced_bt_ble_hidh_audio_event_data_t;

/**
 * HIDH Callback function type wiced_bt_ble_hidh_audio_cback_t
 *
 *                  WICED BLE HID Host Audio Event callback (registered with wiced_bt_ble_hidh_audio_init)
 *
 * @param[in]       event: BLE HIDH Audio event received
 * @param[in]       p_data : Data (pointer on union of structure) associated with the event
 *
 * @return          None
 */
typedef void wiced_bt_ble_hidh_audio_cback_t(wiced_bt_ble_hidh_audio_event_t event,
        wiced_bt_ble_hidh_audio_event_data_t *p_event_data);


wiced_bt_ble_hidh_status_t wiced_bt_ble_hidh_audio_init(wiced_bt_ble_hidh_audio_cback_t *p_callback);

/** @} wiced_bt_ble_hidh_audio_api_functions */

#ifdef __cplusplus
}
#endif
