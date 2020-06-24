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
 * This file provides definitions of the Apple Media Service (AMS) library interface
 */

#ifndef __AMS_API_H
#define __AMS_API_H

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup  wiced_bt_ams_api_functions        AMS Library API
 * @ingroup     wicedbt
 *
 * AMS library of the WICED SDK provide a simple method for an application to integrate AMS
 * functionality.  The application needs to call API to initialize the library when it
 * discovers that AMS service is present in the connected device.
 *
 * @{
 */

/// AMS Service GATT UUID 89D3502B-0F36-433A-8EF4-C502AD55F8DC
const char AMS_SERVICE[]             = {0xDC, 0xF8, 0x55, 0xAD, 0x02, 0xC5, 0xF4, 0x8E, 0x3A, 0x43, 0x36, 0x0F, 0x2B, 0x50, 0xD3, 0x89};

/// Remote Command Characteristic: UUID 9B3C81D8-57B1-4A8A-B8DF-0E56F7CA51C2 (writeable) */
const char AMS_REMOTE_CONTROL[]      = {0xC2, 0x51, 0xCA, 0xF7, 0x56, 0x0E, 0xDF, 0xB8, 0x8A, 0x4A, 0xB1, 0x57, 0xD8, 0x81, 0x3C, 0x9B};

/// Entity Update Characteristic: UUID 2F7CABCE-808D-411F-9A0C-BB92BA96C102 (writeable with response, notifiable) */
const char AMS_ENTITY_UPDATE[]       = {0x02, 0xC1, 0x96, 0xBA, 0x92, 0xBB, 0x0C, 0x9A, 0x1F, 0x41, 0x8D, 0x80, 0xCE, 0xAB, 0x7C, 0x2F};

/// Entity Attribute Characteristic: UUID C6B2F38C-23AB-46D8-A6AB-A3A870BBD5D7 (readable, writeable) */
const char AMS_ENTITY_ATTRIBUTE[]    = {0xD7, 0xD5, 0xBB, 0x70, 0xA8, 0xA3, 0xAB, 0xA6, 0xD8, 0x46, 0xAB, 0x23, 0x8C, 0xF3, 0xB2, 0xC6};

/**
 * @anchor AMS_REMOTE_COMMAND_ID
 * @name RemoteCommandID values
 * @{ */
#define AMS_REMOTE_COMMAND_ID_PLAY                      0
#define AMS_REMOTE_COMMAND_ID_PAUSE                     1
#define AMS_REMOTE_COMMAND_ID_TOGGLE_PLAY_PAUSE         2
#define AMS_REMOTE_COMMAND_ID_NEXT_TRACK                3
#define AMS_REMOTE_COMMAND_ID_PREVIOUS_TRACK            4
#define AMS_REMOTE_COMMAND_ID_VOLUME_UP                 5
#define AMS_REMOTE_COMMAND_ID_VOLUME_DOWN               6
#define AMS_REMOTE_COMMAND_ID_ADVANCED_REPEAT_MODE      7
#define AMS_REMOTE_COMMAND_ID_ADVANCED_SHUFFLE_MODE     8
#define AMS_REMOTE_COMMAND_ID_SKIP_FORWARD              9
#define AMS_REMOTE_COMMAND_ID_SKIP_BACKWARD             10
/** @} AMS_REMOTE_COMMAND_ID */

/**
 * @anchor AMS_ENTITY_ID
 * @name EntityID values
 * @{ */
#define AMS_ENTITY_ID_PLAYER                            0
#define AMS_ENTITY_ID_QUEUE                             1
#define AMS_ENTITY_ID_TRACK                             2
/** @} AMS_ENTITY_ID */

/** EntityUpdateFlags */
#define AMS_ENTITY_UPDATE_FLAG_TRUNCATED               	(1 << 0)

/**
 * @anchor AMS_PLAYER_ATTRIBUTE_ID
 * @name PlayerAttributeID values
 * @{ */

/** A string containing the localized name of the app. */
#define AMS_PLAYER_ATTRIBUTE_ID_NAME                    0

/** A concatenation of three comma-separated values:
 *    PlaybackState: a string that represents the integer value of the playback state:
 *        PlaybackStatePaused = 0
 *        PlaybackStatePlaying = 1
 *        PlaybackStateRewinding = 2
 *        PlaybackStateFastForwarding = 3
 *    PlaybackRate: a string that represents the floating point value of the playback rate.
 *    ElapsedTime: a string that represents the floating point value of the elapsed time of
 *    the current track, in seconds, at the moment the value was sent to the MR.
 * See @ref AMS_PLAYBACK_STATUS "Playback Status Constants"
 */
#define AMS_PLAYER_ATTRIBUTE_ID_PLAYBACK_INFO           1

/** A string that represents the floating point value of the volume, ranging from 0 (silent) to 1 (full volume) */
#define AMS_PLAYER_ATTRIBUTE_ID_VOLUME                  2
/** @} AMS_PLAYER_ATTRIBUTE_ID */

/**
 * @anchor AMS_QUEUE_ATTRIBUTE_ID
 * @name QueueAttributeID values
 * @{ */

/** A string containing the integer value of the queue index, zero-based. */
#define AMS_QUEUE_ATTRIBUTE_ID_INDEX                    0

/** A string containing the integer value of the total number of items in the queue. */
#define AMS_QUEUE_ATTRIBUTE_ID_COUNT                    1

/** A string containing the integer value of the shuffle mode. (see @ref AMS_SHUFFLE_MODE "Shuffle Mode Constants") */
#define AMS_QUEUE_ATTRIBUTE_ID_SHUFFLE_MODE             2

/** A string containing the integer value value of the repeat mode. (see @ref AMS_REPEAT_MODE "Repeat Mode Constants") */
#define AMS_QUEUE_ATTRIBUTE_ID_REPEAT_MODE              3

/** @} AMS_QUEUE_ATTRIBUTE_ID */

/**
* @anchor AMS_PLAYBACK_STATUS
* @name Playback Status Constants
* @{ */
#define AMS_PLAYBACK_STATUS_PAUSED                      0
#define AMS_PLAYBACK_STATUS_PLAYING                     1
#define AMS_PLAYBACK_STATUS_REWINDING                   2
#define AMS_PLAYBACK_STATUS_FAST_FORWARDING             3
#define AMS_PLAYBACK_STATUS_MAX                         AMS_PLAYBACK_STATUS_FAST_FORWARDING
/** @} AMS_PLAYBACK_STATUS */

/**
 * @anchor AMS_SHUFFLE_MODE
 * @name Shuffle Mode Constants
 * @{ */
#define AMS_SHUFFLE_MODE_OFF                            0
#define AMS_SHUFFLE_MODE_ONE                            1
#define AMS_SHUFFLE_MODE_ALL                            2
#define AMS_SHUFFLE_MODE_MAX                            AMS_SHUFFLE_MODE_ALL
/** @} AMS_SHUFFLE_MODE */

/**
 * @anchor AMS_REPEAT_MODE
 * @name Repeat Mode Constants
 * @{ */
#define AMS_REPEAT_MODE_OFF                             0
#define AMS_REPEAT_MODE_ONE                             1
#define AMS_REPEAT_MODE_ALL                             2
#define AMS_REPEAT_MODE_MAX                             AMS_REPEAT_MODE_ALL
/** @} AMS_REPEAT_MODE */

/**
 * @anchor AMS_TRACK_ATTRIBUTE_ID
 * @name TrackAttributeID values
 * @{ */
/** A string containing the name of the artist. */
#define AMS_TRACK_ATTRIBUTE_ID_ARTIST                   0

/** A string containing the name of the album. */
#define AMS_TRACK_ATTRIBUTE_ID_ALBUM                    1

/** A string containing the title of the track. */
#define AMS_TRACK_ATTRIBUTE_ID_TITLE                    2

/** A string containing the floating point value of the total duration of the track in seconds. */
#define AMS_TRACK_ATTRIBUTE_ID_DURATION                 3
/** @} AMS_TRACK_ATTRIBUTE_ID */

/**
 * AMS event
 */
typedef struct
{
    uint8_t  entity_id;     /**<  Entity ID (see @ref AMS_ENTITY_ID "Entity ID Values") */
    uint8_t  attribute_id;  /**<  Attribute ID.  Depending on the Entity ID can be one of @ref AMS_PLAYER_ATTRIBUTE_ID "Player Attribute ID",  @ref AMS_QUEUE_ATTRIBUTE_ID "Queue Attribute ID", or @ref AMS_TRACK_ATTRIBUTE_ID "Track Attribute ID" */
    uint8_t  flags;         /**<  Flags */
    uint8_t* attribute_str; /**<  Pointer to the string with attributes info */
    uint8_t  attribute_len; /**<  Length of the string with attributes info */
} wiced_bt_ams_event_t;

/*****************************************************************************
 *          Function Prototypes
 *****************************************************************************/

/**
 * This callback is executed when AMS library completes discovery of AMS service
 * characteristics and descriptors.
 *
 * @param           conn_id : GATT connection ID
 * @param           status  : WICED_TRUE if discovery has been completed successfully.
 * @return          none
 */
typedef void (*wiced_bt_ams_discovery_complete_callback_t)(uint16_t conn_id, wiced_bool_t success);

/**
 * This callback is executed when AMS library completes startup operation of the AMS.
 *
 * @param           conn_id : GATT connection ID
 * @param           status  : WICED_TRUE if operation completed successfully
 * @return          none
 */
typedef void (*wiced_bt_ams_start_complete_callback_t)(uint16_t conn_id, wiced_bool_t success);

/**
 * This callback is executed when AMS library completes deregistration with the AMS.
 *
 * @param           conn_id : GATT connection ID
 * @param           status  : WICED_TRUE if operation completed successfully
 * @return          none
 */
typedef void (*wiced_bt_ams_stop_complete_callback_t)(uint16_t conn_id, wiced_bool_t success);


/**
 * Following structure is used to register application with wiced_bt_ams library
 */
typedef struct
{
    wiced_bt_ams_discovery_complete_callback_t  p_discovery_complete_callback;  /**< callback to be executed when AMS library completes GATT discovery */
    wiced_bt_ams_start_complete_callback_t      p_start_complete_callback;      /**< callback to be executed when AMS library completes AMS Server configuration */
    wiced_bt_ams_stop_complete_callback_t       p_stop_complete_callback;       /**< callback to be executed when AMS library completes disconnect from AMS Server */
} wiced_bt_ams_reg_t;

/**
 * The application should call this function to register application callbacks
 *
 * @param           p_reg  : Registration control block that includes AMS application callbacks.
 * @return          none
 */
void wiced_bt_ams_client_initialize(wiced_bt_ams_reg_t *p_reg);

/**
 * The application should call this function when it discovers that connected central device
 * contains the AMS service.  The function initialize AMS library and starts the GATT discovery
 * of AMS characteristics.
 *
 * @param           conn_id  : GATT connection ID
 * @param           s_handle : Start GATT handle of the AMS service
 * @param           e_handle : End GATT handle of the AMS service
 * @return          WICED_TRUE if GATT discovery started successfully, WICED_FALSE otherwise
 */
wiced_bool_t wiced_bt_ams_client_discover(uint16_t conn_id, uint16_t s_handle, uint16_t e_handle);

/**
 * While the library performs GATT discovery the application shall pass discovery
 * results received from the stack to the AMS Library. The library needs to find
 * three characteristics that belongs to the AMS service including the remote
 * control, the entity update, and the entity attribute. The second has characteristic
 * client configuration descriptor
 *
 * @param           p_data   : Discovery result data as passed from the stack.
 * @return          none
 */
void wiced_bt_ams_client_discovery_result(wiced_bt_gatt_discovery_result_t *p_data);

/**
 * While the library performs GATT discovery the application shall pass discovery
 * complete callbacks to the AMS Library. As the GATT discovery consists or multiple
 * steps this function initiates the next discovery request or write request to
 * configure the AMS service on the iOS device.
 *
 * @param           p_data   : Discovery complete data as passed from the stack.
 * @return          none
 */
void wiced_bt_ams_client_discovery_complete(wiced_bt_gatt_discovery_complete_t *p_data);

/**
 * The application should call this function to start AMS client. Discovery should be completed
 * before this function.  The start function configures the AMS server on the iOS device
 * for notification and configures information that the client wants to monitor.
 *
 * @param           conn_id  : GATT connection ID
 * @return          WICED_TRUE if operation started successfully, WICED_FALSE otherwise
 */
wiced_bool_t wiced_bt_ams_client_start(uint16_t conn_id);

/**
 * The application calls this function to stop receiving notifications.
 *
 * @param           conn_id  : GATT connection ID
 * @return          WICED_TRUE if operation started successfully, WICED_FALSE otherwise
 */
wiced_bool_t wiced_bt_ams_client_stop(uint16_t conn_id);

/**
 * Application should call this function when BLE connection with a peer
 * device has been established.
 *
 * @param           p_conn_status  : pointer to a wiced_bt_gatt_connection_status_t which includes the address and connection ID.
 * @return          none
 */
void wiced_bt_ams_client_connection_up(wiced_bt_gatt_connection_status_t *p_conn_status);

/**
 * The application should call this function when BLE connection with a peer
 * device has been disconnected.
 *
 * @param           p_conn_status  : pointer to a wiced_bt_gatt_connection_status_t which includes the address and connection ID.
 * @return          none
 */
void wiced_bt_ams_client_connection_down(wiced_bt_gatt_connection_status_t *p_conn_status);

/**
 * The application should call this function when it receives GATT Write Response
 * for the attribute handle which belongs to the AMS service.
 *
 * @param           p_data  : pointer to a GATT operation complete data structure.
 * @return          none
 */
void wiced_bt_ams_client_write_rsp(wiced_bt_gatt_operation_complete_t *p_data);

/**
 * The application calls this function to send remote control command to iOS device.
 *
 * @param           ams_command : AMS command (see @ref AMS_REMOTE_COMMAND_ID "RemoteCommandID values")
 * @return          result of the GATT operation
 */
wiced_bt_gatt_status_t wiced_bt_ams_send_remote_command(uint16_t conn_id, uint16_t ams_command);

/**
 * Process GATT Notifications from the iOS device.  Application passes the received notification
 * to this function if the handle belongs to the AMS service.  This function verifies the data and if
 * successful fills the information in the event.
 *
 * @param           p_data  : GATT notification as received from the iOS device
 * @param           p_event : Pointer to an AMS event structure to be filled
 * @return          WICED_TRUE if event is parsed successfully, WICED_FALSE otherwise
 */
wiced_bool_t wiced_bt_ams_client_process_notification(wiced_bt_gatt_operation_complete_t *p_data, wiced_bt_ams_event_t *p_event);

/** @} wiced_bt_ams_api_functions */

#ifdef __cplusplus
}
#endif

#endif
