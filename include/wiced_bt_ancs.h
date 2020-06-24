/*
 * Copyright 2016-2020, Cypress Semiconductor Corporation or a subsidiary of
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
 * This file provides definitions of the Apple Notification Control Service (ANCS) library interface
 */

#ifndef ANCS_CLIENT__H
#define ANCS_CLIENT__H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup  wiced_bt_ancs_api_functions        ANCS Library API
 * @ingroup     wicedbt
 *
 * ANCS library of the WICED SDK provide a simple method for an application to integrate ANCS
 * client functionality.  The pplication needs to call API to initialize the library when it
 * discovers that ANCS service is present in the connected device.  Library in turn
 * sends callback with various notifications received from the iOS device.
 *
 * @{
 */

/// ANCS service GATT UUID 7905F431-B5CE-4E99-A40F-4B1E122D00D0
const char ANCS_SERVICE[]             = {0xD0, 0x00, 0x2D, 0x12, 0x1E, 0x4B, 0x0F, 0xA4, 0x99, 0x4E, 0xCE, 0xB5, 0x31, 0xF4, 0x05, 0x79};

/// Notification Source Characteristic: UUID 9FBF120D-6301-42D9-8C58-25E699A21DBD (notifiable) */
const char ANCS_NOTIFICATION_SOURCE[] = {0xBD, 0x1D, 0xA2, 0x99, 0xE6, 0x25, 0x58, 0x8C, 0xD9, 0x42, 0x01, 0x63, 0x0D, 0x12, 0xBF, 0x9F};

/// Control Point Characteristic : UUID 69D1D8F3-45E1-49A8-9821-9BBDFDAAD9D9 (writeable with response)
const char ANCS_CONTROL_POINT[]       = {0xD9, 0xD9, 0xAA, 0xFD, 0xBD, 0x9B, 0x21, 0x98, 0xA8, 0x49, 0xE1, 0x45, 0xF3, 0xD8, 0xD1, 0x69};

/// Data Source Characteristic: UUID 22EAC6E9-24D6-4BB5-BE44-B36ACE7C7BFB (notifiable)
const char ANCS_DATA_SOURCE[]         = {0xFB, 0x7B, 0x7C, 0xCE, 0x6A, 0xB3, 0x44, 0xBE, 0xB5, 0x4B, 0xD6, 0x24, 0xE9, 0xC6, 0xEA, 0x22};

/// max notifications to queue
#define ANCS_MAX_QUEUED_NOTIFICATIONS                   20

/**
 * @anchor ANCS_EVENT_ID
 * @name EventID values
 * @{ */
#define ANCS_EVENT_ID_NOTIFICATION_ADDED                0
#define ANCS_EVENT_ID_NOTIFICATION_MODIFIED             1
#define ANCS_EVENT_ID_NOTIFICATION_REMOVED              2
#define ANCS_EVENT_ID_MAX                               3
/** @} ANCS_EVENT_ID */

/**
 * @anchor ANCS_NOTIFICATION_ATTR_ID
 * @name Notification Attribute ID values
 * @{ */
// Definitions for attributes we are not interested in are commented out
//#define ANCS_NOTIFICATION_ATTR_ID_APP_ID                0
#define ANCS_NOTIFICATION_ATTR_ID_TITLE                 1
//#define ANCS_NOTIFICATION_ATTR_ID_SUBTITLE              2
#define ANCS_NOTIFICATION_ATTR_ID_MESSAGE               3
#define ANCS_NOTIFICATION_ATTR_ID_MESSAGE_SIZE          4
//#define ANCS_NOTIFICATION_ATTR_ID_DATE                  5
#define ANCS_NOTIFICATION_ATTR_ID_POSITIVE_ACTION_LABEL 6
#define ANCS_NOTIFICATION_ATTR_ID_NEGATIVE_ACTION_LABEL 7
#define ANCS_NOTIFICATION_ATTR_ID_MAX                   8
/** @} ANCS_NOTIFICATION_ATTR_ID */

/**
 * The list of notification attributes that library is going
 * to request.  Compile out attribute of no interest
 */
const uint8_t  ancs_client_notification_attribute[] =
{
//    ANCS_NOTIFICATION_ATTR_ID_APP_ID,
    ANCS_NOTIFICATION_ATTR_ID_TITLE,
//    ANCS_NOTIFICATION_ATTR_ID_SUBTITLE,
    ANCS_NOTIFICATION_ATTR_ID_MESSAGE_SIZE,
    ANCS_NOTIFICATION_ATTR_ID_MESSAGE,
//    ANCS_NOTIFICATION_ATTR_ID_DATE,
    ANCS_NOTIFICATION_ATTR_ID_POSITIVE_ACTION_LABEL,
    ANCS_NOTIFICATION_ATTR_ID_NEGATIVE_ACTION_LABEL,
    0
};

/**
 *  Maximum length library is going to request.  The values are valid for
 * title subtitle and message.  The number of elements should match number
 * of elements in the ancs_client_notification_attribute above
 */
const uint8_t  ancs_client_notification_attribute_length[] =
{
//    0,
    50,
//    20,
    0,
    255,
//    0,
    0,
    0,
    0
};

/**
 * @anchor ANCS_EVENT_FLAG
 * @name Notification Event Flag values
 * @{ */
#define ANCS_EVENT_FLAG_SILENT                          (1 << 0)
#define ANCS_EVENT_FLAG_IMPORTANT                       (1 << 1)
#define ANCS_EVENT_FLAG_PREEXISTING                     (1 << 2)
#define ANCS_EVENT_FLAG_POSITIVE_ACTION                 (1 << 3)
#define ANCS_EVENT_FLAG_NEGATIVE_ACTION                 (1 << 4)
/** @} ANCS_EVENT_FLAG */

/** ANCS event as the library passes to the application */
typedef struct
{
    void        *p_next;                        /** pointer to the next event when in the queue */
    uint32_t    notification_uid;               /** notification UID */
    uint8_t     command;
    uint8_t     flags;                          /**< Bitmask of the flags, see @ref ANCS_EVENT_FLAG "ANCS Event Flags" */
    uint8_t     category;                       /**< Positive action label */
    uint8_t     title[50];                      /**< Title of the Notification */
    uint8_t     message[255];                   /**< notification message */
    uint8_t     positive_action_label[10];      /**< Positive action label */
    uint8_t     negative_action_label[10];      /**< Negative action label */
} ancs_event_t;

/*****************************************************************************
 *          Function Prototypes
 *****************************************************************************/

/**
 * This callback is executed when ANCS library completes discovery of ANCS service
 * characteristics and descriptors.
 *
 * @param           conn_id : GATT connection ID
 * @param           status  : WICED_TRUE if initialization completed successfully.
 * @return          none
 */
typedef void (*wiced_bt_ancs_discovery_complete_callback_t)(uint16_t conn_id, wiced_bool_t success);

/**
 * This callback is executed when ANCS library completes startup operation of the ANCS.
 *
 * @param           conn_id : GATT connection ID
 * @param           status  : Status of the operation.
 * @return          none
 */
typedef void (*wiced_bt_ancs_start_complete_callback_t)(uint16_t conn_id, wiced_bt_gatt_status_t success);

/**
 * This callback is executed when ANCS library completes stop operation of the ANCS.
 *
 * @param           conn_id : GATT connection ID
 * @param           status  : Status of the operation.
 * @return          none
 */
typedef void (*wiced_bt_ancs_stop_complete_callback_t)(uint16_t conn_id, wiced_bt_gatt_status_t success);

/**
 * WICED BT ANCS library executes this callback when it receives complete notification
 * from the iOS device with new ANCS event.
 *
 * @param           conn_id   	    : Connection ID.
 * @param           ancs_event      : Received ANCS Event.
 * @return          none
 */
typedef void (*wiced_bt_ancs_notification_callback_t)(uint16_t conn_id, ancs_event_t *p_ancs_event);

/**
 * Following structure is used to register application with wiced_bt_ancs library
 */
typedef struct
{
    wiced_bt_ancs_discovery_complete_callback_t  p_discovery_complete_callback; /**< callback to be executed when ANCS library completes GATT discovery */
    wiced_bt_ancs_start_complete_callback_t      p_start_complete_callback;     /**< callback to be executed when ANCS library completes ANCS Server configuration */
    wiced_bt_ancs_stop_complete_callback_t       p_stop_complete_callback;      /**< callback to be executed when ANCS library completes ANCS Server deconfiguration */
    wiced_bt_ancs_notification_callback_t        p_notification_callback;     	/**< callback to be executed when ANCS library receives Attribute from the iOS device */
} wiced_bt_ancs_reg_t;

/**
 * The application should call this function to register application callbacks
 *
 * @param           p_reg  : Registration control block that includes ANCS application callbacks.
 * @return          none
 */
void wiced_bt_ancs_client_initialize(wiced_bt_ancs_reg_t *p_reg);

/**
 * The application should call this function when it discovers that connected central device
 * contains the ANCS service.  The function initialize ANCS library and starts the GATT discovery
 * of ANCS characteristics.
 *
 * @param           conn_id  : GATT connection ID.
 * @param           s_handle : Start GATT handle of the ANCS service.
 * @param           e_handle : End GATT handle of the ANCS service.
 * @return          WICED_TRUE if GATT discovery started successfully, WICED_FALSE otherwise.
 */
wiced_bool_t wiced_bt_ancs_client_discover(uint16_t conn_id, uint16_t s_handle, uint16_t e_handle);

/**
 * While application performs GATT discovery it shall pass discovery results for
 * the ANCS service to the ANCS Library. The library needs to find ANCS service characteristics
 * and associated characteristic client configuration descriptors.
 *
 * @param           p_data   : Discovery result data as passed from the stack.
 * @return          none
 */
void wiced_bt_ancs_client_discovery_result(wiced_bt_gatt_discovery_result_t *p_data);

/**
 * While application performs GATT discovery it shall pass discovery complete callbacks
 * for the ANCS service to the ANCS Library. As the GATT discovery is perfformed in multiple steps
 * this function initiates the next discovery request.
 *
 * @param           p_data   : Discovery complete data as passed from the stack.
 * @return          none
 */
void wiced_bt_ancs_client_discovery_complete(wiced_bt_gatt_discovery_complete_t *p_data);

/**
 * The application should call this function to start ANCS client. Discovery should be completed
 * before this function is executed.  The start function configures the ANCS server on the iOS device
 * for notification and configures information that the client wants to monitor.
 *
 * @param           conn_id  : GATT connection ID.
 * @return          Result of GATT operation.
 */
wiced_bt_gatt_status_t  wiced_bt_ancs_client_start(uint16_t conn_id);

/**
 * The application calls this function to stop receiving ANCS notifications.
 *
 * @param           conn_id  : GATT connection ID.
 * @return          Result of GATT operation.
 */
wiced_bt_gatt_status_t  wiced_bt_ancs_client_stop(uint16_t conn_id);

/**
 * The application should call this function when BLE connection with a peer
 * device has been established.
 *
 * @param           p_conn_status  : pointer to a wiced_bt_gatt_connection_status_t which includes the address and connection ID.
 * @return          none
 */
void wiced_bt_ancs_client_connection_up(wiced_bt_gatt_connection_status_t *p_conn_status);

/**
 * The application should call this function when BLE connection with a peer
 * device has been disconnected.
 *
 * @param           p_conn_status  : pointer to a wiced_bt_gatt_connection_status_t which includes the address and connection ID.
 * @return          none
 */
void wiced_bt_ancs_client_connection_down(wiced_bt_gatt_connection_status_t *p_conn_status);

/**
 * The application should call this function when it receives GATT Write Response
 * for the attribute handle which belongs to the ANCS service.
 *
 * @param           p_data  : pointer to a GATT operation complete data structure.
 * @return          none
 */
void wiced_bt_ancs_client_write_rsp(wiced_bt_gatt_operation_complete_t *p_data);

/**
 * The application calls this function to send the command to the phone to perform specified action.
 * The action command (for example answer the call, or clear notification, is sent as a response to
 * a notification. The UID of the notification is passed back in this function along with the action ID.
 *
 * @param           conn_id : Connection ID.
 * @param           uid : UID as received in the notification.
 * @param           action_id : Positive or Netgative action ID for the notification specified by UID.
 * @return          Status of the GATT Write operation.
 */
wiced_bt_gatt_status_t wiced_bt_ancs_perform_action(uint16_t conn_id, uint32_t uid, uint32_t action_id);

/*
 * Process GATT Notifications from the client.  Application passes it here only
 * if the handle belongs to this service.
 *
 * @param           p_data  : pointer to a GATT operation complete data structure.
 * @return          none
 */
void wiced_bt_ancs_client_process_notification(wiced_bt_gatt_operation_complete_t *p_data);

#ifdef __cplusplus
}
#endif


/**@} wiced_bt_ancs_api_functions */

#endif
