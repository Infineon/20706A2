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
