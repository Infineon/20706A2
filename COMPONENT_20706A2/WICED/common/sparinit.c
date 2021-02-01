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

#include "sparcommon.h"
#include "wiced_swd_interface.h"
#include "wiced_hal_gpio.h"
#include "wiced.h"

#if ENABLE_DEBUG
extern BOOL32 enableWdog;
#include "wiced_power_save.h"
#endif

extern void (*wiced_bt_app_pre_init)(void);
extern void wiced_bt_app_start( void );

ATTRIBUTE((section(".spar_setup")))
////////////////////////////////////////////////////////////////////////////////
/// Spar entry function called early during initialization. This function or
/// or any of the called functions cannot allocate memory or create new objects.
/// This function may only be used to initialize other function pointers/register
/// a new app create function/initialize global data.
////////////////////////////////////////////////////////////////////////////////

void SPAR_APP_SETUP(void)
{
    // Initialize Spar here.
    // Typically, replace the default createInstance method of a singleton/multiton/factory
    // with a newCreateInstance etc

#if ENABLE_DEBUG

    /* Initialise all the GPIO's to be input pins by default*/
    wiced_hal_gpio_init();

    /* Define the SWD pins through application makefile
     * Ex:  C_FLAGS += -DSWD_CLK=SWDCK_ON_P11
     *      C_FLAGS += -DSWD_IO=SWDIO_ON_P31
     * */
#if defined (SWD_CLK) && defined(SWD_IO)
    wiced_configure_swd_pins(SWD_CLK, SWD_IO);
#else
    #error "Debug pins not defined..."
#endif

    /* Do not allow sleep when debug is enabled */
    wiced_allow_sleep(WICED_FALSE);
#else
    /* This is to prevent SWDIO from affecting UART_RX */
    wiced_configure_swd_pins(SWDCK_DISABLED, SWDIO_DISABLED);
#endif

    wiced_bt_app_pre_init = wiced_bt_app_start;
}
