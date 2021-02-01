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
 *  This implements the application-thread level event handling for WICED Apps
 */
#ifndef __WICED_BT_EVENT_H__
#define __WICED_BT_EVENT_H__
#include "wiced.h"

 /* The serialization queue will have these callbacks */
typedef struct
{
    // The function to invoke in application thread context
    int (*fn)(void*);

    // Any arbitrary data to be given to the callback. wiced_app_event_serialize Caller has to allocate and free once serialized event handled
    void* data;
} wiced_app_event_srzn_cb_t;


/*
 *This function lets you serialize a call onto the application thread.
 *
 *@param[in]    fn          : serialized call back on serialization
 *
 *@param[in]    data        : data to be handled in serialized call

 * @return      wiced_bool_t

 * Note: It is application's responsibility freeing data pointer
 */
wiced_bool_t wiced_app_event_serialize( int (*fn)(void*), void* data);

#endif //__WICED_BT_EVENT_H__
