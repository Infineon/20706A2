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
#include "wiced_bt_gatt.h"
#include "wiced_bt_gatt_util.h"

/** @file
 *
 * GATT Multi-Profile library
 *
 */

/*****************************************************************************
 *  External Function Declarations
 ****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/**
 * @addtogroup  wiced_bt_gatt_mp_api_functions     GATT Multi-Profile (GATT_MP) library
 * @ingroup     wicedbt_gatt
 *
 * The GATT MP library of the WICED SDK provides API to implements Multiple GATT Profiles/Services
 *
 * @{
*/

/**
 * @brief Maximum number of BLE/GATT (physical) connections
 */
#define WICED_BT_GATT_MP_CONN_MAX           8

/**
 * @brief Maximum number of BLE ProfileId per connection
 */
#define WICED_BT_GATT_MP_PID_MAX            4

/**
 * @brief GATT MP Profile Id
 */
typedef uint8_t wiced_bt_gatt_mp_pid_t;


/**
 * Function     wiced_bt_gatt_mp_init
 *
 *              Initializes the GATT MP Library
 *
 *
 * @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_init (void);

/**
 * Function     wiced_bt_gatt_mp_register
 *
 *              Register a GATT Profile/Service.
 *              The pid returned must be used by the Profile/Service for future API calls
 *
 * @param[in]   p_gatt_cback    : Callback function of the profile/service
 * @param[out]  p_id            : Registered Profile/service Identification
 *
 * @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_register (wiced_bt_gatt_cback_t *p_gatt_cback,
        wiced_bt_gatt_mp_pid_t *p_id);

/**
 * Function     wiced_bt_gatt_mp_deregister
 *
 *              Deregister a GATT Profile/Service
 *
 * @param[in]  pid              : Profile/service Identification to deregister
 *
 * @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_deregister (wiced_bt_gatt_mp_pid_t pid);

/**
 * Function     wiced_bt_gatt_mp_encryption_changed
 *
 *              This function must be called when the Encryption State of a link changes
 *
 * @param[in]  p_encryption_changed : Encryption data (from BTM_ENCRYPTION_STATUS_EVT event)
 *
 * @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
void wiced_bt_gatt_mp_encryption_changed(wiced_bt_dev_encryption_status_t *p_encryption_changed);

/**
 * Function     wiced_bt_gatt_mp_register_handles
 *
 *              This function is used (by Profile/Service) to register handler range.
 *              For Server Registration (conn_id = 0):
 *                  Indicate which Handle range will GATT Request will be sent to
 *              For Client Registration (conn_id != 0):
 *                  Indicate which Handle range will GATT notification/Indication will be sent to
 *
 * @param[in]  pid              : Profile/service Identification registered
 * @param[in]  start_handle     : First handle of the range
 * @param[in]  end_handle       : Last handle of the range
 * @param[in]  conn_id          : Connection Id
 *
 * @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_register_handles(wiced_bt_gatt_mp_pid_t pid,
        uint16_t start_handle, uint16_t end_handle, uint16_t conn_id);

/**
 * Function     wiced_bt_gatt_mp_is_encrypted
 *
 *              This function is used (by Profile/Service) to check the Encryption status of a link
 *
 * @param[in]  conn_id          : Connection Id
 * @param[out] p_is_encrypted   : WICED_FALSE if not Encrypted. WICED_TRUE otherwise.
 *
 * @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_is_encrypted(uint16_t conn_id,
        wiced_bool_t *p_is_encrypted);

/**
 * Function     wiced_bt_gatt_mp_le_connect
 *
 *              This function is used (by Profile/Service) to Open GATT over LE connection
 *              to a remote device
 *
 * @param[in]  pid              : Profile/service Identification registered
*  @param[in]  bd_addr          : Remote device address
*  @param[in]  bd_addr_type     : Public or random address
*  @param[in]  conn_mode        : connection scan mode
*  @param[in]  is_direct        : Is direct connection or not
 *
 *  @return <b> WICED_TRUE </b> : If connection started
 *          <b> WICED_FALSE </b>: If connection start failure
 *
 */
wiced_bool_t wiced_bt_gatt_mp_le_connect(wiced_bt_gatt_mp_pid_t pid,
        wiced_bt_device_address_t bd_addr, wiced_bt_ble_address_type_t bd_addr_type,
        wiced_bt_ble_conn_mode_t conn_mode, wiced_bool_t is_direct);

/**
 * Function       wiced_bt_gatt_mp_disconnect
 *
 *                Close the specified GATT connection.
 *
 * @param[in]  pid              : Profile/service Identification registered
 * @param[in]  conn_id          : GATT connection ID
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_disconnect(wiced_bt_gatt_mp_pid_t pid, uint16_t conn_id);

/*****************************************************************************/

/**
 * Function       wiced_bt_gatt_mp_configure_mtu
 *
 *                Configure the ATT MTU size for a connection on an LE
 *                transport .Allowed mtu range is 23 to max_mtu_size configured
 *                in #wiced_bt_cfg_settings_t
 *                Note: the response event will be send to every Profile/Service registered
 *
 * @param[in]  pid              : Profile/service Identification registered
 * @param[in]  conn_id          : GATT connection handle
 * @param[in]  mtu              : New MTU size
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
*/
wiced_bt_gatt_status_t wiced_bt_gatt_mp_configure_mtu(wiced_bt_gatt_mp_pid_t pid,
        uint16_t conn_id , uint16_t mtu);

/**
 * Function       wiced_bt_gatt_mp_send_discover
 *
 *                Start an attribute discovery on an ATT server.
 *                Discovery results are notified using <b> GATT_DISCOVERY_RESULT_EVT </b>;
 *                completion is notified using <b> GATT_DISCOVERY_CPLT_EVT </b> of #wiced_bt_gatt_cback_t.
 *
 * @param[in]  pid                 : Profile/service Identification registered
 * @param[in]  conn_id             : GATT connection handle
 * @param[in]  discovery_type      : Discover type
 * @param[in]  p_discovery_param   : Discover parameter
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
*/
wiced_bt_gatt_status_t wiced_bt_gatt_mp_send_discover(wiced_bt_gatt_mp_pid_t pid,
        uint16_t conn_id, wiced_bt_gatt_discovery_type_t discovery_type,
        wiced_bt_gatt_discovery_param_t *p_discovery_param);

/**
 * Function       wiced_bt_gatt_mp_send_discover16
 *
 *                Helper function to send GATT Discovery of 16 bits UUID (calls
 *                wiced_bt_gatt_mp_send_discover function).
 *
 * @param[in]  pid                 : Profile/service Identification registered
 * @param[in]  conn_id             : GATT connection handle
 * @param[in]  discovery_type      : Discover type
 * @param[in]  uuid16              : 16 bits UUID to discover (or 0)
 * @param[in]  start_handle        : Start Handle
 * @param[in]  uuid16              : End Handle
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
*/
wiced_bt_gatt_status_t wiced_bt_gatt_mp_send_discover16(wiced_bt_gatt_mp_pid_t pid,
        uint16_t conn_id, wiced_bt_gatt_discovery_type_t discovery_type, uint16_t uuid16,
        uint16_t start_handle, uint16_t end_handle);


/**
 * Function       wiced_bt_gatt_mp_send_write
 *
 *                Write to remote ATT server.
 *                Result is notified using <b> GATT_OPERATION_CPLT_EVT </b> of #wiced_bt_gatt_cback_t.
 *
 * @param[in]  pid         : Profile/service Identification registered
 * @param[in]  conn_id     : Connection handle
 * @param[in]  type        : Type of write
 * @param[in]  p_write     : Pointer to the write parameters
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_send_write(wiced_bt_gatt_mp_pid_t pid,
        uint16_t conn_id, wiced_bt_gatt_write_type_t type, wiced_bt_gatt_value_t *p_write);

/**
 * Function       wiced_bt_gatt_mp_send_execute_write
 *
 *                Send Execute Write request to remote ATT server.
 *
 * @param[in]  pid         : Profile/service Identification registered
 * @param[in]  conn_id     : Connection handle
 * @param[in]  is_execute  : <b>WICED_BT_TRUE </b> to execute, <b> WICED_BT_FALSE </b> to cancel
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_send_execute_write(wiced_bt_gatt_mp_pid_t pid,
        uint16_t conn_id, wiced_bool_t is_execute);

/**
 * Function       wiced_bt_gatt_mp_send_read
 *
 *                Read from remote ATT server.
 *                Result is notified using <b> GATT_OPERATION_CPLT_EVT </b> of #wiced_bt_gatt_cback_t.
 *
 * @param[in]  pid         : Profile/service Identification registered
 * @param[in]  conn_id     : Connection handle
 * @param[in]  type        : Type of the read
 * @param[in]  p_read      : Pointer to the read request parameters
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_send_read(wiced_bt_gatt_mp_pid_t pid,
        uint16_t conn_id, wiced_bt_gatt_read_type_t type, wiced_bt_gatt_read_param_t *p_read);

/**
 *
 * Function     wiced_bt_gatt_mp_send_indication
 *
 *              Send a handle value indication to a client
 *
 * @param[in]  pid         : Profile/service Identification registered
 * @param[in]  attr_handle : Attribute handle of this handle value indication.
 * @param[in]  val_len     : Length of notification value passed.
 * @param[in]  p_val       : Notification Value.
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_send_indication(wiced_bt_gatt_mp_pid_t pid,
        uint16_t conn_id, uint16_t attr_handle, uint16_t val_len, uint8_t *p_val);

/**
 * Function     wiced_bt_gatt_send_notification
 *
 *              Send a handle value notification to a client.
 *
 * @param[in]  pid         : Profile/service Identification registered
 * @param[in]  conn_id     : connection identifier.
 * @param[in]  handle      : Attribute handle of this handle value indication.
 * @param[in]  length      : Length of notification value passed.
 * @param[in]  p_data      : Notification Value.
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
 *
 */
wiced_bt_gatt_status_t wiced_bt_gatt_mp_send_notification(wiced_bt_gatt_mp_pid_t pid,
        uint16_t conn_id, uint16_t handle, uint16_t length, uint8_t *p_data);

/**
 * Function       wiced_bt_gatt_mp_send_indication_confirm
 *
 *                Send a handle value confirmation to remote ATT server.
 *                (in response to <b>GATTC_OPTYPE_INDICATION </b>  of #wiced_bt_gatt_cback_t)
 *
 * @param[in]  pid         : Profile/service Identification registered
 * @param[in]  conn_id     : Connection handle
 * @param[in]  handle      : Attribute handle
 *
 *  @return @link wiced_bt_gatt_status_e wiced_bt_gatt_status_t @endlink
*/
wiced_bt_gatt_status_t wiced_bt_gatt_mp_send_indication_confirm(wiced_bt_gatt_mp_pid_t pid,
        uint16_t conn_id, uint16_t attr_handle);

/**@} wiced_bt_gatt_mp_api */

#ifdef __cplusplus
}
#endif
