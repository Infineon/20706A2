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
 *  WICED BT App Common Utilities
 *
 * This file provides definitions of the  interfaces for WICED
 * Application development.
 *
 */

#include "bt_types.h"
#include "wiced_gki.h"
#include "wiced_bt_gatt.h"
#include "wiced_bt_ble.h"
#include "wiced_bt_app_common.h"
#include "wiced_bt_app_hal_common.h"
#include "wiced_bt_trace.h"


/*****************************************************************************
 *                                              Internal Function Declarations
 ****************************************************************************/
#if 0
/* Sets the le advertisement data */
wiced_bt_dev_status_t wiced_bt_app_le_set_adverisement_data( void );

/* Handles the advertisement timeouts */
void wiced_bt_app_advt_timeout( uint32_t mode );

#endif //0

/*****************************************************************************
 *                                              Variable Definitions
 ****************************************************************************/

//Todo Initialize with default config
const wiced_bt_app_config_t* p_wiced_bt_app_config;

/* wiced bt app seconds timer */
wiced_timer_t app_timer;

/* wiced bt app fine timer, milli seconds timer*/
wiced_timer_t app_fine_timer;

/* wiced bt app connection idle timer */
wiced_timer_t app_conn_idle_timer ;

/* wiced bt app connection idle timer, which starts the timer if no notification/indication is enabled */
wiced_timer_t app_conn_idle_timer_no_notify_ind;
#if 0
/* wiced bt app adverisement timer */
wiced_timer_t app_advt_timer ;
#endif //0

/* wiced app event callback pointers */
wiced_bt_app_event_callback_t p_wiced_bt_app_callback[WICED_BT_APP_MAX_EVENTS];

/* Holds the BD Address of the remote device */
BD_ADDR wiced_bt_app_remote_addr={0};
#if 0
/* Holds the device discoverable mode */
uint8_t wiced_bt_app_dev_discoverable = NO_DISCOVERABLE;
#endif //0

#if 0
/* wiced GATT callbacks*/
wiced_bt_gatt_cback_t wiced_bt_app_gatt_cback =
{
    wiced_bt_app_gatt_conn_cb,
    wiced_bt_app_gatt_cmpl_cb,
    wiced_bt_app_gatt_disc_result_cb,
    wiced_bt_app_gatt_disc_cmplt_cb,
    wiced_bt_app_gatt_req_cb
};
#endif

/*****************************************************************************
 *                                                   Function Definitions
 ****************************************************************************/

#if 0
/**
 *Registers the application configurations with the wiced bt app
 */
void wiced_bt_app_config( const wiced_bt_app_config_t* p_config)
{
    p_wiced_bt_app_config = p_config;
}

#endif //0

/**
 *Wiced Bt App Initialization
 */
wiced_result_t wiced_bt_app_init ( void )
{
    wiced_bt_app_hal_init();

    //if ( wiced_bt_app_le_set_adverisement_data()!=  WICED_BT_SUCCESS )
       // return WICED_ERROR;

    return WICED_SUCCESS;
}

/**
 *Starts the application timers . One is app timer which is a seconds timer, and the other is
 * app fine timerwhich is a milli second timer.This function initializes the timers using the application
 *defined timeouts and also starts the timers
 */
wiced_result_t wiced_bt_app_start_timer ( uint16_t app_timer_interval,
    uint16_t fine_timer_interval, wiced_timer_callback_t p_app_timer_cb,
    wiced_timer_callback_t p_app_fine_timer_cb  )
{
    if ( app_timer_interval != 0 )
    {
        if ( wiced_init_timer( &app_timer, p_app_timer_cb, 0, WICED_SECONDS_PERIODIC_TIMER ) == WICED_SUCCESS )
        {
            if ( wiced_start_timer( &app_timer, app_timer_interval) != WICED_SUCCESS )
            {
                return WICED_ERROR;
            }

        }
        else
        {
            return WICED_ERROR;
        }
    }

    if ( fine_timer_interval != 0 )
    {
        if ( wiced_init_timer( &app_fine_timer, p_app_fine_timer_cb, 0, WICED_MILLI_SECONDS_PERIODIC_TIMER ) == WICED_SUCCESS )
        {
            if ( wiced_start_timer( &app_fine_timer, fine_timer_interval ) != WICED_SUCCESS )
            {
                return WICED_ERROR;
            }
        }
        else
        {
            return WICED_ERROR;
        }
    }
    return WICED_SUCCESS;
}

/**
 *Stops the application timers.
 */
void wiced_bt_app_stop_timer ( void )
{
    wiced_stop_timer( &app_timer );
    wiced_stop_timer( &app_fine_timer );

}

/**
 *Deinitializes the application timers.
 */
void wiced_bt_app_deinit_timer( void )
{
    wiced_deinit_timer( &app_timer );
    wiced_deinit_timer( &app_fine_timer );
}

/**
 *Starts the application connection idle timer.This function initialize the timer using the application
 *defined connection idle timeout and also starts the timer
 */
wiced_result_t wiced_bt_app_start_conn_idle_timer(
                        UINT8 con_idle_timeout,
                        wiced_timer_callback_t p_app_idle_timer_cb )
{

    if ( wiced_is_timer_in_use ( &app_conn_idle_timer ) )
    {
          wiced_stop_timer( &app_conn_idle_timer );
    }
    if ( wiced_init_timer( &app_conn_idle_timer, p_app_idle_timer_cb, 0, WICED_SECONDS_TIMER ) == WICED_SUCCESS )
    {
        if ( wiced_start_timer( &app_conn_idle_timer, con_idle_timeout ) ==  WICED_SUCCESS )
        {
            return WICED_SUCCESS;
        }
    }
    return WICED_ERROR;
}

/**
 *Stops the application connection idle timer.
 */
void wiced_bt_app_stop_conn_idle_timer( void )
{
    wiced_stop_timer(&app_conn_idle_timer);
}

/**
 *Sets up  the application connection idle timer.This function initializes the timer using the application
 *defined connection idle timeout and starts the timer if notification or indication is not enabled for
 *gatt client characteristic configuration. And if the notificationor indication is enabled in the gatt db,
 * stops the connection idle timer.
 */
wiced_result_t wiced_bt_app_set_conn_idle_timer_notify_ind_gatt_db( wiced_timer_callback_t p_app_idle_timer_cb )
{
    if ( p_wiced_bt_app_config->con_idle_timeout )
    {
        /* Stops the connection idle timer if already in use */
        if ( wiced_is_timer_in_use ( &app_conn_idle_timer_no_notify_ind ) )
        {
              wiced_stop_timer(&app_conn_idle_timer_no_notify_ind);
        }

#if 0
        /* Starts the connection idle timer if notification or indication is not enabled for gatt client characteristic configuration  */
        if ( !wiced_bt_gatt_check_notify_ind_db() )
        {
            if ( wiced_init_timer( &app_conn_idle_timer_no_notify_ind, p_app_idle_timer_cb, 0, WICED_SECONDS_TIMER )== WICED_SUCCESS )
            {
                if ( wiced_start_timer( &app_conn_idle_timer_no_notify_ind, p_wiced_bt_app_config->con_idle_timeout ) ==  WICED_SUCCESS )
                {
                    return WICED_SUCCESS;
                }
            }

            return WICED_ERROR;
        }
#endif
    }
    return WICED_SUCCESS;
}

#if 0
/**
 *Makes the device discoverable and also sets the advertising parameters based on the chosen mode
 *and the application defined configurations
 */
void wiced_bt_app_device_discoverable( wiced_bt_app_dev_discover_mode_t mode, BD_ADDR remote_addr )
{
    uint16_t time_interval = 0;
    uint16_t timer_duration = 0;
    wiced_bt_app_dev_discoverable = mode;
    switch ( mode )
    {
        case NO_DISCOVERABLE:
            wiced_bt_dev_set_discoverability (BTM_NON_DISCOVERABLE,0, 0);
            if ( wiced_is_timer_in_use ( &app_advt_timer ) )
            {
                wiced_stop_timer(&app_advt_timer);
            }
            return;
        case BLE_LOW_DIRECTED_DISCOVERABLE:
            time_interval = p_wiced_bt_app_config->low_direct_adv_interval;
            timer_duration = p_wiced_bt_app_config->low_direct_adv_duration;
            memcpy( wiced_bt_app_remote_addr, remote_addr, sizeof(BD_ADDR));
            break;
        case BLE_HIGH_DIRECTED_DISCOVERABLE:
            time_interval = p_wiced_bt_app_config->high_direct_adv_interval;
            timer_duration = p_wiced_bt_app_config->high_direct_adv_duration;
            memcpy( wiced_bt_app_remote_addr, remote_addr, sizeof(BD_ADDR));
            break;
        case BLE_LOW_UNDIRECTED_DISCOVERABLE:
            time_interval = p_wiced_bt_app_config->low_undirect_adv_interval;
            timer_duration = p_wiced_bt_app_config->low_undirect_adv_duration;
            break;
        case BLE_HIGH_UNDIRECTED_DISCOVERABLE:
            time_interval = p_wiced_bt_app_config->high_undirect_adv_interval;
            timer_duration = p_wiced_bt_app_config->high_undirect_adv_duration;
            break;
        default:
            return;
    }
    // wiced_bt_ble_set_advertising_params( time_interval, time_interval,(tBLE_BD_ADDR*)remote_addr,
    //       p_wiced_bt_app_config->chnl_map );

    wiced_bt_dev_set_discoverability( BTM_BLE_GENERAL_DISCOVERABLE_FLAG, BTM_DEFAULT_DISC_WINDOW, time_interval );

    if ( wiced_is_timer_in_use ( &app_advt_timer ) )
    {
        wiced_stop_timer( &app_advt_timer );
    }

    wiced_init_timer( &app_advt_timer, wiced_bt_app_advt_timeout, mode, WICED_SECONDS_TIMER );

    wiced_start_timer( &app_advt_timer, timer_duration );
}

/**
 *Gets the device discoverable mode
 */
uint8_t wiced_bt_app_get_device_discoverable( void )
{
    return wiced_bt_app_dev_discoverable;
}
#endif //0
/**
 *Registers the application event handler
 */
void wiced_bt_app_reg_event_handler( wiced_bt_app_event_t event , wiced_bt_app_event_callback_t p_callback )
{
    p_wiced_bt_app_callback[event] = p_callback;
}

/*****************************************************************************
 *                                                  Internal  Function Definitions
 ****************************************************************************/
#if 0
/**
 *Sets the le advertisement data
 */
wiced_bt_dev_status_t wiced_bt_app_le_set_adverisement_data( void )
{
    wiced_bt_ble_prop_elem_t prop_element[3] = {
        { BTM_BLE_ADVERT_TYPE_16SRV_COMPLETE, LEN_UUID_16, NULL },
        { BTM_BLE_ADVERT_TYPE_NAME_COMPLETE , 0          , NULL },
        { BTM_BLE_ADVERT_TYPE_TX_POWER    , 1          , NULL }
    };
    wiced_bt_ble_proprietary_t prop_data = { 3, NULL };
    wiced_bt_ble_advert_data_t adv_data = {
        { 0, 0},
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        NULL,
        0,
        BTM_BLE_GENERAL_DISCOVERABLE_FLAG|BTM_BLE_BREDR_NOT_SUPPORTED,
        0
    };


    // set the ptr to
    prop_element[0].p_val = (uint8_t*)&p_wiced_bt_app_config->serv[0];

    // set the len and ptr to adv name
    prop_element[1].len   = strlen(p_wiced_bt_app_config->local_name);
    prop_element[1].p_val = (uint8_t*)p_wiced_bt_app_config->local_name;

    // se the pointer to tx power
    prop_element[2].p_val = (uint8_t*)&p_wiced_bt_app_config->tx_power_level;

    prop_data.p_elem       = prop_element;
    adv_data.p_proprietary = (wiced_bt_ble_proprietary_t*)&prop_data;

    return wiced_bt_ble_set_advertisement_data(
            BTM_BLE_ADVERT_BIT_FLAGS|BTM_BLE_ADVERT_BIT_PROPRIETARY,
            &adv_data);
}


/**
 *Handles the advertisement timeouts
 */
void wiced_bt_app_advt_timeout ( uint32_t mode )
{

    WICED_BT_TRACE_T1("wiced_bt_app_advt_timeout",mode);

    switch ( mode )
    {
        case BLE_LOW_DIRECTED_DISCOVERABLE:
            wiced_bt_app_device_discoverable (NO_DISCOVERABLE,NULL);
             /* Invoke the advertisement stopped callback */
            if ( p_wiced_bt_app_callback[WICED_BT_APP_ADVT_TIMEOUT] )
                p_wiced_bt_app_callback[WICED_BT_APP_ADVT_TIMEOUT](NULL);

            break;

        case BLE_HIGH_DIRECTED_DISCOVERABLE:
            wiced_bt_app_device_discoverable (BLE_LOW_DIRECTED_DISCOVERABLE,wiced_bt_app_remote_addr);
            break;

        case BLE_LOW_UNDIRECTED_DISCOVERABLE:
            wiced_bt_app_device_discoverable (NO_DISCOVERABLE,NULL);

            /* Invoke the advertisement stopped callback */
            if ( p_wiced_bt_app_callback[WICED_BT_APP_ADVT_TIMEOUT] )
               p_wiced_bt_app_callback[WICED_BT_APP_ADVT_TIMEOUT](NULL);
            break;

        case BLE_HIGH_UNDIRECTED_DISCOVERABLE:
             wiced_bt_app_device_discoverable (BLE_LOW_UNDIRECTED_DISCOVERABLE,NULL);
            break;
        default:
            break;
    }
}

#endif //0

#if 0
/**
 * Callback function invoked when a connection is established.or lost
 */
void wiced_bt_app_gatt_conn_cb(  BD_ADDR bda, uint16_t conn_id, BOOLEAN connected, wiced_bt_gatt_disconn_reason_t reason, tBT_TRANSPORT transport )
{
    wiced_bt_app_connection_info info;
    WICED_BT_TRACE_T3("wiced_bt_app_gatt_conn_cb",connected,conn_id,reason);

    info.conn_id = conn_id;
    memcpy(info.bda,bda,sizeof(BD_ADDR));

    if ( connected )
    {
         if ( p_wiced_bt_app_callback[WICED_BT_APP_LINK_UP] )
             p_wiced_bt_app_callback[WICED_BT_APP_LINK_UP](&info);
    }
    else
    {
        if ( p_wiced_bt_app_callback[WICED_BT_APP_LINK_DOWN] )
            p_wiced_bt_app_callback[WICED_BT_APP_LINK_DOWN](&info);
    }
}

/* Callback function invoked on getting responses to read/write/disc/config operations */
/**
 *Handles the advertisement timeouts
 */
void wiced_bt_app_gatt_cmpl_cb( uint16_t conn_id, wiced_bt_gatt_optype_t op, wiced_bt_gatt_status_t status, wiced_bt_gatt_cl_complete_t *p_data )
{
    WICED_BT_TRACE_T3("wiced_bt_app_gatt_cmpl_cb",conn_id,op,status);

    switch ( op )
    {
        case GATTC_OPTYPE_READ:
            if ( p_wiced_bt_app_callback[WICED_BT_APP_GATT_READ_RESPONSE] )
                p_wiced_bt_app_callback[WICED_BT_APP_GATT_READ_RESPONSE](&p_data->att_value);
            break;

        case GATTC_OPTYPE_WRITE:
            if ( p_wiced_bt_app_callback[WICED_BT_APP_GATT_WRITE_RESPONSE] )
                p_wiced_bt_app_callback[WICED_BT_APP_GATT_WRITE_RESPONSE](&p_data->att_value);
            break;

        case GATTC_OPTYPE_NOTIFICATION:
            if ( p_wiced_bt_app_callback[WICED_BT_APP_GATT_NOTIFICATION] )
                p_wiced_bt_app_callback[WICED_BT_APP_GATT_NOTIFICATION](&p_data->att_value);
            break;

       case GATTC_OPTYPE_INDICATION:
            if ( p_wiced_bt_app_callback[WICED_BT_APP_GATT_INDICATION] )
                p_wiced_bt_app_callback[WICED_BT_APP_GATT_INDICATION](&p_data->att_value);
            break;

       default:
            break;
    }
}

/**
 *Callback function called when server receives an attribute request.
 */
void  wiced_bt_app_gatt_req_cb( uint16_t conn_id, uint32_t trans_id, wiced_bt_gatt_req_type_t type, wiced_bt_gatt_data_t *p_data )
{
    wiced_bt_app_status_t app_status = WICED_BT_APP_STATUS_SUCCESS;

    WICED_BT_TRACE_T3("wiced_bt_app_gatt_req_cb",conn_id,trans_id,type);

    switch ( type )
    {
        case WICED_BT_GATT_REQ_TYPE_WRITE:
        {
            wiced_bt_gatt_write_req_ext_t write_data_ext;
            write_data_ext.conn_id = conn_id;
            write_data_ext.p_write_req = &p_data->write_req;

            if ( p_wiced_bt_app_callback[WICED_BT_APP_GATT_HANDLE_WRITE] )
            {
                app_status = p_wiced_bt_app_callback[WICED_BT_APP_GATT_HANDLE_WRITE](&write_data_ext);
            }
            wiced_bt_gatt_handle_write_request(conn_id,trans_id,&p_data->write_req, app_status);
        }
            break;

        case WICED_BT_GATT_REQ_TYPE_READ:
        {
            wiced_bt_gatt_read_req_ext_t read_data_ext;

            if( (read_data_ext.p_val = wiced_bt_get_buffer(WICED_BT_GATT_MTU)) == NULL )
            {
                WICED_BT_TRACE("alloc fail");
                return;
            }
            read_data_ext.conn_id = conn_id;
            read_data_ext.max_val_len = WICED_BT_GATT_MTU -1;//LEATT_ATT_MTU - sizeof(LEATT_PDU_READ_RSP_HDR)
            read_data_ext.p_read_req = &(p_data->read_req);
            if ( p_wiced_bt_app_callback[WICED_BT_APP_GATT_HANDLE_READ] )
            {
                app_status = p_wiced_bt_app_callback[WICED_BT_APP_GATT_HANDLE_READ](&read_data_ext);
            }
            wiced_bt_gatt_handle_read_request(conn_id,trans_id,&p_data->read_req, read_data_ext.p_val, read_data_ext.val_len, app_status);

            wiced_bt_free_buffer(read_data_ext.p_val);
        }
            break;

        case WICED_BT_GATT_REQ_TYPE_CONF:
            /* Invoke the callback to indicate the reception of confirmation from the client */
            if ( p_wiced_bt_app_callback[WICED_BT_APP_GATT_CONFIRMATION] )
               p_wiced_bt_app_callback[WICED_BT_APP_GATT_CONFIRMATION](&conn_id);
            break;

        default:
            break;
    }
}

/**
 *Callback function invoked with discovery results
 */
 void wiced_bt_app_gatt_disc_result_cb( uint16_t conn_id, wiced_bt_gatt_disc_type_t disc_type, wiced_bt_gatt_disc_res_t *p_data )
{
    wiced_bt_app_gatt_disc_res_t result;
    WICED_BT_TRACE_T2( "wiced_bt_app_gatt_disc_result_cb", conn_id, disc_type );

    result.disc_type = disc_type;
    result.p_data = p_data;

    /* Invoke the callback to indicate the reception of discovery result */
    if ( p_wiced_bt_app_callback[ WICED_BT_APP_GATT_DISC_RESULT ] )
        p_wiced_bt_app_callback[ WICED_BT_APP_GATT_DISC_RESULT ]( &result );
}

/**
 *Callback function invoked on discovery complete event
 */
void wiced_bt_app_gatt_disc_cmplt_cb( uint16_t conn_id, wiced_bt_gatt_disc_type_t disc_type, wiced_bt_gatt_status_t status )
{
    wiced_bt_app_gatt_disc_complt_t event;
    WICED_BT_TRACE_T2( "wiced_bt_app_gatt_disc_cmplt_cb", conn_id, disc_type );

    event.disc_type = disc_type;
    event.status = status;

     /* Invoke the callback to indicate the discovery complete */
    if ( p_wiced_bt_app_callback[ WICED_BT_APP_GATT_DISC_COMPLT ] )
        p_wiced_bt_app_callback[ WICED_BT_APP_GATT_DISC_COMPLT ]( &event );
}

#endif
