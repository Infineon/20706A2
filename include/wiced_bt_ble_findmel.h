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
 * @addtogroup  wicedbt_Findmel_api_functions FindMe Locator
 * @ingroup     wicedbt
 *
 * The FindMe Locator (Client) library of the WICED SDK provide a simple method for an application to
 * integrate Alert functionality.
 * This library is typically used to Set the Immediate Alert level of a peer BLE FindMe Target Device.
 *
 * @{
*/

/**
 * @brief BLE FINDMEL Maximum FINDMEL Devices.
 */
#define WICED_BT_BLE_FINDMEL_DEV_MAX                   3

/**
 * @brief FINDMEL Events.
 *
 * BLE FINDMEL event received by the BLE FINDMEL callback (see wiced_bt_ble_findmel_cback_t)
 */
typedef enum
{
    WICED_BT_BLE_FINDMEL_OPEN_EVT,             /**< Connection Open. */
    WICED_BT_BLE_FINDMEL_CLOSE_EVT,            /**< Connection Closed. */
    WICED_BT_BLE_FINDMEL_GATT_CACHE_EVT,       /**< BLE FINDMEL GATT Cache. */
} wiced_bt_ble_findmel_event_t;

/**
 * @brief BLE FINDMEL Error codes.
 *
 * This enumeration contains the list of FINDMEL Error codes.
 */
typedef enum
{
    WICED_BT_BLE_FINDMEL_STATUS_SUCCESS = 0,       /**< Operation success */
    WICED_BT_BLE_FINDMEL_STATUS_UNSUPPORTED,       /**< Peer device does not support Alert Service */
    WICED_BT_BLE_FINDMEL_STATUS_ERROR,             /**< Generic internal error */
    WICED_BT_BLE_FINDMEL_STATUS_GATT_ERROR,        /**< Generic GATT error */
    WICED_BT_BLE_FINDMEL_STATUS_INVALID_PARAM,     /**< Invalid Parameter */
    WICED_BT_BLE_FINDMEL_STATUS_MEM_FULL,          /**< Memory full */
    WICED_BT_BLE_FINDMEL_STATUS_CONNECTION_FAILED, /**< Not able to establish Baseband connection */
} wiced_bt_ble_findmel_status_t;

/**
 * @brief BLE Alert Level.
 *
 * This enumeration contains the list of Alert Level.
 */
typedef enum
{
    WICED_BT_BLE_FINDMEL_LEVEL_NO_ALERT = 0,     /**< No Alert */
    WICED_BT_BLE_FINDMEL_LEVEL_MILD_ALERT,       /**< Mild Alert */
    WICED_BT_BLE_FINDMEL_LEVEL_HIGH_ALERT,       /**< High Alert */
} wiced_bt_ble_findmel_level_t;

/**
 * @brief Data associated with WICED_BT_BLE_FINDMEL_OPEN_EVT.
 *
 * This event is received:
 *  - After the wiced_bt_ble_findmel_open function is called or
 *  - When a peer device reconnects (reconnection allowed with wiced_bt_ble_findmel_add)
 *
 */
typedef struct
{
    wiced_bt_device_address_t bdaddr;           /**< Peer Device address */
    uint16_t handle;                            /**< FINDMEL Connection Handle. */
    wiced_bt_ble_findmel_status_t status;        /**< FINDMEL Connection station */
} wiced_bt_ble_findmel_connected_t;

/**
 * @brief Data associated with WICED_BT_BLE_FINDMEL_CLOSE_EVT.
 *
 * This event is received:
 *  - After the wiced_bt_ble_findmel_disconnect function is called or
 *  - When a peer device disconnects
 *
 */
typedef struct
{
    uint16_t handle;
    wiced_bt_gatt_disconn_reason_t reason;
} wiced_bt_ble_findmel_disconnected_t;

/**
 * @brief BLE FINDMEL GATT Characteristic.
 *
 * This structure contains the informations of a BLE FINDMEL GATT Characteristic.
 */
typedef struct
{
    uint16_t uuid16;
    uint16_t handle;
    uint16_t val_handle;
    wiced_bt_gatt_char_properties_t properties;
} wiced_bt_ble_findmel_gatt_char_t;


/**
 * @brief Data associated with WICED_BT_BLE_FINDMEL_GATT_CACHE_EVT.
 *
 * This event is received to save the BLE FINDMEL GATT Cache information in NVRAM.
 */
typedef struct
{
    wiced_bt_device_address_t bdaddr;           /**< BLE FINDMEL Device Address. */
    wiced_bt_ble_findmel_gatt_char_t characteristic;
} wiced_bt_ble_findmel_gatt_cache_t;

typedef union
{
    wiced_bt_ble_findmel_connected_t    connected;     /**< WICED_BT_BLE_FINDMEL_OPEN_EVT */
    wiced_bt_ble_findmel_disconnected_t disconnected;  /**< WICED_BT_BLE_FINDMEL_CLOSE_EVT */
    wiced_bt_ble_findmel_gatt_cache_t   gatt_cache;    /**< WICED_BT_BLE_FINDMEL_GATT_CACHE_EVT */
} wiced_bt_ble_findmel_event_data_t;

/**
 * FINDMEL Callback function type wiced_bt_ble_findmel_cback_t
 *
 *                  WICED BLE FINDMEL Host Event callback (registered with wiced_bt_ble_findmel_init)
 *
 * @param[in]       event: BLE FINDMEL event received
 * @param[in]       p_data : Data (pointer on union of structure) associated with the event
 *
 * @return          None
 */
typedef void wiced_bt_ble_findmel_cback_t(wiced_bt_ble_findmel_event_t event,
        wiced_bt_ble_findmel_event_data_t *p_event_data);

/**
 *
 * Function         wiced_bt_findmel_init
 *
 * @param[in]       p_cback   : Callback for BLE FINDMEL event notification
 *
 *                  This function is called for BLE FINDMEL Initialization.
 *                  This function must be called, once, before any other BLE FINDMEL functions.
 *
 * @return          None
 *
 */
wiced_bt_ble_findmel_status_t wiced_bt_ble_findmel_init(wiced_bt_ble_findmel_cback_t *p_callback);

/**
 * Function         wiced_bt_ble_findmel_connect
 *
 *                  Open FINDMEL connection to a peer Device
 *                  If this function returns a successful status, the WICED_BT_BLE_FINDMEL_OPEN_EVT
 *                  event will be sent once the connection will be established.
 *
 * @param[in]       bdaddr      : BdAddr of the FINDMEL Device to connect
 * @param[in]       addr_type   : BdAddr Type (Random or Public)
 *
 * @return          Result code (see wiced_bt_ble_findmel_status_t)
 *                  WICED_BT_BLE_FINDMEL_STATUS_OK if opening in progress, otherwise error.
 *
 */
wiced_bt_ble_findmel_status_t wiced_bt_ble_findmel_connect(wiced_bt_device_address_t bdaddr,
        wiced_bt_ble_address_type_t addr_type);

/**
 * Function         wiced_bt_ble_findmel_disconnect
 *
 *                  Disconnect BLE FINDMEL connection to a BLE Device
 *                  If this function returns a successful status, the WICED_BT_BLE_FINDMEL_CLOSE_EVT
 *                  event will be sent once the connection will be released.
 *
 * @param[in]       ble_findmel_conn_handle : BLE FINDMEL connection handle
 *
 * @return          Result code (see wiced_bt_ble_findmel_status_t)
 *                  WICED_BT_BLE_FINDMEL_STATUS_OK if opening in progress, otherwise error.
 *
 */
wiced_bt_ble_findmel_status_t wiced_bt_ble_findmel_disconnect(uint16_t ble_findmel_conn_handle);

/**
 * Function         wiced_bt_ble_findmel_add
 *
 *                  Write the GATT Alert Cache information of a peer device.
 *                  If this function is not called before a connection is established with
 *                  a device (either incoming or outgoing) the BATT Client will perform GATT
 *                  discovery (to search for BATT Service and attributes).
 *                   *
 * @param[in]       bdaddr          : BdAddr of the FINDMEL Device to add
 * @param[in]       p_gatt_cache    : BLE FINDMEL GATT Database
 *
 * @return          Result code (see wiced_bt_ble_findmel_status_t)
 *                  WICED_BT_BLE_FINDMEL_STATUS_OK if opening in progress, otherwise error.
 *
 */
wiced_bt_ble_findmel_status_t wiced_bt_ble_findmel_add(wiced_bt_device_address_t bdaddr,
        wiced_bt_ble_findmel_gatt_cache_t *p_gatt_cache);

/**
 * Function         wiced_bt_ble_findmel_remove
 *
 *                  Remove a BLE FINDMEL Device.
 *
 * @param[in]       bdaddr          : BdAddr of the FINDMEL Device to remove
 *
 * @return          Result code (see wiced_bt_ble_findmel_status_t)
 *                  WICED_BT_BLE_FINDMEL_STATUS_OK if opening in progress, otherwise error.
 *
 */
wiced_bt_ble_findmel_status_t wiced_bt_ble_findmel_remove(wiced_bt_device_address_t bdaddr);

/**
 * Function         wiced_bt_ble_findmel_write_alert
 *
 *                  Write the Alert Level to a peer device.
 *
 * @param[in]       handle   : Handle of the FINDMEL Device (from WICED_BT_FINDMEL_OPEN_EVT)
 * @param[in]       level    : Alert Level (see wiced_bt_ble_findmel_level_t)
 *
 * @return          Result code (see wiced_bt_ble_findmel_status_t)
 *                  WICED_BT_BLE_FINDMEL_STATUS_OK if operation is progress, otherwise error.
 *
 */
wiced_bt_ble_findmel_status_t wiced_bt_ble_findmel_write_alert(uint16_t handle,
        wiced_bt_ble_findmel_level_t alert_level);

/**
 * Function         wiced_bt_ble_findmel_encryption_changed
 *
 *                  Application calls this function to when a the BLE Encryption Status changes
 *
 * @param[in]       p_encryption_changed   : BLE Encryption Status
 *
 * @return          None.
 *
 */
void wiced_bt_ble_findmel_encryption_changed(wiced_bt_dev_encryption_status_t *p_encryption_changed);

/** @} wicedbt_Findmel_api_functions */

#ifdef __cplusplus
}
#endif
