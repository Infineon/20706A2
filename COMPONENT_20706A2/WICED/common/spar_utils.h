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
/*
********************************************************************
*    File Name: spar_utils.h
*
*    Abstract: A few utilities with a reasonable implementation for
*              SPAR.
*
********************************************************************
*/

#ifndef __SPAR_UTILS_H__
#define __SPAR_UTILS_H__


#ifdef __GNUC__
/* Map std functions to what is in the ROM  */
// Memset is a special case - the ARM EABI implementation has
// the length and value parameters swapped so that the EABI
// cal tail-chain memclr. So fis that with a define
// See ARM Runtime ABI for Arm Architecture (IHI0043C)
//#define memset(dest,val,len) __aeabi_memset(dest,len,val)
//#define memcpy __aeabi_memcpy
#define sprintf __2sprintf
#define snprintf __2snprintf
#endif

#if ENABLE_DEBUG
#include "wiced_hal_wdog.h"
unsigned int _tx_v7m_get_int(void);
void _tx_v7m_disable_int(void);
void _tx_v7m_set_int(unsigned int posture);

/// When debugging is enabled, sets up the HW for debugging.
#define SETUP_APP_FOR_DEBUG_IF_DEBUG_ENABLED()   do{   \
        wiced_hal_wdog_disable();                      \
        wiced_configure_swd_pins(SWD_CLK, SWD_IO);     \
    }while(0)

/// Optionally waits in a pseudo while(1) until the user allows the CPU to continue
#define BUSY_WAIT_TILL_MANUAL_CONTINUE_IF_DEBUG_ENABLED()     do{   \
        volatile UINT8 spar_debug_continue = 0;                     \
        unsigned int interrupt_save = _tx_v7m_get_int();            \
        _tx_v7m_disable_int();                                      \
        while(!spar_debug_continue);                                \
        _tx_v7m_set_int(interrupt_save);                            \
    }while(0)
#else
#define SETUP_APP_FOR_DEBUG_IF_DEBUG_ENABLED()
#define BUSY_WAIT_TILL_MANUAL_CONTINUE_IF_DEBUG_ENABLED()
#endif

// If we panic from SPAR, we might not even have access to anything in
// the ROM or the Flash -- we suspect that we've been linked against
// the wrong image. So this.

#define SPAR_ASSERT_PANIC(expr) \
    do { if (!(expr)) while (1) ; } while(0)


#endif
