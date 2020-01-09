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
