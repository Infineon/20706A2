/*
 * Copyright 2020, Cypress Semiconductor Corporation or a subsidiary of
 * Cypress Semiconductor Corporation. All Rights Reserved.
 *
 * This software, including source code, documentation and related
 * materials ("Software"), is owned by Cypress Semiconductor Corporation
 * or one of its subsidiaries ("Cypress") and is protected by and subject to
 * worldwide patent protection (United States and foreign),
 * United States copyright laws and international treaty provisions.
 * Therefore, you may use this Software only as provided in the license
 * agreement accompanying the software package from which you
 * obtained this Software ("EULA").
 * If no EULA applies, Cypress hereby grants you a personal, non-exclusive,
 * non-transferable license to copy, modify, and compile the Software
 * source code solely for use in connection with Cypress's
 * integrated circuit products. Any reproduction, modification, translation,
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
 * WICED HID Host interface
 *
 */

#pragma once

#include <stdint.h>
#include "wiced_bt_types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup    wiced_bt_hid     Human Interface Device (HID)
 * @ingroup     wicedbt
 *
 *
 * @{

*/
/**
 * @addtogroup  wiced_bt_hidh_api_functions     HID Host Role (HIDH) over BR/EDR
 * @ingroup     wiced_bt_hid
 *
 * The Human Interface Device Host Role (HIDH) library of the WICED SDK provide a simple method
 * for an application to integrate HIDH functionality.
 * This library is typically used to connect to HID Devices such as Bluetooth (classic) Mice,
 * Keyboards or Remote Control.
 *
 * @{
*/

/*
 * Default HID MTU
 */
#define HID_DEV_MTU_SIZE    64

/**
 * @brief HIDH Events.
 *
 * HID Host event received by the HID Host callback (see wiced_bt_hidh_cback_t)
 */
typedef enum
{
    WICED_BT_HIDH_OPEN_EVT = 0,             /**< Connection Open. */
    WICED_BT_HIDH_CLOSE_EVT,                /**< Connection Closed. */
    WICED_BT_HIDH_DESCRIPTOR_EVT,           /**< HID Descriptor received. */
    WICED_BT_HIDH_SET_PROTOCOL_EVT,         /**< HID Set Protocol confirmation. */
    WICED_BT_HIDH_REPORT_EVT,               /**< HID Report received from peer HID Device. */
    WICED_BT_HIDH_SET_REPORT_EVT,           /**< Set HID Report confirmation. */
    WICED_BT_HIDH_GET_REPORT_EVT,           /**< Get HID Report confirmation. */
    WICED_BT_HIDH_VIRTUAL_UNPLUG_EVT,       /**< Virtual Unplug. */
} wiced_bt_hidh_event_t;

/**
 * @brief HIDH Status.
 *
 */
typedef enum
{
    WICED_BT_HIDH_STATUS_OK = 0,            /**< Operation success */
    WICED_BT_HIDH_STATUS_ERROR,             /**< Generic internal error */
    WICED_BT_HIDH_STATUS_PAGE_TIMEOUT,      /**< Not able to establish Baseband connection */
    WICED_BT_HIDH_STATUS_CON_LOST,          /**< Connection Lost */
    WICED_BT_HIDH_STATUS_NOT_SUPPORTED,     /**< Peer device does not support HID Device role */
    WICED_BT_HIDH_STATUS_MEM_FULL,          /**< Memory full */
    WICED_BT_HIDH_STATUS_BUSY,              /**< Busy */
    WICED_BT_HIDH_STATUS_INVALID_REP_ID,    /**< Invalid Report Id */
    WICED_BT_HIDH_STATUS_UNSUPPORTED_REQ,   /**< Unsupported Request */
    WICED_BT_HIDH_STATUS_INVALID_PARAM,     /**< Invalid Parameter */
    WICED_BT_HIDH_STATUS_UNKNOWN,           /**< Unknown Error*/
    WICED_BT_HIDH_STATUS_FATAL,             /**< Fatal Error*/

    /* Add other HID Host status here ... */
} wiced_bt_hidh_status_t;

/**
 * @brief HID Protocol definition (Regular Report or Boot Report mode).
 *
 */
typedef enum
{
    WICED_BT_HIDH_PROTOCOL_REPORT = 0,      /**< Protocol Mode Report. */
    WICED_BT_HIDH_PROTOCOL_BOOT,            /**< Protocol Mode Boot. */
} wiced_bt_hidh_protocol_t;

/**
 * @brief HID Report Type.
 *
 */
typedef enum
{
    WICED_BT_HIDH_REPORT_TYPE_RESERVED = 0, /**< Reserved Report Type. */
    WICED_BT_HIDH_REPORT_TYPE_INPUT,        /**< Input Report Type. */
    WICED_BT_HIDH_REPORT_TYPE_OUTPUT,       /**< Output Report Type. */
    WICED_BT_HIDH_REPORT_TYPE_FEATURE       /**< Feature Report Type. */
} wiced_bt_hidh_report_type_t;

/**
 * @brief HID Channel.
 *
 */
typedef enum
{
    WICED_BT_HIDH_CHANNEL_CONTROL = 0,      /**< Control Channel. */
    WICED_BT_HIDH_CHANNEL_INTERRUPT,        /**< Interrupt channel. */
} wiced_bt_hidh_channel_t;

/**
 * @brief Data associated with WICED_BT_HIDH_OPEN_EVT.
 *
 * This event is received:
 *  - After the wiced_bt_hidh_open function is called
 *  - When a peer device reconnects (reconnection allowed with wiced_bt_hidh_add)
 *
 */
typedef struct
{
    uint16_t                    handle;     /**< HIDH Connection Handle. */
    wiced_bt_hidh_status_t      status;     /**< HIDH Connection Status. */
    wiced_bt_device_address_t   bdaddr;     /**< BdAddr of the peer HID Device. */
} wiced_bt_hidh_open_t;

/**
 * @brief Data associated with WICED_BT_HIDH_CLOSE_EVT.
 *
 */
typedef struct
{
    uint16_t                    handle;     /**< HIDH Connection Handle. */
    uint8_t                     reason;     /**< HIDH Disconnection reason (HCI Status). */
} wiced_bt_hidh_close_t;

/**
 * @brief Data associated with WICED_BT_HIDH_DESCRIPTOR_EVT.
 *
 * This event is received after call to the wiced_bt_hidh_get_descriptor function.
 */
typedef struct
{
    uint16_t                    handle;     /**< HIDH Connection Handle. */
    wiced_bt_hidh_status_t      status;     /**< HIDH Operation Status. */
    uint8_t                     *p_descriptor;/**< HID Descriptor of the peer HID device. */
    uint16_t                    length;     /**< Length of the HID Descriptor */
} wiced_bt_hidh_descriptor_t;

/**
 * @brief Data associated with WICED_BT_HIDH_SET_PROTOCOL_EVT.
 *
 * This event is received after call to the wiced_bt_hidh_set_protocol function.
 */
typedef struct
{
    uint16_t                    handle;     /**< HIDH Connection Handle. */
    wiced_bt_hidh_status_t      status;     /**< HIDH Operation Status. */
} wiced_bt_hidh_set_protocol_t;

/**
 * @brief Data associated with WICED_BT_HIDH_SET_REPORT_EVT.
 *
 * This event is received after call to the wiced_bt_hidh_set_report function.
 */
typedef struct
{
    uint16_t                    handle;     /**< HIDH Connection Handle. */
    wiced_bt_hidh_status_t      status;     /**< HIDH Operation Status. */
} wiced_bt_hidh_set_report_t;

/**
 * @brief Data associated with WICED_BT_HIDH_GET_REPORT_EVT.
 *
 * This event is received after call to the wiced_bt_hidh_get_report function.
 */
typedef struct
{
    uint16_t                    handle;     /**< HIDH Connection Handle. */
    wiced_bt_hidh_status_t      status;     /**< HIDH Operation Status. */
    uint8_t                     *p_data;    /**< HID Report data. */
    uint16_t                    length;     /**< HID Report length. */
} wiced_bt_hidh_get_report_t;

/**
 * @brief Data associated with WICED_BT_HIDH_REPORT_EVT.
 *
 * This event is received when the peer HID Device sends a report (e.g. Button pressed/released).
 */
typedef struct
{
    uint16_t                    handle;     /**< HIDH Connection Handle. */
    uint8_t                     report_id;  /**< HID Report Id. */
    uint8_t                     *p_data;    /**< HID Report data. */
    uint16_t                    length;     /**< HID Report length. */
} wiced_bt_hidh_report_t;

/**
 * @brief Data associated with WICED_BT_HIDH_VIRTUAL_UNPLUG_EVT.
 *
 * This event is received when the peer HID Device sends a Virtual UnPlug event.
 * Upon reception of this event, the device will be disconnected and removed from the HID host
 * Database, but the application (embedded and/or MCU) must erase all Pairing information about
 * this device.
 */
typedef struct
{
    uint16_t                    handle;     /**< HIDH Connection Handle. */
} wiced_bt_hidh_virtual_unplug_t;


/**
 * @brief Union of data associated with HID Host events
 *
 */
typedef union
{
    wiced_bt_hidh_open_t            open;           /**< WICED_BT_HIDH_OPEN_EVT */
    wiced_bt_hidh_close_t           close;          /**< WICED_BT_HIDH_CLOSE_EVT */
    wiced_bt_hidh_descriptor_t      descriptor;     /**< WICED_BT_HIDH_DESCRIPTOR_EVT */
    wiced_bt_hidh_set_protocol_t    set_protocol;   /**< WICED_BT_HIDH_SET_PROTOCOL_EVT */
    wiced_bt_hidh_set_report_t      set_report;     /**< WICED_BT_HIDH_SET_REPORT_EVT */
    wiced_bt_hidh_get_report_t      get_report;     /**< WICED_BT_HIDH_GET_REPORT_EVT */
    wiced_bt_hidh_report_t          report;         /**< WICED_BT_HIDH_REPORT_EVT */
    wiced_bt_hidh_virtual_unplug_t  virtual_unplug; /**< WICED_BT_HIDH_VIRTUAL_UNPLUG_EVT */
} wiced_bt_hidh_data_t;


/**
 * HIDH Callback function type wiced_bt_hidh_cback_t
 *
 *                  WICED HID Host Event callback (registered with wiced_bt_hidh_enable)
 *
 * @param[in]       event: HIDH event received
 * @param[in]       p_data : Data (pointer on union of structure) associated with the event
 *
 * @return NONE
 */
typedef void (wiced_bt_hidh_cback_t)(wiced_bt_hidh_event_t event, wiced_bt_hidh_data_t *p_data);

/**
 *
 * Function         wiced_bt_hidh_init
 *
 *                  This function is called for HID Host Initialization.
 *                  This function must be called, once, before any other HIDH functions.
 *
 * @return          None
 *
 */
void wiced_bt_hidh_init(void);

/**
 * Function         wiced_bt_hidh_enable
 *
 *                  Enable (Start) HIDH subsystem. This function is used to register callback for
 *                  HIDH event notifications.
 *
 * @param[in]       p_cback   : Callback for HIDH event notification
 *
 * @return          Result code (see wiced_bt_hidh_status_t)
 *                  WICED_BT_HIDH_STATUS_OK if successful, otherwise error.
 */
wiced_bt_hidh_status_t wiced_bt_hidh_enable(wiced_bt_hidh_cback_t *p_cback);

/**
 * Function         wiced_bt_hidh_open
 *
 *                  Open HID Host connection to an HID Device
 *                  The first HID connection to an HID Device must always be initiated by the HID
 *                  Host device.
 *                  If this function returns a successfull status, the WICED_BT_HIDH_OPEN_EVT
 *                  event will be sent once the connection will be established.
 *
 * @param[in]       bdaddr   : BdAddr of the HID Device to connect
 *
 * @return          Result code (see wiced_bt_hidh_status_t)
 *                  WICED_BT_HIDH_STATUS_OK if opening in progress, otherwise error.
 *
 */
wiced_bt_hidh_status_t wiced_bt_hidh_open(wiced_bt_device_address_t bdaddr);

/*
 * wiced_bt_hidh_close:
 */
/**
 * Function         wiced_bt_hidh_close
 *
 *                  Close HID Host connection to an HID Device.
 *                  If this function returns a successfull status, the WICED_BT_HIDH_CLOSE_EVT
 *                  event will be sent once the connection will be released
 *
 * @param[in]       handle   : Handle of the HID Device to disconnect (from WICED_BT_HIDH_OPEN_EVT)
 *
 * @return          Result code (see wiced_bt_hidh_status_t)
 *                  WICED_BT_HIDH_STATUS_OK if closing in progress, otherwise error.
 *
 */
wiced_bt_hidh_status_t wiced_bt_hidh_close(uint16_t handle);

/**
 * Function         wiced_bt_hidh_add
 *
 *                  Add an HID Device (to the known HID Device list).
 *                  This function is, typically, called during application startup to allow
 *                  a peer HID Device to reconnect.
 *                  When a peer HID Device will reconnect, the WICED_BT_HIDH_OPEN_EVT event will
 *                  be sent to the application.
 *                  Note, that a peer device is not automatically added during the initial HID
 *                  connection. The application must explicitly Add it with this API.
 *
 * @param[in]       bdaddr   : BdAddr of the HID Device to add
 *
 * @return          Result code (see wiced_bt_hidh_status_t)
 *                  WICED_BT_HIDH_STATUS_OK if successful, otherwise error.
 *
 */
wiced_bt_hidh_status_t wiced_bt_hidh_add(wiced_bt_device_address_t bdaddr);

/**
 * Function         wiced_bt_hidh_remove
 *
 *                  Remove an HID Device (from the known HID Device list).
 *                  This function is called to do not allow anymore a peer HID Device to reconnect.
 *                  If this HID Device is already connected, this connection will be closed.
 *
 * @param[in]       bdaddr   : BdAddr of the HID Device to remove
 *
 * @return          Result code (see wiced_bt_hidh_status_t)
 *                  WICED_BT_HIDH_STATUS_OK if successful, otherwise error.
 *
 */
wiced_bt_hidh_status_t wiced_bt_hidh_remove(wiced_bt_device_address_t bdaddr);

/**
 * Function         wiced_bt_hidh_get_descriptor
 *
 *                  Get the HID Descriptor of a connected HID Device.
 *                  This function is called to get the HID Descriptor, of a connected, peer
 *                  HID Device.
 *                  If this function returns a successfull status, the WICED_BT_HIDH_DESCRIPTOR_EVT
 *                  event will be sent once once the operation complete.
 *                  This function is, typically, called during the initial connection to an HID
 *                  Device. The HID Host must store this descriptor in a Non Volatile Memory and
 *                  use it every time this device reconnects.
 *
 * @param[in]       handle   : Handle of the HID Device (from WICED_BT_HIDH_OPEN_EVT)
 *
 * @return          Result code (see wiced_bt_hidh_status_t)
 *                  WICED_BT_HIDH_STATUS_OK if operation in progress, otherwise error.
 *
 */
wiced_bt_hidh_status_t wiced_bt_hidh_get_descriptor(uint16_t handle);

/**
 * Function         wiced_bt_hidh_set_report
 *
 *                  Set (send) a Report to a peer HID Device.
 *                  This function is called to set (send) an HID Report to an HID Device.
 *                  This function can be used, for example, to control the 'Caps Lock" led of
 *                  a Bluetooth Keyboard.
 *                  if the Channel is Control channel, a WICED_BT_HIDH_SET_REPORT_EVT event will
 *                  be sent to the application.
 *
 * @param[in]       handle   : Handle of the HID Device (from WICED_BT_HIDH_OPEN_EVT)
 * @param[in]       channel  : Control or Interrupt channel.
 * @param[in]       type     : Report Type (Input/Output/Feature).
 * @param[in]       report_id: The ReportId to Set.
 * @param[in]       p_data   : The Report Data (NULL if no data).
 * @param[in]       p_data   : The Report Data length (if any).

 * @return          Result code (see wiced_bt_hidh_status_t)
 *                  WICED_BT_HIDH_STATUS_OK if operation is progress, otherwise error.
 *
 */
wiced_bt_hidh_status_t wiced_bt_hidh_set_report(uint16_t handle, wiced_bt_hidh_channel_t channel,
        wiced_bt_hidh_report_type_t type, uint8_t report_id, uint8_t *p_data, uint16_t length);

/**
 * Function         wiced_bt_hidh_get_report
 *
 *                  This function is called to Get (receive) an HID Report from a connected
 *                  HID Device.
 *                  This function can be used, for example, to read the last HID Report received.

 * @param[in]       handle   : Handle of the HID Device (from WICED_BT_HIDH_OPEN_EVT)
 * @param[in]       type     : Report Type (Input/Output/Feature).
 * @param[in]       report_id: The ReportId to Get (optional). If 0, will not be sent in request
 * @param[in]       length   : Maximum Rx buffer size (optional) . If 0, will not be sent in request
 *
 * @return          Result code (see wiced_bt_hidh_status_t)
 *                  WICED_BT_HIDH_STATUS_OK if successful, otherwise error.
 *
 */
wiced_bt_hidh_status_t wiced_bt_hidh_get_report(uint16_t handle,
        wiced_bt_hidh_report_type_t type, uint8_t report_id, uint16_t length);

/**
 * Function         wiced_bt_hidh_set_protocol
 *
 *                  Sends Set HID Protocol to a peer HID Device.
 *                  This function is called to Change the HID Protocol of a connected HID Device.
 *
 * @param[in]       handle   : Handle of the HID Device (from WICED_BT_HIDH_OPEN_EVT)
 * @param[in]       protocol : Protocol mode (Report/Boot).
 *
 * @return          Result code (see wiced_bt_hidh_status_t)
 *                  WICED_BT_HIDH_STATUS_OK if successful, otherwise error.
 *
 */
wiced_bt_hidh_status_t wiced_bt_hidh_set_protocol(uint16_t handle,
        wiced_bt_hidh_protocol_t protocol);

/** @} wiced_bt_hidh_api_functions */
/** @} wiced_bt_hid */

#ifdef __cplusplus
}
#endif
