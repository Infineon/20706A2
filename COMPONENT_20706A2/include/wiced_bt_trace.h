/*
 * (c) 2016-2025, Infineon Technologies AG, or an affiliate of Infineon
 * Technologies AG. All rights reserved.
 * This software, associated documentation and materials ("Software") is
 * owned by Infineon Technologies AG or one of its affiliates ("Infineon")
 * and is protected by and subject to worldwide patent protection, worldwide
 * copyright laws, and international treaty provisions. Therefore, you may use
 * this Software only as provided in the license agreement accompanying the
 * software package from which you obtained this Software. If no license
 * agreement applies, then any use, reproduction, modification, translation, or
 * compilation of this Software is prohibited without the express written
 * permission of Infineon.
 *
 * Disclaimer: UNLESS OTHERWISE EXPRESSLY AGREED WITH INFINEON, THIS SOFTWARE
 * IS PROVIDED AS-IS, WITH NO WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING, BUT NOT LIMITED TO, ALL WARRANTIES OF NON-INFRINGEMENT OF
 * THIRD-PARTY RIGHTS AND IMPLIED WARRANTIES SUCH AS WARRANTIES OF FITNESS FOR A
 * SPECIFIC USE/PURPOSE OR MERCHANTABILITY.
 * Infineon reserves the right to make changes to the Software without notice.
 * You are responsible for properly designing, programming, and testing the
 * functionality and safety of your intended application of the Software, as
 * well as complying with any legal requirements related to its use. Infineon
 * does not guarantee that the Software will be free from intrusion, data theft
 * or loss, or other breaches ("Security Breaches"), and Infineon shall have
 * no liability arising out of any Security Breaches. Unless otherwise
 * explicitly approved by Infineon, the Software may not be used in any
 * application where a failure of the Product or any consequences of the use
 * thereof can reasonably be expected to result in personal injury.
 */

/** @file
*
* \defgroup wiced_utils AIROC Trace Utilities
* \ingroup wicedsys
* @{
*
*Trace Utilities
*
* Support for applications to send debug or information messages to debug UART destinations.
*/
#ifndef _WICED_BT_TRACE_H_
#define _WICED_BT_TRACE_H_

#include <stdarg.h>
#include "bt_types.h"
#include "wiced.h"
#include "wiced_bt_types.h"


/** Debug trace message destinations. Used when calling wiced_set_debug_uart().*/
typedef enum
{
    WICED_ROUTE_DEBUG_NONE  =  0x00, /**< No traces */
    WICED_ROUTE_DEBUG_TO_WICED_UART, /**< send debug strings in formatted AIROC HCI messages over HCI UART to ClientControl or MCU */
    WICED_ROUTE_DEBUG_TO_HCI_UART,   /**< send debug strings as plain text to HCI UART, used by default if wiced_set_debug_uart() not called */
    WICED_ROUTE_DEBUG_TO_DBG_UART,   /**< Deprecated */
    WICED_ROUTE_DEBUG_TO_PUART       /**< send debug strings as plain text to the peripheral uart (PUART) */
}wiced_debug_uart_types_t;

#ifdef WICED_BT_TRACE_ENABLE
/**
 * Macro         WICED_BT_TRACE
 *
 * Utility macro to output trace messages to the debug UART destination.
 *
 * Use this printf()-style macro to print custom messages from application code.
 * Standard printf() % format arguments supported include: 'u,d,i,x,X,c,s'
 *
 * In addition, a custom %B format argument is provided for convenience in printing
 * 6 octect Bluetooth addresses.  Supply a byte array as the corresponding argument
 * to match the %B format specifier.  For example:
 *
 * WICED_BT_TRACE("Received inquiry response from: %B\n", p_inquiry_result->remote_bd_addr);
 */
#define WICED_BT_TRACE(...)                 wiced_printf(NULL, 0, __VA_ARGS__)
/**
 * Macro         WICED_BT_TRACE_ARRAY
 *
 * Utility macro to dump a string message followed by an array of hex data to the debug UART destination.
 *
 * Use this macro to display a string message followed by up to 16 hex bytes of an array from application code.
 * For example:
 *
 * WICED_BT_TRACE_ARRAY("Received EIR data:\n", p_inquiry_result->eir);
 */
#define WICED_BT_TRACE_ARRAY(ptr, len, ...) wiced_printf(NULL, 0, __VA_ARGS__); wiced_trace_array(ptr, len);
#else
#define WICED_BT_TRACE(format, ...)
#define WICED_BT_TRACE_ARRAY(ptr, len, ...)
#endif

/**
 * Macro        wiced_set_debug_uart
 *
 * Override/redirect to wiced_set_debug_uart_patch()
 */
#define wiced_set_debug_uart    wiced_set_debug_uart_patch
/**
 * Function         wiced_set_debug_uart
 *
 * To specify the UART to be used for the debug traces.
 * Overridden by #define to wiced_set_debug_uart_patch()
 *
 * @param[in]      uart        : type of the UART to be used (see #wiced_debug_uart_types_t)
 *
 * @return         void
 *
 */
void wiced_set_debug_uart_patch ( wiced_debug_uart_types_t uart );

/**
 * Function         wiced_set_debug_uart_baudrate
 *
 * It configures the value for wiced_set_debug_uart.
 *
 * @param[in]      baudrate        : baudrate to be used
 *
 * @return          void
 *
 * @note To reflect the configured baudrate, wiced_set_debug_uart API should be invoked
 */
void wiced_set_debug_uart_baudrate ( uint32_t baudrate );

/* @} */

// deprecated/internal
int  wiced_printf(char * buffer, int len, ...);
void wiced_trace_array( const uint8_t* array, uint16_t len );
int  wiced_va_printf(char * buffer, int len, va_list va);
void hs_uart_write(uint8_t byte);

#ifdef WICED_BT_TRACE_ENABLE
#define WICED_SHIM_TRACE_ENABLE
#define WICED_BT_TRACE_CRIT(...) wiced_printf(NULL, 0, __VA_ARGS__)
#else
#define WICED_BT_TRACE_CRIT(...)
#define WICED_BT_TRACE_BDA( bda,... )
#define WICED_BT_TRACE_BDA_CRIT( bda,... )
#endif //WICED_BT_TRACE_ENABLE

#ifdef WICED_SHIM_TRACE_ENABLE
#define WICED_SHIM_TRACE(...)     wiced_printf(NULL, 0, __VA_ARGS__)
#else
#define WICED_SHIM_TRACE(...)
#endif

#endif //_WICED_BT_TRACE_H_
