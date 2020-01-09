/*
 *  Copyright 2020, Cypress Semiconductor Corporation or a subsidiary of
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

#include "wiced.h"
#include "wiced_bt_dev.h"
#include "wiced_bt_gatt.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup  wiced_bt_ble_battc_api_functions   Battery Client
 * @ingroup     wicedbt
 *
 * The Battery Client  library of the WICED SDK provide a simple method for an application to
 * integrate Battery functionality.
 * This library is typically used to get the Battery level of a peer BLE BATTC Device.
 *
 * @{
*/

/**
 * @brief BLE BATTC Maximum BATTC Devices.
 */
#define WICED_BT_BLE_BATTC_DEV_MAX                   3

/**
 * @brief BATTC Events.
 *
 * BLE BATTC event received by the BLE BATTC callback (see wiced_bt_ble_battc_cback_t)
 */
typedef enum
{
    WICED_BT_BLE_BATTC_OPEN_EVT,             /**< Connection Open. */
    WICED_BT_BLE_BATTC_CLOSE_EVT,            /**< Connection Closed. */
    WICED_BT_BLE_BATTC_GATT_CACHE_EVT,       /**< BLE BATTC GATT Cache. */
    WICED_BT_BLE_BATTC_LEVEL_EVT,            /**< Battery Level received from peer Device. */
} wiced_bt_ble_battc_event_t;

/**
 * @brief BLE BATTC Error codes.
 *
 * This enumeration contains the list of BATTC Error codes.
 */

typedef enum
{
    WICED_BT_BLE_BATTC_STATUS_SUCCESS = 0,       /**< Operation success */
    WICED_BT_BLE_BATTC_STATUS_UNSUPPORTED,       /**< Peer device does not support Battery Service */
    WICED_BT_BLE_BATTC_STATUS_ERROR,             /**< Generic internal error */
    WICED_BT_BLE_BATTC_STATUS_GATT_ERROR,        /**< Generic GATT error */
    WICED_BT_BLE_BATTC_STATUS_INVALID_PARAM,     /**< Invalid Parameter */
    WICED_BT_BLE_BATTC_STATUS_MEM_FULL,          /**< Memory full */
    WICED_BT_BLE_BATTC_STATUS_CONNECTION_FAILED, /**< Not able to establish Baseband connection */
} wiced_bt_ble_battc_status_t;

/**
 * @brief Data associated with WICED_BT_BLE_BATTC_OPEN_EVT.
 *
 * This event is received:
 *  - After the wiced_bt_ble_battc_open function is called or
 *  - When a peer device reconnects (reconnection allowed with wiced_bt_ble_battc_add)
 *
 */
typedef struct
{
    wiced_bt_device_address_t bdaddr;           /**< Peer Device address */
    uint16_t handle;                            /**< BATTC Connection Handle. */
    wiced_bt_ble_battc_status_t status;         /**< BATTC Connection station */
    wiced_bool_t notification;                  /**< Indicates if peer supports Level Notification */
} wiced_bt_ble_battc_connected_t;

/**
 * @brief Data associated with WICED_BT_BLE_BATTC_CLOSE_EVT.
 *
 * This event is received:
 *  - After the wiced_bt_ble_battc_disconnect function is called or
 *  - When a peer device disconnects
 *
 */
typedef struct
{
    uint16_t handle;
    wiced_bt_gatt_disconn_reason_t reason;
} wiced_bt_ble_battc_disconnected_t;

/**
 * @brief BLE BATTC GATT Characteristic.
 *
 * This structure contains the informations of a BLE BATTC GATT Characteristic.
 */
typedef struct
{
    uint16_t uuid16;
    uint16_t handle;
    uint16_t val_handle;
    wiced_bt_gatt_char_properties_t properties;
} wiced_bt_ble_battc_gatt_char_t;


/**
 * @brief Data associated with WICED_BT_BLE_BATTC_GATT_CACHE_EVT.
 *
 * This event is received to save the BLE BATTC GATT Cache information in NVRAM.
 */
typedef struct
{
    wiced_bt_device_address_t bdaddr;           /**< BLE BATTC Device Address. */
    wiced_bt_ble_battc_gatt_char_t characteristic;
    wiced_bool_t notification;
} wiced_bt_ble_battc_gatt_cache_t;

/**
 * @brief Data associated with WICED_BT_BLE_BATTC_LEVEL_EVT.
 *
 * This event is received after call to the wiced_bt_ble_battc_read function or if the peer
 * device sends a Battery Level Notification
 */
typedef struct
{
    uint16_t                    handle;         /**< BATTC Connection Handle. */
    wiced_bt_ble_battc_status_t status;         /**< BATTC Level status */
    uint8_t                     level;          /**< BATTC Battery Level (0..100). */
} wiced_bt_ble_battc_level_t;


typedef union
{
    wiced_bt_ble_battc_connected_t    connected;     /**< WICED_BT_BLE_BATTC_OPEN_EVT */
    wiced_bt_ble_battc_disconnected_t disconnected;  /**< WICED_BT_BLE_BATTC_CLOSE_EVT */
    wiced_bt_ble_battc_level_t        level;         /**< WICED_BT_BLE_BATTC_LEVEL_EVT */
    wiced_bt_ble_battc_gatt_cache_t   gatt_cache;    /**< WICED_BT_BLE_BATTC_GATT_CACHE_EVT */
} wiced_bt_ble_battc_event_data_t;

/**
 * BATTC Callback function type wiced_bt_ble_battc_cback_t
 *
 *                  WICED BLE BATTC Host Event callback (registered with wiced_bt_ble_battc_init)
 *
 * @param[in]       event: BLE BATTC event received
 * @param[in]       p_data : Data (pointer on union of structure) associated with the event
 *
 * @return          None
 */
typedef void wiced_bt_ble_battc_cback_t(wiced_bt_ble_battc_event_t event,
        wiced_bt_ble_battc_event_data_t *p_event_data);

/**
 *
 * Function         wiced_bt_battc_init
 *
 * @param[in]       p_cback   : Callback for BLE BATTC event notification
 *
 *                  This function is called for BLE BATTC Initialization.
 *                  This function must be called, once, before any other BLE BATTC functions.
 *
 * @return          None
 *
 */
wiced_bt_ble_battc_status_t wiced_bt_ble_battc_init(wiced_bt_ble_battc_cback_t *p_callback);

/**
 * Function         wiced_bt_ble_battc_connect
 *
 *                  Open BATTC connection to a peer Device
 *                  If this function returns a successful status, the WICED_BT_BLE_BATTC_OPEN_EVT
 *                  event will be sent once the connection will be established.
 *
 * @param[in]       bdaddr      : BdAddr of the BATTC Device to connect
 * @param[in]       addr_type   : BdAddr Type (Random or Public)
 *
 * @return          Result code (see wiced_bt_ble_battc_status_t)
 *                  WICED_BT_BLE_BATTC_STATUS_OK if opening in progress, otherwise error.
 *
 */
wiced_bt_ble_battc_status_t wiced_bt_ble_battc_connect(wiced_bt_device_address_t bdaddr,
        wiced_bt_ble_address_type_t addr_type);

/**
 * Function         wiced_bt_ble_battc_disconnect
 *
 *                  Disconnect BLE BATTC connection to a BLE Device
 *                  If this function returns a successful status, the WICED_BT_BLE_BATTC_CLOSE_EVT
 *                  event will be sent once the connection will be released.
 *
 * @param[in]       ble_battc_conn_handle : BLE BATTC connection handle
 *
 * @return          Result code (see wiced_bt_ble_battc_status_t)
 *                  WICED_BT_BLE_BATTC_STATUS_OK if opening in progress, otherwise error.
 *
 */
wiced_bt_ble_battc_status_t wiced_bt_ble_battc_disconnect(uint16_t ble_battc_conn_handle);

/**
 * Function         wiced_bt_ble_battc_add
 *
 *                  Write the GATT Battery Cache information of a peer device.
 *                  If this function is not called before a connection is established with
 *                  a device (either incoming or outgoing) the BATT Client will perform GATT
 *                  discovery (to search for BATT Service and attributes).
 *                   *
 * @param[in]       bdaddr          : BdAddr of the BATTC Device to add
 * @param[in]       p_gatt_cache    : BLE BATTC GATT Database
 *
 * @return          Result code (see wiced_bt_ble_battc_status_t)
 *                  WICED_BT_BLE_BATTC_STATUS_OK if opening in progress, otherwise error.
 *
 */
wiced_bt_ble_battc_status_t wiced_bt_ble_battc_add(wiced_bt_device_address_t bdaddr,
        wiced_bt_ble_battc_gatt_cache_t *p_gatt_cache);

/**
 * Function         wiced_bt_ble_battc_remove
 *
 *                  Remove a BLE BATTC Device.
 *
 * @param[in]       bdaddr          : BdAddr of the BATTC Device to remove
 *
 * @return          Result code (see wiced_bt_ble_battc_status_t)
 *                  WICED_BT_BLE_BATTC_STATUS_OK if opening in progress, otherwise error.
 *
 */
wiced_bt_ble_battc_status_t wiced_bt_ble_battc_remove(wiced_bt_device_address_t bdaddr);

/**
 * Function         wiced_bt_ble_battc_read
 *
 *                  Read the Battery Level of a peer device.
 *                  Upon completion, a WICED_BT_BLE_BATTC_LEVEL_EVT event will be sent to the
 *                  application.
 *                  Notes:
 *                    - If the peer device supports notification (see WICED_BT_BLE_BATTC_OPEN_EVT)
 *                      the peer device will, automatically, send WICED_BT_BLE_BATTC_LEVEL_EVT
 *                      when the Battery Level will change.
 *                    - The BT SIG recommend to do not read Battery level more than once a week if
 *                      the expected battery life is in the order of years.
 *
 * @param[in]       handle   : Handle of the BATTC Device (from WICED_BT_BATTC_OPEN_EVT)

 * @return          Result code (see wiced_bt_ble_battc_status_t)
 *                  WICED_BT_BLE_BATTC_STATUS_OK if operation is progress, otherwise error.
 *
 */
wiced_bt_ble_battc_status_t wiced_bt_ble_battc_read(uint16_t handle);

/**
 * Function         wiced_bt_ble_battc_encryption_changed
 *
 *                  Application calls this function to when a the BLE Encryption Status changes
 *
 * @param[in]       p_encryption_changed   : BLE Encryption Status
 *
 * @return          None.
 *
 */
void wiced_bt_ble_battc_encryption_changed(wiced_bt_dev_encryption_status_t *p_encryption_changed);

/** @} wiced_bt_ble_battc_api_functions */

#ifdef __cplusplus
}
#endif
