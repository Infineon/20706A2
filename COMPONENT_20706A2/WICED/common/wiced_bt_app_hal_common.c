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
 *  WICED BT App HAL Common Utilities
 *
 * This file provides definitions of the  HAL interfaces for WICED
 * Application development.
 *
 */
#include "bt_types.h"
#include "wiced_hal_mia.h"
#include "wiced_bt_dev.h"
#include "wiced_bt_trace.h"
#include "wiced_bt_app_hal_common.h"

#include "wiced_timer.h"
#include "sparcommon.h"
#include "wiced_swd_interface.h"
#include "wiced_hal_gpio.h"

/*****************************************************************************
 *                                              External Function Declarations
 ****************************************************************************/

/*****************************************************************************
 *                                              Internal Function Declarations
 ****************************************************************************/

/* LED Timer callback, to handle the LED blinks */
void wiced_bt_app_hal_led_timer_cb( uint32_t param );

/*****************************************************************************
 *                                              Variable Definitions
 ****************************************************************************/
extern wiced_led_config_t platform_led[];

/* wiced bt app led timer, to handle the LED blinks */
wiced_timer_t led_timer;

/* To hold the LED on duration in milliseconds */
static uint16_t wiced_bt_app_hal_led_on_ms = 0;

/* To hold the LED off duration in milliseconds */
static uint16_t wiced_bt_app_hal_led_off_ms = 0;

/* To hold the LED blink count */
static uint8_t  wiced_bt_app_hal_led_blink_count = 0;

/* LED index used for blinking */
static uint32_t wiced_bt_app_hal_led_index = 0xFF;

/*****************************************************************************
 *                                                   Function Definitions
 ****************************************************************************/

/**
 *Wiced BT App Common HAL Initialization
 */
void wiced_bt_app_hal_init ( void )
{
    mia_init();
    gpio_init();
    mia_enableMiaInterrupt(TRUE);
    mia_enableLhlInterrupt(TRUE);

    SETUP_APP_FOR_DEBUG_IF_DEBUG_ENABLED();
    BUSY_WAIT_TILL_MANUAL_CONTINUE_IF_DEBUG_ENABLED();
}

/**
 *Wiced BT App Common LED Initialization
 */
void wiced_bt_app_led_init ( void )
{
    wiced_init_timer( &led_timer, wiced_bt_app_hal_led_timer_cb, 0, WICED_MILLI_SECONDS_TIMER );

    platform_led_init();
}


/**
 * Blinks the LED
 */
void wiced_bt_app_hal_led_blink(wiced_platform_led_t led_index, uint16_t on_ms, uint16_t off_ms, uint8_t num_of_blinks )
{
	wiced_bt_app_hal_led_index = led_index;

    if ( num_of_blinks )
    {
        wiced_bt_app_hal_led_on_ms = on_ms;
        wiced_bt_app_hal_led_off_ms = off_ms;
        wiced_bt_app_hal_led_blink_count = num_of_blinks;

        wiced_bt_app_hal_led_on(led_index);
        wiced_stop_timer(&led_timer);
        wiced_start_timer(&led_timer,on_ms);
    }
}

/**
 * Turns the LED On
 */
void wiced_bt_app_hal_led_on( wiced_platform_led_t led_index )
{
    /* by default LED's are configured to be off
     * hence the default state should indicate the type of the LED */
    if(platform_led[led_index].led_default_state)
    {
        wiced_hal_gpio_set_pin_output(platform_led[led_index].led_gpio, GPIO_PIN_OUTPUT_LOW);
    }
    else
    {
        wiced_hal_gpio_set_pin_output(platform_led[led_index].led_gpio, GPIO_PIN_OUTPUT_HIGH);
    }
}

/**
 * Turns the LED Off
 */
void wiced_bt_app_hal_led_off( wiced_platform_led_t led_index )
{
    /* by default LED's are configured to be off
     * hence the default state should indicate the type of the LED */
    if( platform_led[led_index].led_default_state )
    {
        wiced_hal_gpio_set_pin_output(platform_led[led_index].led_gpio, GPIO_PIN_OUTPUT_HIGH);
    }
    else
    {
        wiced_hal_gpio_set_pin_output(platform_led[led_index].led_gpio, GPIO_PIN_OUTPUT_LOW);
    }
}

/**
 * LED timer callback handler, to handle the LED blinks
 */
void wiced_bt_app_hal_led_timer_cb( uint32_t param )
{
    static uint8_t led_on = 1;

    if(wiced_bt_app_hal_led_index == 0xFF)
    {
        return;
    }

    if ( led_on )
    {
        wiced_bt_app_hal_led_off(wiced_bt_app_hal_led_index);
        if ( --wiced_bt_app_hal_led_blink_count )
        {
            led_on = 0;
            wiced_start_timer( &led_timer, wiced_bt_app_hal_led_off_ms );
        }
        else
        {
		wiced_bt_app_hal_led_index = 0xFF;
        }
    }
    else
    {
        led_on = 1;
        wiced_bt_app_hal_led_on(wiced_bt_app_hal_led_index);
        wiced_start_timer( &led_timer, wiced_bt_app_hal_led_on_ms );
    }
}
