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

/** @file
 *
 * WICED BT App Common Utilities. This file provides the interfaces to the utilities that
 * can be used by the applications
 */
#ifndef _WICED_BT_APP_COMMON_H_
#define _WICED_BT_APP_COMMON_H_

#include "wiced_bt_ble.h"
#include "wiced_timer.h"
#include "wiced_bt_gatt.h"

// GHS syntax.
#pragma pack(1)

/*****************************************************************************
**                                                      Constants
*****************************************************************************/
/* Bluetooth Device Address Length */
#define BD_ADDR_LEN        6

/* BLE Advertisement Maximum Length*/
#define ADV_LEN_MAX        31

/* Flag length*/
#define FLAGS_LEN           1

/* Code Length */
#define COD_LEN             3

/* 16 bit UUID Length */
#define UUID_LEN            2

/* Device Local Name Maximum Length Supported, additional 1 byte len, 1 byte value for each field,this will be 17 bytes */
#define LOCAL_NAME_LEN_MAX  ( ADV_LEN_MAX - 2 - FLAGS_LEN - 2 - COD_LEN-2-UUID_LEN-2)

/* Version Length */
#define VERSION_LEN         6

/*GATT number of handles that can be handleb the wiced bt app layer */
#define HANDLE_NUM_MAX      5

#define READ_UART_LEN       15

#define SECURITY_ENABLED    0x01
#define SECURITY_REQUEST    0x02

/*  Discoverable Modes */
typedef enum
{
    /* Turns off the discoverability */
    NO_DISCOVERABLE = 0,

    /* Sends directed advertisements at defined low intervals */
    BLE_LOW_DIRECTED_DISCOVERABLE = 1,

    /* Sends directed advertisements at defined high intervals */
    BLE_HIGH_DIRECTED_DISCOVERABLE = 2,

    /* Sends undirected advertisements at defined low intervals */
    BLE_LOW_UNDIRECTED_DISCOVERABLE = 3,

    /* Sends undirected advertisements at defined high intervals */
    BLE_HIGH_UNDIRECTED_DISCOVERABLE = 4,

    /* Without NVRAM checking and start high undirected adv */
    MANDATORY_DISCOVERABLE = 0xFF,
}wiced_bt_app_dev_discover_mode_t;

/*  Events Handled by the wiced bt app  */
typedef enum
{
    /* BLE Advertisement Timeout */
    WICED_BT_APP_ADVT_TIMEOUT = 0,
#if 0
    /* BLE connection is established */
    WICED_BT_APP_LINK_UP,

    /* BLE connection is removed */
    WICED_BT_APP_LINK_DOWN,

    /* GATT server, registers the event to hanle the write request from the client */
    WICED_BT_APP_GATT_HANDLE_WRITE,


    WICED_BT_APP_GATT_HANDLE_READ,

    /* GATT Client, registers the event to process read response */
    WICED_BT_APP_GATT_READ_RESPONSE,

    /* GATT Client, registers the event to process write response */
    WICED_BT_APP_GATT_WRITE_RESPONSE,

    /* GATT client, registers the event to handle the gatt indication from server */
    WICED_BT_APP_GATT_INDICATION,

    /* GATT client, registers the event to handle the  gatt notification from server */
    WICED_BT_APP_GATT_NOTIFICATION,

    /* GATT server, registers the event to handle the  confirmation from client.
            Confirmations are sent by the client as a response to the indication
            message from the server */
    WICED_BT_APP_GATT_CONFIRMATION,

    WICED_BT_APP_GATT_DISC_RESULT,

    WICED_BT_APP_GATT_DISC_COMPLT,
#endif

    /* Maximum number of events handled */
    WICED_BT_APP_MAX_EVENTS
}wiced_bt_app_event_t;


/* Client Characteristic Configuration mode */
typedef enum
{
    CCC_NONE = 0x00,
    CCC_NOTIFICATION = 0x01,
    CCC_INDICATION = 0x02,
    CCC_RESERVED = 0x04,
}wiced_bt_app_ccc_mode_t;

/* Server Characteristic Configuration mode */
typedef enum
{
    SCC_NONE = 0x00,
    SCC_BROADCAST = 0x01,
}wiced_bt_app_scc_mode_t;

/* Button Function list */
typedef enum
{
    BUTTON_PRESS = 0,
    BUTTON_RELEASE = 1,
    BUTTON_POWER = 2,
    BUTTON_CLIENT = 3,
    BUTTON_DISCOVER = 4,
    BUTTON_FILTER = 5,
#ifdef BLE_UART_LOOPBACK_TRACE
    BUTTON_UART = 6,
#endif
    TIMEOUT_POWER = 10, // This is not related to button, but notify when powersave is started
}wiced_bt_app_button_function_t;

/* Find me client state */
typedef enum
{
    FINDME_IDLE = 0,
    FINDME_WAIT_READ_PRIMARY_SERVICE_DEFER = 1,
    FINDME_WAIT_READ_PRIMARY_SERVICE = 2,
    FINDME_WAIT_READ_PRIMARY_SERVICE_COMPLETE = 3,
    FINDME_WAIT_READ_CHARACTERISTIC_DEFER = 4,
    FINDME_WAIT_READ_CHARACTERISTIC = 5,
    FINDME_WAIT_READ_CHARACTERISTIC_COMPLETE = 6,
    FINDME_WAIT_WRITE_ALERTLEVEL_DEFER = 7,
}wiced_bt_app_findme_state_t;


/*****************************************************************************
**                                                  Type Definitions
*****************************************************************************/

/*  Defines the wiced bt app configurations  */
typedef PACKED struct
{
    UINT16 app_timer_interval; //App timer interval in seconds
    UINT16 fine_timer_interval; //App fine timer intreval in milli seconds
    UINT8 default_adv; //default advertisement mode
    UINT8 button_adv_toggle; //pairing button make adv toggle (if 1) or always on (if 0)
    wiced_bt_ble_advert_chnl_map_t chnl_map;//channel map
    UINT16 high_undirect_adv_interval; //slots
    UINT16 low_undirect_adv_interval; //slots
    UINT16 high_undirect_adv_duration; //seconds
    UINT16 low_undirect_adv_duration; //seconds
    UINT16 high_direct_adv_interval; //seconds
    UINT16 low_direct_adv_interval; //seconds
    UINT16 high_direct_adv_duration; //seconds
    UINT16 low_direct_adv_duration; //seconds
    char local_name[LOCAL_NAME_LEN_MAX];
    char cod[COD_LEN];
    char ver[VERSION_LEN];
    UINT8 encr_required; // if 1, encryption is needed before sending indication/notification
    UINT8 disc_required;// if 1, disconnection after confirmation
    UINT8 test_enable;
    UINT8 tx_power_level; //dbm
    UINT8 con_idle_timeout; //second
    UINT8 powersave_timeout; //second
    UINT16 hdl[HANDLE_NUM_MAX];   //GATT HANDLE number
    UINT16 serv[HANDLE_NUM_MAX];  //GATT service UUID
    UINT16 cha[HANDLE_NUM_MAX];   // GATT characteristic UUID
    UINT8 findme_locator_enable; //if 1 Find me locator is enable
    UINT8 findme_alert_level; //alert level of find me
    UINT8 client_grouptype_enable; // if 1 grouptype read can be used
    UINT8 linkloss_button_enable; //if 1 linkloss button is enable
    UINT8 pathloss_check_interval; //second
    UINT8 alert_interval; //interval of alert
    UINT8 high_alert_num;     //number of alert for each interval
    UINT8 mild_alert_num;     //number of alert for each interval
    UINT8 status_led_enable;    //if 1 status LED is enable
    UINT8 status_led_interval; //second
    UINT8 status_led_con_blink; //blink num of connection
    UINT8 status_led_dir_adv_blink; //blink num of dir adv
    UINT8 status_led_un_adv_blink; //blink num of undir adv
    UINT16 led_on_ms;  //led blink on duration in ms
    UINT16 led_off_ms; //led blink off duration in ms
    UINT16 buz_on_ms; //buzzer on duration in ms
    UINT8 button_power_timeout; // seconds
    UINT8 button_client_timeout; // seconds
    UINT8 button_discover_timeout; // seconds
    UINT8 button_filter_timeout; // seconds
#ifdef BLE_UART_LOOPBACK_TRACE
    UINT8 button_uart_timeout; // seconds
#endif
}wiced_bt_app_config_t;

/* Timer Control  */
typedef PACKED struct
{
    UINT8 count;
    UINT8 interval;
    UINT8 blinknum;
    UINT8 duration;
    UINT8 timeout;
}wiced_bt_app_timer_control_t;

// GHS syntax.
#pragma pack()

/* Connection Info */
typedef struct
{
    UINT16 conn_id; //Connection Identifier
    BD_ADDR bda;//Dluetooth Device Address of the connected device
}wiced_bt_app_connection_info;

typedef struct
{
    wiced_bt_gatt_discovery_type_t disc_type;
    wiced_bt_gatt_discovery_result_t *p_data;
}wiced_bt_app_gatt_disc_res_t;

typedef struct
{
    wiced_bt_gatt_discovery_type_t disc_type;
    wiced_bt_gatt_status_t status;
}wiced_bt_app_gatt_discovery_complt_t;

/*application status returned from callback*/
typedef enum
{
    WICED_BT_APP_STATUS_SUCCESS             , // 0x00,
    WICED_BT_APP_STATUS_INVALID_HANDLE      , // 0x01,
    WICED_BT_APP_STATUS_NOT_EXTERNAL_HANDLE , // 0x02,
    WICED_BT_APP_STATUS_ERROR_UNKNOWN       , // 0x03,
    WICED_BT_APP_STATUS_ERROR_BAD_POINTER   , // 0x04
    WICED_BT_APP_STATUS_INVALID_CONNECTION  , // 0x05
}wiced_bt_app_status_t;

typedef wiced_bt_app_status_t (*wiced_bt_app_event_callback_t )(void* p_data);

//Todo Initialize with default config
extern const wiced_bt_app_config_t* p_wiced_bt_app_config;

/*****************************************************************************
**                                                  Function Declarations
*****************************************************************************/

/**  Registers the application configurations with the wiced bt app
 *
 *@param[in]    p_config             :Pointer to the application configurations
 *
 * @return   None
 */
void wiced_bt_app_config( const wiced_bt_app_config_t* p_config);

/** Wiced Bt App Initialization
 *
 *Performs the HAL initialization, GATT Registration and aslo set the BLE advertisement
 *data with the parameters defined by the app
 *
  * @return   wiced_result_t
 */
 wiced_result_t wiced_bt_app_init( void );


/** Starts the application timers . One is app timer which is a seconds timer, and the other is
 * app fine timerwhich is a milli second timer.This function initializes the timers using the application
 *defined timeouts and also starts the timers
 *
  *@param[in]    app_timer_interval             :App timer interval in seconds
 *
 *@param[in]    fine_timer_interval      :App fine timer interval in milliseconds
 *
 *@param[in]    p_app_timer_cb             :Pointer to the application timer callback
 *
 *@param[in]    p_app_fine_timer_cb      :Pointer to the application fine timer callback
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_bt_app_start_timer ( uint16_t app_timer_interval,
    uint16_t fine_timer_interval, wiced_timer_callback_t p_app_timer_cb,
    wiced_timer_callback_t p_app_fine_timer_cb );

/** Stops the application timers.
 *
 * @return   None
 */
void wiced_bt_app_stop_timer ( void );

/** Deinitializes the application timers.
 *
 * @return   None
 */
void wiced_bt_app_deinit_timer( void );

/** Starts the application connection idle timer.This function initialize the timer using the application
 *defined connection idle timeout and also starts the timer
 *
  *@param[in]    con_idle_timeout             :Connection idle timeout in seconds
 *
 *@param[in]    p_app_idle_timer_cb             :Pointer to the application idle timer callback
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_bt_app_start_conn_idle_timer(
                        UINT8 con_idle_timeout,
                        wiced_timer_callback_t p_app_idle_timer_cb );

/** Stops the application connection idle timer.
 *
 * @return   None
 */
void wiced_bt_app_stop_conn_idle_timer( void );

/** Sets up  the application connection idle timer.This function initializes the timer using the application
 *defined connection idle timeout and starts the timer if notification or indication is not enabled for
 *gatt client characteristic configuration  And if notification or indication is enabled in the gatt db,
 * stops the connection idle timer.
 *
 *@param[in]    p_app_idle_timer_cb             :Pointer to the application idle timer callback
 *
 * @return   wiced_result_t
 */
wiced_result_t wiced_bt_app_set_conn_idle_timer_notify_ind_gatt_db( wiced_timer_callback_t p_app_idle_timer_cb );

/** Makes the device discoverable and also sets the advertising parameters based on the chosen mode
 *and the application defined configurations
 *
 *@param[in]    mode             :Discoverable mode
 *
 *@param[in]    remote_addr   : BD Address of the remote  device
 *
 * @return   None
 */
void wiced_bt_app_device_discoverable( wiced_bt_app_dev_discover_mode_t mode,BD_ADDR remote_addr );

/** Gets the device discoverable mode
 *
 * @return   the device discoverable mode
 */
UINT8 wiced_bt_app_get_device_discoverable( void );

/** Registers the application event handler
 *
 *@param[in]    event          :Event
 *
 *@param[in]    p_callback   : Callback function to be invoked on the occurence of the event
 *
 * @return   None
 */
void wiced_bt_app_reg_event_handler( wiced_bt_app_event_t event , wiced_bt_app_event_callback_t p_callback );

#endif //_WICED_BT_APP_COMMON_H_
