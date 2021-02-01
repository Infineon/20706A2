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
/*******************************************************************************
 * All common definitions for this SPAR
 *******************************************************************************/

#ifndef _SPAR_COMMON_H_
#define _SPAR_COMMON_H_

#include "spar_utils.h"
#include "types.h"

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif

#ifdef BLEAPP
extern void (*bleapp_pre_init)(void);
extern UINT8 bleapp_trace_enable;
#define APPLICATION_INIT() ATTRIBUTE((section(".app_init_code"))) void application_init( void )
#define BLE_APP_DISABLE_TRACING()  do{                                          \
                                         extern UINT8 bleapp_trace_enable;      \
                                         extern UINT32 blecm_enabledFeatures;   \
                                         bleapp_trace_enable = 0;               \
                                         blecm_enabledFeatures &= ~(0x04);      \
                                     }while(0)

#define BLE_APP_ENABLE_TRACING_ON_HCI_UART()  do{                                     \
                                               extern UINT8 bleapp_trace_enable;      \
                                               extern UINT32 blecm_enabledFeatures;   \
                                               bleapp_trace_enable = 0x08 | 2;               \
                                               blecm_enabledFeatures |= (0x04);       \
                                           }while(0)

#define BLE_APP_ENABLE_TRACING_ON_PUART()  do{                                          \
                                                 extern UINT8 bleapp_trace_enable;      \
                                                 extern UINT32 blecm_enabledFeatures;   \
                                                 bleapp_trace_enable = 1;               \
                                                 blecm_enabledFeatures &= ~(0x04);      \
                                           }while(0)

#define HCI_EVENT_GET_STATUS_FROM_COMMAND_COMPLETE_EVT(evt) (*(UINT8 *)(evt + 1))

#else
EXTERN_C void (*hidd_app_post_stack_init)(void);
#endif

/* WICED BT Application Start Point */
#define APPLICATION_START() ATTRIBUTE((section(".app_init_code"))) void wiced_bt_app_start( void )

#endif
